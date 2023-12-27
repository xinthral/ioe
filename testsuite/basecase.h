#ifndef BASECASE_H
#define BASECASE_H

#include <cassert>
#include <iostream>
#include <string.h>
#include <vector>
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

//! Compiler/Linter hint
#define assertm(exp, msg) assert(((void)msg, exp))

class BaseCase {
protected:
  BalanceController*  bal;    //!< Instantiated BalanceController Object
  ConfigManager*      cnf;    //!< Instantiated ConfigManager Object
  Logger*             log;    //!< Instantiated Logger Object
  char                buf[1024];

public:
  BaseCase();
  BaseCase(const char*);
  ~BaseCase();
};

#endif  // BASECASE_H //
