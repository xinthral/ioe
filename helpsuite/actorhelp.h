#ifndef HELPACTOR_H
#define HELPACTOR_H 

#include "basehelp.h"
#include "../core/actor.h"

class HelpActor : public BaseHelp {
protected:
  Actor*            dummy;
  ConfigManager*    cnf;
  Logger*           log;
private:
public:
  HelpActor();
  ~HelpActor();
};

#endif  // HELPACTOR_H //
