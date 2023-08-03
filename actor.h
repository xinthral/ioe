#ifndef ACTOR_H
#define ACTOR_H

#include <unistd.h>
#include <string>
#include "config.h"
#include "utilz.h"

// Actor States
enum CombatState { IDLE, PATROL, FIGHT, FLEE, FOLLOW };
enum HealthState { HEALTHY, HURTING, CRITICAL, SICK, DEAD };

class Actor {
protected:
    // Protected Objects
    ConfigManager* cnf;
    CombatState aiState;
    HealthState condition;

    // Protected Attributes
    std::string name;
    int id;
    int baseAttack;
    int baseDefense;
    int baseHealth;

public:
    // Constructors
    Actor();

    // Status Checks
    bool isFighting();
    bool isAlive();

    // Setters
    void set_id(int);
    void set_name(std::string);
    
    // Getters
    int get_id();
    std::string get_name();
    int get_attack();
    int get_defense();
    int get_health();

    // Combat States
    void set_combat_idle();
    void set_combat_patrol();
    void set_combat_fight();
    void set_combat_flee();
    void set_combat_follow();
    void set_combatstate(CombatState);
    CombatState get_combatstate();

    // Health States
    void set_health_healthy();
    void set_health_hurting();
    void set_health_critical();
    void set_health_sick();
    void set_health_dead();
    void set_healthstate(HealthState);
    HealthState get_healthstate();

    // Deconstructor
    ~Actor();
};

#endif // ACTOR_H //