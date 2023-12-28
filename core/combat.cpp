/*!
 * @class   Combat combat.h combat.cpp
 * @brief   Handle the interactive logic for Combat
*/
#include "combat.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
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
 * @overload
 * @brief   EvE Constructor
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
  
  //! Temporary Combat Logic
  int r = 0;
  int health1 = combatant1.get_health();
  int health2 = combatant2.get_health(); 
  int step = 0;
  while (combatant1.isAlive() && combatant2.isAlive()) {
    r = rand() % 5 + 1;
    if (step % 2 == 0) { 
      // sprintf(buf, "%s hits %s for %d/%d.", combatant1.get_name().c_str(), combatant2.get_name().c_str(), r, health2);
      health2 -= r;
      if (health2 <= 0) { combatant2.set_health_dead(); }
    } else { 
      // sprintf(buf, "%s hits %s for %d/%d.", combatant2.get_name().c_str(), combatant1.get_name().c_str(), r, health1);
      health1 -= r; 
      if (health1 <= 0) { combatant1.set_health_dead(); }
    }
    step++;
    // log->named_log(fbuff, buf);
  }

  sprintf(buf, "EvE Combat Ended! %s Won", (health1 > 0) ? combatant1.get_name().c_str() : combatant2.get_name().c_str());
  log->named_log(__FILENAME__, buf);
}

/*!
 * @overload
 * @brief   PvE Constructor
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
 * @overload
 * @brief   PvP Constructor
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
  // injest_combatants(combatant1, combatant2);
  log->named_log(__FILENAME__, buf);
}

/*!
 * @brief   Initiates Combat
*/
void Combat::injest_combatants(Actor& combatant1, Actor& combatant2) {
  f1.health  = combatant1.get_health();
  f1.attack  = combatant1.get_attack();
  f1.defense = combatant1.get_defense();
  f2.health  = combatant2.get_health();
  f2.attack  = combatant2.get_attack();
  f2.defense = combatant2.get_defense();
}

/*!
 * @brief   Initiates Combat
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
}

/*!
 * @brief   Helper Hook used in CLI Help System
*/
void Combat::_help() {
  std::string helpline = "\nCombat Helpline!\n";
  helpline += "\n\tThis combat module got out of hand quickly and took an excessive amount of";
  helpline += "\nover head to get it under control. Took a long break to let my brain digest.";
  helpline += "\n";
  log->named_log(__FILENAME__, helpline);
}

/*!
 * @brief   Default Deconstructor
*/
Combat::~Combat() { }
