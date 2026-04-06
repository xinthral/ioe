#ifndef XAUDIO_H
#define XAUDIO_H

#include <string>
#include <vector>
#include "logger.h"

/*!
 * @class   AudioDriver audio.h audio.cpp
 * @brief   Abstract base class for format-specific audio drivers.
 * @details Provides a common interface for reading and querying decoded PCM
 *          audio data regardless of source format (WAV, MP3, FLAC, etc.).
*/
class AudioDriver {
protected:
  Logger* log;      //!< Logging Handler
  char    buf[1024]; //!< Buffer for Logger outputs

  /*!
   * @brief   Protected constructor — use a concrete derived class
  */
  AudioDriver();

public:
  //! Non-copyable
  AudioDriver(AudioDriver&) = delete;
  void operator=(const AudioDriver&) = delete;

  /*!
   * @brief   Decode audio from file into PCM samples
   * @param[in] filename - Path to the audio file
  */
  virtual void readAudioData(const std::string& filename) = 0;

  /*!
   * @brief   Return decoded PCM samples as signed 16-bit integers
  */
  virtual std::vector<short> getAudioData() = 0;

  /*!
   * @brief   Return sample rate in Hz
  */
  virtual int getSampleRate() = 0;

  /*!
   * @brief   Return number of audio channels
  */
  virtual int getNumChannels() = 0;

  /*!
   * @brief   Return bit depth of the source file
  */
  virtual int getBitsPerSample() = 0;

  /*!
   * @brief   Helper Hook used in CLI Help System
  */
  virtual void _help();

  /*!
   * @brief   Default Deconstructor
  */
  virtual ~AudioDriver();
};

#endif // XAUDIO_H //
