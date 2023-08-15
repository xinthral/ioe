#ifndef TESTER_H
#define TESTER_H

#include <stdio.h>
#include "../core/utilz.h"
#include "actorcase.h"
#include "balancecase.h"
#include "combatcase.h"
#include "playercase.h"

class TestSuite {
protected:
private:
public:
    TestSuite();
    void CaseActor();
    void CaseBalance();
    void CaseCombat();
    void CasePlayer();
    ~TestSuite();
};

#endif // TESTER_H //