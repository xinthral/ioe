/* */
#include "xactor.h"

Actor::Actor() {
    /* Constructor */
    cm = ConfigManager::GetInstance();
    this->aiState = IDLE;
    this->condition = HEALTHY;
    this->baseAttack = cm->get_attack();
    this->baseDefense = cm->get_defense();
    this->baseHealth = cm->get_health();
}

void Actor::set_id(int id) { 
    this->id = id; 
}

void Actor::set_name(std::string name) { 
    this->name = name; 
}

int Actor::get_id() { 
    return this->id; 
}

std::string Actor::get_name() { 
    return this->name; 
}

int Actor::get_attack() {
    return this->baseAttack;
}

int Actor::get_defense() {
    return this->baseDefense;
}


Actor::~Actor() { /* Deconstructor */}