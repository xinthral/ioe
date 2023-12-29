#ifndef TESTPLAYER_H 
#define TESTPLAYER_H

#include "basecase.h"
#include "../core/player.h"

class TestPlayer: public BaseCase {
protected:
  Player* dummy;
private:
public:
  TestPlayer();
  void test_all();
  void test_isAlive();
  void test_isFighting();
  ~TestPlayer();
};

#endif // TESTPLAYER_H //
