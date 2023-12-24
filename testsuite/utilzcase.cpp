/*!
 * @class   TestUtilz utilzcase.cpp utilzcase.h
 * @brief   Testing for the Utilz Functions 
*/
#include "utilzcase.h"

/*!
 * @brief   Default Constructor
*/
TestUtilz::TestUtilz() : BaseCase(__FILE__) {
  BaseCase::log->named_log(__FILE__, "Testing the Utilz Functionality!");
  sprintf(this->msgHead, "Tested");
  sprintf(this->msgTail, "for Actors!");
  this->test_all();
}

/*!
 * @brief   
*/
void TestUtilz::test_all() {
  this->test_StringToArray();
  this->test_StringToArray_TrailingSpace();
}

/*!
 * @brief   Test Utilz StringToArray feature
*/
void TestUtilz::test_StringToArray() {
  std::string testline = "this is a test";
  std::vector<std::string> cmds;
  Utilz::StringToArray(testline, cmds);
  assert(cmds.size() == 4);
  BaseCase::log->named_log(__FILE__, "Tested [StringToArray]");
}

/*!
 * @brief   Test Utilz StringToArray feature with trailing spaces
*/
void TestUtilz::test_StringToArray_TrailingSpace() {
  std::string testline = "this is a test ";
  std::vector<std::string> cmds;
  Utilz::StringToArray(testline, cmds);
  assert(cmds.size() == 4);
  BaseCase::log->named_log(__FILE__, "Tested [StringToArray Trailing Space]");
}

/*!
 * @brief   Default Deconstructor
*/
TestUtilz::~TestUtilz() { }
