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
 * @brief   
*/
void TestToon::test_all() {
  this->test_toonCreation();
  this->test_toonCreation_id();
  this->test_toonCreation_name();
  this->test_toonCreation_both();
}

/*!
 * @brief   
*/
void TestToon::test_toonCreation() {
  Toon* _toon = new Toon();
  char* _name = (char*)"Toon_#-1";
  assert( strcmp(_name, _toon->get_name().c_str()) == 0 );
  sprintf(buf, "%s [%s] %s", msgHead, "instantiation", msgTail);
  BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   
*/
void TestToon::test_toonCreation_id() {
  Toon* _toon = new Toon(3);
  char* _name = (char*)"Toon_#3";
  assert( strcmp(_name, _toon->get_name().c_str()) == 0 );
  sprintf(buf, "%s [%s] %s", msgHead, "id instantiation", msgTail);
  BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   
*/
void TestToon::test_toonCreation_name() {
  Toon* _toon = new Toon("Maji");
  char* _name = (char*)"Maji";
  assert( strcmp(_name, _toon->get_name().c_str()) == 0 );
  sprintf(buf, "%s [%s] %s", msgHead, "name instantiation", msgTail);
  BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   
*/
void TestToon::test_toonCreation_both() {
  Toon* _toon = new Toon(4, "Jesse");
  char* _name = (char*)"Jesse";
  assert( strcmp(_name, _toon->get_name().c_str()) == 0 );
  sprintf(buf, "%s [%s] %s", msgHead, "both instantiation", msgTail);
  BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Default Deconstructor
*/
TestToon::~TestToon() {}
