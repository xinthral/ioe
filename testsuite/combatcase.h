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
  void EVECombat();
  void PVECombat();
  void PVPCombat();
  ~TestCombat();
};

#endif // TESTCOMBAT_H //
