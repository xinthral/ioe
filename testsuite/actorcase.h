#ifndef TESTACTOR_H
#define TESTACTOR_H

#include "basecase.h"
#include "../core/actor.h"

class TestActors : public BaseCase {
protected:
  Actor* dummy;
  char msgHead[32];
  char msgTail[16];
  char msgNote[64];

public:
  //! Constructors
  TestActors();

  //! Feet to the fire
  void test_all();
  void test_combatstate();
  void test_healthstate();

  //! Test Stats
  void base_attack();
  void base_defense(); 
  void base_health();

  //! Test Combat States
  void combatstate_idle();
  void combatstate_patrol();
  void combatstate_fight();
  void combatstate_flee();
  void combatstate_follow();

  //! Test Health States
  void healthstate_healthy();
  void healthstate_hurting();
  void healthstate_critical();
  void healthstate_sick();
  void healthstate_dead();

  //! Deconstructors
  ~TestActors();
};

#endif // TESTACTOR_H //
