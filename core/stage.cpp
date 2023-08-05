#include "stage.h"

// Singleton Instance
StageManager* StageManager::_singleton = NULL;
std::mutex StageManager::_mutex;

/**
 * Protected Constructor
*/
StageManager::StageManager(const std::string _name) : name(_name) {
    log = Logger::GetInstance();
    sprintf(buf, "StageManager Established: %s", this->name.c_str());
    log->named_log(Utilz::FileName(__FILE__), buf);
}


/**
 * Singleton Constructor
*/
StageManager* StageManager::GetInstance(const std::string& name) {
    // Acquire Instance Mutex
    std::lock_guard<std::mutex> lock(_mutex);
    // If singleton already exists, return instance
    if (_singleton == NULL) { _singleton = new StageManager(name); }
    return _singleton;
}

/**
 * Returns the name attribute
 * @return :<str|name>
*/
std::string StageManager::get_name() { return this->name; }

void StageManager::casting_call() { }


/**
 * Helper Hook used in CLI Help System
*/
void StageManager::_help() { }

/**
 * Default Constructor
*/
StageManager::~StageManager() { }