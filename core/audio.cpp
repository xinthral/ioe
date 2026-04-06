
#include "audio.h"

/*!
 * @def     __FILENAME__
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Protected Constructor
*/
AudioDriver::AudioDriver() {
  log = Logger::GetInstance();
}

/*!
 * @brief   Helper Hook used in CLI Help System
*/
void AudioDriver::_help() {
  std::string helpline = "\nAudioDriver Help File"
  "\n\nBase class for format-specific audio drivers (WAV, MP3, FLAC)."
  "\nUse a concrete driver or AudioPlayer to load and play audio files.\n";
  log->named_log(__FILENAME__, helpline);
}

/*!
 * @brief   Default Deconstructor
*/
AudioDriver::~AudioDriver() { }
