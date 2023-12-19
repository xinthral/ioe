#ifndef HELPBALANCE_H
#define HELPBALANCE_H

#include "basehelp.h"

class HelpBalance : public BaseHelp {
protected:
BalanceController* bal;
private:
public:
  HelpBalance();
  ~HelpBalance();
};

#endif // HELPBALANCE_H //