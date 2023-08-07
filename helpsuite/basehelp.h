#ifndef BASEHELP_H
#define BASEHELP_H

#include "../core/config.h"
#include "../core/balance.h"
#include "../core/logger.h"

class BaseHelp {
protected:
    BalanceController*  bal;
    ConfigManager*      cnf;
    Logger*             log;
    char buf[512];

private:
public:
    BaseHelp();
    ~BaseHelp();
};

#endif // BASEHELP_H //