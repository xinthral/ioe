#include "wavsampling.h"

WaveSampler::WaveSampler() { }

void WaveSampler::sampleFile(const std::string& filename) {
  //! Scoped Variables
  Logger* log = Logger::GetInstance();
  char buf[128];

  //! Instantiate Audio Module 
  wavReader = new AudioDriver(filename);

  //! Access audio data and other information
  if (!wavReader->getAudioData().empty()) {
    sprintf(buf, "\n  Sample Rate: %d Hz", wavReader->getSampleRate());
    log->named_log(__FILE__, buf);
    sprintf(buf, "  Channels: %d", wavReader->getNumChannels());
    log->raw_log(buf);

    //! Sample some audio data (for demonstration purposes)
    for (int i = 0; i < std::min(10, static_cast<int>(wavReader->getAudioData().size())); ++i) {
      sprintf(buf, "  Sample %d: %d", i, wavReader->getAudioData()[i]);
      log->raw_log(buf);
    }
  }
}

WaveSampler::~WaveSampler() { }
