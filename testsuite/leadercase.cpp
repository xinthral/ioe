/*!
 * @class   TestLeader leadercase.cpp leadercase.h
 * @brief   Test for the LeaderBoard
*/

#include "leadercase.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
TestLeader::TestLeader() : BaseCase(__FILENAME__) {
  BaseCase::log->named_log(__FILENAME__, "Testing the LeaderBoard!");
}

/*!
 * @brief   Default Deconstructor
*/
TestLeader::~TestLeader() { }
