/*!
 * @class   TestStage stagecase.cpp stagecase.h
 * @brief   Test for the StageManager 
*/

#include "stagecase.h"

/*!
 * @brief   Default Constructor
*/
TestStage::TestStage() : BaseCase(__FILE__) {
  BaseCase::log->named_log(__FILE__, "Testing the StageManager!");
}

/*!
 * @brief   Default Deconstructor
*/
TestStage::~TestStage() { }
