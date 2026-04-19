#ifndef TESTBACKPACK_H
#define TESTBACKPACK_H

#include "basecase.h"
#include "../core/backpack.h"

/*!
 * @class   TestBackpack backpackcase.h backpackcase.cpp
 * @brief   Tests for the Backpack module
*/
class TestBackpack : public BaseCase {
private:
  Backpack* _pack;  //!< Placeholder for backpack object

public:
  /*!
   * @brief   Default Constructor
  */
  TestBackpack();

  /*!
   * @brief   Overloaded Constructor — sets profiling granularity before running tests
   * @param[in] granularity  Level of profiling detail (0 = named only, 1 = per-method + named)
  */
  TestBackpack(int granularity);

  /*!
   * @brief   Run full set of tests on module
  */
  void test_all();

  /*!
   * @brief   Validate label is set on construction
  */
  void test_label();

  /*!
   * @brief   Validate ItemType is BACKPACK
  */
  void test_type();

  /*!
   * @brief   Validate adding an item increases contents size
  */
  void test_add_item();

  /*!
   * @brief   Validate adding a null item is rejected
  */
  void test_add_null();

  /*!
   * @brief   Validate removing an item by label succeeds
  */
  void test_remove_item();

  /*!
   * @brief   Validate removing a non-existent item returns false
  */
  void test_remove_nonexistent();

  /*!
   * @brief   Validate get_items returns correct count
  */
  void test_get_items();

  /*!
   * @brief   Default Deconstructor
  */
  ~TestBackpack();
};

#endif // TESTBACKPACK_H //
