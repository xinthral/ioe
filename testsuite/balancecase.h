#ifndef TESTBALANCE_H
#define TESTBALANCE_H

#include <cassert>
#include "basecase.h"
#include "../core/balance.h"

/*!
 * @class   TestBalance balancecase.h balancecase.cpp
 * @brief   Test BalanceController Module 
*/
class TestBalance : public BaseCase {
protected:
  int baseAtk;
  int baseDef;
  int baseHlt;
public:
  /*!
   * @brief   Default Constructor
  */
  TestBalance();

  /*!
   * @brief   Validate the entire Balance Module
  */
  void test_all();

  /*!
   * @brief   Validate Scaling factors against attack and defense
  */
  void def_atk_ratio();

  /*!
   * @brief   Validate that the appropriate difficulty level is
   *          being assigned. 
  */
  void difficulty_level();

  /*!
   * @brief   Validate that the appropriate difficulty level is being assigned. 
  */
  void difficulty_range();

  /*!
   * @brief   Default Deconstructor
  */
  ~TestBalance();
};

#endif // TESTBALANCE_H //
