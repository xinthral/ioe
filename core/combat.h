#ifndef COMBAT_H
#define COMBAT_H

#include "balance.h"
#include "config.h"
#include "logger.h"
#include "player.h"
#include "toon.h"

//! Combat Condition
enum Condition { EvE, PvE, PvP };
struct fighter {
  int health;
  int attack;
  int defense;
  // int speed; 
};

class Combat {
protected:
  struct fighter f1;
  struct fighter f2;

private:
  BalanceController*  bal;
  ConfigManager*      cnf;
  Logger*             log;
  Condition           matchup;
  char                buf[256];

public:
  Combat();
  Combat(Toon&, Toon&);
  Combat(Player&, Toon&);
  Combat(Player&, Player&);
  void begin_combat();
  void injest_combatants(Actor&, Actor&);
  void _help();
  ~Combat();
};

#endif // COMBAT_H //
