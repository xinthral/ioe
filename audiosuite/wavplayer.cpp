#include "wavplayer.h"
#include <cstdlib>

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*! @todo    Default Constructor */
WavPlayer::WavPlayer() {
  log = Logger::GetInstance();
  cnf = ConfigManager::GetInstance();
  sprintf(buf, "WavPlayer Loaded!");
  log->named_log(__FILENAME__, buf);
}

/*! @todo    needs desc */
void WavPlayer::playwav(const std::string& inFile) {
  // Build the aplay command
  char command[64], cmdline[128];
#if defined(_WIN32)
  sprintf(command, "%s", cnf->raw_config("VLCPATHW").c_str());
  sprintf(cmdline, "%s --qt-start-minimized --play-and-exit %s", command, inFile.c_str());
#else
  sprintf(command, "%s", cnf->raw_config("VLCPATHL").c_str());
  sprintf(cmdline, "%s --play-and-exit --audiofile-wav %s", command, inFile.c_str());
#endif
  // printf("_______ %s\n", cmdline);

  // Call aplay using the system command
  int result = std::system(cmdline);

  // Check the result
  if (result == 0) { sprintf(buf, "WavFile executed successfully."); } 
  else { sprintf(buf, "Error executing WavFile: %s.", cmdline); }
  log->named_log(__FILENAME__, buf);
}

/*! @todo    Default Deconstructor */
WavPlayer::~WavPlayer() { }