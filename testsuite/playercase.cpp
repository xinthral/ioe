/*!
 * @class   TestPlayer testplayer.cpp testplayer.h
 * @brief   Test Case for testing Player objects
*/
#include "playercase.h"

/*!
 * @brief   Default Constructor
*/
TestPlayer::TestPlayer() : BaseCase(__FILE__) {
  BaseCase::log->named_log(__FILE__, "Testing Player's!");
  this->dummy = new Player();
  sprintf(msgHead, "Tested");
  sprintf(msgTail, "for Actors!");
  this->test_all();
}

/*!
 * @brief   Test if Player Alive State holds
*/
void TestPlayer::test_all() {
  test_isAlive();
  test_isFighting();
}

/*!
 * @brief   Test if Player Alive State holds
*/
void TestPlayer::test_isAlive() {
  bool isAlive = dummy->isAlive();
  assertm(isAlive == true, "Is Not Alive");
  dummy->set_health_dead();
  isAlive = dummy->isAlive();
  assertm(isAlive == false, "Has Risen from the Dead");
  sprintf(buf, "%s %s %s", msgHead, "[Alive] Value", msgTail);
  BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Test if Player Combat State holds
*/
void TestPlayer::test_isFighting() { }

/*!
 * @brief   Default Deconstructor
*/
TestPlayer::~TestPlayer() { }
