/*!
 * @class   StageManager stage.h stage.cpp
 * @brief   The stage manager controls the entirety of whom
 *          is active on the stage for any given scene.
*/
#include "stage.h"

//! Singleton Instance
StageManager* StageManager::_singleton = NULL;
std::mutex StageManager::_mutex;

/*!
 * @brief   Protected Constructor
*/
StageManager::StageManager(const std::string _name) : name(_name) {
    log = Logger::GetInstance();
    sprintf(buf, "StageManager Established: %s", this->name.c_str());
    log->named_log(Utilz::FileName(__FILE__), buf);
}


/*!
 * @brief   Singleton Constructor
*/
StageManager* StageManager::GetInstance(const std::string& name) {
    //! Acquire Instance Mutex
    std::lock_guard<std::mutex> lock(_mutex);
    //! If singleton already exists, return instance
    if (_singleton == NULL) { _singleton = new StageManager(name); }
    return _singleton;
}

/*!
 * @brief   Returns the name attribute
 * @return  Name Value
*/
std::string StageManager::get_name() { return this->name; }

/*!
 * @brief   StageManager Loads the Scene with Actors
 * @note    FIXME
*/
void StageManager::casting_call() { }


/*!
 * @brief   Helper Hook used in CLI Help System
*/
void StageManager::_help() { }

/**
 * @brief   Default Constructor
*/
StageManager::~StageManager() { }