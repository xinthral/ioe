#include "basecase.h"

BaseCase::BaseCase() {
    conf = ConfigManager::GetInstance();
    log  = Logger::GetInstance();
    log->named_log(__FILE__, "Tester Loaded!");
}

BaseCase::~BaseCase() {}