#include "battlecase.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor
*/
TestBattle::TestBattle() : BaseCase(__FILENAME__) {
  BaseCase::log->named_log(__FILENAME__, "Testing the BattleManager!");
	this->battle = Battle::GetInstance();
	sprintf(this->msgHead, "BattleManager");
	sprintf(this->msgTail, "has successfully been tested.");
  this->test_all();
}

/*!
 * @todo    Run full set of test on module 
*/
void TestBattle::test_all() {
	this->level1_eve();
  this->level1_pve();
}

/*!
 * @todo    EVE Combat test on level 1 combatants
*/
void TestBattle::level1_eve() {
  bool pendingWork = true;
  this->toon1 = new Toon("Toon1");
  this->toon2 = new Toon("Toon2");
  this->battle->startEVE(*toon1, *toon2);

  do {
    this->battle->doCycleWork(pendingWork);
  } while(pendingWork);

  sprintf(buf, "T1:[ %d ] T2:[ %d ]", toon1->get_healthstate(), toon2->get_healthstate());
  BaseCase::log->timed_log(buf);
  assertm(toon1->get_healthstate() == 0 || toon2->get_healthstate() == 0, "Combat ended while health remained.");
  sprintf(buf, "%s [%s] %s", msgHead, "PVE", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    PVE Combat test on level 1 combatants
*/
void TestBattle::level1_pve() {
  bool pendingWork = true;
  this->player1 = new Player();
  this->toon1 = new Toon();
  this->battle->startPVE(*player1, *toon1);

  do {
    this->battle->doCycleWork(pendingWork);
  } while(pendingWork);

  sprintf(buf, "P1:[ %d ] T1:[ %d ]", player1->get_healthstate(), toon1->get_healthstate());
  BaseCase::log->timed_log(buf);
  assertm(player1->get_healthstate() == 0 || toon1->get_healthstate() == 0, "Combat ended while health remained.");
  sprintf(buf, "%s [%s] %s", msgHead, "PVE", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Default Deconstructor
*/
TestBattle::~TestBattle() { }
