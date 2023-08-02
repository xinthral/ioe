#include "xlogger.h"

const std::string Logger::DELIM = " :=: ";

/* Singleton Instance */
Logger* Logger::_singleton = NULL;
std::mutex Logger::_mutex;

Logger::Logger() {}

Logger* Logger::GetInstance() {
    // Acquire Instance Mutex
    std::lock_guard<std::mutex> lock(_mutex);
    // If singleton already exists, return instance
    if (_singleton == NULL) { _singleton = new Logger(); }
    return _singleton;
}

void Logger::raw_log(std::string message) {
    printf("%s\n", message.c_str());
}

void Logger::formed_log(std::string message) {
    std::string time = Utilz::TimeStamp();
    char tmp[1024];
    std::sprintf(tmp, "%s :: %s", time.c_str(), message.c_str());
    this->raw_log(tmp);
}

void Logger::named_log(std::string fileName, std::string message) {
    std::string time = Utilz::TimeStamp();
    char tmp[1024];
    std::sprintf(tmp, "%s :: _%s_ :: %s", time.c_str(), Utilz::FileName(fileName.c_str()).c_str(), message.c_str());
    this->raw_log(tmp);
}

Logger::~Logger() {}