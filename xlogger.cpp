#include "xlogger.h"

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

Logger::~Logger() {}