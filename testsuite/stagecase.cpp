#include "stagecase.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor
*/
TestStage::TestStage() : TestStage(0) {}

TestStage::TestStage(int granularity) : BaseCase(__FILENAME__) {
  set_granularity(granularity);
  BaseCase::log->named_log(__FILENAME__, "Testing the StageManager!");
  this->test_all();
}

/*!
 * @todo    Run full set of test on module 
*/
void TestStage::test_all() { }

/*!
 * @todo    Default Deconstructor
*/
TestStage::~TestStage() { }
