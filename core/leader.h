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
  //! Singletons should not be cloneable
  LeaderBoard(LeaderBoard&) = delete;
  //! Singletons should not be assignable
  void operator=(const LeaderBoard&) = delete;
  static LeaderBoard* GetInstance();
  void _help();
  ~LeaderBoard();
};

#endif  // LEADERBOARD_H //