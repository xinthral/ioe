#include "actor.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @note    Default Constructor 
*/
Actor::Actor() {
  cnf = ConfigManager::GetInstance();
  this->aiState     = IDLE;
  this->condition   = HEALTHY;
  this->level       = 0;
  this->baseAttack  = cnf->get_attack();
  this->attack      = this->baseAttack;
  this->baseDefense = cnf->get_defense();
  this->defense     = this->baseDefense;
  this->baseHealth  = cnf->get_health();
  this->health      = this->baseHealth;
  this->baseFlux    = cnf->get_flux();
  this->flux        = this->baseFlux;
  std::string cnvt  = std::to_string(
    std::chrono::duration_cast<std::chrono::milliseconds>(
      std::chrono::system_clock::now().time_since_epoch()
    ).count() % 100
  );
  this->name = "Actor_" + cnvt;
}

/*!
 * @note    Named Constructor 
*/
Actor::Actor(std::string name) : Actor() { this->name = name; }

/*!
 * @note    Conditional Combat Check 
*/
bool Actor::isFighting() { return (this->aiState == FIGHT); }

/*!
 * @note    Conditional Health Check 
*/
bool Actor::isAlive() { return (this->condition != DEAD); }

/*!
 * @note    Return Attack Attribute
*/
int Actor::get_baseAttack() { return this->baseAttack; }

/*!
 * @note    Return Attack Attribute
*/
int Actor::get_attack() { return this->attack; }

/*!
 * @note
*/
void Actor::set_attack(int input) { this->attack = input; }

/*!
 * @note    Return Defense Attribute
*/
int Actor::get_baseDefense() { return this->baseDefense; }

/*!
 * @note    Return Defense Attribute
*/
int Actor::get_defense() { return this->defense; }

/*!
 * @note    
*/
void Actor::set_defense(int input) { this->defense = input; }

/*!
 * @note    Return Flux Attribute
*/
int Actor::get_baseFlux() { return this->baseFlux; }

/*!
 * @note    Return Flux Attribute
*/
int Actor::get_flux() { return this->flux; }

/*!
 * @note    Return Health Attribute
*/
int Actor::get_baseHealth() { return this->baseHealth; }

/*!
 * @note    Return Health Attribute
*/
int Actor::get_health() { return this->health; }

/*!
 * @note    
*/
void Actor::set_health(int input) { this->health = input; }

/*!
 * @note    Return ID Attribute
*/
int Actor::get_id() { return this->id; }

/*!
 * @note    Return Level Attribute
*/
int Actor::get_level() { return this->level; }

/*!
 * @note    Return Name Attribute
*/
std::string Actor::get_name() { return this->name; }

/*!
 * @note    ReAssign Actor Flux Value
*/
void Actor::set_flux(int flux) { this->baseFlux = flux; }

/*!
 * @note    ReAssign Actor ID number
*/
void Actor::set_id(int id) { this->id = id; }

/*!
 * @note    ReAssign Actor Level
*/
void Actor::set_level(int level) { this->level = level; }

/*!
 * @note    ReAssign Actor Name
*/
void Actor::set_name(std::string name) { this->name = name; }

/*!
 * @note    Return Combat State 
*/
CombatState Actor::get_combatstate() { return this->aiState; }

/*!
 * @note    ReAssign Combat State
*/
void Actor::set_combatstate(CombatState state) { this->aiState = state; }

/*!
 * @note    Meant to be overwritten by inhereted class
 *          including multiplier and reducers
*/
int Actor::output_damage() { return this->attack; }

/*!
 * @note    Set Combat State to Idling
*/
void Actor::set_combat_idle() { this->set_combatstate(IDLE); }

/*!
 * @note    Set Combat State to Patrolling 
*/
void Actor::set_combat_patrol() { this->set_combatstate(PATROL); }

/*!
 * @note    Set Combat State to Fighting 
*/
void Actor::set_combat_fight() { this->set_combatstate(FIGHT); }

/*!
 * @note    Set Combat State to Fleeing 
*/
void Actor::set_combat_flee() { this->set_combatstate(FLEE); }

/*!
 * @brief   Set Combat State to Following 
*/
void Actor::set_combat_follow() { this->set_combatstate(FOLLOW); }

/*!
 * @note    Return Health State
*/
HealthState Actor::get_healthstate() { return this->condition; }

/*!
 * @note    ReAssign Health State
*/
void Actor::set_healthstate(HealthState state) { this->condition = state; }

/*!
 * @note    Meant to be overwritten by inhereted class
 *          including multiplier and reducers
*/
int Actor::receive_damage(int damage) {
  int new_value = damage;
  if (this->defense < damage) { new_value = damage * (damage / this->defense); }
  this->health -= new_value;
  return new_value;
}

/*!
 * @note    Set Health State to Healthy
*/
void Actor::set_health_healthy() { this->set_healthstate(HEALTHY); }

/*!
 * @note    Set Health State to Hurting
*/
void Actor::set_health_hurting() { this->set_healthstate(HURTING); }

/*!
 * @note    Set Health State to Critical 
*/
void Actor::set_health_critical() { this->set_healthstate(CRITICAL); }

/*!
 * @note    Set Health State to Sick 
*/
void Actor::set_health_sick() { this->set_healthstate(SICK); }

/*!
 * @note    Set Health State to Dead 
*/
void Actor::set_health_dead() { 
  this->set_healthstate(DEAD);
  this->set_combatstate(IDLE);
}

/*!
 * @note    Helper Hook used in CLI Help System
*/
void Actor::_help() {
  std::string helpline = "\nActor HelpLine!\n";
  helpline += "\n\tThis is the base class for all Actor's in the scene. NPC's, Players, and all";
  helpline += "\nspecialty mobs are derived from this class";
  helpline += "\n";
  log->named_log(__FILENAME__, helpline);
}

/*!
 * @note    Default Deconstructor 
*/
Actor::~Actor() {}
