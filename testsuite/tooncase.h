#ifndef TESTTOON_H
#define TESTTOON_H

#include "basecase.h"

/*!
 * @class   TestToon tooncase.cpp tooncase.h
 * @brief   Testing for the Toon Module 
*/
class TestToon : public BaseCase {
protected:
private:
public:
  /*!
   * @brief   Default Constructor
  */
  TestToon();

  /*!
   * @brief   Run full set of test on module 
  */
  void test_all();

  /*!
   * @brief   Validate Instantiation of default Class
  */
  void test_toonCreation();

  /*!
   * @brief   Validate Numerical Instantiation
  */
  void test_toonCreation_id();

  /*!
   * @brief   Validate Alphabetical Instantiation
  */
  void test_toonCreation_name();

  /*!
   * @brief   Validate AlphaNumerica Instatiation
  */
  void test_toonCreation_both();

  /*!
   * @brief   Default Deconstructor
  */
  ~TestToon();
};

#endif // TESTTOON_H //
