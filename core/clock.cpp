
#include "clock.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

//! Singleton Instance
xClock* xClock::_singleton = NULL;
//! Lock Mutex 
std::mutex xClock::_mutex;

/*!
 * @todo    Protected Constructor
*/
xClock::xClock() {
  battle = Battle::GetInstance();
  cnf  = ConfigManager::GetInstance();
  log  = Logger::GetInstance();
  log->named_log(__FILENAME__, "Clock Loaded!");
}

/*!
 * @todo    Singleton Constructor
*/
xClock* xClock::GetInstance() { 
  //! Acquire Instance Mutex
  std::lock_guard<std::mutex> lock(_mutex);
  //! If singleton already exists, return instance
  if (_singleton == NULL) { _singleton = new xClock(); }
  return _singleton;
}

/*!
 * @todo    Returns if cycle work is still pending
*/
bool xClock::getPendingWorkState() {
  return this->isPendingWork;
}

/*!
 * @todo    Singleton Constructor
*/
void xClock::doCycleWork() {
  if (this->cnf->debugEnabled()) { PROFILE_FUNCTION(); }
  bool pendingBattles = true;
  log->raw_log("Clock Cycle Work!");
  do {
    battle->doCycleWork(pendingBattles);
    isPendingWork = pendingBattles || false;
  } while (isPendingWork);
}

/*!
 * @todo    Helper Hook used in CLI Help System
*/
void xClock::_help() {
  std::string helpline = "\nClock Helpline!"
  "\n\nThis is a singleton object (https://www.geeksforgeeks.org/implementation-of-singleton-class-in-cpp/)"
  "\n\n\tThe Clock is meant to be the module that keeps them all in time. This is particularly"
  "\nuseful in the areas of combat, and actions. The clock provides an immense amount of control"
  "\nover these areas because the iterative step and delay between them is an established variable."
  "\nThis could be iterated through manually for debugging or a unique gaming experience of time"
  "\ndialation."
  "\n";
  log->named_log(__FILENAME__, helpline);
}


/*!
 * @todo    Default Deconstructor
*/
xClock::~xClock() { }
