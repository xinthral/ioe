#ifndef COMBAT_H
#define COMBAT_H

#include <unistd.h>
#include "balance.h"
#include "config.h"
#include "logger.h"
#include "player.h"
#include "toon.h"

enum Condition { EvE, PvE, PvP };

class Combat {
private:
    BalanceController*  bal;
    ConfigManager*      cnf;
    Logger*             log;
    Condition matchup;
    char buf[1024];

public:
    Combat();
    Combat(Toon&, Toon&);
    Combat(Player&, Toon&);
    Combat(Player&, Player&);
    void begin_combat();
    ~Combat();
};

#endif // COMBAT_H //