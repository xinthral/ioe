/*!
 * @class   Actor actor.h actor.cpp
 * @brief   The base class for all Toon and Player types.
 */
#include "actor.h"

/*!
 * Default Constructor 
*/
Actor::Actor() {
    cnf = ConfigManager::GetInstance();
    this->aiState = IDLE;
    this->condition = HEALTHY;
    this->baseAttack = cnf->get_attack();
    this->baseDefense = cnf->get_defense();
    this->baseHealth = cnf->get_health();
    // DEBUG: line
    this->name = "Actor_" + Utilz::TailString(2, Utilz::TimeStamp());
    // sleep(1);
}

/*!
 * @brief   Conditional Combat Check 
 * @details Confirm if Actor is currently fighting
 * @return  Boolean answer 
*/
bool Actor::isFighting() { return (this->aiState == FIGHT); }

/*!
 * @brief   Conditional Health Check 
 * @details Confirm if Actor is not dead
 * @return  Boolean answer 
*/
bool Actor::isAlive() { return (this->condition != DEAD); }

/*!
 * @brief   ReAssign Actor ID number
 * @details Set ID Attribute
 * @param[in] id - Identity Reference Number
*/
void Actor::set_id(int id) { this->id = id; }

/*!
 * @brief   ReAssign Actor Name
 * @details Set Name Attribute
 * @param[in] name - Replace Name
*/
void Actor::set_name(std::string name) { this->name = name; }

/*!
 * @brief   Return ID Attribute
 * @return  Identity Reference Number
*/
int Actor::get_id() { return this->id; }

/*!
 * @brief   Return Name Attribute
 * @return  Name Value 
*/
std::string Actor::get_name() { return this->name; }

/*!
 * @brief   Return Attack Attribute
 * @return  Base Attack Value 
*/
int Actor::get_attack() { return this->baseAttack; }

/*!
 * @brief   Return Defense Attribute
 * @return  Base Defense Value 
*/
int Actor::get_defense() { return this->baseDefense; }

/*!
 * @brief   Return Health Attribute
 * @return  Base Health Value 
*/
int Actor::get_health() { return this->baseHealth; }

/*!
 * @brief   ReAssign Combat State
*/
void Actor::set_combatstate(CombatState state) { this->aiState = state; }

/*!
 * @brief   Set Combat State to Idling
*/
void Actor::set_combat_idle() { this->set_combatstate(IDLE); }

/*!
 * @brief   Set Combat State to Patrolling 
*/
void Actor::set_combat_patrol() { this->set_combatstate(PATROL); }

/*!
 * @brief   Set Combat State to Fighting 
*/
void Actor::set_combat_fight() { this->set_combatstate(FIGHT); }

/*!
 * @brief   Set Combat State to Fleeing 
*/
void Actor::set_combat_flee() { this->set_combatstate(FLEE); }

/*!
 * @brief   Set Combat State to Following 
*/
void Actor::set_combat_follow() { this->set_combatstate(FOLLOW); }

/*!
 * @brief   Return Combat State 
 * @return  Current Combat State of the character.
*/
CombatState Actor::get_combatstate() { return this->aiState; }

/*!
 * @brief   ReAssign Health State
*/
void Actor::set_healthstate(HealthState state) { this->condition = state; }

/*!
 * @brief   Set Health State to Healthy
*/
void Actor::set_health_healthy() { this->set_healthstate(HEALTHY); }

/*!
 * @brief   Set Health State to Hurting
*/
void Actor::set_health_hurting() { this->set_healthstate(HURTING); }

/*!
 * @brief   Set Health State to Critical 
*/
void Actor::set_health_critical() { this->set_healthstate(CRITICAL); }

/*!
 * @brief   Set Health State to Sick 
*/
void Actor::set_health_sick() { this->set_healthstate(SICK); }

/*!
 * @brief   Set Health State to Dead 
*/
void Actor::set_health_dead() { this->set_healthstate(DEAD); }

/*!
 * @brief   Return Health State
 * @return  Current Health State of the character.
*/
HealthState Actor::get_healthstate() { return this->condition; }

/*!
 * @brief   Default Deconstructor 
*/
Actor::~Actor() { }