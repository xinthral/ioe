#ifndef TESTPLAYER_H
#define TESTPLAYER_H

#include "basecase.h"
#include "../core/player.h"

/*!
 * @class   TestPlayer playercase.h playercase.cpp
 * @brief   Tests for the Player module
*/
class TestPlayer : public BaseCase {
private:
  Player* dummy; //!< Reusable Player object across tests

public:
  /*!
   * @brief   Default Constructor
  */
  TestPlayer();

  /*!
   * @brief   Run full set of tests on module
  */
  void test_all();

  /*!
   * @brief   Validate isAlive returns true when healthy, false when dead
  */
  void test_isAlive();

  /*!
   * @brief   Validate isFighting reflects CombatState correctly
  */
  void test_isFighting();

  /*!
   * @brief   Validate name is stored correctly on construction
  */
  void test_name();

  /*!
   * @brief   Validate level is stored correctly on construction
  */
  void test_level();

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
  ~TestPlayer();
};

#endif // TESTPLAYER_H //
