#ifndef XCLOCK_H
#define XCLOCK_H

#include <chrono>
#include <mutex>
#include <thread>
#include "balance.h"
#include "battle.h"
#include "combat.h"
#include "config.h"

/*!
 * @class   xClock clock.h clock.cpp
 * @brief   xClock handles timing amongst the chaos and 
 *          otherwise manipulating the temporal dimension.
 * @details needs desc
*/
class xClock {
protected:
  /*!
   * @brief   Singleton Constructor 
  */
  xClock();

private:
  static xClock*    _singleton;     //!< Singleton Instance
  static std::mutex _mutex;         //!< Lock Mutex 
  Battle*           battle;         //!< Battle Instantiation
  ConfigManager*    cnf;            //!< ConfigManager Instantiation
  Logger*           log;            //!< Logging Handler Instantiation
  char              buf[128];       //!< Buffer Value for Logger outputs
  bool              isPendingWork;  //!< Tracks if there is Cycle Work Pending

public:
  //! Singletons should not be cloneable
  xClock(xClock&) = delete;

  //! Singletons should not be assignable
  void operator = (const xClock&) = delete;

  /*!
   * @brief   Singleton Constructor 
  */
  static xClock* GetInstance();

  /*!
   * @todo    Returns if cycle work is still pending
  */
  bool getPendingWorkState();

  /*!
   * @todo    Perform Cycle Work
  */
  void doCycleWork();

  /*!
   * @brief   Helper Hook used in CLI Help System
  */
  void _help();

  /*!
   * @brief   Default Deconstructor 
  */
  ~xClock();
};

#endif // XCLOCK_H //