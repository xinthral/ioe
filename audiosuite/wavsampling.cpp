#include "wavsampling.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*! @todo    Default Constructor */
WavSampler::WavSampler() { log = Logger::GetInstance(); }

/*! @todo    needs desc */
void WavSampler::sampleFile(const std::string& filename) {
  //! Scoped Variables
  char buf[128];

  //! Instantiate Audio Module 
  wavReader = new AudioDriver();
  wavReader->readWavData(filename);

  //! Access audio data and other information
  if (!wavReader->getAudioData().empty()) {
    sprintf(buf, "\n  Sample Rate: %d Hz", wavReader->getSampleRate());
    log->named_log(__FILENAME__, buf);
    sprintf(buf, "  Channels: %d", wavReader->getNumChannels());
    log->raw_log(buf);

    //! Sample some audio data (for demonstration purposes)
    for (int i = 0; i < std::min(10, static_cast<int>(wavReader->getAudioData().size())); ++i) {
      sprintf(buf, "  Sample %d: %d", i, wavReader->getAudioData()[i]);
      log->raw_log(buf);
    }
  }
}

/*! @todo    Default Deconstructor */
WavSampler::~WavSampler() { }
