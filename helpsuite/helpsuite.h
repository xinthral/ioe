#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>
#include <string.h>
#include "../core/config.h"
#include "../core/logger.h"
#include "../core/utilz.h"
#include "actorhelp.h"

class HelpSuite {
protected:
  ConfigManager*    cnf;
  Logger*           log;
  char helpmsg[1024];
public:
  HelpSuite();
  HelpSuite(bool);
  void HelpActor();
  void _help(char *);
  ~HelpSuite();
};

#endif // HELPER_H //