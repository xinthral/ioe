#ifndef HELPBASE_H 
#define HELPBASE_H

#include "../core/actor.h"
#include "../core/audio.h"
#include "../core/balance.h"
#include "../core/battle.h"
#include "../core/config.h"
#include "../core/item.h"
#include "../core/logger.h"
#include "../core/player.h"
#include "../core/stage.h"
#include "../core/toon.h"
#include "../core/utilz.h"

/*!
 * @class   BaseHelp helpbase.h helpbase.cpp 
 * @brief   Base Class for the HelpSuite Module
*/
class BaseHelp {
protected:
  BalanceController*  bal;        //!< Instantiated BalanceController Object
  ConfigManager*      cnf;        //!< Instantiated ConfigManager Object
  Logger*             log;        //!< Instantiated Logger Object
  char                buf[1024];  //!< Buffer Value for Logger outputs

private:
public:
  /*!
   * @brief   Default Constructor
  */
  BaseHelp();

  /*!
   * @brief   Default Deconstructor
  */
  ~BaseHelp();
};

#endif // HELPBASE_H //