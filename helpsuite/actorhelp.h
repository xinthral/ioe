#ifndef ACTORHELP_H
#define ACTORHELP_H 

#include "basehelp.h"
#include "../core/actor.h"

class ActorHelp : public BaseHelp {
protected:
  ConfigManager*    cnf;
  Logger*           log;
private:
public:
  ActorHelp();
  ~ActorHelp();
};

#endif  // ACTORHELP_H //
