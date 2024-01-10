
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
  cnf  = ConfigManager::GetInstance();
  log  = Logger::GetInstance();
  log->named_log(__FILENAME__, "xClock Loaded!");
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
 * @todo    Helper Hook used in CLI Help System
*/
void xClock::_help() {
  std::string helpline = "\nClock Helpline!\n";
  helpline += "\n\tThe Clock is meant to be the module that keeps them all in time.";
  helpline += "\n";
  log->named_log(__FILENAME__, helpline);
}


/*!
 * @todo    Default Deconstructor
*/
xClock::~xClock() { }
