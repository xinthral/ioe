#ifndef BASECASE_H
#define BASECASE_H

#include <cassert>
#include <iostream>
#include "../actor.h"
#include "../config.h"
#include "../logger.h"

// Compiler/Linter hint
#define assertm(exp, msg) assert(((void)msg, exp))

class BaseCase {
protected:
    ConfigManager* conf;
    Logger* log;
    Actor* dummy;
public:
    BaseCase();
    ~BaseCase();
};

#endif // BASECASE_H //