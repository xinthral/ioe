#include "wavsampling.h"
#if defined(__linux__)
#include <sys/wait.h>
#include <unistd.h>
#endif

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief Default constructor for the WavSampler class.
 *
 * @details Initializes the Logger instance for use within the class.
*/
static AudioDriver* createDriver(const std::string& filename) {
  size_t pos = filename.rfind('.');
  if (pos == std::string::npos) return nullptr;
  std::string ext = filename.substr(pos + 1);
  std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
  if (ext == "wav")  return new WavDriver();
  if (ext == "mp3")  return new Mp3Driver();
  if (ext == "flac") return new FlacDriver();
  return nullptr;
}

WavSampler::WavSampler() {
  log = Logger::GetInstance();
  wavReader = nullptr;
}

/*!
 * @brief   Samples a WAV file and logs some of its properties.
 *
 * @details This function reads a WAV file, instantiates an AudioDriver, and logs some of its properties.
 *          It demonstrates how to use the AudioDriver to access audio data and other information.
 *
 * @param[in] filename - The name of the WAV file to sample.
 *
 * @todo    Replace the sample logging with actual processing or analysis of the audio data.
*/
void WavSampler::sampleFile(const std::string& filename) {
  //! Scoped Variables
  char buf[128];
  delete wavReader;
  wavReader = createDriver(filename);
  if (!wavReader) {
    log->named_log(__FILENAME__, "Unsupported audio format");
    return;
  }
  wavReader->readAudioData(filename);
  auto data = wavReader->getAudioData();

  //! Access audio data and other information
  if (!data.empty()) {
    sprintf(buf, "\n  Sample Rate: %d Hz", wavReader->getSampleRate());
    log->named_log(__FILENAME__, buf);
    sprintf(buf, "  Channels: %d", wavReader->getNumChannels());
    log->raw_log(buf);

    //! Sample some audio data (for demonstration purposes)
    for (int i = 0; i < std::min(10, static_cast<int>(data.size())); ++i) {
      sprintf(buf, "  Sample %d: %u", i, data[i]);
      log->raw_log(buf);
    }
#if defined(__linux__)
    plotFrequencyChart(data, wavReader->getSampleRate());
#endif
  }
}

#if defined(__linux__)
void WavSampler::plotFrequencyChart(const std::vector<short>& data, int sampleRate) {
    std::string filename = "docs/out/data.txt";
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error: Cannot create data file!" << std::endl;
        return;
    }
    log->raw_log("Converting samples to milliseconds");

    // Write data with time progression - X = sample index converted to ms, Y = amplitude
    for (size_t i = 0; i < data.size(); ++i) {
        outFile << (i * 1000.0 / sampleRate) << " " << data[i] << std::endl;
    }
    outFile.close();

    // Create gnuplot script
    std::string scriptFilename = "docs/out/plot_script.gp";
    std::ofstream scriptFile(scriptFilename);
    if (!scriptFile) {
        std::cerr << "Error: Cannot create gnuplot script file!" << std::endl;
        return;
    }

    scriptFile << "set terminal pngcairo enhanced font 'Arial,10'\n";
    scriptFile << "set output 'docs/out/amplitude_chart.png'\n";
    scriptFile << "set title 'Amplitude Over Time'\n";
    scriptFile << "set xlabel 'Time (milliseconds)'\n";
    scriptFile << "set ylabel 'Amplitude'\n";
    scriptFile << "set grid\n";
    scriptFile << "set yrange [*:*]\n";  // Allow negative amplitudes
    scriptFile << "set xrange [0:*]\n";  // Ensure X-axis starts at 0

    // BarChart
    scriptFile << "plot '" << filename << "' using 1:2 with points title 'Data Points' pt 7 ps 0.3 lc rgb 'blue'\n";
    scriptFile.close();

    // Run gnuplot — use execvp to avoid shell interpretation
    log->raw_log("Preparing to plot");
    pid_t pid = fork();
    if (pid == 0) {
      const char* args[] = { "gnuplot", scriptFilename.c_str(), nullptr };
      execvp("gnuplot", const_cast<char* const*>(args));
      _exit(1);
    } else if (pid > 0) {
      waitpid(pid, nullptr, 0);
    }
    log->raw_log("Plot saved as docs/out/amplitude_chart.png");
}
#endif // defined(__linux__)

/*! @todo    Default Deconstructor */
WavSampler::~WavSampler() { 
    //! Delete AudioDriver
    delete wavReader;

}