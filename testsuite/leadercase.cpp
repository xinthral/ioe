#include "leadercase.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor
*/
TestLeader::TestLeader() : TestLeader(0) {}

TestLeader::TestLeader(int granularity) : BaseCase(__FILENAME__) {
  set_granularity(granularity);
  BaseCase::log->named_log(__FILENAME__, "Testing the LeaderBoard!");
}

/*!
 * @todo    Run full set of test on module 
*/
void TestLeader::test_all() { }

/*!
 * @todo    Default Deconstructor
*/
TestLeader::~TestLeader() { }
