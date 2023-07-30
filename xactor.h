#ifndef XACTOR_H
#define XACTOR_H

#include <string>
#include "xconfig.h"

// Actor States
enum COMBSTATE { IDLE, PATROL, FIGHT, FLEE, FOLLOW };
enum LIFESTATE { HEALTHY, HURTING, CRITICAL, SICK, DEAD };

class Actor {
protected:
    ConfigManager* cm;
    COMBSTATE aiState;
    LIFESTATE condition;
    std::string name;
    int id;
    int baseAttack;
    int baseDefense;
    int baseHealth;
public:
    Actor();
    void set_id(int);
    void set_name(std::string);
    int get_id();
    std::string get_name();
    int get_attack();
    int get_defense();
    ~Actor();
};

#endif // XACTOR_H //