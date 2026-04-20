#include "combatcase.h"

/*!
 * @def     __FILENAME__
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

TestCombat::TestCombat() : TestCombat(0) {}

TestCombat::TestCombat(int granularity) : BaseCase(__FILENAME__) {
  set_granularity(granularity);
  BaseCase::log->named_log(__FILENAME__, "Testing Combat!");
  sprintf(this->msgHead, "Tested");
  sprintf(this->msgTail, "for Combat!");
  _player1 = _player2 = nullptr;
  _toon1   = _toon2   = nullptr;
  _combat  = nullptr;
  this->test_all();
}

void TestCombat::test_all() {
  this->EVECombat();
  this->PVECombat();
  this->PVPCombat();
}

void TestCombat::EVECombat() {
  if (this->_granularity >= 1) {
    PROFILE_FUNCTION();
  }
  PROFILE_NAMED("EvE_Combat");
  delete _toon1;  _toon1  = nullptr;
  delete _toon2;  _toon2  = nullptr;
  delete _combat; _combat = nullptr;
  _toon1  = new Toon("EvE_T1");
  _toon2  = new Toon("EvE_T2");
  _combat = new Combat(_toon1, _toon2);
  while (_combat->inCombat()) { _combat->cycleCombat(); }
  record(_toon1->get_healthstate() == DEAD || _toon2->get_healthstate() == DEAD,
         "EvE combat ended without a DEAD combatant");
  record(!_toon1->isAlive() || !_toon2->isAlive(),
         "EvE combat ended while both combatants still alive");
  sprintf(buf, "%s [%s] %s", msgHead, "EvE combat", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestCombat::PVECombat() {
  if (this->_granularity >= 1) {
    PROFILE_FUNCTION();
  }
  PROFILE_NAMED("PvE_Combat");
  delete _player1; _player1 = nullptr;
  delete _toon1;   _toon1   = nullptr;
  delete _combat;  _combat  = nullptr;
  _player1 = new Player("PvE_P1", 1);
  _toon1   = new Toon("PvE_T1");
  _combat  = new Combat(_player1, _toon1);
  while (_combat->inCombat()) { _combat->cycleCombat(); }
  record(_player1->get_healthstate() == DEAD || _toon1->get_healthstate() == DEAD,
         "PvE combat ended without a DEAD combatant");
  record(!_player1->isAlive() || !_toon1->isAlive(),
         "PvE combat ended while both combatants still alive");
  sprintf(buf, "%s [%s] %s", msgHead, "PvE combat", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestCombat::PVPCombat() {
  if (this->_granularity >= 1) {
    PROFILE_FUNCTION();
  }
  PROFILE_NAMED("PvP_Combat");
  delete _player1; _player1 = nullptr;
  delete _player2; _player2 = nullptr;
  delete _combat;  _combat  = nullptr;
  _player1 = new Player("PvP_P1", 1);
  _player2 = new Player("PvP_P2", 1);
  _combat  = new Combat(_player1, _player2);
  while (_combat->inCombat()) { _combat->cycleCombat(); }
  record(_player1->get_healthstate() == DEAD || _player2->get_healthstate() == DEAD,
         "PvP combat ended without a DEAD combatant");
  record(!_player1->isAlive() || !_player2->isAlive(),
         "PvP combat ended while both combatants still alive");
  sprintf(buf, "%s [%s] %s", msgHead, "PvP combat", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

TestCombat::~TestCombat() {
  delete _player1; delete _player2;
  delete _toon1;   delete _toon2;
  delete _combat;
}
