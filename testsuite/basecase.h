#ifndef BASECASE_H
#define BASECASE_H

#include <cassert>
#include <iostream>
#include "../balance.h"
#include "../config.h"
#include "../logger.h"

// Compiler/Linter hint
#define assertm(exp, msg) assert(((void)msg, exp))

class BaseCase {
protected:
    BalanceController* bal;
    ConfigManager* cnf;
    Logger* log;

public:
    BaseCase();
    ~BaseCase();
};

#endif // BASECASE_H //