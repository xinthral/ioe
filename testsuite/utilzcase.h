#ifndef TESTUTILZ_H
#define TESTUTILZ_H

#include "basecase.h"

/*!
 * @class   TestUtilz utilzcase.cpp utilzcase.h
 * @brief   Testing for the Utilz Functions 
*/
class TestUtilz : public BaseCase {
protected:
private:
public:
  /*!
   * @brief   Default Constructor
  */
  TestUtilz();

  /*!
   * @brief   Overloaded Constructor — sets profiling granularity before running tests
   * @param[in] granularity  Level of profiling detail (0 = named only, 1 = per-method + named)
  */
  TestUtilz(int granularity);

  /*!
   * @brief   Run full set of test on module 
  */
  void test_all();

  /*!
   * @brief   Test Utilz StringToArray feature
  */
  void test_StringToArray();

  /*!
   * @brief   Test Utilz StringToArray feature with trailing spaces
  */
  void test_StringToArray_TrailingSpace();

  /*!
   * @brief   Default Deconstructor
  */
  ~TestUtilz();
};

#endif // TESTUTILZ_H //
