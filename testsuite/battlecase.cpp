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
  this->level1_pvp();
}

/*!
 * @todo    EVE Combat test on level 1 combatants
*/
void TestBattle::level1_eve() {
  bool pendingWork = true;
  this->toon1 = new Toon("Toon1");
  this->toon2 = new Toon("Toon2");
  this->battle->startEVE(toon1, toon2);

  do {
    this->battle->doCycleWork(pendingWork);
  } while(pendingWork);

  sprintf(buf, "T1 :: T2 :: [ %d ] : [ %d ]", toon1->get_health(), toon2->get_health());
  BaseCase::log->timed_log(buf);
  assertm(toon1->get_healthstate() == 4 || toon2->get_healthstate() == 4, "Combat ended while health remained.");
  sprintf(buf, "%s [%s] %s", msgHead, "EVE", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    PVE Combat test on level 1 combatants
*/
void TestBattle::level1_pve() {
  bool pendingWork = true;
  this->player1 = new Player();
  this->toon1 = new Toon("Toon1");
  this->battle->startPVE(player1, toon1);

  do {
    this->battle->doCycleWork(pendingWork);
  } while(pendingWork);

  sprintf(buf, "P1 :: T1 :: [ %d ] : [ %d ]", player1->get_health(), toon1->get_health());
  BaseCase::log->timed_log(buf);
  assertm(player1->get_healthstate() == 4 || toon1->get_healthstate() == 4, "Combat ended while health remained.");
  sprintf(buf, "%s [%s] %s", msgHead, "PVE", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    PVP Combat test on level 1 combatants
*/
void TestBattle::level1_pvp() {
  bool pendingWork = true;
  this->player1 = new Player("Player1", 1, 1, 1);
  this->player2 = new Player("Player2", 1, 1, 1);
  this->battle->startPVP(player1, player2);

  do {
    this->battle->doCycleWork(pendingWork);
  } while(pendingWork);

  sprintf(buf, "P1 :: P2 :: [ %d ] : [ %d ]", player1->get_health(), player2->get_health());
  BaseCase::log->timed_log(buf);
  assertm(player1->get_healthstate() == 4 || toon1->get_healthstate() == 4, "Combat ended while health remained.");
  sprintf(buf, "%s [%s] %s", msgHead, "PVP", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Default Deconstructor
*/
TestBattle::~TestBattle() {}
