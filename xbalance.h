#ifndef XBALANCE_H
#define XBALANCE_H
#define _USE_MATH_DEFINES

#include <cmath>
#include <stdio.h>
#include <iostream>

enum Hardness { Easy, Norm, Hard };
const double levels[] = {1.3, 1.6, 1.9, 2.2};

class BalanceController {
private:
public:
    BalanceController();
    double scalar(double, int);
    ~BalanceController();
};

#endif // XBALANCE_H //