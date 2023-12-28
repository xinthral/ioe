/*!
 * @class   Logger logger.h logger.cpp
 * @brief   Logger Management module
*/
#include "logger.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

//! Global Variables
const std::string Logger::DELIM = " :=: ";

//! Singleton Instance
Logger* Logger::_singleton = NULL;
std::mutex Logger::_mutex;

/*!
 * @brief   Protected Constructor
*/
Logger::Logger() {}

/*!
 * @brief   Singleton Constructor
*/
Logger* Logger::GetInstance() {
  //! Acquire Instance Mutex
  std::lock_guard<std::mutex> lock(_mutex);
  //! If singleton already exists, return instance
  if (_singleton == NULL) { _singleton = new Logger(); }
  return _singleton;
}

/*!
 * @brief   Log attach with an alert level
*/
void Logger::alert_log(std::string level, std::string message) {}

/*!
 * @brief   Labeled and Stamped Logging
*/
void Logger::named_log(std::string fileName, std::string message) {
  std::string time = Utilz::TimeStamp();
  char tmp[1024];
  std::sprintf(tmp, 
    "%s :: _%s_ :: %s", 
    time.c_str(), 
    Utilz::FileName(fileName.c_str()).c_str(),
    message.c_str()
  );
  this->raw_log(tmp);
}

/*!
 * @brief   Raw Unformatted Logging
*/
void Logger::raw_log(std::string message) {
  printf("%s\n", message.c_str());
}

/*!
 * @brief   TimeStamped Logging
*/
void Logger::timed_log(std::string message) {
  std::string time = Utilz::TimeStamp();
  char tmp[1024];
  std::sprintf(tmp, "%s :: %s", time.c_str(), message.c_str());
  this->raw_log(tmp);
}

/*!
 * @brief   Helper Hook used in CLI Help System
*/
void Logger::_help() {
  std::string helpline = "\nLogger Helpline!\n";
  helpline += "\n\tUnimplemented";
  helpline += "\n";
  this->named_log(__FILENAME__, helpline);
}

/*!
 * @brief   Default Deconstructor
*/
Logger::~Logger() { }
