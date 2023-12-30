/*!
 * @class   TestLexicon lexiconcase.cpp lexiconcase.h
 * @brief   Test for the Lexicon
*/
#include "lexiconcase.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
TestLexicon::TestLexicon() : BaseCase(__FILENAME__) {
  BaseCase::log->named_log(__FILENAME__, "Testing the Lexicon!");
  sprintf(this->msgHead, "Tested");
  sprintf(this->msgTail, "from the Lexicon!");
  this->lex = new Lexicon();
  this->test_all();
}

/*!
 * @brief   Run full set of test on module 
*/
void TestLexicon::test_all() { 
  this->generateName();
}

/*!
 * @brief   Validate the Name Generation feature
*/
void TestLexicon::generateName() {
  std::string response = lex->generateName(3);
  assertm(response.size() > 0, "Name Responded with Zero Length");
  sprintf(buf, "%s [%s] %s (%s)", msgHead, "name generation", msgTail, response.c_str());
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @brief   Default Deconstructor
*/
TestLexicon::~TestLexicon() { }
