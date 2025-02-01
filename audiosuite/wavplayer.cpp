#include "wavplayer.h"
#include <cstdlib>

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Constructs a new instance of the WavPlayer class.
 *
 * @details This constructor initializes the Logger and ConfigManager instances,
 *          logs a message indicating that the WavPlayer has been loaded, and
 *          prepares a buffer for logging purposes.
 *
 * @note    The Logger and ConfigManager instances are obtained using their
 *          respective GetInstance methods.
*/
WavPlayer::WavPlayer() {
  log = Logger::GetInstance();
  cnf = ConfigManager::GetInstance();
  sprintf(buf, "WavPlayer Loaded!");
  log->named_log(__FILENAME__, buf);
}


/*!
 * @brief   Plays a WAV file using the system's aplay command.
 *
 * @details This function constructs a command to play a WAV file using the system's aplay command.
 *          The command is built based on the operating system (Windows or Linux) and the provided
 *          input file. The function then executes the command using the system() function and checks
 *          the result.
 *
 * @param[in] inFile - The path to the WAV file to be played.
 *
 * @note    The function uses the VLCPATHW and VLCPATHL configuration settings to determine
 *          the path to the aplay command for Windows and Linux, respectively.
 *
 * @todo    Consider using a more efficient method for playing WAV files, such as a library
 *          specifically designed for audio playback.
*/
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

  // Call aplay using the system command
  int result = std::system(cmdline);

  // Check the result
  if (result == 0) { sprintf(buf, "WavFile executed successfully."); } 
  else { sprintf(buf, "Error executing WavFile: %s.", cmdline); }
  log->named_log(__FILENAME__, buf);
}


/*! @brief   Default Deconstructor */
WavPlayer::~WavPlayer() { }