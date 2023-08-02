/**
 * The base class for all Toon and Player types.
 */
#include "actor.h"

/**
 * Default Constructor 
*/
Actor::Actor() {
    cm = ConfigManager::GetInstance();
    this->aiState = IDLE;
    this->condition = HEALTHY;
    this->baseAttack = cm->get_attack();
    this->baseDefense = cm->get_defense();
    this->baseHealth = cm->get_health();
    // DEBUG: line
    this->name = "Actor_" + Utilz::TailString(2, Utilz::TimeStamp());
    // sleep(1);
}

/**
 * Conditional Combat Check 
 * @return :<bool|condition> 
*/
bool Actor::isFighting() { return (this->aiState == FIGHT); }

/**
 * Conditional Health Check 
 * @return :<bool|condition> 
*/
bool Actor::isAlive() { return (this->condition != DEAD); }

/**
 * ReAssign Actor ID number
 * @param :<int|id> - Identity Reference Number
*/
void Actor::set_id(int id) { this->id = id; }

/**
 * ReAssign Actor Name
 * @param :<str|name> - Replace Name
*/
void Actor::set_name(std::string name) { this->name = name; }

/**
 * Return ID Attribute
 * @return :<int|id> - Identity Reference Number
*/
int Actor::get_id() { return this->id; }

/**
 * Return Name Attribute
 * @return :<str|name> - Name Attribute
*/
std::string Actor::get_name() { return this->name; }

/**
 * Return Attack Attribute
 * @return :<int|attack> - Base Attack Attribute
*/
int Actor::get_attack() { return this->baseAttack; }

/**
 * Return Defense Attribute
 * @return :<int|defense> - Base Defense Attribute
*/
int Actor::get_defense() { return this->baseDefense; }

/**
 * Return Health Attribute
 * @return :<int|health> - Base Health Attribute
*/
int Actor::get_health() { return this->baseHealth; }

/**
 * ReAssign Combat State
*/
void Actor::set_combatstate(CombatState state) { this->aiState = state; }

/**
 * Set Combat State to Idling
*/
void Actor::set_combat_idle() { this->set_combatstate(IDLE); }

/**
 * Set Combat State to Patrolling 
*/
void Actor::set_combat_patrol() { this->set_combatstate(PATROL); }

/**
 * Set Combat State to Fighting 
*/
void Actor::set_combat_fight() { this->set_combatstate(FIGHT); }

/**
 * Set Combat State to Fleeing 
*/
void Actor::set_combat_flee() { this->set_combatstate(FLEE); }

/**
 * Set Combat State to Following 
*/
void Actor::set_combat_follow() { this->set_combatstate(FOLLOW); }

/**
 * Return Combat State 
 * @return :<CombatState|state> - Current Combat State of the character.
*/
CombatState Actor::get_combatstate() { return this->aiState; }

/**
 * ReAssign Health State
*/
void Actor::set_healthstate(HealthState state) { this->condition = state; }

/**
 * Set Health State to Healthy
*/
void Actor::set_health_healthy() { this->set_healthstate(HEALTHY); }

/**
 * Set Health State to Hurting
*/
void Actor::set_health_hurting() { this->set_healthstate(HURTING); }

/**
 * Set Health State to Critical 
*/
void Actor::set_health_critical() { this->set_healthstate(CRITICAL); }

/**
 * Set Health State to Sick 
*/
void Actor::set_health_sick() { this->set_healthstate(SICK); }

/**
 * Set Health State to Dead 
*/
void Actor::set_health_dead() { this->set_healthstate(DEAD); }

/**
 * Return Health State
 * @return :<HealthState|state> - Current Health State of the character.
*/
HealthState Actor::get_healthstate() { return this->condition; }

/**
 * Default Deconstructor 
*/
Actor::~Actor() { }