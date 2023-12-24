#ifndef TESTBALANCE_H
#define TESTBALANCE_H

#include <cassert>
#include "basecase.h"
#include "../core/balance.h"

class TestBalance : public BaseCase {
protected:
  int baseAtk;
  int baseDef;
  int baseHlt;
public:
  TestBalance();
  void test_all();
  void def_atk_ratio();
  void difficulty_level();
  void difficulty_range();
  ~TestBalance();
};

#endif // TESTBALANCE_H //
