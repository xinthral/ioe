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
    void _help();
    ~Toon();
};

#endif // TOON_H //