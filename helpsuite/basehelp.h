#ifndef HELPBASE_H 
#define HELPBASE_H

#include "../core/actor.h"
#include "../core/config.h"
#include "../core/balance.h"
#include "../core/logger.h"

class BaseHelp {
protected:
  BalanceController*    bal;
  ConfigManager*        cnf;
  Logger*               log;
  char buf[512];

private:
public:
  BaseHelp();
  ~BaseHelp();
};

#endif // HELPBASE_H //