/*!
 * @class   TestBalance balancecase.h balancecase.cpp
 * @brief   Test Balance Module 
*/
#include "balancecase.h"

/*!
 * @brief   Default Constructor
*/
TestBalance::TestBalance() {
    BaseCase::log->named_log(__FILE__, "Testing Balance!");
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
    this->difficulty_level();   //! Test Difficulty Level
}

/*!
 * @brief   Validate Scaling factors against attack and defense
*/
void TestBalance::def_atk_ratio() { 
    double preRatio = (this->baseAtk * 1.0) / this->baseDef;
    double numerator = this->baseAtk * bal->scalar(100);
    double denominator = this->baseDef * bal->scalar(100);
    double posRatio = numerator / denominator;
    assert(preRatio == posRatio);
    sprintf(buf, "Tested Defense/Attack Ratio at Scale; %f.", posRatio);
    BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   
*/
void TestBalance::difficulty_level() {
    // std::string dif = cnf->raw_config("DIF");
    // Hardness diff   = bal->get_difficulty();
    // Hardness difff  = Norm;
    // printf("%s dd \n", difff);
}

/*!
 * @brief   Default Deconstructor
*/
TestBalance::~TestBalance() {}