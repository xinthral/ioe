#ifndef XCOMBAT_H
#define XCOMBAT_H

#include "xbalance.h"
#include "xplayer.h"
#include "xtoon.h"

class Combat {
private:
    BalanceController* balance;
public:
    Combat();
    Combat(Toon&, Toon&);
    Combat(Player&, Toon&);
    Combat(Player&, Player&);
    ~Combat();
};

#endif // XCOMBAT_H //