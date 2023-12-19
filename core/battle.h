#ifndef BATTLE_H
#define BATTLE_H

#include "combat.h"
#include "player.h"
#include "toon.h"

class Battle {
protected:
  Logger*   log;
private:
public:
  Battle();
  Battle(int, Player*, std::vector<Toon*>&);
  Battle(std::vector<Toon*>&, std::vector<Toon*>&);
  void _help();
  ~Battle();
};

#endif // BATTLE_H //
