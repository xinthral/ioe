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
  if (cnf->debugEnabled()) { PROFILE_FUNCTION(); }
  cycleCompletionTracker = 10;
  cycleDelay = 500;
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
  // this->log->named_log(__FILENAME__, "Battle Cycle Work");
  if (this->combat) { 
    this->combat->cycleCombat();
    if (!this->combat->inCombat()) { 
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
  this->combat = new Combat(t1, t2);
}

/*!
 * @brief   Start a Player vs Toon combat session
 * @param[in] player  Player combatant
 * @param[in] t       NPC combatant
*/
void Battle::startPVE(Player *player, Toon *t) {
  this->combat = new Combat(player, t);
}

/*!
 * @brief   Start a Player vs Player combat session
 * @param[in] player1  First Player combatant
 * @param[in] player2  Second Player combatant
*/
void Battle::startPVP(Player *player1, Player *player2) {
  this->combat = new Combat(player1, player2);
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
