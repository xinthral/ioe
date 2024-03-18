#ifndef TESTACTOR_H
#define TESTACTOR_H

#include "basecase.h"
#include "../core/actor.h"

/*! 
 * @class   TestActors actorcase.h actorcase.cpp
 * @brief   Case for testing Actor functionality
*/
class TestActors : public BaseCase {
protected:
  Actor* dummy;     //!< Placeholder Actor Object

private:
public:
  /*!
   * @brief   Default Constructor
  */
  TestActors();

  /*!
   * @brief   Run full set of test on module 
  */
  void test_all();

  /*!
   * @brief   Run full set of test on Base Values 
  */
  void test_basevalues();

  /*!
   * @brief   Run full set of test on Combat States 
  */
  void test_combatstate();

  /*!
   * @brief   Run full set of test on Health States 
  */
  void test_healthstate();

  /*!
   * @brief   Validate Initial Condition: Attack Value
   * @note    Are actors getting proper base values?
  */
  void base_attack();

  /*!
   * @brief   Validate Initial Condition: Defense Value
   * @note    Are actors getting proper base values?
  */
  void base_defense();

  /*!
   * @brief   Validate Initial Condition: Flux Value
   * @note    Are actors getting proper base values?
  */
  void base_flux();

  /*!
   * @brief   Validate Initial Condition: Health Value
   * @note    Are actors getting proper base values?
  */
  void base_health();

  /*!
   * @brief   Validate Initial Condition: Combat Idle
   * @note    Are actors states getting set properly?
  */
  void combatstate_idle();

  /*!
   * @brief   Validate Initial Condition: Combat Patrol
   * @note    Are actors states getting set properly?
  */
  void combatstate_patrol();

  /*!
   * @brief   Validate Initial Condition: Combat Fight
   * @note    Are actors states getting set properly?
  */
  void combatstate_fight();

  /*!
   * @brief   Validate Initial Condition: Combat Flee
   * @note    Are actors states getting set properly?
  */
  void combatstate_flee();

  /*!
   * @brief   Validate Initial Condition: Combat Follow
   * @note    Are actors states getting set properly?
  */
  void combatstate_follow();

  /*!
   * @brief   Validate Initial Condition: Health Healthy
   * @note    Are actors states getting set properly?
  */
  void healthstate_healthy();

  /*!
   * @brief   Validate Initial Condition: Health Hurting
   * @note    Are actors states getting set properly?
  */
  void healthstate_hurting();

  /*!
   * @brief   Validate Initial Condition: Health Critical 
   * @note    Are actors states getting set properly?
  */
  void healthstate_critical();

  /*!
   * @brief   Validate Initial Condition: Health Sick 
   * @note    Are actors states getting set properly?
  */
  void healthstate_sick();

  /*!
   * @brief   Validate Initial Condition: Health Dead 
   * @note    Are actors states getting set properly?
  */
  void healthstate_dead();

  /*!
   * @brief   Validate Initial Condition: Health Value
   * @note    Are actors states getting set properly?
  */
  void starting_health();

  /*!
   * @brief   Default Deconstructor
  */
  ~TestActors();
};

#endif // TESTACTOR_H //
