#ifndef BATTLE_H
#define BATTLE_H

#include "combat.h"
#include "player.h"
#include "toon.h"

class Battle {
protected:
private:
public:
    Battle();
    Battle(int, Player*, std::vector<Toon*>&);
    ~Battle();
};

#endif // BATTLE_H //