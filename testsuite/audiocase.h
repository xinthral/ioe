#ifndef TESTAUDIO_H
#define TESTAUDIO_H

#include "basecase.h"

class TestAudio : public BaseCase {
protected:
private:
  AudioDriver* audio;
public:
  TestAudio();
  void test_all();
  void test_wavSampling();
  ~TestAudio();
};

#endif // TESTAUDIO_H //
