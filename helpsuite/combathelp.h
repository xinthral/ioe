#ifndef HELPCOMBAT_H
#define HELPCOMBAT_H

#include "basehelp.h"

class HelpCombat : public BaseHelp {
protected:
private:
  Combat* cc;
public:
  HelpCombat();
  ~HelpCombat();
};

#endif // HELPCOMBAT_H //