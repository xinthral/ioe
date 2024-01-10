#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <mutex>
#include "logger.h"

/*!
 * @class   LeaderBoard leader.cpp leader.h
 * @brief   LeaderBoard is a statistical culmination of player interactions in any
 *          given session. Evaluate interesting data points like largest or fastest
 *          damage, or people who hit the hardest/were hit the hardest, etc...
*/
class LeaderBoard {
protected:
  /*!
   * @brief   Protected Constructor 
  */
  LeaderBoard();

private:
  static LeaderBoard* _singleton; //!< Singleton Instance
  static std::mutex   _mutex;     //!< Lock Mutex
  Logger*             log;        //!< Logging Handler Instantiation
  char                buf[1024];  //!< Buffer Value for Logger outputs

public:
  //! Singletons should not be cloneable
  LeaderBoard(LeaderBoard&) = delete;

  //!< Singletons should not be assignable
  void operator=(const LeaderBoard&) = delete;

  //!< Singleton Constructor
  static LeaderBoard* GetInstance();

  /*!
   * @brief   Helper Hook used in CLI Help System
  */
  void _help();

  /*!
   * @brief   Default Deconstructor
  */
  ~LeaderBoard();
};

#endif  // LEADERBOARD_H //
