#ifndef TESTCOMBAT_H
#define TESTCOMBAT_H

#include "basecase.h"

/*!
 * @class   TestCombat combatcase.h combatcase.cpp
 * @brief   Tests for Combat interactions (EvE, PvE, PvP)
*/
class TestCombat : public BaseCase {
private:
  Player* _player1; //!< Reusable Player slot
  Player* _player2; //!< Reusable Player slot
  Toon*   _toon1;   //!< Reusable Toon slot
  Toon*   _toon2;   //!< Reusable Toon slot
  Combat* _combat;  //!< Reusable Combat object

public:
  /*!
   * @brief   Default Constructor
  */
  TestCombat();

  /*!
   * @brief   Overloaded Constructor — sets profiling granularity before running tests
   * @param[in] granularity  Level of profiling detail (0 = named only, 1 = per-method + named)
  */
  TestCombat(int granularity);

  /*!
   * @brief   Run full set of tests on module
  */
  void test_all();

  /*!
   * @brief   Validate Environment vs Environment combat ends with one combatant dead
  */
  void EVECombat();

  /*!
   * @brief   Validate Player vs Environment combat ends with one combatant dead
  */
  void PVECombat();

  /*!
   * @brief   Validate Player vs Player combat ends with one combatant dead
  */
  void PVPCombat();

  /*!
   * @brief   Validate that peak and total damage tracking fields are populated after combat
  */
  void test_damage_tracking();

  /*!
   * @brief   Default Deconstructor
  */
  ~TestCombat();
};

#endif // TESTCOMBAT_H //
