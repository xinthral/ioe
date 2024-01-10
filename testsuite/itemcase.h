#ifndef TESTITEM_H
#define TESTITEM_H

#include "basecase.h"

/*!
 * @class   TestItem itemcase.cpp itemcase.h
 * @brief   Test for the Base Item 
*/
class TestItem : public BaseCase {
protected:
private:
public:
  /*!
   * @brief   Default Constructor
  */
  TestItem();

  /*!
   * @brief   Run full set of test on module 
  */
  void test_all();

  /*!
   * @brief   Default Deconstructor
  */
  ~TestItem();
};

#endif // TESTITEM_H //
