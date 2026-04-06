#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-function"
#define DR_MP3_IMPLEMENTATION
#include "../vendor/dr_mp3.h"
#pragma GCC diagnostic pop

#include "mp3driver.h"

/*!
 * @def     __FILENAME__
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

Mp3Driver::Mp3Driver() : AudioDriver() {
  sampleRate = 0; numChannels = 0;
}

void Mp3Driver::readAudioData(const std::string& filename) {
  drmp3_config config;
  drmp3_uint64 frameCount;
  drmp3_int16* samples = drmp3_open_file_and_read_pcm_frames_s16(
    filename.c_str(), &config, &frameCount, NULL
  );
  if (!samples) {
    sprintf(buf, "Failed to open MP3 file: %s", filename.c_str());
    log->named_log(__FILENAME__, buf);
    return;
  }
  sampleRate  = config.sampleRate;
  numChannels = config.channels;
  audioData.assign(samples, samples + frameCount * config.channels);
  drmp3_free(samples, NULL);
}

std::vector<short> Mp3Driver::getAudioData()  { return audioData; }
int Mp3Driver::getSampleRate()                 { return sampleRate; }
int Mp3Driver::getNumChannels()                { return numChannels; }
int Mp3Driver::getBitsPerSample()              { return 16; }  //!< MP3 always decodes to 16-bit

Mp3Driver::~Mp3Driver() { }
