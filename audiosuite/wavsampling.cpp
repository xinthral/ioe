#include "wavsampling.h"

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
WavSampler::WavSampler() { 
  log = Logger::GetInstance();
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

  //! Instantiate Audio Module 
  wavReader = new AudioDriver();
  wavReader->readWavData(filename.c_str());
  auto data = wavReader->getAudioData();

  //! Access audio data and other information
  if (!wavReader->getAudioData().empty()) {
    sprintf(buf, "\n  Sample Rate: %d Hz", wavReader->getSampleRate());
    log->named_log(__FILENAME__, buf);
    sprintf(buf, "  Channels: %d", wavReader->getNumChannels());
    log->raw_log(buf);

    //! Sample some audio data (for demonstration purposes)
    for (int i = 0; i < std::max(10, static_cast<int>(data.size())); ++i) {
      sprintf(buf, "  Sample %d: %u", i, data[i]);
      log->raw_log(buf);
    }
#if defined(__linux__)
    plotFrequencyChart(data);
#endif
  }
}

void WavSampler::plotFrequencyChart(const std::vector<short>& data) {
    std::string filename = "docs/out/data.txt";
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error: Cannot create data file!" << std::endl;
        return;
    }

    std::cout << "Converting Frequency to milliseconds" << std::endl;
    // Write data with time progression
    for (size_t i = 0; i < data.size(); ++i) {
        outFile << (i * 1000) << " " << data[i] << std::endl; // X = time, Y = frequency
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
    scriptFile << "set output 'docs/out/frequency_chart.png'\n";
    scriptFile << "set title 'Frequency Over Time'\n";
    scriptFile << "set xlabel 'Time (milliseconds)'\n";
    scriptFile << "set ylabel 'Frequency'\n";
    scriptFile << "set grid\n";
    scriptFile << "set yrange [0:*]\n";  // Ensure Y-axis starts at 0
    scriptFile << "set xrange [0:*]\n";  // Ensure X-axis starts at 0
    // BarChart
    // scriptFile << "plot '" << filename << "' using 1:2 with lines title 'Data Frequency' lw 2 lc rgb 'blue'\n";
    // ScatterPlot
    scriptFile << "plot '" << filename << "' using 1:2 with points title 'Data Points' pt 7 ps 0.3 lc rgb 'blue'\n"; // Scatterplot
    scriptFile.close();
    std::cout << "Preparing to plot" << std::endl;

    std::string cmdline = "gnuplot " + scriptFilename;
    // Run gnuplot
    system(cmdline.c_str());

    std::cout << "Plot saved as docs/out/frequency_chart.png" << std::endl;
}


/*! @todo    Default Deconstructor */
WavSampler::~WavSampler() { }
