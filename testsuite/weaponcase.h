#ifndef TESTWEAPON_H
#define TESTWEAPON_H

#include "basecase.h"

class TestWeapon : public BaseCase {
private:
public:
  TestWeapon();

  /*!
   * @brief   Overloaded Constructor — sets profiling granularity before running tests
   * @param[in] granularity  Level of profiling detail (0 = named only, 1 = per-method + named)
  */
  TestWeapon(int granularity);
  void test_all();
  void test_weapon_type();
  ~TestWeapon();
};

#endif // TESTWEAPON_H //