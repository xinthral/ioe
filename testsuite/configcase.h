#ifndef TESTCONFIG_H
#define TESTCONFIG_H

#include <cassert>
#include "basecase.h"

class TestConfig : public BaseCase {
protected:
    char buf[128];          //! Buffer Value for Logger outputs
    char msgHead[32];       //! Logging Output Formatting, leading
    char msgNote[256];      //! Buffer Value for Results outputs
    char msgTail[32];       //! Logging Output Formatting, trailing
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
