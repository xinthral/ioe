/*!
 * @class   TestAudio audiocase.cpp audiocase.h
 * @brief   Test for the LeaderBoard
*/

#include "audiocase.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
TestAudio::TestAudio() : BaseCase(__FILENAME__) {
  BaseCase::log->named_log(__FILENAME__, "Testing the Audio!");
  this->test_all();
}

/*!
 * @brief   needs desc
*/
void TestAudio::test_all() {
  // this->test_wavSampling();  // #FIXME Disabled for GitHubActions because audio files missing
}

/*!
 * @brief   needs desc
*/
void TestAudio::test_wavSampling() {
  audio = new AudioDriver();
  audio->readWavData("./audiosuite/samples/mixkit-retro-game-over.wav");
  assert(audio->getSampleRate() == 44100);
  BaseCase::log->named_log(__FILENAME__, "Sample Rate Success!");
}

/*!
 * @brief   Default Deconstructor
*/
TestAudio::~TestAudio() { }
