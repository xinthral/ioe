#include "battle.h"

/*!
 * @def     __FILENAME__
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

//! Singleton Instance
Battle* Battle::_singleton = NULL;
//! Lock Mutex
std::mutex Battle::_mutex;

/*!
 * @brief   Default Constructor
*/
Battle::Battle() {
  cnf = ConfigManager::GetInstance();
  log = Logger::GetInstance();
  lb  = LeaderBoard::GetInstance();
  if (cnf->debugEnabled()) { PROFILE_FUNCTION(); }
  cycleCompletionTracker = 10;
  cycleDelay = 500;
  _c1 = _c2 = nullptr;
}

/*!
 * @brief   Return the singleton Battle instance, creating it on first call
*/
Battle* Battle::GetInstance() {
  //! Acquire Instance Mutex
  std::lock_guard<std::mutex> lock(_mutex);
  //! If singleton already exists, return instance
  if (_singleton == NULL) { _singleton = new Battle(); }
  return _singleton;
}


/*!
 * @brief   Perform combat in a consistant, controlled cycle
*/
void Battle::doCycleWork(bool &isPendingWork) {
  if (this->combat) {
    this->combat->cycleCombat();
    if (!this->combat->inCombat()) {
      record_stats();
      isPendingWork = false;
      this->combat = NULL;
    }
  } else {
    isPendingWork = false;
  }
}

/*!
 * @brief   Start a Toon vs Toon combat session
 * @param[in] t1  First NPC combatant
 * @param[in] t2  Second NPC combatant
*/
void Battle::startEVE(Toon *t1, Toon *t2) {
  _c1 = t1; _c2 = t2; _matchup = Condition::EvE;
  this->combat = new Combat(t1, t2);
}

/*!
 * @brief   Start a Player vs Toon combat session
 * @param[in] player  Player combatant
 * @param[in] t       NPC combatant
*/
void Battle::startPVE(Player *player, Toon *t) {
  _c1 = player; _c2 = t; _matchup = Condition::PvE;
  this->combat = new Combat(player, t);
}

/*!
 * @brief   Start a Player vs Player combat session
 * @param[in] player1  First Player combatant
 * @param[in] player2  Second Player combatant
*/
void Battle::startPVP(Player *player1, Player *player2) {
  _c1 = player1; _c2 = player2; _matchup = Condition::PvP;
  this->combat = new Combat(player1, player2);
}

/*!
 * @brief   Submit all recordable stats from the concluded combat session to the LeaderBoard
*/
void Battle::record_stats() {
  if (!combat || !_c1 || !_c2) { return; }

  // Damage — always available regardless of matchup
  lb->record_single_damage(_c1->get_name(), combat->get_peak1());
  lb->record_single_damage(_c2->get_name(), combat->get_peak2());

  // Burst damage — total damage dealt; valid as a 30s window if session was under 30s
  double elapsed = std::difftime(std::time(nullptr), combat->get_burst_start());
  if (elapsed <= 30.0) {
    lb->record_burst_damage(_c1->get_name(), combat->get_total1());
    lb->record_burst_damage(_c2->get_name(), combat->get_total2());
  }

  // Level and health — categorised by matchup type
  switch (_matchup) {
    case Condition::EvE:
      lb->record_toon_level(_c1->get_name(), _c1->get_level());
      lb->record_toon_level(_c2->get_name(), _c2->get_level());
      break;
    case Condition::PvE:
      lb->record_player_level(_c1->get_name(), _c1->get_level());
      lb->record_player_health(_c1->get_name(), _c1->get_health());
      lb->record_toon_level(_c2->get_name(), _c2->get_level());
      break;
    case Condition::PvP:
      lb->record_player_level(_c1->get_name(), _c1->get_level());
      lb->record_player_level(_c2->get_name(), _c2->get_level());
      lb->record_player_health(_c1->get_name(), _c1->get_health());
      lb->record_player_health(_c2->get_name(), _c2->get_health());
      break;
    default: break;
  }
}

/*!
 * @brief   Print a description of the Battle module to the log
*/
void Battle::_help() {
  std::string helpline = "\nBattle Helpline!"
    "\n\nThis is a singleton object (https://www.geeksforgeeks.org/implementation-of-singleton-class-in-cpp/)"
    "\n\n\tThe Battle Module is attempting to handle battlefield logic. This will essentially handle upscaled Combat,"
    "\nmaintaining the battlefield. I wanted Player V Player combat as well as Player V Toon, Toon V Toon, and any"
    "\ngroup Combat that is interrelated."
    "\n";
  this->log->named_log(__FILENAME__, helpline);
}

/*!
 * @todo    Default Deconstructor
*/
Battle::~Battle() {}
