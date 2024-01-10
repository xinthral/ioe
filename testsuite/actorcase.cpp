#include "actorcase.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor
*/
TestActors::TestActors() : BaseCase(__FILENAME__) {
  BaseCase::log->named_log(__FILENAME__, "Testing Actor's!");
  sprintf(this->msgHead, "Tested");
  sprintf(this->msgTail, "for Actors!");
  this->test_all();
}

/*!
 * @todo    Run full set of test on module 
*/
void TestActors::test_all() {
  test_basevalues();    //! Testing Base Values
  test_combatstate();   //! Testing Combat States
  test_healthstate();   //! Testing Health States
}

/*!
 * @todo    Run full set of test on Base Values 
*/
void TestActors::test_basevalues() {
  sprintf(this->msgNote, "Actor Base Value Mismatch");
  base_attack();        //! Test Base Attack Value
  base_defense();       //! Test Base Defense Value
  base_flux();          //! Test Base Flux Value
  base_health();        //! Test Base Health Value
}

/*!
 * @todo    Run full set of test on Combat States 
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
 * @todo    Run full set of test on Health States 
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
 * @todo    Validate Initial Condition: Attack Value
*/
void TestActors::base_attack() {
  int cnf_atk = cnf->get_attack();
  dummy = new Actor();
  assertm(cnf_atk == dummy->get_attack(), "Actor Attack Mismatch");
  sprintf(buf, "%s %s %s", msgHead, "Base [Attack] Value", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Defense Value
*/
void TestActors::base_defense() {
  int cnf_def = cnf->get_defense();
  dummy = new Actor();
  assertm(cnf_def == dummy->get_defense(), "Actor Defense Mismatch");
  sprintf(buf, "%s %s %s", msgHead, "Base [Defense] Value", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Flux Value
*/
void TestActors::base_flux() {
  int cnf_flx = cnf->get_flux();
  dummy = new Actor();
  assertm(cnf_flx == dummy->get_flux(), "Actor Flux Mismatch");
  sprintf(buf, "%s %s %s", msgHead, "Base [Flux] Value", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Health Value
*/
void TestActors::base_health() {
  int cnf_hlt = cnf->get_health();
  dummy = new Actor();
  assertm(cnf_hlt == dummy->get_health(), this->msgNote);
  sprintf(buf, "%s %s %s", msgHead, "Base [Health] Value", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Combat Idle
*/
void TestActors::combatstate_idle() { 
  dummy = new Actor();
  dummy->set_combat_idle();
  assertm(IDLE == dummy->get_combatstate(), this->msgNote);
  sprintf(buf, "%s %s %s", msgHead, "[Idle] Combatstate", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Combat Patrol
*/
void TestActors::combatstate_patrol() { 
  dummy = new Actor();
  dummy->set_combat_patrol();
  assertm(PATROL == dummy->get_combatstate(), this->msgNote);
  sprintf(buf, "%s %s %s", msgHead, "[Patrol] Combatstate", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Combat Fight
*/
void TestActors::combatstate_fight() { 
  dummy = new Actor();
  dummy->set_combat_fight();
  assertm(FIGHT == dummy->get_combatstate(), this->msgNote);
  sprintf(buf, "%s %s %s", msgHead, "[Fight] Combatstate", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Combat Flee
*/
void TestActors::combatstate_flee() { 
  dummy = new Actor();
  dummy->set_combat_flee();
  assertm(FLEE == dummy->get_combatstate(), this->msgNote);
  sprintf(buf, "%s %s %s", msgHead, "[Flee] Combatstate", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Combat Follow
*/
void TestActors::combatstate_follow() { 
  dummy = new Actor();
  dummy->set_combat_follow();
  assertm(FOLLOW == dummy->get_combatstate(), this->msgNote);
  sprintf(buf, "%s %s %s", msgHead, "[Follow] Combatstate", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Health Healthy
*/
void TestActors::healthstate_healthy() { 
  dummy = new Actor();
  dummy->set_health_healthy();
  assertm(HEALTHY == dummy->get_healthstate(), this->msgNote);
  sprintf(buf, "%s %s %s", msgHead, "[Healthy] Healthstate", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Health Hurting
*/
void TestActors::healthstate_hurting() { 
  dummy = new Actor();
  dummy->set_health_hurting();
  assertm(HURTING == dummy->get_healthstate(), this->msgNote);
  sprintf(buf, "%s %s %s", msgHead, "[Hurting] Healthstate", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Health Critical 
*/
void TestActors::healthstate_critical() { 
  dummy = new Actor();
  dummy->set_health_critical();
  assertm(CRITICAL == dummy->get_healthstate(), this->msgNote);
  sprintf(buf, "%s %s %s", msgHead, "[Critical] Healthstate", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Health Sick 
*/
void TestActors::healthstate_sick() { 
  dummy = new Actor();
  dummy->set_health_sick();
  assertm(SICK == dummy->get_healthstate(), this->msgNote);
  sprintf(buf, "%s %s %s", msgHead, "[Sick] Healthstate", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Health Dead 
*/
void TestActors::healthstate_dead() { 
  dummy = new Actor();
  dummy->set_health_dead();
  assertm(DEAD == dummy->get_healthstate(), this->msgNote);
  sprintf(buf, "%s %s %s", msgHead, "[Dead] Healthstate", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Default Deconstructor
*/
TestActors::~TestActors() { }
