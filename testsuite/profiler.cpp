#include "profiler.h"
#include <cstdlib>

Profiler::Profiler(const std::string& functionName) :
  functionName_(functionName),
  startTime_(std::chrono::high_resolution_clock::now()),
  startMemory_(memoryProfiler_.getCurrentMemoryUsage()) {  
}

Profiler::~Profiler() {
  auto endTime = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration<double, std::milli>(endTime - startTime_).count();
  size_t memoryUsed = memoryProfiler_.getCurrentMemoryUsage() - startMemory_;
  Profiler::logProfileData(functionName_, duration, memoryUsed);
}

void Profiler::report() {
  std::cout << "\nProfiling Report:\n";
  std::cout << std::setw(30) << std::left << "Function" 
            << std::setw(15) << "Calls" 
            << std::setw(20) << "Total (ms)" 
            << std::setw(20) << "Average (ms)"
            << std::setw(20) << "Peak Mem (bytes)\n";
  std::cout << std::string(105, '-') << "\n";

  for (const auto& [name, data] : profileData_) {
    double avgTime = data.totalTime / data.calls;
    std::cout << std::setw(30) << name
              << std::setw(15) << data.calls
              << std::setw(20) << data.totalTime
              << std::setw(20) << avgTime
              << std::setw(20) << data.maxMemoryUsage << "\n";
  }
}