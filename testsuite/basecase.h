#ifndef BASECASE_H
#define BASECASE_H

#include <cassert>
#include <iostream>
#include <string.h>
#include <vector>
#include "../core/actor.h"
#include "../core/balance.h"
#include "../core/config.h"
#include "../core/logger.h"
#include "../core/utilz.h"

//! Compiler/Linter hint
#define assertm(exp, msg) assert(((void)msg, exp))

class BaseCase {
protected:
  BalanceController*  bal;    //!< Instantiated BalanceController Object
  ConfigManager*      cnf;    //!< Instantiated ConfigManager Object
  Logger*             log;    //!< Instantiated Logger Object
  char buf[256];

public:
  BaseCase();
  BaseCase(const char*);
  ~BaseCase();
};

#endif  // BASECASE_H //
