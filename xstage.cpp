#include "xstage.h"

// Singleton Instance
StageManager* StageManager::_singleton = NULL;
std::mutex StageManager::_mutex;

StageManager::StageManager(const std::string _name) : name(_name) {
    printf("StageManager Established: %s\n", this->name.c_str());
}

StageManager* StageManager::GetInstance(const std::string& name) {
    // Acquire Instance Mutex
    std::lock_guard<std::mutex> lock(_mutex);
    // If singleton already exists, return instance
    if (_singleton == NULL) { _singleton = new StageManager(name); }
    return _singleton;
}

std::string StageManager::get_name() { return this->name; }

void StageManager::casting_call() {
    
}