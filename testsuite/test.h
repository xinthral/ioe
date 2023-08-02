#ifndef TEST_H
#define TEST_H

#include "../logger.h"
// #include "../engine.h"

class TestSuite {
protected:
    Logger* log;
public:
    TestSuite();
    ~TestSuite();
};

#endif // TEST_H //