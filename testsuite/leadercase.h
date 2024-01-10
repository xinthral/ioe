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
   * @brief   Run full set of test on module 
  */
  void test_all();

  /*!
   * @brief   Default Deconstructor
  */
  ~TestLeader();
};

#endif // TESTLEADER_H //
