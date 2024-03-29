#include "audiocase.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor
*/
TestAudio::TestAudio() : BaseCase(__FILENAME__) {
  BaseCase::log->named_log(__FILENAME__, "Testing the Audio!");
  sprintf(this->msgHead, "Tested");
  sprintf(this->msgTail, "for Audio!");
  this->test_all();
}

/*!
 * @todo    Run full set of test on module 
*/
void TestAudio::test_all() {
  // this->wavSampling();  // #FIXME Disabled for GitHubActions because audio files missing
}

/*!
 * @todo    Sample a Wavfile
*/
void TestAudio::wavSampling() {
  audio = new AudioDriver();
  audio->readWavData("./audiosuite/samples/game-over.wav");
  assertm(audio->getSampleRate() == 44100, "Audio Wav SampleRate Mismatch");
  sprintf(buf, "%s %s %s", msgHead, "[44100] Sample Rate", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Default Deconstructor
*/
TestAudio::~TestAudio() { }
