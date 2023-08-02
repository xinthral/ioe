#ifndef TEST_H
#define TEST_H

#include "../config.h"
#include "../logger.h"
// #include "../engine.h"

class TestSuite {
protected:
    ConfigManager* cm;
    Logger* log;
public:
    TestSuite();
    ~TestSuite();
};

#endif // TEST_H //