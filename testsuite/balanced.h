#ifndef TESTBALANCE_H
#define TESTBALANCE_H

#include "basecase.h"
#include "../core/balance.h"

class TestBalance : public BaseCase {
protected:
    int baseAtk;
    int baseDef;
    int baseHlt;
public:
    TestBalance();
    void test_balance();
    void def_atk_ratio();
    ~TestBalance();
};

#endif // TESTBALANCE_H //