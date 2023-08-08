/*! 
 * @class   TestActors actors.h actors.cpp
 * @brief   Base Class for interactive Characters
*/
#include "actors.h"

TestActors::TestActors() {
    BaseCase::log->named_log(__FILE__, "Testing Actors!");
    sprintf(this->msgHead, "Tested");
    sprintf(this->msgTail, "for Actors!");
    test_actor();
}

/*!
 * @brief   Run full set of test on Actor
*/
void TestActors::test_actor() {
    base_attack();          //! Test Base Attack Value
    base_defense();         //! Test Base Defense Value
    base_health();          //! Test Base Health Value

    combatstate_idle();     //! Test Combat State Idle
    combatstate_patrol();   //! Test Combat State Patrol
    combatstate_fight();    //! Test Combat State Fight
    combatstate_flee();     //! Test Combat State Flee
    combatstate_follow();   //! Test Combat State Follow

    healthstate_healthy();  //! Test Health State Healthy
    healthstate_hurting();  //! Test Health State Hurting
    healthstate_critical(); //! Test Health State Critical 
    healthstate_sick();     //! Test Health State Sick 
    healthstate_dead();     //! Test Health State Dead 
}

/*!
 * @brief   Validate Initial Condition: Attack Value
 * @note    Are actors getting proper base values?
*/
void TestActors::base_attack() {
    int cnf_atk = cnf->get_attack();
    dummy = new Actor();
    assert(cnf_atk == dummy->get_attack());
    sprintf(buf, "%s %s %s", msgHead, "Base [Attack] Value", msgTail);
    BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Validate Initial Condition: Defense Value
 * @note    Are actors getting proper base values?
*/
void TestActors::base_defense() {
    int cnf_def = cnf->get_defense();
    dummy = new Actor();
    sprintf(buf, "%s %s %s", msgHead, "Base [Defense] Value", msgTail);
    assertm(cnf_def == dummy->get_defense(), "Actor Defense Mismatch\t<--");
    BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Validate Initial Condition: Health Value
 * @note    Are actors getting proper base values?
*/
void TestActors::base_health() {
    int cnf_hlt = cnf->get_health();
    dummy = new Actor();
    assert(cnf_hlt == dummy->get_health());
    sprintf(buf, "%s %s %s", msgHead, "Base [Health] Value", msgTail);
    BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Validate Initial Condition: Combat Idle
 * @note    Are actors states getting set properly?
*/
void TestActors::combatstate_idle() { 
    dummy = new Actor();
    dummy->set_combat_idle();
    sprintf(buf, "%s %s %s", msgHead, "[Idle] Combatstate", msgTail);
    assert(IDLE == dummy->get_combatstate());
    BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Validate Initial Condition: Combat Patrol
 * @note    Are actors states getting set properly?
*/
void TestActors::combatstate_patrol() { 
    dummy = new Actor();
    dummy->set_combat_patrol();
    assert(PATROL == dummy->get_combatstate());
    sprintf(buf, "%s %s %s", msgHead, "[Patrol] Combatstate", msgTail);
    BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Validate Initial Condition: Combat Fight
 * @note    Are actors states getting set properly?
*/
void TestActors::combatstate_fight() { 
    dummy = new Actor();
    dummy->set_combat_fight();
    assert(FIGHT == dummy->get_combatstate());
    sprintf(buf, "%s %s %s", msgHead, "[Fight] Combatstate", msgTail);
    BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Validate Initial Condition: Combat Flee
 * @note    Are actors states getting set properly?
*/
void TestActors::combatstate_flee() { 
    dummy = new Actor();
    dummy->set_combat_flee();
    assert(FLEE == dummy->get_combatstate());
    sprintf(buf, "%s %s %s", msgHead, "[Flee] Combatstate", msgTail);
    BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Validate Initial Condition: Combat Follow
 * @note    Are actors states getting set properly?
*/
void TestActors::combatstate_follow() { 
    dummy = new Actor();
    dummy->set_combat_follow();
    assert(FOLLOW == dummy->get_combatstate());
    sprintf(buf, "%s %s %s", msgHead, "[Follow] Combatstate", msgTail);
    BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Validate Initial Condition: Health Healthy
 * @note    Are actors states getting set properly?
*/
void TestActors::healthstate_healthy() { 
    dummy = new Actor();
    dummy->set_health_healthy();
    assert(HEALTHY == dummy->get_healthstate());
    sprintf(buf, "%s %s %s", msgHead, "[Healthy] Healthstate", msgTail);
    BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Validate Initial Condition: Health Hurting
 * @note    Are actors states getting set properly?
*/
void TestActors::healthstate_hurting() { 
    dummy = new Actor();
    dummy->set_health_hurting();
    assert(HURTING == dummy->get_healthstate());
    sprintf(buf, "%s %s %s", msgHead, "[Hurting] Healthstate", msgTail);
    BaseCase::log->named_log(__FILE__, buf);
}

/**
 * @brief   Validate Initial Condition: Health Critical 
 * @note    Are actors states getting set properly?
*/
void TestActors::healthstate_critical() { 
    dummy = new Actor();
    dummy->set_health_critical();
    assert(CRITICAL == dummy->get_healthstate());
    sprintf(buf, "%s %s %s", msgHead, "[Critical] Healthstate", msgTail);
    BaseCase::log->named_log(__FILE__, buf);
}

/**
 * @brief   Validate Initial Condition: Health Sick 
 * @note    Are actors states getting set properly?
*/
void TestActors::healthstate_sick() { 
    dummy = new Actor();
    dummy->set_health_sick();
    assert(SICK == dummy->get_healthstate());
    sprintf(buf, "%s %s %s", msgHead, "[Sick] Healthstate", msgTail);
    BaseCase::log->named_log(__FILE__, buf);
}

/**
 * @brief   Validate Initial Condition: Health Dead 
 * @note    Are actors states getting set properly?
*/
void TestActors::healthstate_dead() { 
    dummy = new Actor();
    dummy->set_health_dead();
    assert(DEAD == dummy->get_healthstate());
    sprintf(buf, "%s %s %s", msgHead, "[Dead] Healthstate", msgTail);
    BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Default Deconstructor
*/
TestActors::~TestActors() {}