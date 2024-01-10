#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>
#include <string.h>
#include "../core/actor.h"
#include "../core/balance.h"
#include "../core/battle.h"
#include "../core/combat.h"
#include "../core/config.h"
#include "../core/item.h"
#include "../core/leader.h"
#include "../core/logger.h"
#include "../core/player.h"
#include "../core/stage.h"
#include "../core/toon.h"
#include "../core/utilz.h"
#include "actorhelp.h"
#include "balancehelp.h"
#include "battlehelp.h"
#include "combathelp.h"
#include "confighelp.h"
#include "itemhelp.h"
#include "leaderhelp.h"
#include "playerhelp.h"
#include "stagehelp.h"
#include "toonhelp.h"
#include "utilzhelp.h"

/*!
 * @class   HelpSuite helpsuite.h helpsuite.cpp
 * @brief   Command Line Tool (CLI) for the HelpSuite
 * @details Helper Suite is meant to parse Doxygen outputs, and 
 *      provide a commandline utility for quick reference 
 *      while developing or debugging.
*/
class HelpSuite {
protected:
  ConfigManager*    cnf;  //!< Instantiated ConfigManager Object
  Logger*           log;  //!< Instantiated Logger Object

private:
public:
  /*!
   * @brief   Default Constructor
  */
  HelpSuite();

  /*!
   * @overload
   * @brief   Debugging Constructor
   * @param[in] _debug Debugging option 
  */
  HelpSuite(bool);
  void HelpAll();
  void ActorHelp();
  void BattleHelp();
  void BalanceHelp();
  void CombatHelp();
  void ConfigHelp();
  void ItemHelp();
  void LeaderHelp();
  void PlayerHelp();
  void StageHelp();
  void ToonHelp();
  void UtilzHelp();

  /*!
   * @brief   Helper hook for CLI Tool to display help details
  */
  void _help();

  /*!
   * @brief   Default Deconstructor
  */
  ~HelpSuite();
};

/*!
 * @brief   Static Function to display help details
*/
void print_help();

#endif // HELPER_H //