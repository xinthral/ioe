/*!
 * @class   TestBalance balanced.h balanced.cpp
 * @brief   Test Balance Module 
*/
#include "balanced.h"

/*!
 * @brief   Default Constructor
*/
TestBalance::TestBalance() {
    BaseCase::log->named_log(__FILE__, "Testing Actors!");
    this->baseAtk = BaseCase::cnf->get_attack();
    this->baseDef = BaseCase::cnf->get_defense();
    this->baseHlt = BaseCase::cnf->get_health();
    this->test_balance();
}

/*!
 * @brief   Test the entire Balance Module
*/
void TestBalance::test_balance() { 
    this->def_atk_ratio();      //! Test Atk/Def Ration
}

/*!
 * @brief   Validate Scaling factors against attack and defense
*/
void TestBalance::def_atk_ratio() { }

/*!
 * @brief   Default Deconstructor
*/
TestBalance::~TestBalance() {}