#include "basecase.h"

BaseCase::BaseCase() {
    bal = BalanceController::GetInstance();
    cnf = ConfigManager::GetInstance();
    log = Logger::GetInstance();
    log->named_log(__FILE__, "Tester Loaded!");
}

BaseCase::~BaseCase() {}