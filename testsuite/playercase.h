#ifndef TESTPLAYER_H 
#define TESTPLAYER_H

#include "basecase.h"
#include "../core/player.h"

class TestPlayer: public BaseCase {
protected:
  Player* dummy;
  char msgHead[32];
  char msgTail[16];
  char msgNote[64];

private:
public:
  TestPlayer();
  void test_all();
  void test_isAlive();
  void test_isFighting();
  ~TestPlayer();
};

#endif // TESTPLAYER_H //
