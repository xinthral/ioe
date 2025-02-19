#ifndef BATTLE_H
#define BATTLE_H

#include <mutex>
#include "combat.h"
#include "config.h"
#include "player.h"
#include "toon.h"

/*! 
 * @class   Battle battle.h battle.cpp
 * @brief   Interweaving Combat events
*/
class Battle {
protected:
private:
  /*! 
   * @brief   Singleton Constructor
  */
  Battle();

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
   * @brief   Handles Cycle Actions
  */
  void doCycleWork(bool&);

  void startEVE(Toon*,Toon*);
  void startPVE(Player*,Toon*);
  void startPVP(Player*,Player*);

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
