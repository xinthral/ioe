/*!
 * @class   TestBalance balancecase.h balancecase.cpp
 * @brief   Test BalanceController Module 
*/
#include "balancecase.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
TestBalance::TestBalance() : BaseCase(__FILENAME__) {
  BaseCase::log->named_log(__FILENAME__, "Testing the BalanceController!");
  this->baseAtk = BaseCase::cnf->get_attack();
  this->baseDef = BaseCase::cnf->get_defense();
  this->baseHlt = BaseCase::cnf->get_health();
  this->test_all();
}

/*!
 * @brief   Validate the entire Balance Module
*/
void TestBalance::test_all() { 
  this->def_atk_ratio();      //!< Test Atk/Def Ration
  this->difficulty_level();   //!< Test Difficulty Level
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
  sprintf(buf, "Tested [DAF: %.4f] (Defense/Attack Ratio) at Scale.", posRatio);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @brief   Validate that the appropriate difficulty level is
 *          is being assigned. 
*/
void TestBalance::difficulty_level() {
  std::string dif  = cnf->raw_config("DIF");
  std::string diff = bal->get_difficulty_str();
  assert(dif.compare(diff));
  sprintf(buf, "Tested [Difficulty] level assigned.");
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @brief   Default Deconstructor
*/
TestBalance::~TestBalance() { }
