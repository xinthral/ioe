#ifndef STAGE_H
#define STAGE_H

#include <mutex>
#include <stdio.h>
#include <string>
#include <vector>
#include "logger.h"
#include "toon.h"

/*!
 * @class   StageManager stage.h stage.cpp
 * @brief   StageManager controls the entirety of whom
 *          is active on the stage for any given scene.
*/
class StageManager {
protected:
  /*!
   * @brief   Protected Constructor
  */
  StageManager(const std::string);

private:
  static StageManager*  _singleton;                       //!< Singleton Instance
  static std::mutex     _mutex;                           //!< Mutex Lock
  Logger*               log;                              //!< Logging Handler Instantiation
  std::string           name;
  int                   maxCrew;
  char                  buf[1024];                        //!< Buffer Value for Logger outputs

public:
  //!< Singletons should not be cloneable
  StageManager(StageManager&) = delete;

  //!< Singletons should not be assignable
  void operator = (const StageManager&) = delete;

  /*!
   * @brief   Singleton Constructor
  */
  static StageManager *GetInstance(const std::string&);

  /*!
   * @brief   Returns the name attribute
   * @return  Name Value
  */
  std::string get_name();

  /*!
   * @brief   StageManager Loads the Scene with Actors
  */
  void casting_call(int, std::vector<Toon*>&);

  /*!
   * @brief   Helper Hook used in CLI Help System
  */
  void _help();

  /*!
   * @brief   Default Constructor
  */
  ~StageManager();
};

#endif // STAGE_H //
