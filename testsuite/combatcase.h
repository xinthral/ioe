#ifndef TESTCOMBAT_H
#define TESTCOMBAT_H

#include "basecase.h"

/*!
 * @class   TestCombat combatcase.h combatcase.cpp
 * @brief   Test Class for Combat interactions
*/
class TestCombat : public BaseCase {
protected:
private:
  int _idx;
public:
  /*! 
   * @brief   Default Constructor
  */
  TestCombat();

  /*! 
   * @brief   Default Constructor
  */
  void test_all();

  /*! 
   * @brief   Evironment Vs Environment Combat
  */
  void EVECombat();

  /*! 
   * @brief   Player Vs Environment Combat
  */
  void PVECombat();

  /*! 
   * @brief   Player Vs Player Combat
  */
  void PVPCombat();

  /*! 
   * @brief   Default Deconstructor
  */
  ~TestCombat();
};

#endif // TESTCOMBAT_H //
