#include "actor.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor 
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
 * @todo    Named Constructor 
*/
Actor::Actor(std::string name) : Actor() { this->name = name; }

/*!
 * @todo    Conditional Combat Check 
*/
bool Actor::isFighting() { return (this->aiState == FIGHT); }

/*!
 * @todo    Conditional Health Check 
*/
bool Actor::isAlive() { return (this->condition != DEAD); }

/*!
 * @todo    Return Attack Attribute
*/
int Actor::get_attack() { return this->baseAttack; }

/*!
 * @todo    Return Defense Attribute
*/
int Actor::get_defense() { return this->baseDefense; }

/*!
 * @todo    Return Flux Attribute
*/
int Actor::get_flux() { return this->baseFlux; }

/*!
 * @todo    Return Health Attribute
*/
int Actor::get_health() { return this->baseHealth; }

/*!
 * @todo    Return ID Attribute
*/
int Actor::get_id() { return this->id; }

/*!
 * @todo    Return Name Attribute
*/
std::string Actor::get_name() { return this->name; }

/*!
 * @todo    ReAssign Actor Flux Value
*/
void Actor::set_flux(int flux) { this->baseFlux = flux; }

/*!
 * @todo    ReAssign Actor ID number
*/
void Actor::set_id(int id) { this->id = id; }

/*!
 * @todo    ReAssign Actor Name
*/
void Actor::set_name(std::string name) { this->name = name; }

/*!
 * @todo    Return Combat State 
*/
CombatState Actor::get_combatstate() { return this->aiState; }

/*!
 * @todo    ReAssign Combat State
*/
void Actor::set_combatstate(CombatState state) { this->aiState = state; }

/*!
 * @todo    Set Combat State to Idling
*/
void Actor::set_combat_idle() { this->set_combatstate(IDLE); }

/*!
 * @todo    Set Combat State to Patrolling 
*/
void Actor::set_combat_patrol() { this->set_combatstate(PATROL); }

/*!
 * @todo    Set Combat State to Fighting 
*/
void Actor::set_combat_fight() { this->set_combatstate(FIGHT); }

/*!
 * @todo    Set Combat State to Fleeing 
*/
void Actor::set_combat_flee() { this->set_combatstate(FLEE); }

/*!
 * @brief   Set Combat State to Following 
*/
void Actor::set_combat_follow() { this->set_combatstate(FOLLOW); }

/*!
 * @todo    Return Health State
*/
HealthState Actor::get_healthstate() { return this->condition; }

/*!
 * @todo    ReAssign Health State
*/
void Actor::set_healthstate(HealthState state) { this->condition = state; }

/*!
 * @todo    Set Health State to Healthy
*/
void Actor::set_health_healthy() { this->set_healthstate(HEALTHY); }

/*!
 * @todo    Set Health State to Hurting
*/
void Actor::set_health_hurting() { this->set_healthstate(HURTING); }

/*!
 * @todo    Set Health State to Critical 
*/
void Actor::set_health_critical() { this->set_healthstate(CRITICAL); }

/*!
 * @todo    Set Health State to Sick 
*/
void Actor::set_health_sick() { this->set_healthstate(SICK); }

/*!
 * @todo    Set Health State to Dead 
*/
void Actor::set_health_dead() { this->set_healthstate(DEAD); }

/*!
 * @todo    Helper Hook used in CLI Help System
*/
void Actor::_help() {
  std::string helpline = "\nActor HelpLine!\n";
  helpline += "\n\tThis is the base class for all Actor's in the scene. NPC's, Players, and all";
  helpline += "\nspecialty mobs are derived from this class"; 
  helpline += "\n";
  log->named_log(__FILENAME__, helpline);
}

/*!
 * @todo    Default Deconstructor 
*/
Actor::~Actor() { }
