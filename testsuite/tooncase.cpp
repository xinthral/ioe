#include "tooncase.h"

/*!
 * @def     __FILENAME__
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

TestToon::TestToon() : BaseCase(__FILENAME__) {
  BaseCase::log->named_log(__FILENAME__, "Testing Toons!");
  sprintf(this->msgHead, "Tested Toon");
  sprintf(this->msgTail, "successfully.");
  dummy = nullptr;
  this->test_all();
}

void TestToon::test_all() {
  test_toonCreation();
  test_toonCreation_id();
  test_toonCreation_name();
  test_toonCreation_both();
  test_isAlive();
  test_isAlive_dead();
  test_initial_combatstate();
  test_initial_healthstate();
}

void TestToon::test_toonCreation() {
  PROFILE_NAMED("Actor_Instantiation");
  delete dummy;
  dummy = new Toon();
  record(strcmp("Toon_#-1", dummy->get_name().c_str()) == 0, "Toon default name mismatch");
  sprintf(buf, "%s [%s] %s", msgHead, "default instantiation", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestToon::test_toonCreation_id() {
  PROFILE_NAMED("Actor_Instantiation");
  delete dummy;
  dummy = new Toon(3);
  record(strcmp("Toon_#3", dummy->get_name().c_str()) == 0, "Toon id name mismatch");
  sprintf(buf, "%s [%s] %s", msgHead, "id instantiation", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestToon::test_toonCreation_name() {
  PROFILE_NAMED("Actor_Instantiation");
  delete dummy;
  dummy = new Toon("Maji");
  record(strcmp("Maji", dummy->get_name().c_str()) == 0, "Toon named instantiation mismatch");
  sprintf(buf, "%s [%s] %s", msgHead, "name instantiation", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestToon::test_toonCreation_both() {
  PROFILE_NAMED("Actor_Instantiation");
  delete dummy;
  dummy = new Toon(4, "Jesse");
  record(strcmp("Jesse", dummy->get_name().c_str()) == 0, "Toon id+name instantiation mismatch");
  record(dummy->get_id() == 4, "Toon id mismatch on id+name construction");
  sprintf(buf, "%s [%s] %s", msgHead, "id+name instantiation", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestToon::test_isAlive() {
  PROFILE_NAMED("Actor_HealthState");
  delete dummy;
  dummy = new Toon("AliveToon");
  record(dummy->isAlive() == true, "Fresh Toon should report isAlive true");
  sprintf(buf, "%s [%s] %s", msgHead, "isAlive fresh", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestToon::test_isAlive_dead() {
  PROFILE_NAMED("Actor_HealthState");
  delete dummy;
  dummy = new Toon("DeadToon");
  dummy->set_health_dead();
  record(dummy->isAlive() == false, "Toon after set_health_dead should report isAlive false");
  record(dummy->get_combatstate() == IDLE, "Dead Toon combat state should revert to IDLE");
  sprintf(buf, "%s [%s] %s", msgHead, "isAlive after death", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestToon::test_initial_combatstate() {
  PROFILE_NAMED("Actor_CombatState");
  delete dummy;
  dummy = new Toon();
  record(dummy->get_combatstate() == IDLE, "Toon initial CombatState should be IDLE");
  sprintf(buf, "%s [%s] %s", msgHead, "initial CombatState", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestToon::test_initial_healthstate() {
  PROFILE_NAMED("Actor_HealthState");
  delete dummy;
  dummy = new Toon();
  record(dummy->get_healthstate() == HEALTHY, "Toon initial HealthState should be HEALTHY");
  sprintf(buf, "%s [%s] %s", msgHead, "initial HealthState", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

TestToon::~TestToon() { delete dummy; }
