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
  tempTracker = 5;
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
  // Toon* t = new Toon();
  // Toon* v;
  // Combat* cc;
  // while (team.size() > 1) {
  //   t = team[team.size() - 1];
  //   v = team[team.size() - 2];
  //   team.pop_back();
  //   team.pop_back();
  //   cc = new Combat(*t, *v);
  //   cc->begin_combat();
  // }

  // cc = new Combat(*player, *t);
  // cc->begin_combat();
}

void Battle::doCycleWork(bool &isPendingWork) {
  this->log->named_log(__FILENAME__, "Battle Cycle Work");
  if (tempTracker--<1) { isPendingWork = false; }
}

/*!
 * @todo    Helper Hook used in CLI Help System
*/
void Battle::_help() {
  std::string helpline = "\nBattle Helpline!\n";
  helpline += "\t";
  helpline += "The Battle Module is attempting to handle battlefield logic. This will essentially handle ";
  helpline += "upscaled Combat, maintaining the battlefield. I wanted Player V Player combat as well as ";
  helpline += "Player V Toon, Toon V Toon, and any group Combat that is interrelated.";
  helpline += "\n";
  log->named_log(__FILENAME__, helpline);
}

/*! 
 * @todo    Default Deconstructor
*/
Battle::~Battle() { }
