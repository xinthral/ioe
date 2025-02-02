#ifndef TESTWEAPON_H
#define TESTWEAPON_H

#include "basecase.h"

class TestWeapon : public BaseCase {
private:
public:
  TestWeapon();
  void test_all();
  void test_weapon_type();
  ~TestWeapon();
};

#endif // TESTWEAPON_H //