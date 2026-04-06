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
  BaseCase::log->named_log(__FILENAME__, "Testing Audio Drivers!");
  sprintf(this->msgHead, "Tested");
  sprintf(this->msgTail, "for Audio!");
  wavDriver  = nullptr;
  mp3Driver  = nullptr;
  flacDriver = nullptr;
  this->test_all();
}

/*!
 * @brief   Run full set of tests on all audio modules
*/
void TestAudio::test_all() {
  this->test_wav_loads();
  this->test_wav_samplerate();
  this->test_wav_channels();
  this->test_wav_bitdepth();
  this->test_mp3_loads();
  this->test_mp3_samplerate();
  this->test_mp3_channels();
  this->test_mp3_bitdepth();
  // this->test_flac_loads();  // #TODO Enable when FLAC sample added to audiosuite/samples/
}

/*!
 * @brief   Validate WavDriver loads a file and returns non-empty data
*/
void TestAudio::test_wav_loads() {
  PROFILE_FUNCTION();
  delete wavDriver;
  wavDriver = new WavDriver();
  wavDriver->readAudioData("./audiosuite/samples/game_over.wav");
  record(!wavDriver->getAudioData().empty(), "WavDriver returned empty audio data");
  sprintf(buf, "%s %s %s", msgHead, "[WAV] Data Load", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @brief   Validate WavDriver sample rate is non-zero
*/
void TestAudio::test_wav_samplerate() {
  PROFILE_FUNCTION();
  record(wavDriver->getSampleRate() > 0, "WavDriver sample rate is zero");
  sprintf(buf, "%s [WAV] Sample Rate: %d Hz %s", msgHead, wavDriver->getSampleRate(), msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @brief   Validate WavDriver channel count is non-zero
*/
void TestAudio::test_wav_channels() {
  PROFILE_FUNCTION();
  record(wavDriver->getNumChannels() > 0, "WavDriver channel count is zero");
  sprintf(buf, "%s [WAV] Channels: %d %s", msgHead, wavDriver->getNumChannels(), msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @brief   Validate WavDriver bit depth is non-zero
*/
void TestAudio::test_wav_bitdepth() {
  PROFILE_FUNCTION();
  record(wavDriver->getBitsPerSample() > 0, "WavDriver bit depth is zero");
  sprintf(buf, "%s [WAV] Bit Depth: %d %s", msgHead, wavDriver->getBitsPerSample(), msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @brief   Validate Mp3Driver loads a file and returns non-empty data
*/
void TestAudio::test_mp3_loads() {
  PROFILE_FUNCTION();
  delete mp3Driver;
  mp3Driver = new Mp3Driver();
  mp3Driver->readAudioData("./audiosuite/samples/game_over.mp3");
  record(!mp3Driver->getAudioData().empty(), "Mp3Driver returned empty audio data");
  sprintf(buf, "%s %s %s", msgHead, "[MP3] Data Load", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @brief   Validate Mp3Driver sample rate is non-zero
*/
void TestAudio::test_mp3_samplerate() {
  PROFILE_FUNCTION();
  record(mp3Driver->getSampleRate() > 0, "Mp3Driver sample rate is zero");
  sprintf(buf, "%s [MP3] Sample Rate: %d Hz %s", msgHead, mp3Driver->getSampleRate(), msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @brief   Validate Mp3Driver channel count is non-zero
*/
void TestAudio::test_mp3_channels() {
  PROFILE_FUNCTION();
  record(mp3Driver->getNumChannels() > 0, "Mp3Driver channel count is zero");
  sprintf(buf, "%s [MP3] Channels: %d %s", msgHead, mp3Driver->getNumChannels(), msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @brief   Validate Mp3Driver reports 16-bit depth (dr_mp3 always decodes to s16)
*/
void TestAudio::test_mp3_bitdepth() {
  PROFILE_FUNCTION();
  record(mp3Driver->getBitsPerSample() == 16, "Mp3Driver bit depth is not 16");
  sprintf(buf, "%s [MP3] Bit Depth: %d %s", msgHead, mp3Driver->getBitsPerSample(), msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @brief   Validate FlacDriver loads a file and returns non-empty data
 * @note    Disabled — no FLAC samples in audiosuite/samples/
*/
void TestAudio::test_flac_loads() {
  PROFILE_FUNCTION();
  delete flacDriver;
  flacDriver = new FlacDriver();
  flacDriver->readAudioData("./audiosuite/samples/game_over.flac");
  record(!flacDriver->getAudioData().empty(), "FlacDriver returned empty audio data");
  sprintf(buf, "%s %s %s", msgHead, "[FLAC] Data Load", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @brief   Default Deconstructor
*/
TestAudio::~TestAudio() {
  delete wavDriver;
  delete mp3Driver;
  delete flacDriver;
}
