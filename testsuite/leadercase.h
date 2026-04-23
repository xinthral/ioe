#ifndef TESTLEADER_H
#define TESTLEADER_H

#include "basecase.h"

/*!
 * @class   TestLeader leadercase.cpp leadercase.h
 * @brief   Tests for the LeaderBoard singleton
*/
class TestLeader : public BaseCase {
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
   * @brief   Run full set of tests on module
  */
  void test_all();

  /*!
   * @brief   Verify entries are stored in descending order and trimmed to 10
  */
  void test_ordering_and_trim();

  /*!
   * @brief   Verify all eight record_* methods accept submissions without error
  */
  void test_all_sections();

  /*!
   * @brief   Verify display() runs without error on a populated board
  */
  void test_display();

  /*!
   * @brief   Default Deconstructor
  */
  ~TestLeader();
};

#endif // TESTLEADER_H //
