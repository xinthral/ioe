#ifndef TESTSTAGE_H
#define TESTSTAGE_H

#include "basecase.h"

/*!
 * @class   TestStage stagecase.cpp stagecase.h
 * @brief   Test for the StageManager 
*/
class TestStage : public BaseCase {
protected:
private:
public:
  /*!
   * @brief   Default Constructor
  */
  TestStage();

  /*!
   * @brief   Run full set of test on module 
  */
  void test_all();

  /*!
   * @brief   Default Deconstructor
  */
  ~TestStage();
};

#endif // TESTSTAGE_H //
