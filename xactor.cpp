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
    this->name = "Actor_" + Utilz::TailString(2, Utilz::TimeStamp());
    // sleep(1);
}

bool Actor::isFighting() { return (this->aiState == FIGHT); }
bool Actor::isAlive() { return (this->condition != DEAD); }

void Actor::set_id(int id) { this->id = id; }
void Actor::set_name(std::string name) { this->name = name; }
int Actor::get_id() { return this->id; }
std::string Actor::get_name() { return this->name; }
int Actor::get_attack() { return this->baseAttack; }
int Actor::get_defense() { return this->baseDefense; }
int Actor::get_health() { return this->baseHealth; }

void Actor::set_combatstate(CombatState state) { this->aiState = state; }
void Actor::set_combat_idle() { this->set_combatstate(IDLE); }
void Actor::set_combat_patrol() { this->set_combatstate(PATROL); }
void Actor::set_combat_fight() { this->set_combatstate(FIGHT); }
void Actor::set_combat_flee() { this->set_combatstate(FLEE); }
void Actor::set_combat_follow() { this->set_combatstate(FOLLOW); }
CombatState Actor::get_combatstate() { return this->aiState; }

void Actor::set_healthstate(HealthState state) { this->condition = state; }
void Actor::set_health_healthy() { this->set_healthstate(HEALTHY); }
void Actor::set_health_hurting() { this->set_healthstate(HURTING); }
void Actor::set_health_critical() { this->set_healthstate(CRITICAL); }
void Actor::set_health_sick() { this->set_healthstate(SICK); }
void Actor::set_health_dead() { this->set_healthstate(DEAD); }
HealthState Actor::get_healthstate() { return this->condition; }

Actor::~Actor() { /* Deconstructor */}