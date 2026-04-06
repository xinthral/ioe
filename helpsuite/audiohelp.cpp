#include "audiohelp.h"

/*!
 * @def     __FILENAME__
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
HelpAudio::HelpAudio() {
  Logger* log = Logger::GetInstance();
  std::string helpline = "\nAudio System Help"
    "\n\nThe audio system is organized into four layers:"

    "\n\n  1. AudioDriver  (core/audio.h)"
    "\n     Abstract base class defining the common PCM decoding interface."
    "\n     All format drivers inherit from this and implement:"
    "\n       readAudioData(filename)  - decode file into PCM samples"
    "\n       getAudioData()           - return decoded samples as int16"
    "\n       getSampleRate()          - Hz"
    "\n       getNumChannels()         - mono / stereo / etc."
    "\n       getBitsPerSample()       - bit depth of source"

    "\n\n  2. Format Drivers  (audiosuite/)"
    "\n     Concrete AudioDriver implementations backed by dr_libs"
    "\n     (single-header, public domain decoders in vendor/):"
    "\n       WavDriver   - .wav  via dr_wav.h"
    "\n       Mp3Driver   - .mp3  via dr_mp3.h"
    "\n       FlacDriver  - .flac via dr_flac.h"
    "\n     The correct driver is selected automatically by file extension."

    "\n\n  3. AudioPlayer  (audiosuite/audioplayer.h)"
    "\n     Unified player that handles WAV, MP3, and FLAC via VLC."
    "\n     VLC path is read from engine.ini:"
    "\n       VLCPATHW  - path on Windows"
    "\n       VLCPATHL  - path on Linux"
    "\n     Replaces the older WavPlayer (WAV-only)."

    "\n\n  4. WavSampler  (audiosuite/wavsampling.h)"
    "\n     Reads and analyses an audio file, logging:"
    "\n       - Sample rate and channel count"
    "\n       - First 10 PCM amplitude samples"
    "\n     On Linux, generates a GNUPlot waveform chart:"
    "\n       docs/out/amplitude_chart.png  (amplitude over time in ms)"

    "\n\nCLI Usage:"
    "\n  audiosuite.exe [filename]   Play and analyse the given audio file"
    "\n  audiosuite.exe -h           Show this help message"
    "\n\nSupported Formats:  .wav   .mp3   .flac"
    "\n";
  log->named_log(__FILENAME__, helpline);
}

/*!
 * @brief   Default Deconstructor
*/
HelpAudio::~HelpAudio() { }
