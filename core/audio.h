#ifndef XAUDIO_H
#define XAUDIO_H

#include <cstring>
#include <fstream>
#include <vector>
#include "config.h"
#include "logger.h"

class AudioDriver {
protected:
  ConfigManager*    cnf;
  Logger*           log;
private:
  struct WavHeader {
    char chunkId[4];
    uint32_t chunkSize;
    char format[4];
    char subchunk1Id[4];
    uint32_t subchunk1Size;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    char subchunk2Id[4];
    uint32_t subchunk2Size;
  };
  WavHeader header;
  std::vector<short> audioData;

public:
  AudioDriver();
  void readWavData(const std::string&);
  std::vector<short> getAudioData();
  int getSampleRate();
  int getNumChannels();
  ~AudioDriver();
};

#endif // XAUDIO_H //