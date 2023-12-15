#ifndef TESTER_H
#define TESTER_H

#include <stdio.h>
#include <string.h>
#include <thread>
#include "actorcase.h"
#include "balancecase.h"
#include "combatcase.h"
#include "configcase.h"
#include "leadercase.h"
#include "playercase.h"
#include "stagecase.h"
#include "tooncase.h"
#include "utilzcase.h"

class TestSuite {
protected:
private:
public:
    TestSuite();
    void CaseActor();
    void CaseBalance();
    void CaseCombat();
    void CaseConfig();
    void CaseLeader();
    void CasePlayer();
    void CaseStage();
    void CaseToon();
    void CaseUtilz();
    ~TestSuite();
};

#endif // TESTER_H //