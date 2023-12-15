/*!
 * @class   LeaderBoard leader.cpp leader.h
 * @brief   LeaderBoard stuff
*/

#include "leader.h"

//! Singleton Instance 
LeaderBoard* LeaderBoard::_singleton = NULL;
std::mutex LeaderBoard::_mutex;

/*!
 * @brief   Protected Constructor 
*/
LeaderBoard::LeaderBoard() { 
    log = Logger::GetInstance();
    log->named_log(__FILE__, "LeaderBoard Established.");
}

/*!
 * @brief   Singleton Constructor 
*/
LeaderBoard* LeaderBoard::GetInstance() {
    // Acquire Instance Mutex
    std::lock_guard<std::mutex> lock(_mutex);
    // If singleton already exists, return instance
    if (_singleton == NULL) { _singleton = new LeaderBoard(); }
    return _singleton;
}

/*!
 * @brief   Helper Hook used in CLI Help System
*/
void LeaderBoard::_help() { }

LeaderBoard::~LeaderBoard() { }
