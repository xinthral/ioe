
#include "combatcase.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*! 
 * @todo    Default Constructor
*/
TestCombat::TestCombat() : BaseCase(__FILENAME__) {
  BaseCase::log->named_log(__FILENAME__, "Testing Combat!");
  _idx = 0;
  this->test_all();
}

/*! 
 * @todo    Validate the entire Combat Module
*/
void TestCombat::test_all() {
  this->EVECombat();
  this->PVECombat();
  this->PVPCombat();
}

/*! 
 * @todo    Evironment Vs Environment Combat
*/
void TestCombat::EVECombat() {
  Toon* _toon1 = new Toon(++_idx);
  Toon* _toon2 = new Toon(++_idx);
  Combat* cc = new Combat(_toon1, _toon2);
  cc->cycle_combat();
  log->named_log(__FILENAME__, "EvE Combat Tested!");
}

/*! 
 * @todo    Player Vs Environment Combat
*/
void TestCombat::PVECombat() {
  Player* _player = new Player("Player", ++_idx);
  Toon* _toon = new Toon(++_idx);
  Combat* cc = new Combat(_player, _toon);
  cc->cycle_combat();
  log->named_log(__FILENAME__, "PvE Combat Tested!");
}

/*! 
 * @todo    Player Vs Player Combat
*/
void TestCombat::PVPCombat() {
  Player* _player1 = new Player("Max", ++_idx);
  Player* _player2 = new Player("Min", ++_idx);
  Combat* cc = new Combat(_player1, _player2);
  cc->cycle_combat();
  log->named_log(__FILENAME__, "PvP Combat Tested!");
}

/*! 
 * @todo    Default Deconstructor
*/
TestCombat::~TestCombat() { }
