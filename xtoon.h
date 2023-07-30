#ifndef XTOON_H
#define XTOON_H

#include "xactor.h"

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

#endif // XTOON_H //