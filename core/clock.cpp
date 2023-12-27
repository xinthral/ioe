/*!
 * @class   xClock clock.h clock.cpp
 * @brief   xClock handles timing amongst the chaos and 
 *          otherwise manipulating the temporal dimension.
 * @details needs desc
*/
#include "clock.h"

//! Singleton Instance
xClock* xClock::_singleton = NULL;
//! Lock Mutex 
std::mutex xClock::_mutex;

xClock::xClock() {
  cnf  = ConfigManager::GetInstance();
  log  = Logger::GetInstance();
  log->named_log(__FILE__, "xClock Loaded!");
}

xClock* xClock::GetInstance() { 
  //! Acquire Instance Mutex
  std::lock_guard<std::mutex> lock(_mutex);
  //! If singleton already exists, return instance
  if (_singleton == NULL) { _singleton = new xClock(); }
  return _singleton;
}

void xClock::_help() {
  std::string helpline = "\nClock Helpline!\n";
  helpline += "\n\tThe Clock is meant to be the module that keeps them all in time.";
  helpline += "\n";
  log->named_log(__FILE__, helpline);
}

xClock::~xClock() { }
