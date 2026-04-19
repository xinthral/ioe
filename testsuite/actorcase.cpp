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
  test_equip();         //! Testing Equip System
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
  starting_health();      //!< Test Health Initial Value
}

/*!
 * @todo    Validate Initial Condition: Attack Value
*/
void TestActors::base_attack() {
  PROFILE_NAMED("Actor_BaseStats");
  int cnf_atk = cnf->get_attack();
  dummy = new Actor();
  record(cnf_atk == dummy->get_baseAttack(), "Actor Attack Mismatch");
  sprintf(buf, "%s %s %s", msgHead, "Base [Attack] Value", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Defense Value
*/
void TestActors::base_defense() {
  PROFILE_NAMED("Actor_BaseStats");
  int cnf_def = cnf->get_defense();
  dummy = new Actor();
  record(cnf_def == dummy->get_baseDefense(), "Actor Defense Mismatch");
  sprintf(buf, "%s %s %s", msgHead, "Base [Defense] Value", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Flux Value
*/
void TestActors::base_flux() {
  PROFILE_NAMED("Actor_BaseStats");
  int cnf_flx = cnf->get_flux();
  dummy = new Actor();
  record(cnf_flx == dummy->get_baseFlux(), "Actor Flux Mismatch");
  sprintf(buf, "%s %s %s", msgHead, "Base [Flux] Value", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Health Value
*/
void TestActors::base_health() {
  PROFILE_NAMED("Actor_BaseStats");
  int cnf_hlt = cnf->get_health();
  dummy = new Actor();
  record(cnf_hlt == dummy->get_baseHealth(), this->msgNote);
  sprintf(buf, "%s %s %s", msgHead, "Base [Health] Value", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Combat Idle
*/
void TestActors::combatstate_idle() {
  PROFILE_NAMED("Actor_CombatState");
  dummy = new Actor();
  dummy->set_combat_idle();
  record(IDLE == dummy->get_combatstate(), this->msgNote);
  sprintf(buf, "%s %s %s", msgHead, "[Idle] Combatstate", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Combat Patrol
*/
void TestActors::combatstate_patrol() {
  PROFILE_NAMED("Actor_CombatState");
  dummy = new Actor();
  dummy->set_combat_patrol();
  record(PATROL == dummy->get_combatstate(), this->msgNote);
  sprintf(buf, "%s %s %s", msgHead, "[Patrol] Combatstate", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Combat Fight
*/
void TestActors::combatstate_fight() {
  PROFILE_NAMED("Actor_CombatState");
  dummy = new Actor();
  dummy->set_combat_fight();
  record(FIGHT == dummy->get_combatstate(), this->msgNote);
  sprintf(buf, "%s %s %s", msgHead, "[Fight] Combatstate", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Combat Flee
*/
void TestActors::combatstate_flee() {
  PROFILE_NAMED("Actor_CombatState");
  dummy = new Actor();
  dummy->set_combat_flee();
  record(FLEE == dummy->get_combatstate(), this->msgNote);
  sprintf(buf, "%s %s %s", msgHead, "[Flee] Combatstate", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Combat Follow
*/
void TestActors::combatstate_follow() {
  PROFILE_NAMED("Actor_CombatState");
  dummy = new Actor();
  dummy->set_combat_follow();
  record(FOLLOW == dummy->get_combatstate(), this->msgNote);
  sprintf(buf, "%s %s %s", msgHead, "[Follow] Combatstate", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Health Healthy
*/
void TestActors::healthstate_healthy() {
  PROFILE_NAMED("Actor_HealthState");
  dummy = new Actor();
  dummy->set_health_healthy();
  record(HEALTHY == dummy->get_healthstate(), this->msgNote);
  sprintf(buf, "%s %s %s", msgHead, "[Healthy] Healthstate", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Health Hurting
*/
void TestActors::healthstate_hurting() {
  PROFILE_NAMED("Actor_HealthState");
  dummy = new Actor();
  dummy->set_health_hurting();
  record(HURTING == dummy->get_healthstate(), this->msgNote);
  sprintf(buf, "%s %s %s", msgHead, "[Hurting] Healthstate", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Health Critical 
*/
void TestActors::healthstate_critical() {
  PROFILE_NAMED("Actor_HealthState");
  dummy = new Actor();
  dummy->set_health_critical();
  record(CRITICAL == dummy->get_healthstate(), this->msgNote);
  sprintf(buf, "%s %s %s", msgHead, "[Critical] Healthstate", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Health Sick 
*/
void TestActors::healthstate_sick() {
  PROFILE_NAMED("Actor_HealthState");
  dummy = new Actor();
  dummy->set_health_sick();
  record(SICK == dummy->get_healthstate(), this->msgNote);
  sprintf(buf, "%s %s %s", msgHead, "[Sick] Healthstate", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Initial Condition: Health Dead 
*/
void TestActors::healthstate_dead() {
  PROFILE_NAMED("Actor_HealthState");
  dummy = new Actor();
  dummy->set_health_dead();
  record(DEAD == dummy->get_healthstate(), this->msgNote);
  sprintf(buf, "%s %s %s", msgHead, "[Dead] Healthstate", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestActors::starting_health() {
  PROFILE_NAMED("Actor_BaseStats");
  dummy = new Actor();
  // assertm(32 == dummy->get_health(), "Actor failed to initialize");
  record(cnf->get_health() == dummy->get_health(), "Actor failed to initialize");
  sprintf(buf, "%s [%s] %s", msgHead, "Initial Health", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}


void TestActors::test_equip() {
  sprintf(this->msgNote, "Actor Equip System Mismatch");
  equip_applies_stats();
  equip_rejects_duplicate_type();
  equip_rejects_second_unique();
  unequip_reverses_stats();
  equip_get_equipped_count();
}

void TestActors::equip_applies_stats() {
  PROFILE_NAMED("Actor_EquipSystem");
  dummy = new Actor();
  int base_attack = dummy->get_attack();
  Equipment* sword = new Equipment("Sword", SWORD);
  dummy->equip(sword);
  record(dummy->get_attack() > base_attack, "Equipping sword should increase attack");
  sprintf(buf, "%s [%s] %s", msgHead, "equip applies stats", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestActors::equip_rejects_duplicate_type() {
  PROFILE_NAMED("Actor_EquipSystem");
  dummy = new Actor();
  Equipment* sword1 = new Equipment("Sword1", SWORD);
  Equipment* sword2 = new Equipment("Sword2", SWORD);
  dummy->equip(sword1);
  bool result = dummy->equip(sword2);
  record(result == false, "Should reject second item of same ItemType");
  record(dummy->get_equipped().size() == 1, "Equipped count should remain 1");
  sprintf(buf, "%s [%s] %s", msgHead, "equip rejects duplicate type", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestActors::equip_rejects_second_unique() {
  PROFILE_NAMED("Actor_EquipSystem");
  dummy = new Actor();
  Equipment* u1 = new Equipment("UniqueA", RELIC);
  Equipment* u2 = new Equipment("UniqueB", RING);
  u1->set_rarity(UNIQUE);
  u2->set_rarity(UNIQUE);
  dummy->equip(u1);
  bool result = dummy->equip(u2);
  record(result == false, "Should reject second UNIQUE item");
  record(dummy->get_equipped().size() == 1, "Equipped count should remain 1");
  sprintf(buf, "%s [%s] %s", msgHead, "equip rejects second UNIQUE", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestActors::unequip_reverses_stats() {
  PROFILE_NAMED("Actor_EquipSystem");
  dummy = new Actor();
  int base_attack = dummy->get_attack();
  Equipment* sword = new Equipment("Sword", SWORD);
  dummy->equip(sword);
  dummy->unequip(SWORD);
  record(dummy->get_attack() == base_attack, "Unequip should restore original attack");
  record(dummy->get_equipped().size() == 0, "Equipped count should be 0 after unequip");
  sprintf(buf, "%s [%s] %s", msgHead, "unequip reverses stats", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestActors::equip_get_equipped_count() {
  PROFILE_NAMED("Actor_EquipSystem");
  dummy = new Actor();
  dummy->equip(new Equipment("Sword",  SWORD));
  dummy->equip(new Equipment("Shield", SHIELD));
  dummy->equip(new Equipment("Ring",   RING));
  record(dummy->get_equipped().size() == 3, "get_equipped should return 3 items");
  sprintf(buf, "%s [%s] %s", msgHead, "equip get_equipped count", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Default Deconstructor
*/
TestActors::~TestActors() { }
