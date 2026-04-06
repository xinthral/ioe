#ifndef WAVDRIVER_H
#define WAVDRIVER_H

#include <vector>
#include "../core/audio.h"

/*!
 * @class   WavDriver wavdriver.h wavdriver.cpp
 * @brief   AudioDriver implementation for WAV files via dr_wav
*/
class WavDriver : public AudioDriver {
private:
  std::vector<short> audioData;
  int sampleRate;
  int numChannels;
  int bitsPerSample;

public:
  /*! @brief   Default Constructor */
  WavDriver();

  void readAudioData(const std::string& filename) override;
  std::vector<short> getAudioData() override;
  int getSampleRate() override;
  int getNumChannels() override;
  int getBitsPerSample() override;

  /*! @brief   Default Deconstructor */
  ~WavDriver();
};

#endif // WAVDRIVER_H //
