#include "lexiconcase.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor
*/
TestLexicon::TestLexicon() : BaseCase(__FILENAME__) {
  BaseCase::log->named_log(__FILENAME__, "Testing the Lexicon!");
  sprintf(this->msgHead, "Tested");
  sprintf(this->msgTail, "from the Lexicon!");
  this->lex = new Lexicon();
  this->test_all();
}

/*!
 * @todo    Run full set of test on module 
*/
void TestLexicon::test_all() { 
  this->generateName(3);
  this->lexigraphChangeSize();
}

/*!
 * @todo    Validate the name generation feature
*/
void TestLexicon::generateName(int len) {
  std::string response = lex->generateName(len);
  assertm(response.size() >= (2*len), "Name Responded with Insufficient Length");
  sprintf(buf, "%s [%s] %s (%s)", msgHead, "name generation", msgTail, response.c_str());
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo  Validate the Lexicon swap still holds true
*/
void TestLexicon::lexigraphChangeSize() {
  lex->setLexigraph("1234567890ABCDEFGHIJKLMNOQRSTUVWXYZ");
  assertm(35 == lex->getLexigraphSize(), "New Lexigraph has mismatched Size");
  sprintf(buf, "%s [%s] %s (%d)", msgHead, "changing lexigraph", msgTail, lex->getLexigraphSize());
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Default Deconstructor
*/
TestLexicon::~TestLexicon() { }
