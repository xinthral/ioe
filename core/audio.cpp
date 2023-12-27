/*!
 * @class   AudioDriver audio.h audio.cpp
 * @brief   AudioDriver handles audio filtering, sampling and 
 *          otherwise manipulating sound.
 * @details needs desc
*/
#include "audio.h"

AudioDriver::AudioDriver() {
  log = Logger::GetInstance();
}

void AudioDriver::readWavData(const std::string& filename) {
  std::ifstream file(filename, std::ios::binary);

  if (!file.is_open()) {
    std::cerr << "Failed to open WAV file: " << filename << std::endl;
    return;
  }

  // Read WAV header
  file.read(reinterpret_cast<char*>(&header), sizeof(header));

  if (file.gcount() != sizeof(header)) {
    std::cerr << "Error reading WAV header." << std::endl;
    return;
  }

  // Check if the file is a valid WAV file
  if (std::memcmp(header.chunkId, "RIFF", 4) != 0 || std::memcmp(header.format, "WAVE", 4) != 0 || header.subchunk1Size != 16 || header.audioFormat != 1) {
    std::cerr << "Invalid or unsupported WAV file." << std::endl;
    return;
  }

  // Read audio data
  audioData.resize(header.subchunk2Size / sizeof(short));
  file.read(reinterpret_cast<char*>(audioData.data()), header.subchunk2Size);

}

std::vector<short> AudioDriver::getAudioData() {
    return audioData;
}

int AudioDriver::getSampleRate() {
    return header.sampleRate;
}

int AudioDriver::getNumChannels() {
    return header.numChannels;
}

AudioDriver::~AudioDriver() { }
