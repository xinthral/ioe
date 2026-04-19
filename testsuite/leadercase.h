#ifndef TESTLEADER_H
#define TESTLEADER_H

#include "basecase.h"

/*!
 * @class   TestLeader leadercase.cpp leadercase.h
 * @brief   Test for the LeaderBoard
*/
class TestLeader : public BaseCase {
protected:
private:
public:
  /*!
   * @brief   Default Constructor
  */
  TestLeader();

  /*!
   * @brief   Overloaded Constructor — sets profiling granularity before running tests
   * @param[in] granularity  Level of profiling detail (0 = named only, 1 = per-method + named)
  */
  TestLeader(int granularity);

  /*!
   * @brief   Run full set of test on module 
  */
  void test_all();

  /*!
   * @brief   Default Deconstructor
  */
  ~TestLeader();
};

#endif // TESTLEADER_H //
