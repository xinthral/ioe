#include "utilzcase.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor
*/
TestUtilz::TestUtilz() : BaseCase(__FILENAME__) {
  BaseCase::log->named_log(__FILENAME__, "Testing the Utilz Functionality!");
  sprintf(this->msgHead, "Tested");
  sprintf(this->msgTail, "for Actors!");
  this->test_all();
}

/*!
 * @todo    Run full set of test on module 
*/
void TestUtilz::test_all() {
  this->test_StringToArray();
  this->test_StringToArray_TrailingSpace();
}

/*!
 * @todo    Test Utilz StringToArray feature
*/
void TestUtilz::test_StringToArray() {
  PROFILE_FUNCTION();
  std::string testline = "this is a test";
  std::vector<std::string> cmds;
  Utilz::StringToArray(testline, cmds);
  assert(cmds.size() == 4);
  sprintf(buf, "%s [%s] %s", msgHead, "StringToArray", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Test Utilz StringToArray feature with trailing spaces
*/
void TestUtilz::test_StringToArray_TrailingSpace() {
  PROFILE_FUNCTION();
  std::string testline = "this is a test ";
  std::vector<std::string> cmds;
  Utilz::StringToArray(testline, cmds);
  assert(cmds.size() == 4);
  sprintf(buf, "%s [%s] %s", msgHead, "StringToArray Trailing Space", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Default Deconstructor
*/
TestUtilz::~TestUtilz() { }
