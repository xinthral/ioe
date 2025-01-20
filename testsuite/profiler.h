#ifndef PROFILER_H
#define PROFILER_H

#include <iostream>
#include <chrono>
#include <string>
#include <unordered_map>
#include <vector>
#include <iomanip>

class Profiler {
private:
  std::string functionName_;
  std::chrono::time_point<std::chrono::high_resolution_clock> startTime_;

  struct ProfileData {
    int calls = 0;
    double totalTime = 0.0;
  };

  static inline std::unordered_map<std::string, ProfileData> profileData_;

  static void logDuration(const std::string& functionName, double duration) {
    auto& data = profileData_[functionName];
    data.calls++;
    data.totalTime += duration;
  }

public:
  // Constructor starts the timer
  Profiler(const std::string&);

    // Function to display the profiling report
  static void report() {
    std::cout << "\nProfiling Report:\n";
    std::cout << std::setw(30) << std::left << "Function" 
              << std::setw(15) << "Calls" 
              << std::setw(20) << "Total (ms)" 
              << std::setw(20) << "Average (ms)\n";
    std::cout << std::string(85, '-') << "\n";

    for (const auto& [name, data] : profileData_) {
      double avgTime = data.totalTime / data.calls;
      std::cout << std::setw(30) << name
                << std::setw(15) << data.calls
                << std::setw(20) << data.totalTime
                << std::setw(20) << avgTime << "\n";
    }
  }
  // Destructor stops the timer and logs the duration
  ~Profiler();

};

// Macro to simplify usage
#define PROFILE_FUNCTION() Profiler profiler(__FUNCTION__)

#endif // PROFILER_H