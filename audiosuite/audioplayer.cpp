#include "audioplayer.h"
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
  int result = -1;
#if defined(_WIN32)
  std::string vlcPath = cnf->raw_config("VLCPATHW");
  std::string args = vlcPath + " --qt-start-minimized --play-and-exit \"" + filename + "\"";
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
    const char* args[] = { vlcPath.c_str(), "--play-and-exit", filename.c_str(), nullptr };
    execvp(vlcPath.c_str(), const_cast<char* const*>(args));
    _exit(1);
  } else if (pid > 0) {
    int status;
    waitpid(pid, &status, 0);
    result = (WIFEXITED(status) && WEXITSTATUS(status) == 0) ? 0 : -1;
  }
#endif
  if (result == 0) { snprintf(buf, sizeof(buf), "Played successfully: %s", filename.c_str()); }
  else             { snprintf(buf, sizeof(buf), "Error playing file: %s", filename.c_str()); }
  log->named_log(__FILENAME__, buf);
}

/*! @brief   Default Deconstructor */
AudioPlayer::~AudioPlayer() { }
