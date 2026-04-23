#include "combat.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor
*/
Combat::Combat() {
  //! Establish Singletons 
  bal = BalanceController::GetInstance();
  cnf = ConfigManager::GetInstance();
  log = Logger::GetInstance();
  log->named_log(__FILENAME__, "Combat has been initiated!");
  std::srand(std::time(NULL));
  _peak1 = _peak2 = _total1 = _total2 = 0;
  _burst_start = std::time(nullptr);
}

/*!
 * @todo    EvE Constructor
*/
Combat::Combat(Toon* combatant1, Toon* combatant2) : Combat() { 
  if (!validFighters(combatant1, combatant2)) { exit(-1); }
  this->matchup = Condition::EvE;
  injestCombatants(combatant1, combatant2);
}

/*!
 * @todo    PvE Constructor
*/
Combat::Combat(Player* combatant1, Toon* combatant2) : Combat() { 
  if (!validFighters(combatant1, combatant2)) { exit(-1); }
  this->matchup = Condition::PvE; 
  injestCombatants(combatant1, combatant2);
}

/*!
 * @todo    PvP Constructor
*/
Combat::Combat(Player* combatant1, Player* combatant2) : Combat() { 
  if (!validFighters(combatant1, combatant2)) { exit(-1); }
  this->matchup = Condition::PvP; 
  injestCombatants(combatant1, combatant2);
}

/*!
 * @todo   Checks combat state 
*/
bool Combat::inCombat() {
  return (this->combatant1->isFighting() && this->combatant2->isFighting());
}

bool Combat::validFighters(Actor* combatant1, Actor* combatant2) {
  //! Check Health State
  if (combatant1->get_health() < 1 || combatant2->get_health() < 1) { return false; }
  //! Check Combat State
  if (!combatant1->isAlive() || !combatant2->isAlive()) { return false; }
  return true;
}

/*!
 * @todo    Initiates Combat
*/
void Combat::cycleCombat() {
  int r = 0, s = 0, x = 0, y = 0;

  // Combatant 1 turn
  if (this->combatant1->isAlive()) {
    r = this->combatant1->get_health();
    s = this->combatant2->get_health();

    x = this->combatant1->get_strategy()->resolve_attack(this->combatant1->output_damage());
    if (x > 0) x = this->combatant2->get_strategy()->resolve_defense(x);
    if (x > 0) x = this->combatant2->receive_damage(x);
    if (x > 0) { _total1 += x; if (x > _peak1) _peak1 = x; }

    snprintf(buf, sizeof(buf), "%s hits %s for %d<->%d.",
      this->combatant1->get_name().c_str(),
      this->combatant2->get_name().c_str(), x, s);
    log->named_log(__FILENAME__, buf);
    if (this->combatant2->get_health() < 1) { this->combatant2->set_health_dead(); }
  }

  // Combatant 2 turn
  if (this->combatant2->isAlive()) {
    y = this->combatant2->get_strategy()->resolve_attack(this->combatant2->output_damage());
    if (y > 0) y = this->combatant1->get_strategy()->resolve_defense(y);
    if (y > 0) y = this->combatant1->receive_damage(y);
    if (y > 0) { _total2 += y; if (y > _peak2) _peak2 = y; }

    snprintf(buf, sizeof(buf), "%s hits %s for %d<->%d!",
      this->combatant2->get_name().c_str(),
      this->combatant1->get_name().c_str(), y, r);
    log->named_log(__FILENAME__, buf);
    if (this->combatant1->get_health() < 1) { this->combatant1->set_health_dead(); }
  }

  // Flee checks
  if (this->combatant1->isAlive() &&
      this->combatant1->get_strategy()->should_flee(this->combatant1->get_health())) {
    this->combatant1->set_combat_flee();
    snprintf(buf, sizeof(buf), "%s fled!", this->combatant1->get_name().c_str());
    log->named_log(__FILENAME__, buf);
  }
  if (this->combatant2->isAlive() &&
      this->combatant2->get_strategy()->should_flee(this->combatant2->get_health())) {
    this->combatant2->set_combat_flee();
    snprintf(buf, sizeof(buf), "%s fled!", this->combatant2->get_name().c_str());
    log->named_log(__FILENAME__, buf);
  }

  if (!this->combatant1->isAlive() || !this->combatant2->isAlive()) {
    snprintf(buf, sizeof(buf), "Combat Ended, [%s] Won!", this->combatant1->isAlive() ?
      this->combatant1->get_name().c_str() : this->combatant2->get_name().c_str());
    log->named_log(__FILENAME__, buf);
  }
}

/*!
 * @todo    Intakes Combatants
*/
void Combat::injestCombatants(Actor* combatant1, Actor* combatant2) {
  // Establish Combat Type
  switch (this->matchup) {
    case Condition::EvE: {
      log->named_log(__FILENAME__, "EvE Combat!");
    } break;
    case Condition::PvE: {
      log->named_log(__FILENAME__, "PvE Combat!");
    } break;
    case Condition::PvP: {
      log->named_log(__FILENAME__, "PvP Combat!");
    } break;
    default: break;
  }

  // Injested Combatant1
  this->combatant1 = combatant1;
  this->combatant1->set_combat_fight();

  // Injested Combatant2
  this->combatant2 = combatant2;
  this->combatant2->set_combat_fight();

  sprintf(
    buf, "%s is fighting %s", 
    this->combatant1->get_name().c_str(), 
    this->combatant2->get_name().c_str()
  );
  log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Helper Hook used in CLI Help System
*/
void Combat::_help() {
  std::string helpline = "\nCombat Helpline!\n"
  "\n\tThis combat module got out of hand quickly and took an excessive amount of over"
  "\nhead to get it under control. Took a long break to let my brain digest. Eventually,"
  "\nI got my shit together and was able to strip the code and reprototype the combat."
  "\n\tI envisioned this being used as a turn-based combat system, but allowing for Player"
  "\nvs Player, Player vs NPC, and NPC vs NPC. This works in conjunction with the battle"
  "\nsystem to provide multiple combatants."
  "\n";
  log->named_log(__FILENAME__, helpline);
}

/*!
 * @todo    Default Deconstructor
*/
Combat::~Combat() { }
