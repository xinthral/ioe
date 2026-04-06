#ifndef FLACDRIVER_H
#define FLACDRIVER_H

#include <vector>
#include "../core/audio.h"

/*!
 * @class   FlacDriver flacdriver.h flacdriver.cpp
 * @brief   AudioDriver implementation for FLAC files via dr_flac
*/
class FlacDriver : public AudioDriver {
private:
  std::vector<short> audioData;
  int sampleRate;
  int numChannels;
  int bitsPerSample;

public:
  /*! @brief   Default Constructor */
  FlacDriver();

  void readAudioData(const std::string& filename) override;
  std::vector<short> getAudioData() override;
  int getSampleRate() override;
  int getNumChannels() override;
  int getBitsPerSample() override;

  /*! @brief   Default Deconstructor */
  ~FlacDriver();
};

#endif // FLACDRIVER_H //
