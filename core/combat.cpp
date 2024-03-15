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
}

/*!
 * @todo    EvE Constructor
*/
Combat::Combat(Toon& combatant1, Toon& combatant2) : Combat() { 
  //! Check Health State
  if (combatant1.get_health() < 1 && combatant2.get_health() < 1) { exit(-1); }
  //! Check Combat State
  if (!combatant1.isAlive() || !combatant2.isAlive()) { exit(-1); }
  this->matchup = Condition::EvE;
  //! Set Combat State
  combatant1.set_combat_fight();
  combatant2.set_combat_fight();
  sprintf(buf, 
    "%s is fighting %s", 
    combatant1.get_name().c_str(), 
    combatant2.get_name().c_str()
  );
  injest_combatants(combatant1, combatant2);
  log->named_log(__FILENAME__, buf);
  
}

/*!
 * @todo    PvE Constructor
*/
Combat::Combat(Player& combatant1, Toon& combatant2) : Combat() { 
  //! Check Health State
  if (combatant1.get_health() < 1 && combatant2.get_health() < 1) { exit(-1); }
  //! Check Combat State
  if (!combatant1.isAlive() || !combatant2.isAlive()) { exit(-1); }
  this->matchup = Condition::PvE; 
  //! Set Combat State
  combatant1.set_combat_fight();
  combatant2.set_combat_fight();
  sprintf(
    buf, "%s is fighting %s", 
    combatant1.get_name().c_str(), 
    combatant2.get_name().c_str()
  );
  injest_combatants(combatant1, combatant2);
  log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    PvP Constructor
*/
Combat::Combat(Player& combatant1, Player& combatant2) : Combat() { 
  //! Check Health State
  if (combatant1.get_health() < 1 && combatant2.get_health() < 1) { exit(-1); }
  //! Check Combat State
  if (!combatant1.isAlive() || !combatant2.isAlive()) { exit(-1); }
  this->matchup = Condition::PvP; 

  //! Set Combat State
  combatant1.set_combat_fight();
  combatant2.set_combat_fight();
  sprintf(
    buf, "%s is fighting %s", 
    combatant1.get_name().c_str(), 
    combatant2.get_name().c_str()
  );
  injest_combatants(combatant1, combatant2);
  log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Intakes Combatants
*/
void Combat::injest_combatants(Actor& combatant1, Actor& combatant2) {
	// Injested Combatant1
  f1.name    = combatant1.get_name();
  f1.health  = combatant1.get_health();
  f1.attack  = combatant1.get_attack();
  f1.defense = combatant1.get_defense();

	// Injested Combatant2
  f2.name    = combatant2.get_name();
  f2.health  = combatant2.get_health();
  f2.attack  = combatant2.get_attack();
  f2.defense = combatant2.get_defense();
  
  combatant1.set_combat_fight();
  combatant2.set_combat_fight();
}

/*!
 * @todo    Initiates Combat
*/
void Combat::begin_combat() {
  //! Seed and Generate Random Number
  int r = rand() % 5 + 1;
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
  sprintf(buf, "Sleeping for %d", r);
  log->named_log(__FILENAME__, buf);
  // sleep(r);

  //! Temporary Combat Logic
  int x = 0, y = 0;
  while (f1.health > 0 && f2.health > 0) {
    x = rand() % 5 + 1;
    sprintf(buf, "%s hits %s for %d/%d.", f1.name.c_str(), f2.name.c_str(), x, f2.health);
    f2.health -= x;
    log->named_log(__FILENAME__, buf);

    y = rand() % 5 + 1;
    sprintf(buf, "%s hits %s for %d/%d.", f2.name.c_str(), f1.name.c_str(), y, f1.health);
    f1.health -= y; 
		log->named_log(__FILENAME__, buf);
  } 

  // if (f1.health <= 0) { combatant1.set_health_dead(); }
  // if (f2.health <= 0) { combatant2.set_health_dead(); }
  sprintf(buf, "EvE Combat Ended! %s Won", (f1.health > 0) ? f1.name.c_str() : f2.name.c_str());
  log->named_log(__FILENAME__, buf);

}

/*!
 * @todo    Helper Hook used in CLI Help System
*/
void Combat::_help() {
  std::string helpline = "\nCombat Helpline!\n";
  helpline += "\n\tThis combat module got out of hand quickly and took an excessive amount of";
  helpline += "\nover head to get it under control. Took a long break to let my brain digest.";
  helpline += "\n";
  log->named_log(__FILENAME__, helpline);
}

/*!
 * @todo    Default Deconstructor
*/
Combat::~Combat() { }
