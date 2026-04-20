#include "basecase.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor 
*/
BaseCase::BaseCase() {
  this->bal = BalanceController::GetInstance();   //!< Instantiated BalanceController Object
  this->cnf = ConfigManager::GetInstance();       //!< Instantiated ConfigManager Object
  this->cnf->toggleDebug();
  this->log = Logger::GetInstance();              //!< Instantiated Logger Object
  this->_passed = 0;
  this->_failed = 0;
  this->_granularity = 0;
}

/*!
 * @todo    Overloaded Constructor
*/
BaseCase::BaseCase(const char * casename) : BaseCase() {
  this->log->named_log(casename, "TestCase Initiated!");
}

/*!
 * @todo    Check a condition and tally pass/fail
*/
void BaseCase::record(bool condition, const char* msg) {
  if (condition) {
    _passed++;
  } else {
    _failed++;
    this->log->named_log("FAIL", msg);
  }
}

int BaseCase::set_granularity(int level) {
  this->_granularity = level;
  return this->_granularity;
}

/*!
 * @todo    Default Deconstructor
*/
BaseCase::~BaseCase() {
  char buf[64];
  sprintf(buf, "Passed: %d | Failed: %d", _passed, _failed);
  this->log->named_log("Results", buf);
}
