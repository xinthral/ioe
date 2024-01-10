#ifndef XLOGGER_H
#define XLOGGER_H

#include <stdio.h>
#include <mutex>
#include <string>
#include <unordered_map>
#include "utilz.h"

/*!
 * @class   Logger logger.h logger.cpp
 * @brief   Logger Management module
*/
class Logger {
protected:
  /*!
   * @brief   Protected Constructor
  */
  Logger();

private:
  std::unordered_map<
      std::string, std::string
  > settings;                                 //!< Key-Value Lookup Map
  static const std::string DELIM;             //!< Global Variables
  static Logger* _singleton;                  //!< Singleton Instance
  static std::mutex _mutex;                   //!< Mutex Lock
  char buf[1024];                             //!< Buffer Value for Logger outputs

public:
  //!< Singletons should not be cloneable
  Logger(Logger&) = delete;

  //!< Singletons should not be assignable
  void operator =(const Logger&) = delete;

  /*!
   * @brief   Singleton Constructor
  */
  static Logger* GetInstance();

  /*!
   * @brief   Log attach with an alert level
  */
  void alert_log(std::string,std::string);

  /*!
   * @brief   Labeled and Stamped Logging
  */
  void named_log(std::string,std::string); 

  /*!
   * @brief   Raw Unformatted Logging
  */
  void raw_log(std::string);

  /*!
   * @brief   TimeStamped Logging
  */
  void timed_log(std::string);

  /*!
   * @brief   Helper Hook used in CLI Help System
  */
  void _help();

  /*!
   * @brief   Default Deconstructor
  */
  ~Logger();
};

#endif // XLOGGER_H //
