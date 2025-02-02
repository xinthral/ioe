#ifndef TESTER_H
#define TESTER_H

#include <stdio.h>
#include <string.h>
#include <thread>
#include "actorcase.h"
#include "audiocase.h"
#include "balancecase.h"
#include "battlecase.h"
#include "clockcase.h"
#include "cipherscase.h"
#include "combatcase.h"
#include "configcase.h"
#include "itemcase.h"
#include "leadercase.h"
#include "lexiconcase.h"
#include "playercase.h"
#include "profiler.h"
#include "stagecase.h"
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
  char buf[32];
private:
public:
  /*!
   * @brief   Default Constructor
  */
  TestSuite();

  void TestAll();

  /*!
   * @brief   Initiates the Test for the Actor Module
  */
  void CaseActor();

  /*!
   * @brief   Initiates the Test for the Audio Module
  */
  void CaseAudio();

  /*!
   * @brief   Initiates the Test for the BalanceController Module
  */
  void CaseBalance();

  /*!
   * @brief   Initiates the Test for the BattleManager Module
  */
  void CaseBattle();

  /*!
   * @brief   Initiates the Test for the Engine's Clock
  */
  void CaseClock();

  /*!
   * @brief   Initiates the Test for the Ciphers Module
  */
  void CaseCiphers();

  /*!
   * @brief   Initiates the Test for the Combat Module
  */
  void CaseCombat();

  /*!
   * @brief   Initiates the Test for the ConfigManager Module
  */
  void CaseConfig();

  /*!
   * @brief   Initiates the Test for the Item Module
  */
  void CaseItem();

  /*!
   * @brief   Initiates the Test for the LeaderBoard Module 
  */
  void CaseLeader();

  /*!
   * @brief   Initiates the Test for the Lexicon Module 
  */
  void CaseLexicon();

  /*!
   * @brief   Initiates the Test for the Player Module
  */
  void CasePlayer();

  /*!
   * @brief   Initiates the Test for the StageManager Module
  */
  void CaseStage();

  /*!
   * @brief   Initiates the Test for the Toon Module
  */
  void CaseToon();

  /*!
   * @brief   Initiates the Test for the Utilz Module
  */
  void CaseUtilz();

  /*!
   * @brief   Initiates the Test for the Weapon Module
  */
  void CaseWeapon();

  /*!
   * @brief   Default Deconstructor
  */
  ~TestSuite();
};

#endif // TESTER_H //
