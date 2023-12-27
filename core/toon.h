#ifndef TOON_H
#define TOON_H

#include "actor.h"

class Toon : public Actor {
protected:
    std::string name;
    int attack;
    int defense;
    char buf[128];
public:
    Toon();
    Toon(int);
    Toon(std::string);
    Toon(int,std::string);
    std::string get_name();
    int get_attack();
    int get_defense();
    void set_name(std::string);
    void _help();
    ~Toon();
};

#endif // TOON_H //
