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
public:
  HelpSuite();
  HelpSuite(bool);
  void HelpAll();
  void HelpActor();
  void _help();
  ~HelpSuite();
};

//! Static Display Function
void print_help();

#endif // HELPER_H //