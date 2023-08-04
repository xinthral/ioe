#ifndef BALANCE_H
#define BALANCE_H
#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <stdio.h>
#include "config.h"
#include "logger.h"

enum Hardness { Vesy, Easy, Norm, Hard, Vard };

const double LEVELS[] = {1, 3, 5, 8, 13, 21};

class BalanceController {
protected:
    BalanceController();
	ConfigManager* cnf;
    Logger* log;
    int MAXLVL = 80;
    double base = 5.0;
    int span = 8;
    int atk = 24;
    int def = 32;
    int hlt = 100;

private:
    static BalanceController* _singleton;
    static std::mutex _mutex;
    Hardness  DIF;
    char buf[256];

public:
    // Singletons should not be cloneable
    BalanceController(BalanceController&) = delete;
    // Singletons should not be assignable
    void operator = (const BalanceController&) = delete;
    // Singleton Constructor
    static BalanceController *GetInstance();
    
    double scalar(int);
    void display_state();
    double get_base();
    Hardness get_difficulty();
    void _help();
    ~BalanceController();
};

#endif // BALANCE_H //