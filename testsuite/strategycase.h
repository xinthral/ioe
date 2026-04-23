#ifndef TESTSTRATEGY_H
#define TESTSTRATEGY_H

#include "basecase.h"

/*!
 * @class   TestStrategy strategycase.h strategycase.cpp
 * @brief   Tests for the CombatStrategy system and each concrete style
*/
class TestStrategy : public BaseCase {
private:
public:
  /*!
   * @brief   Default Constructor
  */
  TestStrategy();

  /*!
   * @brief   Overloaded Constructor — sets profiling granularity before running tests
   * @param[in] granularity  Level of profiling detail (0 = named only, 1 = per-method + named)
  */
  TestStrategy(int granularity);

  /*!
   * @brief   Run full set of tests on module
  */
  void test_all();

  /*!
   * @brief   Verify Actor defaults to BalancedStyle and set_strategy swaps correctly
  */
  void test_assign();

  /*!
   * @brief   Verify make_strategy factory returns the correct concrete type for each StyleType
  */
  void test_factory();

  /*!
   * @brief   Verify resolve_attack returns 0 on miss and > base on crit over many rolls
  */
  void test_attack_resolution();

  /*!
   * @brief   Verify resolve_defense returns 0 on dodge over many rolls
  */
  void test_defense_resolution();

  /*!
   * @brief   Verify should_flee thresholds for strategies that flee
  */
  void test_flee_thresholds();

  /*!
   * @brief   Run full EvE combat with each style pair and verify combat terminates
  */
  void test_combat_with_styles();

  /*!
   * @brief   Default Deconstructor
  */
  ~TestStrategy();
};

#endif // TESTSTRATEGY_H //
