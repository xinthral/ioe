#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-function"
#define DR_WAV_IMPLEMENTATION
#include "../vendor/dr_wav.h"
#pragma GCC diagnostic pop

#include "wavdriver.h"

/*!
 * @def     __FILENAME__
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

WavDriver::WavDriver() : AudioDriver() {
  sampleRate = 0; numChannels = 0; bitsPerSample = 0;
}

void WavDriver::readAudioData(const std::string& filename) {
  drwav wav;
  if (!drwav_init_file(&wav, filename.c_str(), NULL)) {
    sprintf(buf, "Failed to open WAV file: %s", filename.c_str());
    log->named_log(__FILENAME__, buf);
    return;
  }
  sampleRate    = wav.sampleRate;
  numChannels   = wav.channels;
  bitsPerSample = wav.bitsPerSample;
  audioData.resize(wav.totalPCMFrameCount * wav.channels);
  drwav_read_pcm_frames_s16(&wav, wav.totalPCMFrameCount, audioData.data());
  drwav_uninit(&wav);
}

std::vector<short> WavDriver::getAudioData()  { return audioData; }
int WavDriver::getSampleRate()                 { return sampleRate; }
int WavDriver::getNumChannels()                { return numChannels; }
int WavDriver::getBitsPerSample()              { return bitsPerSample; }

WavDriver::~WavDriver() { }
