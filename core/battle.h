#ifndef BATTLE_H
#define BATTLE_H

#include <mutex>
#include "combat.h"
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

  static Battle*    _singleton;     //!< Singleton Instance
  static std::mutex _mutex;         //!< Lock Mutex
  Logger*   log;                    //!< Logging Handler Instantiation
  Combat*   combat;
  int       cycleCompletionTracker;

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
