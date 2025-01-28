#include "tooncase.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor
*/
TestToon::TestToon() : BaseCase(__FILENAME__) {
  BaseCase::log->named_log(__FILENAME__, "Testing the Toon's!");
  sprintf(this->msgHead, "Tested Toon");
  sprintf(this->msgTail, "successfully.");
  this->test_all();
}

/*!
 * @todo    Run full set of test on module 
*/
void TestToon::test_all() {
  this->test_toonCreation();
  this->test_toonCreation_id();
  this->test_toonCreation_name();
  this->test_toonCreation_both();
}

/*!
 * @todo    Validate Instantiation of default Class
*/
void TestToon::test_toonCreation() {
  PROFILE_FUNCTION();
  Toon* toon = new Toon();
  char* name = (char*)"Toon_#-1";
  assert( strcmp(name, toon->get_name().c_str()) == 0 );
  sprintf(this->msgNote, "instantiation");
  sprintf(buf, "%s [%s] %s", msgHead, msgNote, msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Numerical Instantiation
*/
void TestToon::test_toonCreation_id() {
  PROFILE_FUNCTION();
  Toon* toon = new Toon(3);
  char* name = (char*)"Toon_#3";
  assert( strcmp(name, toon->get_name().c_str()) == 0 );
  sprintf(this->msgNote, "id instantiation");
  sprintf(buf, "%s [%s] %s", msgHead, msgNote, msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate Alphabetical Instantiation
*/
void TestToon::test_toonCreation_name() {
  PROFILE_FUNCTION();
  Toon* toon = new Toon("Maji");
  char* name = (char*)"Maji";
  assert( strcmp(name, toon->get_name().c_str()) == 0 );
  sprintf(this->msgNote, "name instantiation");
  sprintf(buf, "%s [%s] %s", msgHead, msgNote, msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Validate AlphaNumerica Instatiation
*/
void TestToon::test_toonCreation_both() {
  PROFILE_FUNCTION();
  Toon* toon = new Toon(4, "Jesse");
  char* name = (char*)"Jesse";
  assert( strcmp(name, toon->get_name().c_str()) == 0 );
  sprintf(this->msgNote, "both instantiation");
  sprintf(buf, "%s [%s] %s", msgHead, msgNote, msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Default Deconstructor
*/
TestToon::~TestToon() { }
