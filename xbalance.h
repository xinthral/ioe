#ifndef XBALANCE_H
#define XBALANCE_H
#define _USE_MATH_DEFINES

#include <cmath>
#include <stdio.h>
#include <iostream>

enum Hardness { Vesy, Easy, Norm, Hard, Vard };
const double LEVELS[] = {1, 3, 5, 8, 13, 21};
const int MAXLVL = 80;

class BalanceController {
private:
	double base = 0.0;
    const int SPN = 8;
	const int ATK = 24;
	const int DEF = 32;
	const int SKP = 1;
    Hardness  DIF;
public:
    BalanceController(Hardness);
    double scalar(int);
    void display_state();
    double get_base();
    Hardness get_difficulty();
    ~BalanceController();
};

#endif // XBALANCE_H //