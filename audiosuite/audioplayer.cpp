#include "audioplayer.h"
#include <cstdlib>

/*!
 * @def     __FILENAME__
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

AudioPlayer::AudioPlayer() {
  log = Logger::GetInstance();
  cnf = ConfigManager::GetInstance();
  log->named_log(__FILENAME__, "AudioPlayer Loaded!");
}

/*!
 * @brief   Play an audio file using VLC.
 * @details Builds a VLC command using the configured path (VLCPATHW on Windows,
 *          VLCPATHL on Linux). VLC auto-detects the format, so WAV, MP3, and
 *          FLAC are all supported without format-specific flags.
*/
void AudioPlayer::play(const std::string& filename) {
  char command[64], cmdline[256];
#if defined(_WIN32)
  sprintf(command, "%s", cnf->raw_config("VLCPATHW").c_str());
  sprintf(cmdline, "%s --qt-start-minimized --play-and-exit %s", command, filename.c_str());
#else
  sprintf(command, "%s", cnf->raw_config("VLCPATHL").c_str());
  sprintf(cmdline, "%s --play-and-exit %s", command, filename.c_str());
#endif

  int result = std::system(cmdline);
  if (result == 0) { sprintf(buf, "Played successfully: %s", filename.c_str()); }
  else             { sprintf(buf, "Error playing file: %s", cmdline); }
  log->named_log(__FILENAME__, buf);
}

/*! @brief   Default Deconstructor */
AudioPlayer::~AudioPlayer() { }
