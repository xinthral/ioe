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
    std::regex rgx("\\w+(?=::).*");
    std::smatch m;
    std::regex_search(functionName, m, rgx);
    functionName_ = m.str();
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
  std::cout << "\nProfiling Report:\n";
  std::cout << std::setw(40) << std::left << "Function" 
            << std::setw(15) << "Calls" 
            << std::setw(20) << "Total (ms)" 
            << std::setw(20) << "Average (ms)"
            << std::setw(20) << "Peak Mem (bytes)"
            << std::endl;
  std::cout << std::string(115, '-') << "\n";

  for (const auto& [name, data] : profileData_) {
    double avgTime = data.totalTime / data.calls;
    std::cout << std::setw(40) << name
              << std::setw(15) << data.calls
              << std::setw(20) << data.totalTime
              << std::setw(20) << avgTime
              << std::setw(20) << data.maxMemoryUsage << "\n";
  }
}

Profiler::~Profiler() {
  auto endTime = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration<double, std::milli>(endTime - startTime_).count();
  size_t memoryUsed = totalAllocated - startMemory_;
  Profiler::logProfileData(functionName_, duration, memoryUsed);
}
