#include "clockcase.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor
*/
TestClock::TestClock() : BaseCase(__FILENAME__) {
  BaseCase::log->named_log(__FILENAME__, "Testing the Clock!");
  sprintf(this->msgHead, "Clock");
  sprintf(this->msgTail, "has been tested.");
  this->clock = xClock::GetInstance();
  this->test_all();
}

/*!
 * @todo    Run full set of test on module 
*/
void TestClock::test_all() {
  this->doCycleWork();
}

/*!
 * @todo    Confirm Cycle ends in valid state
*/
void TestClock::doCycleWork() {
  PROFILE_FUNCTION();
  // Setup Combat
  Player* p = new Player();
  Toon* t = new Toon();
  this->battle = Battle::GetInstance();
  this->battle->startPVE(p, t);

  // Run Test
  this->clock->doCycleWork();
  assertm(false == this->clock->getPendingWorkState(), "Clock Completed Cycle while work still pending.");
  sprintf(buf, "%s [%s] %s", msgHead, "cycle state", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Default Deconstructor
*/
TestClock::~TestClock() { }
