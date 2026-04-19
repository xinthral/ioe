#include "playercase.h"

/*!
 * @def     __FILENAME__
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

TestPlayer::TestPlayer() : TestPlayer(0) {}

TestPlayer::TestPlayer(int granularity) : BaseCase(__FILENAME__) {
  set_granularity(granularity);
  BaseCase::log->named_log(__FILENAME__, "Testing Players!");
  sprintf(this->msgHead, "Tested");
  sprintf(this->msgTail, "for Players!");
  dummy = new Player("TestPlayer", 1);
  this->test_all();
}

void TestPlayer::test_all() {
  test_isAlive();
  test_isFighting();
  test_name();
  test_level();
  test_initial_combatstate();
  test_initial_healthstate();
}

void TestPlayer::test_isAlive() {
  if (this->_granularity >= 1) {
    PROFILE_FUNCTION();
  }
  PROFILE_NAMED("Actor_HealthState");
  delete dummy;
  dummy = new Player("TestPlayer", 1);
  record(dummy->isAlive() == true, "Fresh Player should report isAlive true");
  dummy->set_health_dead();
  record(dummy->isAlive() == false, "Player after set_health_dead should report isAlive false");
  sprintf(buf, "%s [%s] %s", msgHead, "isAlive", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestPlayer::test_isFighting() {
  if (this->_granularity >= 1) {
    PROFILE_FUNCTION();
  }
  PROFILE_NAMED("Actor_CombatState");
  delete dummy;
  dummy = new Player("TestPlayer", 1);
  record(dummy->isFighting() == false, "Fresh Player should not be fighting");
  dummy->set_combat_fight();
  record(dummy->isFighting() == true, "Player should be fighting after set_combat_fight");
  dummy->set_combat_idle();
  record(dummy->isFighting() == false, "Player should not be fighting after set_combat_idle");
  sprintf(buf, "%s [%s] %s", msgHead, "isFighting", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestPlayer::test_name() {
  if (this->_granularity >= 1) {
    PROFILE_FUNCTION();
  }
  PROFILE_NAMED("Actor_Instantiation");
  delete dummy;
  dummy = new Player("Xinthral", 1);
  record(dummy->get_name() == "Xinthral", "Player name mismatch on construction");
  sprintf(buf, "%s [%s] %s", msgHead, "name", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestPlayer::test_level() {
  if (this->_granularity >= 1) {
    PROFILE_FUNCTION();
  }
  PROFILE_NAMED("Actor_Instantiation");
  delete dummy;
  dummy = new Player("LevelTest", 5);
  record(dummy->get_level() == 5, "Player level mismatch on construction");
  sprintf(buf, "%s [%s] %s", msgHead, "level", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestPlayer::test_initial_combatstate() {
  if (this->_granularity >= 1) {
    PROFILE_FUNCTION();
  }
  PROFILE_NAMED("Actor_CombatState");
  delete dummy;
  dummy = new Player("TestPlayer", 1);
  record(dummy->get_combatstate() == IDLE, "Player initial CombatState should be IDLE");
  sprintf(buf, "%s [%s] %s", msgHead, "initial CombatState", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestPlayer::test_initial_healthstate() {
  if (this->_granularity >= 1) {
    PROFILE_FUNCTION();
  }
  PROFILE_NAMED("Actor_HealthState");
  delete dummy;
  dummy = new Player("TestPlayer", 1);
  record(dummy->get_healthstate() == HEALTHY, "Player initial HealthState should be HEALTHY");
  sprintf(buf, "%s [%s] %s", msgHead, "initial HealthState", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

TestPlayer::~TestPlayer() { delete dummy; }
