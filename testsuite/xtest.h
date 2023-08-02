#ifndef XTEST_H
#define XTEST_H

#include "../xlogger.h"
// #include "../xengine.h"

class TestSuite {
protected:
    Logger* log;
public:
    TestSuite();
    ~TestSuite();
};

#endif // XTEST_H //