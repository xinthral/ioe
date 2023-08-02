#ifndef PLAYER_H
#define PLAYER_H

#include "actor.h"

class Player : private Actor {
private:
    int level;
    int power;
    int block;
public:
    Player();
    ~Player();
};

#endif // PLAYER_H //