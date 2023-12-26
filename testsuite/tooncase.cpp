/*!
 * @class   TestToon tooncase.cpp tooncase.h
 * @brief   Testing for the Toon Module 
*/
#include "tooncase.h"

/*!
 * @brief   Default Constructor
*/
TestToon::TestToon() : BaseCase(__FILE__) {
  BaseCase::log->named_log(__FILE__, "Testing the Toon's!");
  sprintf(msgHead, "Tested Toon");
  sprintf(msgTail, "successfully.");
  this->test_all();
}

/*!
 * @brief   Validate the entire Toon module
*/
void TestToon::test_all() {
  this->test_toonCreation();
  // this->test_toonCreation_id();
  // this->test_toonCreation_name();
  // this->test_toonCreation_both();
}

/*!
 * @brief   Validate Instantiation of default Class
*/
void TestToon::test_toonCreation() {
  Toon* toon = new Toon();
  char* name = (char*)"Toon_#-1";
  assert( strcmp(name, toon->get_name().c_str()) == 0 );
  sprintf(buf, "%s [%s] %s", msgHead, "instantiation", msgTail);
  BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Validate Numerical Instantiation
*/
void TestToon::test_toonCreation_id() {
  Toon* toon = new Toon(3);
  char* name = (char*)"Toon_#3";
  assert( strcmp(name, toon->get_name().c_str()) == 0 );
  sprintf(buf, "%s [%s] %s", msgHead, "id instantiation", msgTail);
  BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Validate Alphabetical Instantiation
*/
void TestToon::test_toonCreation_name() {
  Toon* toon = new Toon("Maji");
  char* name = (char*)"Maji";
  assert( strcmp(name, toon->get_name().c_str()) == 0 );
  sprintf(buf, "%s [%s] %s", msgHead, "name instantiation", msgTail);
  BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Validate AlphaNumerica Instatiation
*/
void TestToon::test_toonCreation_both() {
  Toon* toon = new Toon(4, "Jesse");
  char* name = (char*)"Jesse";
  assert( strcmp(name, toon->get_name().c_str()) == 0 );
  sprintf(buf, "%s [%s] %s", msgHead, "both instantiation", msgTail);
  BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Default Deconstructor
*/
TestToon::~TestToon() { }
