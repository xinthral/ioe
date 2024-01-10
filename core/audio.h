#ifndef XAUDIO_H
#define XAUDIO_H

#include <cstring>
#include <fstream>
#include <vector>
#include "config.h"
#include "logger.h"

/*!
 * @class   AudioDriver audio.h audio.cpp
 * @brief   AudioDriver handles audio filtering, sampling and 
 *          otherwise manipulating sound.
 * @details needs desc
*/
class AudioDriver {
protected:
  ConfigManager* cnf;           //!< ConfigManager Instantiation
  Logger*        log;           //!< Logging Handler Instantiation
  char           buf[1024];     //!< Buffer Value for Logger outputs
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
  };                            //!< Struct to hold wav metadata
  WavHeader header;             //!< Wav Struct instantiation
  std::vector<short> audioData; //!< Array of audio data
public:
  /*!
   * @brief   Default Constructor
  */
  AudioDriver();

  /*!
   * @brief   Injest Wav File
   * @param[in] filename - Name of Wav File in the Samples Directory
  */
  void readWavData(const std::string&);

  /*!
   * @brief   Return audio data
  */
  std::vector<short> getAudioData();

  /*!
   * @brief   Return sample rate 
  */
  int getSampleRate();

  /*!
   * @brief   Return channel count 
  */
  int getNumChannels();

  /*!
   * @brief   Default Deconstructor
  */
  ~AudioDriver();
};

#endif // XAUDIO_H //