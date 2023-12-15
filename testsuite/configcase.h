#ifndef TESTCONFIG_H
#define TESTCONFIG_H

#include <cassert>
#include "basecase.h"

class TestConfig : public BaseCase {
protected:
    char buf[128];
    char msgHead[32];
    char msgNote[256];
    char msgTail[32];
private:
public:
    TestConfig();
    void test_all();
    void test_mapping();
    void test_addConfig();
    void test_remConfig();
    void test_listOfCommands();
    ~TestConfig();
};

#endif // TESTCONFIG_H //
