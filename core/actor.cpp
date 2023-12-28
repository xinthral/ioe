/*!
 * @class   Actor actor.h actor.cpp
 * @brief   The base class for all Toon and Player types.
 */
#include "actor.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor 
*/
Actor::Actor() {
  cnf = ConfigManager::GetInstance();
  this->aiState     = IDLE;
  this->condition   = HEALTHY;
  this->baseAttack  = cnf->get_attack();
  this->baseDefense = cnf->get_defense();
  this->baseHealth  = cnf->get_health();
  this->baseFlux    = cnf->get_flux();
  this->name        = "Actor_" + Utilz::TailString(2, Utilz::TimeStamp());
}

/*!
 * @overload
 * @brief   Named Constructor 
 * @param[in] name - Name to assign to actor
*/
Actor::Actor(std::string name) : Actor() { this->name = name; }

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
 * @brief   Return Flux Attribute
 * @return  Flux Value
*/
int Actor::get_flux() { return this->baseFlux; }

/*!
 * @brief   Return Health Attribute
 * @return  Base Health Value 
*/
int Actor::get_health() { return this->baseHealth; }

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
 * @brief   ReAssign Actor Flux Value
 * @details Set Flux Attribute 
 * @param[in] flux - New Flux Value
*/
void Actor::set_flux(int flux) { this->baseFlux = flux; }

/*!
 * @brief   ReAssign Actor ID number
 * @details Set ID Attribute
 * @param[in] id - Identity Reference Number
*/
void Actor::set_id(int id) { this->id = id; }

/*!
 * @brief   ReAssign Actor Name
 * @details Set Name Attribute
 * @param[in] name - New Name Value
*/
void Actor::set_name(std::string name) { this->name = name; }

/*!
 * @brief   Return Combat State 
 * @return  Current Combat State of the character.
*/
CombatState Actor::get_combatstate() { return this->aiState; }

/*!
 * @brief   ReAssign Combat State
 * @param[in] state Current State of the Combat AI 
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
 * @brief   Return Health State
 * @return  Current Health State of the character.
*/
HealthState Actor::get_healthstate() { return this->condition; }

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
 * @brief   Helper Hook used in CLI Help System
*/
void Actor::_help() {
  std::string helpline = "\nActor HelpLine!\n";
  helpline += "\n\tThis is the base class for all Actor's in the scene. NPC's, Players, and all";
  helpline += "\nspecialty mobs are derived from this class"; 
  helpline += "\n";
  log->named_log(__FILENAME__, helpline);
}

/*!
 * @brief   Default Deconstructor 
*/
Actor::~Actor() { }
