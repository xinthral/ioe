#ifndef BASEHELP_H
#define BASEHELP_H

#include "../config.h"
#include "../balance.h"
#include "../logger.h"

class BaseHelp {
protected:
    BalanceController* bal;
    ConfigManager* cnf;
    Logger* log;
    char buf[1024];

private:
public:
    BaseHelp();
    ~BaseHelp();
};

#endif // BASEHELP_H //