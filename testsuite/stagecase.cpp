/*!
 * @class   TestStage stagecase.cpp stagecase.h
 * @brief   Test for the StageManager 
*/

#include "stagecase.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
TestStage::TestStage() : BaseCase(__FILENAME__) {
  BaseCase::log->named_log(__FILENAME__, "Testing the StageManager!");
}

/*!
 * @brief   Run full set of test on module 
*/
void TestStage::test_all() { }

/*!
 * @brief   Default Deconstructor
*/
TestStage::~TestStage() { }
