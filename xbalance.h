#ifndef XBALANCE_H
#define XBALANCE_H
#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <stdio.h>
#include "xstage.h"

enum Hardness { Vesy, Easy, Norm, Hard, Vard };
const double LEVELS[] = {1, 3, 5, 8, 13, 21};
const int MAXLVL = 80;

class BalanceController {
protected:
    BalanceController(int);

private:
    static BalanceController* _singleton;
    static std::mutex _mutex;

    Hardness  DIF;
	double base = 0.0;
    const int SPN = 8;
	const int ATK = 24;
	const int DEF = 32;
	const int SKP = 1;

public:
    // Singletons should not be cloneable
    BalanceController(BalanceController&) = delete;
    // Singletons should not be assignable
    void operator=(const BalanceController&) = delete;
    static BalanceController *GetInstance(int);

    double scalar(int);
    void display_state();
    double get_base();
    Hardness get_difficulty();
    void _help();
    ~BalanceController();
};

#endif // XBALANCE_H //