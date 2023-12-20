/*!
 * @class   TestCombat combatcase.h combatcase.cpp
 * @brief   Test Class for Combat interactions
*/
#include "combatcase.h"

/*! 
 * @brief   Default Constructor
*/
TestCombat::TestCombat() : BaseCase(__FILE__) {
  BaseCase::log->named_log(__FILE__, "Testing Combat!");
 }

/*! 
 * @brief   Default Deconstructor
*/
TestCombat::~TestCombat() { }
