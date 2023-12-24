/*!
 * @class   TestAudio audiocase.cpp audiocase.h
 * @brief   Test for the LeaderBoard
*/

#include "audiocase.h"

/*!
 * @brief   Default Constructor
*/
TestAudio::TestAudio() : BaseCase(__FILE__) {
  BaseCase::log->named_log(__FILE__, "Testing the Audio!");
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
  BaseCase::log->named_log(__FILE__, "Sample Rate Success!");
}

/*!
 * @brief   Default Deconstructor
*/
TestAudio::~TestAudio() { }
