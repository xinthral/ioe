#include "profiler.h"

Profiler::Profiler(const std::string& functionName) :
  functionName_(functionName),
  startTime_(std::chrono::high_resolution_clock::now()) {
}

Profiler::~Profiler() {
  auto endTime = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration<double, std::milli>(endTime - startTime_).count();
  Profiler::logDuration(functionName_, duration);
}