#ifndef BASECASE_H
#define BASECASE_H

#include <cassert>
#include <iostream>
#include "../core/balance.h"
#include "../core/config.h"
#include "../core/logger.h"

// Compiler/Linter hint
#define assertm(exp, msg) assert(((void)msg, exp))

class BaseCase {
protected:
    BalanceController* bal;
    ConfigManager* cnf;
    Logger* log;
    char buf[1024];

public:
    BaseCase();
    ~BaseCase();
};

#endif // BASECASE_H //