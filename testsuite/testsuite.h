#ifndef TESTER_H
#define TESTER_H

#include <stdio.h>
#include "../core/utilz.h"
#include "actorcase.h"
#include "balancecase.h"
#include "combatcase.h"

class TestSuite {
protected:
private:
public:
    TestSuite();
    void CaseActor();
    void CaseBalance();
    void CaseCombat();
    ~TestSuite();
};

#endif // TESTER_H //