#ifndef XCOMBAT_H
#define XCOMBAT_H

#include <windows.h>
#include <unistd.h>
// #include <thread>
#include "xbalance.h"
#include "xconfig.h"
#include "xlogger.h"
#include "xplayer.h"
#include "xtoon.h"

enum Condition { EvE, PvE, PvP };

class Combat {
private:
    BalanceController* balance;
    ConfigManager* cm;
    Logger* log;
    Condition matchup;
public:
    Combat();
    Combat(Toon&, Toon&);
    Combat(Player&, Toon&);
    Combat(Player&, Player&);
    void begin_combat();
    ~Combat();
};

#endif // XCOMBAT_H //