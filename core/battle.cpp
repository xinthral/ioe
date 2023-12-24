/*! 
 * @class   Battle battle.h battle.cpp
 * @brief   Interweaving Combat events
 */
#include "battle.h"

/*! 
 * @brief   Default Constructor
*/
Battle::Battle() {
  log = Logger::GetInstance();
}

/*! 
 * @overload
 * @brief   Player v Team Constructor
*/
Battle::Battle(int size, Player* player, std::vector<Toon*>& team) : Battle() {
  Toon* t = new Toon();
  Toon* v;
  Combat* cc;
  while (team.size() > 1) {
    t = team[team.size() - 1];
    v = team[team.size() - 2];
    team.pop_back();
    team.pop_back();
    cc = new Combat(*t, *v);
    cc->begin_combat();
  }

  cc = new Combat(*player, *t);
  cc->begin_combat();
  
}

/*!
 * @overload
 * @brief    Gang v Gang Constructor
*/
Battle::Battle(std::vector<Toon*>& gang1, std::vector<Toon*>& gang2) : Battle() { }

/*!
 * @brief   Helper Hook used in CLI Help System
*/
void Battle::_help() {
  std::string helpline = "\nBattle Helpline!\n";
  helpline += "\n";
  log->named_log(__FILE__, helpline);
}

/*! 
 * @brief   Default Deconstructor
*/
Battle::~Battle() { }
