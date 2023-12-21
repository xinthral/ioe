/*!
 * @class   Combat combat.h combat.cpp
 * @brief   Handle the interactive logic for Combat
*/
#include "combat.h"

/*!
 * @brief   Default Constructor
*/
Combat::Combat() {
  //! Establish Singletons 
  bal = BalanceController::GetInstance();
  cnf = ConfigManager::GetInstance();
  log = Logger::GetInstance();
  log->named_log(__FILE__, "Combat has been initiated!");
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
  sprintf(
    buf, "%s is fighting %s", 
    combatant1.get_name().c_str(), 
    combatant2.get_name().c_str()
  );
  log->named_log(__FILE__, buf);
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
  log->named_log(__FILE__, buf);
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
  log->named_log(__FILE__, buf);
}

/*!
 * @brief   Initiates Combat
*/
void Combat::begin_combat() {
  //! Seed and Generate Random Number
  std::srand(std::time(0));
  int r = rand() % 5 + 1;
  switch(this->matchup) {
    case Condition::EvE: {
      log->named_log(__FILE__, "EvE Combat!");
      this->eVe();
    } break;
    case Condition::PvE: {
      log->named_log(__FILE__, "PvE Combat!");
      this->pVe();
    } break;
    case Condition::PvP: {
      log->named_log(__FILE__, "PvP Combat!");
      this->pVp();
    } break;
    default: break;
  } 
  sprintf(buf, "Sleeping for %d", r);
  log->named_log(__FILE__, buf);
  // sleep(r);
}

/*!
 * @brief   Environment Vs Environment Combat Call
*/
void Combat::eVe() {
  sprintf(buf, "NPC Combat!");
  log->named_log(__FILE__, buf);
}

/*!
 * @brief   Player Vs Environment Combat Call
*/
void Combat::pVe() {
  sprintf(buf, "Mob Combat!");
  log->named_log(__FILE__, buf);
}

/*!
 * @brief   Player Vs Player Combat Call
*/
void Combat::pVp() {
  sprintf(buf, "Player Combat!");
  log->named_log(__FILE__, buf);
}

/*!
 * @brief   Helper Hook used in CLI Help System
*/
void Combat::_help() {
  std::string helpline = "\nCombat Helpline!\n";
  helpline += "\n\tThis combat module got out of hand quickly and took an excessive amount of";
  helpline += "\nover head to get it under control. Took a long break to let my brain digest.";
  helpline += "\n";
  log->named_log(__FILE__, helpline);
}

/*!
 * @brief   Default Deconstructor
*/
Combat::~Combat() { }
