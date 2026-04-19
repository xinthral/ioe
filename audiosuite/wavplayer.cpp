#include "wavplayer.h"
#if defined(_WIN32)
#include <windows.h>
#else
#include <sys/wait.h>
#include <unistd.h>
#endif

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
  int result = -1;
#if defined(_WIN32)
  std::string vlcPath = cnf->raw_config("VLCPATHW");
  std::string args = vlcPath + " --qt-start-minimized --play-and-exit \"" + inFile + "\"";
  STARTUPINFOA si{}; si.cb = sizeof(si);
  PROCESS_INFORMATION pi{};
  DWORD exitCode = 1;
  if (CreateProcessA(vlcPath.c_str(), args.data(), nullptr, nullptr, FALSE, 0, nullptr, nullptr, &si, &pi)) {
    WaitForSingleObject(pi.hProcess, INFINITE);
    GetExitCodeProcess(pi.hProcess, &exitCode);
    CloseHandle(pi.hProcess); CloseHandle(pi.hThread);
    result = (exitCode == 0) ? 0 : -1;
  }
#else
  std::string vlcPath = cnf->raw_config("VLCPATHL");
  pid_t pid = fork();
  if (pid == 0) {
    const char* args[] = { vlcPath.c_str(), "--play-and-exit", "--audiofile-wav", inFile.c_str(), nullptr };
    execvp(vlcPath.c_str(), const_cast<char* const*>(args));
    _exit(1);
  } else if (pid > 0) {
    int status;
    waitpid(pid, &status, 0);
    result = (WIFEXITED(status) && WEXITSTATUS(status) == 0) ? 0 : -1;
  }
#endif
  if (result == 0) { snprintf(buf, sizeof(buf), "WavFile executed successfully."); }
  else             { snprintf(buf, sizeof(buf), "Error executing WavFile: %s.", inFile.c_str()); }
  log->named_log(__FILENAME__, buf);
}


/*! @brief   Default Deconstructor */
WavPlayer::~WavPlayer() { }