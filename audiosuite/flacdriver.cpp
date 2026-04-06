#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-function"
#define DR_FLAC_IMPLEMENTATION
#include "../vendor/dr_flac.h"
#pragma GCC diagnostic pop

#include "flacdriver.h"

/*!
 * @def     __FILENAME__
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

FlacDriver::FlacDriver() : AudioDriver() {
  sampleRate = 0; numChannels = 0; bitsPerSample = 0;
}

void FlacDriver::readAudioData(const std::string& filename) {
  drflac* flac = drflac_open_file(filename.c_str(), NULL);
  if (!flac) {
    sprintf(buf, "Failed to open FLAC file: %s", filename.c_str());
    log->named_log(__FILENAME__, buf);
    return;
  }
  sampleRate    = flac->sampleRate;
  numChannels   = flac->channels;
  bitsPerSample = flac->bitsPerSample;
  audioData.resize(flac->totalPCMFrameCount * flac->channels);
  drflac_read_pcm_frames_s16(flac, flac->totalPCMFrameCount, audioData.data());
  drflac_close(flac);
}

std::vector<short> FlacDriver::getAudioData()  { return audioData; }
int FlacDriver::getSampleRate()                 { return sampleRate; }
int FlacDriver::getNumChannels()                { return numChannels; }
int FlacDriver::getBitsPerSample()              { return bitsPerSample; }

FlacDriver::~FlacDriver() { }
