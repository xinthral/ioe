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
  this->l1_pve();
}

void TestBattle::l1_pve() {
  bool pendingWork = true;
  this->player1 = new Player();
  this->toon1 = new Toon();
  this->battle->startPVE(*player1, *toon1);

  do {
    this->battle->doCycleWork(pendingWork);
  } while(pendingWork);

  // assertm(player1->get_healthstate() == 0 || toon1->get_healthstate() == 0, "Combat ended while health remained.");
  assertm(player1->get_healthstate() == 0 || toon1->get_healthstate() == 0, "Combat ended while health remained.");
  sprintf(buf, "%s [%s] %s", msgHead, "PVE", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);

}

/*!
 * @todo    Default Deconstructor
*/
TestBattle::~TestBattle() { }
