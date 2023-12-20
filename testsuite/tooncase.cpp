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
}

/*!
 * @brief   Default Deconstructor
*/
TestToon::~TestToon() { }
