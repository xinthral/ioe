#ifndef TESTAUDIO_H
#define TESTAUDIO_H

#include "basecase.h"

class TestAudio : public BaseCase {
protected:
  char msgHead[32];
  char msgTail[16];
  char msgNote[64];
private:
  AudioDriver* audio;
public:
  TestAudio();
  void test_all();
  void wavSampling();
  ~TestAudio();
};

#endif // TESTAUDIO_H //
