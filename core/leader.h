#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <mutex>
#include "logger.h"

class LeaderBoard {
protected:
  LeaderBoard();

private:
  static LeaderBoard*   _singleton;
  static std::mutex     _mutex;
  Logger*               log;
  char buf[1024];
public:
  LeaderBoard(LeaderBoard&) = delete;             //! Singletons should not be cloneable
  void operator=(const LeaderBoard&) = delete;    //! Singletons should not be assignable
  static LeaderBoard* GetInstance();              //! Singleton Constructor
  void _help();
  ~LeaderBoard();
};

#endif  // LEADERBOARD_H //
