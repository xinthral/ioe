#ifndef PLAYER_H
#define PLAYER_H

#include "actor.h"
#include "logger.h"

class Player : private Actor {
private:
    Logger* log;
    int level;
    int power;
    int block;
public:
    Player(int, int, int);
    ~Player();
};

#endif // PLAYER_H //