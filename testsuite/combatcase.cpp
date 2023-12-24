/*!
 * @class   TestCombat combatcase.h combatcase.cpp
 * @brief   Test Class for Combat interactions
*/
#include "combatcase.h"

/*! 
 * @brief   Default Constructor
*/
TestCombat::TestCombat() : BaseCase(__FILE__) {
  BaseCase::log->named_log(__FILE__, "Testing Combat!");
  _idx = 0;
  this->test_all();
}

/*! 
 * @brief   Validate the entire Combat Module
*/
void TestCombat::test_all() {
  this->test_eve();
  this->test_pve();
  this->test_pvp();
}

/*! 
 * @brief   Evironment Vs Environment Combat
*/
void TestCombat::test_eve() {
  Toon* _toon1 = new Toon(++_idx);
  Toon* _toon2 = new Toon(++_idx);
  Combat* cc = new Combat(*_toon1, *_toon2);
  cc->begin_combat();
}

/*! 
 * @brief   Player Vs Environment Combat
*/
void TestCombat::test_pve() {
  Player* _player = new Player("P",++_idx, 1, 1);
  Toon* _toon = new Toon(++_idx);
  Combat* cc = new Combat(*_player, *_toon);
  cc->begin_combat();
}

/*! 
 * @brief   Player Vs Player Combat
*/
void TestCombat::test_pvp() {
  Player* _player1 = new Player("M",++_idx, 1, 1);
  Player* _player2 = new Player("A",++_idx, 1, 1);
  Combat* cc = new Combat(*_player1, *_player2);
  cc->begin_combat();
}

/*! 
 * @brief   Default Deconstructor
*/
TestCombat::~TestCombat() { }
