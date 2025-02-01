#include "profiler.h"
#include <cstdlib>

std::mutex memMutex;
size_t totalAllocated = 0;
size_t peakAllocated = 0;

/*!
 * @brief   Overloads the global new operator to track memory allocation.
 *
 * @details This function is called whenever a new object is created using the 'new' keyword.
 *          It locks a mutex to ensure thread safety while updating the total allocated memory and peak allocated memory.
 *          The function also prints the allocated size and the total allocated memory to the console.
 *
 * @param[in] size The size of the memory to be allocated.
 * @return  A pointer to the allocated memory.
*/
void* operator new(size_t size) {
  std::lock_guard<std::mutex> lock(memMutex);
  totalAllocated += size;
  peakAllocated = std::max(peakAllocated, totalAllocated);
  // std::cout << "Allocated: " << size << " bytes, Total: " << totalAllocated << " bytes\n";
  return malloc(size);
}


/*!
 * @brief   Overloads the global delete operator to track memory deallocation.
 *
 * @details This function is called whenever an object is deleted using the 'delete' keyword.
 *          It locks a mutex to ensure thread safety while updating the total allocated memory.
 *          The function also prints the freed size and the total allocated memory to the console.
 *
 * @param[in] ptr  A pointer to the memory to be deallocated.
 * @param[in] size The size of the memory to be deallocated.
 *
 * @return  This function does not return a value.
 *
 * @note    This function is marked as 'noexcept' to indicate that it does not throw any exceptions.
*/
void operator delete(void* ptr, size_t size) noexcept {
  std::lock_guard<std::mutex> lock(memMutex);
  totalAllocated -= size;
  // std::cout << "Freed: " << size << " bytes, Total: " << totalAllocated << " bytes\n";
  free(ptr);
}

// Constructor for Memory Tracker
MemoryTracker::MemoryTracker() : startAlloc(totalAllocated) {}

// Memory Tracker Deconstructor
MemoryTracker::~MemoryTracker() {
  size_t endAlloc = totalAllocated;
  std::cout << "Memory used by function: " << (endAlloc - startAlloc) << " bytes\n";
}

// Track allocation and memory usage
void* MemoryProfiler::allocate(size_t size) {
  currentMemoryUsage_ += size;
  if (currentMemoryUsage_ > peakMemoryUsage_) {
    peakMemoryUsage_ = currentMemoryUsage_;
  }
  if (currentMemoryUsage_ > peakAllocated) {
    peakAllocated = currentMemoryUsage_;
  }
  return malloc(size);
}

// Track deallocation and memory usage
void MemoryProfiler::deallocate(void* ptr, size_t size) {
  currentMemoryUsage_ -= size;
  free(ptr);
}

// Return tracked memory usage
size_t MemoryProfiler::getCurrentMemoryUsage() const {
  return currentMemoryUsage_;
}

// Return maximum tracked memory usage
size_t MemoryProfiler::getPeakMemoryUsage() const {
  return peakMemoryUsage_;
}

Profiler::Profiler(const std::string& functionName) :
  startTime_(std::chrono::high_resolution_clock::now()),
  startMemory_(memoryProfiler_.getCurrentMemoryUsage()) {  
    std::smatch m;
    std::regex rgx1("\\w+(?=::).*");
    std::regex rgx2("(std::\\w+\\s)");
    std::regex_search(functionName, m, rgx1);
    std::string match = std::regex_replace(m.str(), rgx2, "");
    functionName_ = match;
}

void Profiler::logProfileData(const std::string& functionName, double duration, size_t memoryUsage) {
  auto& data = profileData_[functionName];
  data.calls++;
  data.totalTime += duration;
  if (memoryUsage > data.maxMemoryUsage) {
    data.maxMemoryUsage = memoryUsage;
  }
}

void Profiler::report() {
  int width = 120;
  std::cout << "\nProfiling Report:\n";
  std::cout << std::setw(width / 3) << std::left << "Function" 
            << std::setw(width / 8) << "Calls" 
            << std::setw(width / 6) << "Total (ms)" 
            << std::setw(width / 6) << "Average (ms)"
            << std::setw(width / 6) << "Peak Mem (bytes)"
            << std::endl;
  std::cout << std::string(width, '-') << "\n";

  std::map<std::string, ProfileData> sortedMap(profileData_.begin(), profileData_.end());

  for (const auto& [name, data] : sortedMap) {
    double avgTime = data.totalTime / data.calls;
    std::cout << std::setw(width / 3) << name.substr(0, width / 3.2)
              << std::setw(width / 8) << data.calls
              << std::setw(width / 6) << data.totalTime
              << std::setw(width / 6) << avgTime
              << std::setw(width / 6) << data.maxMemoryUsage << "\n";
  }
  std::cout << std::string(width, '-') << "\n" << std::endl;
}

Profiler::~Profiler() {
  auto endTime = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration<double, std::milli>(endTime - startTime_).count();
  size_t memoryUsed = totalAllocated - startMemory_;
  Profiler::logProfileData(functionName_, duration, memoryUsed);
}
