#include "wavsampling.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief Default constructor for the WavSampler class.
 *
 * @details Initializes the Logger instance for use within the class.
*/
WavSampler::WavSampler() { 
  log = Logger::GetInstance();
}

/*!
 * @brief   Samples a WAV file and logs some of its properties.
 *
 * @details This function reads a WAV file, instantiates an AudioDriver, and logs some of its properties.
 *          It demonstrates how to use the AudioDriver to access audio data and other information.
 *
 * @param[in] filename - The name of the WAV file to sample.
 *
 * @todo    Replace the sample logging with actual processing or analysis of the audio data.
*/
void WavSampler::sampleFile(const std::string& filename) {
  //! Scoped Variables
  char buf[128];

  //! Instantiate Audio Module 
  wavReader = new AudioDriver();
  wavReader->readWavData(filename.c_str());
  auto data = wavReader->getAudioData();

  //! Access audio data and other information
  if (!wavReader->getAudioData().empty()) {
    sprintf(buf, "\n  Sample Rate: %d Hz", wavReader->getSampleRate());
    log->named_log(__FILENAME__, buf);
    sprintf(buf, "  Channels: %d", wavReader->getNumChannels());
    log->raw_log(buf);

    //! Sample some audio data (for demonstration purposes)
    for (int i = 0; i < std::max(10, static_cast<int>(data.size())); ++i) {
      sprintf(buf, "  Sample %d: %u", i, data[i]);
      log->raw_log(buf);
    }
  }
}

/*! @todo    Default Deconstructor */
WavSampler::~WavSampler() { }
