#include "stagecase.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor
*/
TestStage::TestStage() : BaseCase(__FILENAME__) {
  BaseCase::log->named_log(__FILENAME__, "Testing the StageManager!");
}

/*!
 * @todo    Run full set of test on module 
*/
void TestStage::test_all() { }

/*!
 * @todo    Default Deconstructor
*/
TestStage::~TestStage() { }
