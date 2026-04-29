#ifndef ENGINE_SERVER_H
#define ENGINE_SERVER_H

#include <mutex>
#include <random>
#include <unordered_map>

// httplib requires Win10+ Winsock APIs on Windows
#ifdef _WIN32
#  if !defined(_WIN32_WINNT) || _WIN32_WINNT < 0x0A00
#    undef  _WIN32_WINNT
#    define _WIN32_WINNT 0x0A00
#  endif
#endif
#include "httplib.h"
#include "json.hpp"

#include "../core/actor.h"
#include "../core/battle.h"
#include "../core/combat.h"
#include "../core/config.h"
#include "../core/leader.h"
#include "../core/logger.h"
#include "../core/strategy.h"
#include "../core/toon.h"

/*!
 * @struct  CombatSession server.h
 * @brief   Owns two Toons and the Combat object for one active session.
 * @details Destroyed when combat ends or the session TTL expires.
*/
struct CombatSession {
  Toon*       t1;
  Toon*       t2;
  Combat*     combat;
  std::time_t last_active;
  bool        ended;
  std::string winner;

  CombatSession(Toon* a, Toon* b)
    : t1(a), t2(b), combat(new Combat(a, b)),
      last_active(std::time(nullptr)), ended(false) {}

  ~CombatSession() {
    delete combat; combat = nullptr;
    delete t1;     t1     = nullptr;
    delete t2;     t2     = nullptr;
  }

  void touch() { last_active = std::time(nullptr); }
};

/*!
 * @class   WorldServer server.h server.cpp
 * @brief   HTTP server that exposes the IoE game engine as a REST API.
 * @details Maintains an in-memory session registry for active combat.
 *          Each session is keyed by a random 128-bit hex string and expires
 *          after SESSION_TTL seconds of inactivity.
*/
class WorldServer {
private:
  static constexpr int SESSION_TTL = 300; //!< Seconds before idle session expires

  httplib::Server   _sv;
  ConfigManager    *cnf;
  Logger           *log;
  LeaderBoard      *lb;

  std::unordered_map<std::string, CombatSession*> _sessions;
  std::mutex _session_mutex;

  int         _port;
  std::string _host;

  std::string new_session_id();
  void        sweep_expired();

  void register_routes();

  // Route handlers
  void route_health      (const httplib::Request&, httplib::Response&);
  void route_fight       (const httplib::Request&, httplib::Response&);
  void route_step        (const httplib::Request&, httplib::Response&);
  void route_status      (const httplib::Request&, httplib::Response&);
  void route_leaderboard (const httplib::Request&, httplib::Response&);
  void route_reset       (const httplib::Request&, httplib::Response&);

public:
  /*!
   * @brief   Construct the server, wiring up all singletons and routes.
   * @param[in] host  Bind address (default "0.0.0.0")
   * @param[in] port  Listen port  (default 8081)
  */
  WorldServer(const std::string& host = "0.0.0.0", int port = 8081);

  /*!
   * @brief   Block and serve until the process is killed.
  */
  void listen();

  ~WorldServer();
};

#endif // ENGINE_SERVER_H //
