#ifndef TESTCONFIG_H
#define TESTCONFIG_H

#include <cassert>
#include "basecase.h"

class TestConfig : public BaseCase {
protected:
    char buf[128];
    char msgHead[32];
    char msgNote[64];
    char msgTail[32];
private:
public:
    TestConfig();
    void test_mapping();
    void test_addConfig();
    void test_remConfig();
    ~TestConfig();
};

#endif // TESTCONFIG_H //