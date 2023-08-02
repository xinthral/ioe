#ifndef TOON_H
#define TOON_H

#include "actor.h"

class Toon : public Actor {
protected:
    int attack;
    int defense;
public:
    Toon();
    Toon(int);
    int get_attack();
    int get_defense();
    ~Toon();
};

#endif // TOON_H //