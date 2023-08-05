#ifndef TESTACTOR_H
#define TESTACTOR_H

#include "basecase.h"
#include "../actor.h"

class TestActors : public BaseCase {
protected:
    Actor* dummy;
    char msgHead[128];
    char msgTail[128];

public:
    TestActors();

    // Feet to the fire
    void test_actor();

    // Test Stats
    void base_attack();
    void base_defense(); 
    void base_health();

    // Test Combat States
    void combatstate_idle();
    void combatstate_patrol();
    void combatstate_fight();
    void combatstate_flee();
    void combatstate_follow();

    // Test Health States
    void healthstate_healthy();
    void healthstate_hurting();
    void healthstate_critical();
    void healthstate_sick();
    void healthstate_dead();

    ~TestActors();
};

#endif // TESTACTOR_H //