#include "basecase.h"

BaseCase::BaseCase() {
    this->bal = BalanceController::GetInstance();
    this->cnf = ConfigManager::GetInstance();
    this->log = Logger::GetInstance();
    this->log->named_log(__FILE__, "Tester Loaded!");
}

BaseCase::~BaseCase() {}