#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>
#include <string.h>
#include "../core/actor.h"
#include "../core/balance.h"
#include "../core/battle.h"
#include "../core/combat.h"
#include "../core/config.h"
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
#include "leaderhelp.h"
#include "playerhelp.h"
#include "stagehelp.h"
#include "toonhelp.h"
#include "utilzhelp.h"

class HelpSuite {
protected:
  ConfigManager*    cnf;  //!< Instantiated ConfigManager Object
  Logger*           log;  //!< Instantiated Logger Object
public:
  HelpSuite();
  HelpSuite(bool);
  void HelpAll();
  void ActorHelp();
  void BattleHelp();
  void BalanceHelp();
  void CombatHelp();
  void ConfigHelp();
  void LeaderHelp();
  void PlayerHelp();
  void StageHelp();
  void ToonHelp();
  void UtilzHelp();
  void _help();
  ~HelpSuite();
};

//! Static Display Function
void print_help();

#endif // HELPER_H //