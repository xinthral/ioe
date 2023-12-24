/*! 
 * @class   TestActors actorcase.h actorcase.cpp
 * @brief   Case for testing Actor functionality
*/
#include "actorcase.h"

/*!
 * @brief   Default Constructor
*/
TestActors::TestActors() : BaseCase(__FILE__) {
  BaseCase::log->named_log(__FILE__, "Testing Actor's!");
  sprintf(this->msgHead, "Tested");
  sprintf(this->msgTail, "for Actors!");
  this->test_all();
}

/*!
 * @brief   Run full set of test on module 
*/
void TestActors::test_all() {
  base_attack();        //! Test Base Attack Value
  base_defense();       //! Test Base Defense Value
  base_health();        //! Test Base Health Value
  test_combatstate();   //! Testing Combat States
  test_healthstate();   //! Testing Health States
}

/*!
 * @brief   Run full set of test on Combat States 
*/
void TestActors::test_combatstate() {
  sprintf(this->msgNote, "Actor CombatState Mismatch");
  combatstate_idle();     //!< Test Combat State Idle
  combatstate_patrol();   //!< Test Combat State Patrol
  combatstate_fight();    //!< Test Combat State Fight
  combatstate_flee();     //!< Test Combat State Flee
  combatstate_follow();   //!< Test Combat State Follow
}

/*!
 * @brief   Run full set of test on Health States 
*/
void TestActors::test_healthstate() {
  sprintf(this->msgNote, "Actor HealthState Mismatch");
  healthstate_healthy();  //!< Test Health State Healthy
  healthstate_hurting();  //!< Test Health State Hurting
  healthstate_critical(); //!< Test Health State Critical 
  healthstate_sick();     //!< Test Health State Sick 
  healthstate_dead();     //!< Test Health State Dead 
}

/*!
 * @brief   Validate Initial Condition: Attack Value
 * @note    Are actors getting proper base values?
*/
void TestActors::base_attack() {
  int cnf_atk = cnf->get_attack();
  dummy = new Actor();
  assertm(cnf_atk == dummy->get_attack(), "Actor Attack Mismatch");
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
  assertm(cnf_def == dummy->get_defense(), "Actor Defense Mismatch");
  sprintf(buf, "%s %s %s", msgHead, "Base [Defense] Value", msgTail);
  BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Validate Initial Condition: Health Value
 * @note    Are actors getting proper base values?
*/
void TestActors::base_health() {
  int cnf_hlt = cnf->get_health();
  dummy = new Actor();
  assertm(cnf_hlt == dummy->get_health(), this->msgNote);
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
  assertm(IDLE == dummy->get_combatstate(), this->msgNote);
  sprintf(buf, "%s %s %s", msgHead, "[Idle] Combatstate", msgTail);
  BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Validate Initial Condition: Combat Patrol
 * @note    Are actors states getting set properly?
*/
void TestActors::combatstate_patrol() { 
  dummy = new Actor();
  dummy->set_combat_patrol();
  assertm(PATROL == dummy->get_combatstate(), this->msgNote);
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
  assertm(FIGHT == dummy->get_combatstate(), this->msgNote);
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
  assertm(FLEE == dummy->get_combatstate(), this->msgNote);
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
  assertm(FOLLOW == dummy->get_combatstate(), this->msgNote);
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
  assertm(HEALTHY == dummy->get_healthstate(), this->msgNote);
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
  assertm(HURTING == dummy->get_healthstate(), this->msgNote);
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
  assertm(CRITICAL == dummy->get_healthstate(), this->msgNote);
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
  assertm(SICK == dummy->get_healthstate(), this->msgNote);
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
  assertm(DEAD == dummy->get_healthstate(), this->msgNote);
  sprintf(buf, "%s %s %s", msgHead, "[Dead] Healthstate", msgTail);
  BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Default Deconstructor
*/
TestActors::~TestActors() { }
