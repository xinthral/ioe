/*!
 * @class   BaseCase basecase.h basecase.cpp
 * @brief   Base Testing Case for TestSuite Module  
*/
#include "basecase.h"

/*!
 * @brief   Default Constructor 
*/
BaseCase::BaseCase() {
  this->bal = BalanceController::GetInstance();   //!< Instantiated BalanceController Object
  this->cnf = ConfigManager::GetInstance();       //!< Instantiated ConfigManager Object
  this->log = Logger::GetInstance();              //!< Instantiated Logger Object
}

/*!
 * @brief   Overloaded Constructor
 * @param[in] casename - Name of Case being initiated
*/
BaseCase::BaseCase(const char * casename) : BaseCase() {
  this->log->named_log(casename, "TestCase Initiated!");
}

/*!
 * @brief   Default Deconstructor 
*/
BaseCase::~BaseCase() { }
