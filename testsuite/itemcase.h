#ifndef TESTITEM_H
#define TESTITEM_H

#include "basecase.h"
#include "../core/item.h"

/*!
 * @class   TestItem itemcase.h itemcase.cpp
 * @brief   Tests for the base Item module
*/
class TestItem : public BaseCase {
private:
  Item* _item; //!< Reusable Item object across tests

public:
  /*!
   * @brief   Default Constructor
  */
  TestItem();

  /*!
   * @brief   Run full set of tests on module
  */
  void test_all();

  /*!
   * @brief   Validate setting a valid ItemRarity stores correctly
  */
  void itemrarity();

  /*!
   * @brief   Validate out-of-range ItemRarity is rejected
  */
  void rarity_invalidation();

  /*!
   * @brief   Validate setting a valid ItemType stores correctly
  */
  void itemtype();

  /*!
   * @brief   Validate out-of-range ItemType is rejected
  */
  void type_invalidation();

  /*!
   * @brief   Validate BACKPACK is a legal ItemType
  */
  void test_backpack_type();

  /*!
   * @brief   Validate weight get and set round-trip correctly
  */
  void test_weight();

  /*!
   * @brief   Validate label is stored on construction
  */
  void test_label();

  /*!
   * @brief   Validate label longer than the buffer is rejected by set_label
  */
  void test_label_overflow();

  /*!
   * @brief   Default Deconstructor
  */
  ~TestItem();
};

#endif // TESTITEM_H //
