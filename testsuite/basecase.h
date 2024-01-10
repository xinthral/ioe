#ifndef BASECASE_H
#define BASECASE_H

#include <cassert>
#include <string.h>
#include <vector>
#include "../core/actor.h"
#include "../core/audio.h"
#include "../core/balance.h"
#include "../core/battle.h"
#include "../core/ciphers.h"
#include "../core/combat.h"
#include "../core/config.h"
#include "../core/item.h"
#include "../core/leader.h"
#include "../core/lexicon.h"
#include "../core/logger.h"
#include "../core/player.h"
#include "../core/stage.h"
#include "../core/toon.h"
#include "../core/utilz.h"

//! Compiler/Linter hint
#define assertm(exp, msg) assert(((void)msg, exp))

/*!
 * @class   BaseCase basecase.h basecase.cpp
 * @brief   Base Testing Case for TestSuite Module  
*/
class BaseCase {
protected:
  BalanceController*  bal;          //!< Instantiated BalanceController Object
  ConfigManager*      cnf;          //!< Instantiated ConfigManager Object
  Logger*             log;          //!< Instantiated Logger Object
  char                buf[1024];    //!< Buffer Value for Logger outputs
  char                msgHead[32];  //!< Unified prefix for test
  char                msgNote[64];  //!< Unified buffer for test
  char                msgTail[16];  //!< Unified suffix for test

public:

  /*!
   * @brief   Default Constructor 
  */
  BaseCase();

  /*!
   * @brief   Overloaded Constructor
   * @param[in] casename - Name of Case being initiated
  */
  BaseCase(const char*);

  /*!
   * @brief   Default Deconstructor 
  */
  ~BaseCase();
};

#endif  // BASECASE_H //
