#ifndef BATTLE_H
#define BATTLE_H

#include <mutex>
#include "combat.h"
#include "config.h"
#include "player.h"
#include "toon.h"

/*!
 * @class   Battle battle.h battle.cpp
 * @brief   Singleton battlefield manager that orchestrates turn-based Combat sessions
 * @details Owns a single active Combat instance at a time. Callers start a session
 *          with startEVE / startPVE / startPVP, then drive it forward by calling
 *          doCycleWork() in a loop until isPendingWork is set to false.
*/
class Battle {
protected:
private:
  /*!
   * @brief   Singleton Constructor
  */
  Battle();
  ConfigManager*    cnf;
  Combat*           combat;                 //!< Combat Handler
  Logger*           log;                    //!< Logging Handler Instantiation
  static Battle*    _singleton;             //!< Singleton Instance
  static std::mutex _mutex;                 //!< Lock Mutex
  int               cycleCompletionTracker;
  int               cycleDelay;             //!< Delay between battle operations

public:
  //! Singletons should not be cloneable
  Battle(Battle&) = delete;

  //! Singletons should not be assignable
  void operator = (const Battle&) = delete;

  /*!
   * @brief   Singleton Constructor
  */
  static Battle* GetInstance();

  /*!
   * @brief   Advance the active combat session by one cycle
   * @details Calls cycleCombat() on the current Combat instance. Sets isPendingWork
   *          to false and releases the Combat object when inCombat() returns false,
   *          signalling that a winner has been decided.
   * @param[out] isPendingWork  Set to false when combat concludes; unchanged otherwise
  */
  void doCycleWork(bool& isPendingWork);

  /*!
   * @brief   Initialise an NPC vs NPC combat session
   * @param[in] t1  First Toon combatant
   * @param[in] t2  Second Toon combatant
  */
  void startEVE(Toon* t1, Toon* t2);

  /*!
   * @brief   Initialise a Player vs NPC combat session
   * @param[in] player  Player combatant
   * @param[in] t       Toon combatant
  */
  void startPVE(Player* player, Toon* t);

  /*!
   * @brief   Initialise a Player vs Player combat session
   * @param[in] player1  First Player combatant
   * @param[in] player2  Second Player combatant
  */
  void startPVP(Player* player1, Player* player2);

  /*!
   * @brief   Helper Hook used in CLI Help System
  */
  void _help();

  /*!
   * @brief   Default Deconstructor
  */
  ~Battle();
};

#endif // BATTLE_H //
