#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <string>
#include "../core/config.h"
#include "../core/logger.h"

/*!
 * @class   AudioPlayer audioplayer.h audioplayer.cpp
 * @brief   Format-agnostic audio player - plays WAV, MP3, and FLAC via VLC
*/
class AudioPlayer {
protected:
  ConfigManager*  cnf;
  Logger*         log;
  char            buf[1024];
private:
public:
  /*! @brief   Default Constructor */
  AudioPlayer();

  /*!
   * @brief   Play an audio file
   * @param[in] filename - Path to WAV, MP3, or FLAC file
  */
  void play(const std::string& filename);

  /*! @brief   Default Deconstructor */
  ~AudioPlayer();
};

#endif // AUDIOPLAYER_H //
