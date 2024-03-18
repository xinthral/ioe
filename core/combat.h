#ifndef COMBAT_H
#define COMBAT_H

#include <thread>
#include "balance.h"
#include "config.h"
#include "logger.h"
#include "player.h"
#include "toon.h"

//! Combat Condition
enum Condition { EvE, PvE, PvP };
struct fighter {
  std::string name;
  int health;
  int attack;
  int defense;
  // int speed; 
};

/*!
 * @class   Combat combat.h combat.cpp
 * @brief   Handle the interactive logic for Combat
*/
class Combat {
protected:
  // struct fighter f1;
  // struct fighter f2;

private:
  BalanceController*  bal;      //!< BalanceController Instantiation
  ConfigManager*      cnf;      //!< ConfigManager Instantiation
  Logger*             log;      //!< Logging Handler Instantiation
  Condition           matchup;
  Actor*              combatant1;
  Actor*              combatant2;
  char                buf[256];

public:
  /*!
   * @brief   Default Constructor
  */
  Combat();

  /*!
   * @overload
   * @brief   EvE Constructor
  */
  Combat(Toon*, Toon*);

  /*!
   * @overload
   * @brief   PvE Constructor
  */
  Combat(Player*, Toon*);

  /*!
   * @overload
   * @brief   PvP Constructor
  */
  Combat(Player*, Player*);

  bool inCombat();
  
  /*!
   * @brief   Initiates Combat
  */
  void cycle_combat();

  /*!
   * @brief   Intakes Combatants
  */
  void injest_combatants(Actor*, Actor*);

  /*!
   * @brief   Helper Hook used in CLI Help System
  */
  void _help();

  /*!
   * @brief   Default Deconstructor
  */
  ~Combat();
};

#endif // COMBAT_H //
