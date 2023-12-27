#ifndef WAVSAMPLING_H
#define WAVSAMPLING_H

#include <string>
#include "../core/audio.h"
#include "../core/logger.h"

class WaveSampler {
protected:
private:
  Logger* log;
public:
  AudioDriver* wavReader;
  WaveSampler();
  void sampleFile(const std::string&);
  ~WaveSampler();
};

#endif // WAVSAMPLING_H //