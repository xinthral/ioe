#ifndef BALANCE_H
#define BALANCE_H
#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <stdio.h>
#include "config.h"
#include "logger.h"
// #include "xstager.h"

enum Hardness { Vesy, Easy, Norm, Hard, Vard };
extern const double LEVELS[]; // = {1, 3, 5, 8, 13, 21};
extern const int MAXLVL; // = 80;
extern double    BAS;
extern const int SPN;
extern const int ATK;
extern const int DEF;
// extern const int SKP;

class BalanceController {
protected:
    BalanceController();
	ConfigManager* cm;
    Logger* log;

private:
    static BalanceController* _singleton;
    static std::mutex _mutex;
    Hardness  DIF;

public:
    // Singletons should not be cloneable
    BalanceController(BalanceController&) = delete;
    // Singletons should not be assignable
    void operator=(const BalanceController&) = delete;
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