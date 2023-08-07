/*!
 * @class   Logger logger.h logger.cpp
 * @brief   Logger Management module
*/
#include "logger.h"

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
 * @brief   Helper Hook used in CLI Help System
*/
void Logger::_help() { }

/*!
 * @brief   Default Deconstructor
*/
Logger::~Logger() {}