#include "balancecase.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief    Default Constructor
*/
TestBalance::TestBalance() : TestBalance(0) {}

TestBalance::TestBalance(int granularity) : BaseCase(__FILENAME__) {
  set_granularity(granularity);
  BaseCase::log->named_log(__FILENAME__, "Testing the BalanceController!");
  sprintf(this->msgHead, "Tested");
  sprintf(this->msgTail, "at scale for Balance!");
  this->baseAtk = BaseCase::cnf->get_attack();
  this->baseDef = BaseCase::cnf->get_defense();
  this->baseHlt = BaseCase::cnf->get_health();
  this->test_all();
}

/*!
 * @brief    Validate the entire Balance Module
*/
void TestBalance::test_all() {
  this->def_atk_ratio();      //!< Test Atk/Def Ratio
  this->difficulty_level();   //!< Test Difficulty Level
  this->difficulty_range();   //!< Test Difficulty Range
}

/*!
 * @brief    Validate Scaling factors against attack and defense
*/
void TestBalance::def_atk_ratio() {
  if (this->_granularity >= 1) {
    PROFILE_FUNCTION();
  }
  PROFILE_NAMED("Balance");
  double preRatio = (this->baseAtk * 1.0) / this->baseDef;
  double numerator = this->baseAtk * bal->scalar(100);
  double denominator = this->baseDef * bal->scalar(100);
  double posRatio = numerator / denominator;
  record(preRatio == posRatio, "Attack/Defense ratio changed after scaling");
  sprintf(buf, "%s [DAF: %.4f] (Defense/Attack Ratio) %s", msgHead, posRatio, msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @brief    Validate that the appropriate difficulty level is being assigned. 
*/
void TestBalance::difficulty_level() {
  if (this->_granularity >= 1) {
    PROFILE_FUNCTION();
  }
  PROFILE_NAMED("Balance");
  std::string dif  = cnf->raw_config("DIF");
  std::string diff = bal->get_difficulty_str();
  record(dif.compare(diff) == 0, "Difficulty level mismatch");
  sprintf(buf, "%s [Difficulty] %s", msgHead, msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @brief    Validate difficulty value falls within the valid range [1, 5]
*/
void TestBalance::difficulty_range() {
  if (this->_granularity >= 1) {
    PROFILE_FUNCTION();
  }
  PROFILE_NAMED("Balance");
  int dif = atoi(cnf->raw_config("DIF").c_str());
  record(dif >= 1 && dif <= 5, "Difficulty value out of valid range [1, 5]");
  sprintf(buf, "%s [Difficulty Range: %d] %s", msgHead, dif, msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @brief    Default Deconstructor
*/
TestBalance::~TestBalance() { }