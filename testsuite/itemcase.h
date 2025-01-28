#ifndef TESTITEM_H
#define TESTITEM_H

#include "basecase.h"
#include "../core/item.h"

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
  void test_rarity();
  void test_rarity_invalid_rarity();
  void test_type();
  void test_type_invalid_type();

  /*!
   * @brief   Default Deconstructor
  */
  ~TestItem();
};

#endif // TESTITEM_H //
