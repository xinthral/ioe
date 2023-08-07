/*!
 * @class   BaseCase basecase.h basecase.cpp
 * @brief   Base Testing Case for Tester Module  
*/
#include "basecase.h"

/*!
 * @brief   Default Constructor 
*/
BaseCase::BaseCase() {
    this->bal = BalanceController::GetInstance();
    this->cnf = ConfigManager::GetInstance();
    this->log = Logger::GetInstance();
    this->log->named_log(__FILE__, "Tester Loaded!");
}

/*!
 * @brief   Default Deconstructor 
*/
BaseCase::~BaseCase() {}
