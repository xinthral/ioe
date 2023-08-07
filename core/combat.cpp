/*!
 * @class   Combat combat.h combat.cpp
 * @brief   Handle the interactive logic for combat
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
    char buf[1024];
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
Combat::Combat(Player& combatant1, Toon& combatant2) : Combat() { this->matchup = Condition::PvE; }

/*!
 * @overload
 * @brief   PvP Constructor
*/
Combat::Combat(Player& combatant1, Player& combatant2) : Combat() { this->matchup = Condition::PvP; }

/*!
 * @brief   Initiates Combat
*/
void Combat::begin_combat() {
    std::srand(std::time(NULL));
    char buf[1024];
    int r = rand() % 8 + 1;
    sprintf(buf, "Sleeping for %d", r);
    log->named_log(__FILE__, buf);
    sleep(r);
    switch(this->matchup) {
        case Condition::EvE: {
            log->named_log(__FILE__, "EvE Combat!");
        } break;
        case Condition::PvE: {
            log->named_log(__FILE__, "PvE Combat!");
        } break;
        case Condition::PvP: {
            log->named_log(__FILE__, "PvP Combat!");
        } break;
        default: break;
    } 
}

/*!
 * @brief   Default Deconstructor
*/
Combat::~Combat() { }