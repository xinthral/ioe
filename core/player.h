#ifndef PLAYER_H
#define PLAYER_H

#include "actor.h"
#include "logger.h"

class Player : private Actor {
private:
    Logger* log;
    char buf[1024];
    int level;
    int power;
    int block;
public:
    Player(int, int, int);
    void _help();
    ~Player();
};

#endif // PLAYER_H //