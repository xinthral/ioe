#ifndef XCLOCK_H
#define XCLOCK_H

#include <mutex>
#include "balance.h"
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
  static xClock* _singleton;  //!< Singleton Instance
  static std::mutex _mutex;   //!< Lock Mutex 
  ConfigManager*  cnf;        //!< ConfigManager Instantiation
  Logger*         log;        //!< Logging Handler Instantiation
  char            buf[1024];  //!< Buffer Value for Logger outputs
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
   * @brief   Helper Hook used in CLI Help System
  */
  void _help();

  /*!
   * @brief   Default Deconstructor 
  */
  ~xClock();
};

#endif // XCLOCK_H //