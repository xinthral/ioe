#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>
#include "../core/config.h"
#include "../core/logger.h"
#include "../core/utilz.h"

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