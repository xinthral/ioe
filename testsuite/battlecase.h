#ifndef TESTBATTLE_H
#define TESTBATTLE_H

#include "basecase.h"

/*!
 * @class   TestBattle battlecase.cpp battlecase.h
 * @brief   Test for the BattleManager 
*/
class TestBattle : public BaseCase {
protected:
private:
  Battle* battle;
	Player* player1;
	Player* player2;
	Toon* toon1;
	Toon* toon2;
	Toon* toon3;
	Toon* toon4;

public:
  /*!
   * @brief   Default Constructor
  */
  TestBattle();

  /*!
   * @brief   Run full set of test on module 
  */
  void test_all();

	void l1_pve();

  /*!
   * @brief   Default Deconstructor
  */
  ~TestBattle();
};

#endif // TESTBATTLE_H //
