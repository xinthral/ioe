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
}

/*!
 * @todo    Overloaded Constructor
*/
BaseCase::BaseCase(const char * casename) : BaseCase() {
  this->log->named_log(casename, "TestCase Initiated!");
}

/*!
 * @todo    Default Deconstructor 
*/
BaseCase::~BaseCase() { }
