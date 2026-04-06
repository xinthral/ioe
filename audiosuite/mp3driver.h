#ifndef MP3DRIVER_H
#define MP3DRIVER_H

#include <vector>
#include "../core/audio.h"

/*!
 * @class   Mp3Driver mp3driver.h mp3driver.cpp
 * @brief   AudioDriver implementation for MP3 files via dr_mp3
*/
class Mp3Driver : public AudioDriver {
private:
  std::vector<short> audioData;
  int sampleRate;
  int numChannels;

public:
  /*! @brief   Default Constructor */
  Mp3Driver();

  void readAudioData(const std::string& filename) override;
  std::vector<short> getAudioData() override;
  int getSampleRate() override;
  int getNumChannels() override;
  int getBitsPerSample() override;

  /*! @brief   Default Deconstructor */
  ~Mp3Driver();
};

#endif // MP3DRIVER_H //
