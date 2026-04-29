#include "server.h"

using json = nlohmann::json;

#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

// ─── Helpers ────────────────────────────────────────────────────────────────

static void json_reply(httplib::Response& res, int status, const json& body) {
  res.status = status;
  res.set_content(body.dump(), "application/json");
}

static StyleType parse_style(const std::string& s) {
  if (s == "aggressive") return StyleType::AGGRESSIVE;
  if (s == "defensive")  return StyleType::DEFENSIVE;
  if (s == "berserker")  return StyleType::BERSERKER;
  if (s == "cowardly")   return StyleType::COWARDLY;
  return StyleType::BALANCED;
}

static json actor_json(Actor* a) {
  return {
    {"name",         a->get_name()},
    {"hp",           a->get_health()},
    {"health_state", healthStateStr(a->get_healthstate())},
    {"combat_state", combatStateStr(a->get_combatstate())},
    {"strategy",     a->get_strategy()->get_name()},
  };
}

// ─── WorldServer ────────────────────────────────────────────────────────────

WorldServer::WorldServer(const std::string& host, int port)
  : _host(host), _port(port) {
  cnf = ConfigManager::GetInstance();
  log = Logger::GetInstance();
  lb  = LeaderBoard::GetInstance();
  register_routes();
}

std::string WorldServer::new_session_id() {
  static std::mt19937 rng(std::random_device{}());
  static std::uniform_int_distribution<uint32_t> dist;
  char buf[33];
  snprintf(buf, sizeof(buf), "%08x%08x%08x%08x",
    dist(rng), dist(rng), dist(rng), dist(rng));
  return std::string(buf);
}

void WorldServer::sweep_expired() {
  std::time_t now = std::time(nullptr);
  for (auto it = _sessions.begin(); it != _sessions.end(); ) {
    if (now - it->second->last_active > SESSION_TTL) {
      char buf[64];
      snprintf(buf, sizeof(buf), "Session expired: %s", it->first.c_str());
      log->named_log(__FILENAME__, buf);
      delete it->second;
      it = _sessions.erase(it);
    } else {
      ++it;
    }
  }
}

void WorldServer::register_routes() {
  _sv.Get("/health", [this](const httplib::Request& req, httplib::Response& res) {
    route_health(req, res);
  });
  _sv.Post("/fight", [this](const httplib::Request& req, httplib::Response& res) {
    route_fight(req, res);
  });
  _sv.Post("/step", [this](const httplib::Request& req, httplib::Response& res) {
    route_step(req, res);
  });
  _sv.Get("/status", [this](const httplib::Request& req, httplib::Response& res) {
    route_status(req, res);
  });
  _sv.Get("/leaderboard", [this](const httplib::Request& req, httplib::Response& res) {
    route_leaderboard(req, res);
  });
  _sv.Post("/reset", [this](const httplib::Request& req, httplib::Response& res) {
    route_reset(req, res);
  });
}

// ─── Route Handlers ─────────────────────────────────────────────────────────

void WorldServer::route_health(const httplib::Request&, httplib::Response& res) {
  std::lock_guard<std::mutex> lock(_session_mutex);
  json_reply(res, 200, {
    {"status",   "ok"},
    {"version",  cnf->get_version()},
    {"sessions", _sessions.size()},
  });
}

/*!
 * POST /fight
 * Body: { "t1": "name", "t2": "name", "style1"?: "...", "style2"?: "..." }
 * Creates a new CombatSession and returns the session_id.
*/
void WorldServer::route_fight(const httplib::Request& req, httplib::Response& res) {
  json body;
  try { body = json::parse(req.body); }
  catch (...) { json_reply(res, 400, {{"error", "invalid JSON"}}); return; }

  if (!body.contains("t1") || !body.contains("t2")) {
    json_reply(res, 400, {{"error", "required fields: t1, t2"}}); return;
  }

  std::string n1 = body["t1"];
  std::string n2 = body["t2"];
  std::string s1 = body.value("style1", "balanced");
  std::string s2 = body.value("style2", "balanced");

  Toon* t1 = new Toon(n1); t1->set_strategy(make_strategy(parse_style(s1)));
  Toon* t2 = new Toon(n2); t2->set_strategy(make_strategy(parse_style(s2)));

  CombatSession* session = new CombatSession(t1, t2);
  std::string sid = new_session_id();

  {
    std::lock_guard<std::mutex> lock(_session_mutex);
    sweep_expired();
    _sessions[sid] = session;
  }

  char buf[64];
  snprintf(buf, sizeof(buf), "Session started: %s (%s vs %s)", sid.c_str(), n1.c_str(), n2.c_str());
  log->named_log(__FILENAME__, buf);

  json_reply(res, 201, {
    {"session_id", sid},
    {"t1",         actor_json(t1)},
    {"t2",         actor_json(t2)},
  });
}

/*!
 * POST /step
 * Body: { "session_id": "..." }
 * Advances combat one cycle. Returns updated actor states and combat outcome.
*/
void WorldServer::route_step(const httplib::Request& req, httplib::Response& res) {
  json body;
  try { body = json::parse(req.body); }
  catch (...) { json_reply(res, 400, {{"error", "invalid JSON"}}); return; }

  if (!body.contains("session_id")) {
    json_reply(res, 400, {{"error", "required field: session_id"}}); return;
  }
  std::string sid = body["session_id"];

  std::lock_guard<std::mutex> lock(_session_mutex);
  auto it = _sessions.find(sid);
  if (it == _sessions.end()) {
    json_reply(res, 404, {{"error", "session not found or expired"}}); return;
  }

  CombatSession* s = it->second;
  s->touch();

  if (s->ended) {
    json_reply(res, 200, {
      {"session_id", sid},
      {"in_combat",  false},
      {"ended",      true},
      {"winner",     s->winner},
      {"t1",         actor_json(s->t1)},
      {"t2",         actor_json(s->t2)},
    });
    return;
  }

  if (s->combat->inCombat()) {
    s->combat->cycleCombat();
  }

  bool still_going = s->combat->inCombat();

  if (!still_going && !s->ended) {
    s->ended = true;
    if (!s->t1->isAlive())
      s->winner = s->t2->get_name();
    else if (!s->t2->isAlive())
      s->winner = s->t1->get_name();
    else
      s->winner = "fled";

    lb->record_single_damage(s->t1->get_name(), s->combat->get_peak1());
    lb->record_single_damage(s->t2->get_name(), s->combat->get_peak2());

    char buf[64];
    snprintf(buf, sizeof(buf), "Session ended: %s, winner: %s", sid.c_str(), s->winner.c_str());
    log->named_log(__FILENAME__, buf);
  }

  json_reply(res, 200, {
    {"session_id", sid},
    {"in_combat",  still_going},
    {"ended",      s->ended},
    {"winner",     s->ended ? s->winner : ""},
    {"t1",         actor_json(s->t1)},
    {"t2",         actor_json(s->t2)},
  });
}

/*!
 * GET /status?session=<session_id>
 * Returns current actor state without advancing combat.
*/
void WorldServer::route_status(const httplib::Request& req, httplib::Response& res) {
  if (!req.has_param("session")) {
    // No session param — return summary of all active sessions
    std::lock_guard<std::mutex> lock(_session_mutex);
    json sessions = json::array();
    for (auto& [sid, s] : _sessions) {
      sessions.push_back({
        {"session_id", sid},
        {"ended",      s->ended},
        {"t1",         s->t1->get_name()},
        {"t2",         s->t2->get_name()},
      });
    }
    json_reply(res, 200, {{"sessions", sessions}});
    return;
  }

  std::string sid = req.get_param_value("session");
  std::lock_guard<std::mutex> lock(_session_mutex);
  auto it = _sessions.find(sid);
  if (it == _sessions.end()) {
    json_reply(res, 404, {{"error", "session not found or expired"}}); return;
  }

  CombatSession* s = it->second;
  json_reply(res, 200, {
    {"session_id", sid},
    {"in_combat",  s->combat->inCombat()},
    {"ended",      s->ended},
    {"winner",     s->ended ? s->winner : ""},
    {"t1",         actor_json(s->t1)},
    {"t2",         actor_json(s->t2)},
  });
}

void WorldServer::route_leaderboard(const httplib::Request&, httplib::Response& res) {
  lb->display();
  json_reply(res, 200, {{"note", "leaderboard printed to server log"}});
}

/*!
 * POST /reset
 * Body: { "session_id": "..." }  — delete one session
 * Body: {}                       — delete all sessions
*/
void WorldServer::route_reset(const httplib::Request& req, httplib::Response& res) {
  json body;
  try { body = json::parse(req.body); } catch (...) { body = json::object(); }

  std::lock_guard<std::mutex> lock(_session_mutex);

  if (body.contains("session_id")) {
    std::string sid = body["session_id"];
    auto it = _sessions.find(sid);
    if (it == _sessions.end()) {
      json_reply(res, 404, {{"error", "session not found"}}); return;
    }
    delete it->second;
    _sessions.erase(it);
    json_reply(res, 200, {{"reset", sid}});
  } else {
    int count = static_cast<int>(_sessions.size());
    for (auto& [sid, s] : _sessions) { delete s; }
    _sessions.clear();
    json_reply(res, 200, {{"reset", "all"}, {"cleared", count}});
  }
}

// ─── Listen ─────────────────────────────────────────────────────────────────

void WorldServer::listen() {
  char buf[64];
  snprintf(buf, sizeof(buf), "WorldServer listening on %s:%d", _host.c_str(), _port);
  log->named_log(__FILENAME__, buf);
  _sv.listen(_host.c_str(), _port);
}

WorldServer::~WorldServer() {
  std::lock_guard<std::mutex> lock(_session_mutex);
  for (auto& [sid, s] : _sessions) { delete s; }
  _sessions.clear();
}
