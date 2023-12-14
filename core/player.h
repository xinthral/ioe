#ifndef PLAYER_H
#define PLAYER_H

#include "actor.h"
#include "logger.h"

class Player : public Actor {
private:
  Logger* log;
  char buf[128];
  int block   = 1;
  int health  = 1;
  int level   = 1;
  int power   = 1;
public:
  Player();
  Player(int, int, int);
  Player(std::string, int, int, int);
  void _help();
  ~Player();
};

#endif // PLAYER_H //
