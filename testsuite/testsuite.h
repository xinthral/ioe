#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include "../utilz.h"
#include "actors.h"

class TestSuite {
protected:
private:
public:
    TestSuite();
    void CaseActor();
    void CaseBalance();
    ~TestSuite();
};

#endif // TEST_H //