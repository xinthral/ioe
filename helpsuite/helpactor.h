#ifndef HELPACTOR_H
#define HELPACTOR_H

#include "helpbase.h"

class HelpActor {
protected:
  ConfigManager*    cnf;
  Logger*           log;
private:
public:
  HelpActor();
  ~HelpActor();
};

#endif  // HELPACTOR_H //
