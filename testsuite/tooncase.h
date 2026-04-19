#ifndef TESTTOON_H
#define TESTTOON_H

#include "basecase.h"

/*!
 * @class   TestToon tooncase.h tooncase.cpp
 * @brief   Tests for the Toon module
*/
class TestToon : public BaseCase {
private:
  Toon* dummy; //!< Reusable Toon object across tests

public:
  /*!
   * @brief   Default Constructor
  */
  TestToon();

  /*!
   * @brief   Run full set of tests on module
  */
  void test_all();

  /*!
   * @brief   Validate default construction sets name to Toon_#-1
  */
  void test_toonCreation();

  /*!
   * @brief   Validate construction by integer ID sets name to Toon_#<id>
  */
  void test_toonCreation_id();

  /*!
   * @brief   Validate construction by name stores the name correctly
  */
  void test_toonCreation_name();

  /*!
   * @brief   Validate construction by id and name stores both correctly
  */
  void test_toonCreation_both();

  /*!
   * @brief   Validate a freshly constructed Toon reports isAlive true
  */
  void test_isAlive();

  /*!
   * @brief   Validate isAlive returns false after set_health_dead
  */
  void test_isAlive_dead();

  /*!
   * @brief   Validate initial CombatState is IDLE
  */
  void test_initial_combatstate();

  /*!
   * @brief   Validate initial HealthState is HEALTHY
  */
  void test_initial_healthstate();

  /*!
   * @brief   Default Deconstructor
  */
  ~TestToon();
};

#endif // TESTTOON_H //
