
#include "audio.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor
*/
AudioDriver::AudioDriver() { log = Logger::GetInstance(); }

/*!
 * @todo    Injest Wav File
*/
void AudioDriver::readWavData(const std::string& filename) {
  std::ifstream file(filename, std::ios::binary);

  if (!file.is_open()) {
    sprintf(buf, "Failed to open WAV file: %s", filename);
    //!//////// Should be Error
    log->named_log(__FILENAME__, buf);
    return;
  }

  //! Read WAV header
  file.read(reinterpret_cast<char*>(&header), sizeof(header));

  if (file.gcount() != sizeof(header)) {
    sprintf(buf, "Error reading WAV header.");
    //!//////// Should be Error
    log->named_log(__FILENAME__, buf);
    return;
  }

  // Check if the file is a valid WAV file
  if (std::memcmp(header.chunkId, "RIFF", 4) != 0 || std::memcmp(header.format, "WAVE", 4) != 0 || header.subchunk1Size != 16 || header.audioFormat != 1) {
    sprintf(buf, "Invalid or unsupported WAV file.");
    //!//////// Should be Error
    log->named_log(__FILENAME__, buf);
    return;
  }

  //! Read audio data
  audioData.resize(header.subchunk2Size / sizeof(short));
  file.read(reinterpret_cast<char*>(audioData.data()), header.subchunk2Size);

}

/*!
 * @todo    Return audio data
*/
std::vector<short> AudioDriver::getAudioData() {
    return audioData;
}

/*!
 * @todo    Return sample rate 
*/
int AudioDriver::getSampleRate() {
    return header.sampleRate;
}

/*!
 * @todo    Return channel count 
*/
int AudioDriver::getNumChannels() {
    return header.numChannels;
}

/*!
 * @todo    Default Deconstructor
*/
AudioDriver::~AudioDriver() { }
