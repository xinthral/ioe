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
   * @brief Default Constructor for the Combat class.
   *
   * Initializes the Combat class with default values for the BalanceController,
   * ConfigManager, Logger, Condition, combatant1, combatant2, and buf.
   *
   * @param None
   * @return None
  */
  Combat();

  /*!
   * @overload
   * @brief Constructor for the Combat class in EvE (Enemy vs Enemy) mode.
   *
   * This constructor initializes the Combat class for two Toon characters in an EvE matchup.
   * It sets the matchup condition to EvE and injests the provided combatants.
   *
   * @param[in] toon1 - A pointer to the first Toon character participating in the combat.
   * @param[in] toon2 - A pointer to the second Toon character participating in the combat.
   * @return None
  */
  Combat(Toon*, Toon*);

  /*!
   * @overload
   * @brief Constructor for the Combat class in PvE (Player vs Enemy) mode.
   *
   * This constructor initializes the Combat class for two Toon characters in an PvE matchup.
   * It sets the matchup condition to PvE and injests the provided combatants.
   *
   * @param[in] Player - A pointer to the Player character participating in the combat.
   * @param[in] toon   - A pointer to the Toon character participating in the combat.
   * @return None
  */
  Combat(Player*, Toon*);

  /*!
   * @overload
   * @brief Constructor for the Combat class in PvP (Player vs Player) mode.
   *
   * This constructor initializes the Combat class for two Player characters in a PvP matchup.
   * It sets the matchup condition to PvP and injects the provided combatants.
   *
   * @param[in] player1 - A pointer to the first Player character participating in the combat.
   * @param[in] player2 - A pointer to the second Player character participating in the combat.
   *
   * @return None
   */
  Combat(Player*, Player*);

  /*!
   * @brief Checks if there is an ongoing combat.
   *
   * This function determines if there is currently a combat between two combatants.
   * It checks if both combatant1 and combatant2 are not nullptr and if their healths are greater than zero.
   *
   * @return bool - Returns true if combat is ongoing (both combatants are valid and alive), otherwise returns false.
  */
  bool inCombat();

  bool validFighters(Actor*, Actor*);

  /*!
   * @brief Initiates Combat
   *
   * This function orchestrates the combat between two combatants based on the matchup condition.
   * It repeatedly calls the combat round until one of the combatants' health drops to zero or below.
   *
   * @return void - This function does not return any value.
   */
  void cycleCombat();

  /*!
   * @brief   Intakes Combatants
  */
  void injestCombatants(Actor*, Actor*);

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
