#ifndef TESTPLAYER_H 
#define TESTPLAYER_H

#include "basecase.h"
#include "../core/player.h"

/*!
 * @class   TestPlayer testplayer.cpp testplayer.h
 * @brief   Test Case for testing Player objects
*/
class TestPlayer: public BaseCase {
protected:
private:
  Player* dummy;    //!< Placeholder Player Object
public:
/*!
 * @brief   Default Constructor
*/
  TestPlayer();

/*!
 * @brief   Run full set of test on module 
*/
  void test_all();

/*!
 * @brief   Test if Player Alive State holds
*/
  void test_isAlive();

/*!
 * @brief   Test if Player Combat State holds
*/
  void test_isFighting();

/*!
 * @brief   Default Deconstructor
*/
  ~TestPlayer();
};

#endif // TESTPLAYER_H //
