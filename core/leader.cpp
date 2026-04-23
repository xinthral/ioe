#include "leader.h"

/*!
 * @def     __FILENAME__
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

//! Singleton Instance
LeaderBoard* LeaderBoard::_singleton = NULL;
std::mutex   LeaderBoard::_mutex;

/*!
 * @brief   Protected Constructor
*/
LeaderBoard::LeaderBoard() {
  log = Logger::GetInstance();
  log->named_log(__FILENAME__, "LeaderBoard Established.");
}

/*!
 * @brief   Return the singleton LeaderBoard instance, creating it on first call
*/
LeaderBoard* LeaderBoard::GetInstance() {
  std::lock_guard<std::mutex> lock(_mutex);
  if (_singleton == NULL) { _singleton = new LeaderBoard(); }
  return _singleton;
}

/*!
 * @brief   Insert in descending value order and trim to HISTORY entries
*/
void LeaderBoard::submit(std::deque<LeaderEntry>& section, const LeaderEntry& entry) {
  auto it = section.begin();
  while (it != section.end() && it->value >= entry.value) { ++it; }
  section.insert(it, entry);
  if ((int)section.size() > HISTORY) { section.resize(HISTORY); }
}

void LeaderBoard::record_single_damage(const std::string& name, int damage) {
  submit(_single_damage, { name, damage, std::time(nullptr) });
}

void LeaderBoard::record_burst_damage(const std::string& name, int total) {
  submit(_burst_damage, { name, total, std::time(nullptr) });
}

void LeaderBoard::record_single_heal(const std::string& name, int heal) {
  submit(_single_heal, { name, heal, std::time(nullptr) });
}

void LeaderBoard::record_burst_heal(const std::string& name, int total) {
  submit(_burst_heal, { name, total, std::time(nullptr) });
}

void LeaderBoard::record_toon_level(const std::string& name, int level) {
  submit(_toon_level, { name, level, std::time(nullptr) });
}

void LeaderBoard::record_player_level(const std::string& name, int level) {
  submit(_player_level, { name, level, std::time(nullptr) });
}

void LeaderBoard::record_player_health(const std::string& name, int hp) {
  submit(_player_health, { name, hp, std::time(nullptr) });
}

void LeaderBoard::record_player_wealth(const std::string& name, int gold) {
  submit(_player_wealth, { name, gold, std::time(nullptr) });
}

/*!
 * @brief   Print a named section to the log, one ranked line per entry
*/
void LeaderBoard::print_section(const char* title, const std::deque<LeaderEntry>& section) const {
  char line[1024];
  snprintf(line, sizeof(line), "\n  %-30s", title);
  log->raw_log(line);
  log->raw_log("  --------------------------------------------------");
  if (section.empty()) {
    log->raw_log("  (no entries)");
    return;
  }
  int rank = 1;
  for (const auto& e : section) {
    char ts[20];
    std::strftime(ts, sizeof(ts), "%H:%M:%S", std::localtime(&e.timestamp));
    snprintf(line, sizeof(line), "  #%-2d  %-20s  %6d  [%s]", rank++, e.name.c_str(), e.value, ts);
    log->raw_log(line);
  }
}

/*!
 * @brief   Print all eight leaderboard sections to the log
*/
void LeaderBoard::display() const {
  log->raw_log("\n========== LEADERBOARD ==========");
  print_section("Largest Single Damage Hit",  _single_damage);
  print_section("Most Damage in 30s",         _burst_damage);
  print_section("Greatest Single Heal",       _single_heal);
  print_section("Most Healing in 30s",        _burst_heal);
  print_section("Highest Level Toon",         _toon_level);
  print_section("Highest Level Player",       _player_level);
  print_section("Greatest Player Health",     _player_health);
  print_section("Greatest Player Wealth",     _player_wealth);
  log->raw_log("=================================\n");
}

/*!
 * @brief   Print a description of the LeaderBoard module to the log
*/
void LeaderBoard::_help() {
  std::string helpline = "\nLeaderBoard Helpline!"
    "\n\n\tTracks peak session statistics across eight categories, each holding the"
    "\ntop 10 entries by value. Submit values via record_* methods; the board"
    "\ninserts in sorted order and trims automatically. Call display() to print"
    "\nall sections. Burst categories expect the caller to accumulate totals over"
    "\na 30-second window before submitting."
    "\n";
  log->named_log(__FILENAME__, helpline);
}

LeaderBoard::~LeaderBoard() { }
