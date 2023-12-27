#ifndef HELPCONFIG_H
#define HELPCONFIG_H

#include "basehelp.h"

class HelpConfig : public BaseHelp {
protected:
private:
  ConfigManager* _cnf;
public:
  HelpConfig();
  ~HelpConfig();
};

#endif // HELPCONFIG_H //