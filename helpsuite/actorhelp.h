#ifndef HELPACTOR_H
#define HELPACTOR_H 

#include "basehelp.h"

class HelpActor : public BaseHelp {
protected:
  Actor* dummy;
private:
public:
  HelpActor();
  ~HelpActor();
};

#endif  // HELPACTOR_H //
