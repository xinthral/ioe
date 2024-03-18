#ifndef TESTCLOCK_H
#define TESTCLOCK_H

#include "basecase.h"

/*!
 * @class   TestClock clockcase.cpp clockcase.h
 * @brief   Test for the Engine Clock
*/
class TestClock : public BaseCase {
protected:
private:
  xClock* clock;
  Battle* battle;

public:
  /*!
   * @brief   Default Constructor
  */
  TestClock();

  /*!
   * @brief   Run full set of test on module
  */
  void test_all();

  /*!
   * @brief   Run Cycles
  */
  void doCycleWork();

  /*!
   * @brief   Default Deconstructor
  */
  ~TestClock();
};

#endif // TESTCLOCK_H //
