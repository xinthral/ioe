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
  log = Logger::GetInstance();
  cycleCompletionTracker = 10;
  cycleDelay = 500;
}

/*! 
 * @todo    Player v Team Constructor
*/
Battle* Battle::GetInstance() {
  //! Acquire Instance Mutex
  std::lock_guard<std::mutex> lock(_mutex);
  //! If singleton already exists, return instance
  if (_singleton == NULL) { _singleton = new Battle(); }
  return _singleton;
}

void Battle::doCycleWork(bool &isPendingWork) {
  std::this_thread::sleep_for(std::chrono::milliseconds(cycleDelay));
  // this->log->named_log(__FILENAME__, "Battle Cycle Work");
  if (this->combat) { this->combat->cycleCombat(); }
  // if (cycleCompletionTracker--<1) { isPendingWork = false; this->combat = NULL; }
  if (!this->combat->inCombat()) { isPendingWork = false; this->combat = NULL; }
}

void Battle::startEVE(Toon *t1, Toon *t2) { 
  this->combat = new Combat(t1, t2);
}

void Battle::startPVE(Player *player, Toon *t) { 
  this->combat = new Combat(player, t); 
}

void Battle::startPVP(Player *player1, Player *player2) {
  this->combat = new Combat(player1, player2);
}

/*!
 * @todo    Helper Hook used in CLI Help System
*/
void Battle::_help() {
  std::string helpline = "\nBattle Helpline!\n"
    "\n\tThe Battle Module is attempting to handle battlefield logic. This will essentially handle upscaled Combat,"
    "\nmaintaining the battlefield. I wanted Player V Player combat as well as Player V Toon, Toon V Toon, and any"
    "\ngroup Combat that is interrelated."
    "\n";
  this->log->named_log(__FILENAME__, helpline);
}

/*! 
 * @todo    Default Deconstructor
*/
Battle::~Battle() {}
