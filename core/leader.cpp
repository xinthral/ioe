/*!
 * @class   LeaderBoard leader.cpp leader.h
 * @brief   LeaderBoard is a statistical culmination of player interactions in any
 *          given session. Evaluate interesting data points like largest or fastest
 *          damage, or people who hit the hardest/were hit the hardest, etc...
*/

#include "leader.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

//! Singleton Instance 
LeaderBoard* LeaderBoard::_singleton = NULL;
std::mutex LeaderBoard::_mutex;

/*!
 * @brief   Protected Constructor 
*/
LeaderBoard::LeaderBoard() { 
    log = Logger::GetInstance();
    log->named_log(__FILENAME__, "LeaderBoard Established.");
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
void LeaderBoard::_help() { 
  std::string helpline = "\nLeaderBoard Helpline!\n";
  helpline += "\n";
  log->named_log(__FILENAME__, helpline);
}

LeaderBoard::~LeaderBoard() { }
