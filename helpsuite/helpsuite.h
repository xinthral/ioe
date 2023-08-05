#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>
#include "../config.h"
#include "../logger.h"

class HelpSuite {
protected:
    ConfigManager* cnf;
    Logger* log;
public:
    HelpSuite();
    HelpSuite(bool);
    ~HelpSuite();
};

#endif // HELPER_H //