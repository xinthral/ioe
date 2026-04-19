#ifndef TESTEQUIPMENT_H
#define TESTEQUIPMENT_H

#include "basecase.h"
#include "../core/equipment.h"

/*!
 * @class   TestEquipment equipmentcase.h equipmentcase.cpp
 * @brief   Tests for the Equipment module
*/
class TestEquipment : public BaseCase {
private:
  Equipment* _equip;

public:
  /*!
   * @brief   Default Constructor
  */
  TestEquipment();

  /*!
   * @brief   Overloaded Constructor — sets profiling granularity before running tests
   * @param[in] granularity  Level of profiling detail (0 = named only, 1 = per-method + named)
  */
  TestEquipment(int granularity);

  /*!
   * @brief   Run full set of tests on module
  */
  void test_all();

  /*!
   * @brief   Validate default construction initializes multipliers to 0.0f
  */
  void test_default_multipliers();

  /*!
   * @brief   Validate typed construction applies the correct profile
  */
  void test_profile_sword();
  void test_profile_shield();
  void test_profile_staff();
  void test_profile_ring();
  void test_profile_relic();
  void test_profile_backpack();

  /*!
   * @brief   Validate multiplier validation rejects out-of-range values
  */
  void test_multiplier_validation();

  /*!
   * @brief   Validate label is set correctly on construction
  */
  void test_label();

  /*!
   * @brief   Default Deconstructor
  */
  ~TestEquipment();
};

#endif // TESTEQUIPMENT_H //
