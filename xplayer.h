#ifndef XPLAYER_H
#define XPLAYER_H

#include "xactors.h"

class Player : private Actor {
private:
    int level;
    int power;
    int block;
public:
    Player();
    ~Player();
};

#endif // XPLAYER_H //