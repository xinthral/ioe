#ifndef TESTER_H
#define TESTER_H

#include <stdio.h>
#include <string.h>
#include <thread>
#include "actorcase.h"
#include "audiocase.h"
#include "backpackcase.h"
#include "balancecase.h"
#include "battlecase.h"
#include "clockcase.h"
#include "cipherscase.h"
#include "combatcase.h"
#include "configcase.h"
#include "equipmentcase.h"
#include "itemcase.h"
#include "leadercase.h"
#include "lexiconcase.h"
#include "playercase.h"
#include "profiler.h"
#include "stagecase.h"
#include "strategycase.h"
#include "tooncase.h"
#include "utilzcase.h"
#include "weaponcase.h"

/*!
 * @class   TestSuite testsuite.h testsuite.cpp
 * @brief   Command Line Tool (CLI) for the TestSuite
 * @details Test Suite is meant to be a collection of unit testing
 *          with the idea of reaching 100% coverage of testing,
 *          while providing a command line utility for reference
 *          when developing or debugging.
*/
class TestSuite {
protected:
  Logger* log;
public:
  /*!
   * @brief   Default Constructor
  */
  TestSuite();

  /*!
   * @brief   Run all test cases with full profiling granularity
  */
  void TestAll();

  /*!
   * @brief   Initiates the Test for the Actor Module
   * @param[in] level  Profiling granularity (0 = named groups only, 1 = per-method + named)
  */
  void CaseActor(int level=0);

  /*!
   * @brief   Initiates the Test for the Audio Module
   * @param[in] level  Profiling granularity (0 = named groups only, 1 = per-method + named)
  */
  void CaseAudio(int level=0);

  /*!
   * @brief   Initiates the Test for the Backpack Module
   * @param[in] level  Profiling granularity (0 = named groups only, 1 = per-method + named)
  */
  void CaseBackpack(int level=0);

  /*!
   * @brief   Initiates the Test for the Equipment Module
   * @param[in] level  Profiling granularity (0 = named groups only, 1 = per-method + named)
  */
  void CaseEquipment(int level=0);

  /*!
   * @brief   Initiates the Test for the BalanceController Module
   * @param[in] level  Profiling granularity (0 = named groups only, 1 = per-method + named)
  */
  void CaseBalance(int level=0);

  /*!
   * @brief   Initiates the Test for the BattleManager Module
   * @param[in] level  Profiling granularity (0 = named groups only, 1 = per-method + named)
  */
  void CaseBattle(int level=0);

  /*!
   * @brief   Initiates the Test for the Engine's Clock
   * @param[in] level  Profiling granularity (0 = named groups only, 1 = per-method + named)
  */
  void CaseClock(int level=0);

  /*!
   * @brief   Initiates the Test for the Ciphers Module
   * @param[in] level  Profiling granularity (0 = named groups only, 1 = per-method + named)
  */
  void CaseCiphers(int level=0);

  /*!
   * @brief   Initiates the Test for the Combat Module
   * @param[in] level  Profiling granularity (0 = named groups only, 1 = per-method + named)
  */
  void CaseCombat(int level=0);

  /*!
   * @brief   Initiates the Test for the ConfigManager Module
   * @param[in] level  Profiling granularity (0 = named groups only, 1 = per-method + named)
  */
  void CaseConfig(int level=0);

  /*!
   * @brief   Initiates the Test for the Item Module
   * @param[in] level  Profiling granularity (0 = named groups only, 1 = per-method + named)
  */
  void CaseItem(int level=0);

  /*!
   * @brief   Initiates the Test for the LeaderBoard Module
   * @param[in] level  Profiling granularity (0 = named groups only, 1 = per-method + named)
  */
  void CaseLeader(int level=0);

  /*!
   * @brief   Initiates the Test for the Lexicon Module
   * @param[in] level  Profiling granularity (0 = named groups only, 1 = per-method + named)
  */
  void CaseLexicon(int level=0);

  /*!
   * @brief   Initiates the Test for the Player Module
   * @param[in] level  Profiling granularity (0 = named groups only, 1 = per-method + named)
  */
  void CasePlayer(int level=0);

  /*!
   * @brief   Initiates the Test for the StageManager Module
   * @param[in] level  Profiling granularity (0 = named groups only, 1 = per-method + named)
  */
  void CaseStage(int level=0);

  /*!
   * @brief   Initiates the Test for the CombatStrategy Module
   * @param[in] level  Profiling granularity (0 = named groups only, 1 = per-method + named)
  */
  void CaseStrategy(int level=0);

  /*!
   * @brief   Initiates the Test for the Toon Module
   * @param[in] level  Profiling granularity (0 = named groups only, 1 = per-method + named)
  */
  void CaseToon(int level=0);

  /*!
   * @brief   Initiates the Test for the Utilz Module
   * @param[in] level  Profiling granularity (0 = named groups only, 1 = per-method + named)
  */
  void CaseUtilz(int level=0);

  /*!
   * @brief   Initiates the Test for the Weapon Module
   * @param[in] level  Profiling granularity (0 = named groups only, 1 = per-method + named)
  */
  void CaseWeapon(int level=0);

  /*!
   * @brief   Default Deconstructor
  */
  ~TestSuite();
};

#endif // TESTER_H //
