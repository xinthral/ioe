#ifndef TESTCOMBAT_H
#define TESTCOMBAT_H

#include "basecase.h"

class TestCombat : public BaseCase {
protected:
private:
  int _idx;
public:
  TestCombat();
  void test_all();
  void test_eve();
  void test_pve();
  void test_pvp();
  ~TestCombat();
};

#endif // TESTCOMBAT_H //
