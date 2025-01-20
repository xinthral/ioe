#ifndef PROFILER_H
#define PROFILER_H

#include <iostream>
#include <chrono>
#include <string>
#include <unordered_map>
#include <vector>
#include <iomanip>
#include <mutex>

// Class for memory tracking
class MemoryProfiler {
private:
  size_t currentMemoryUsage_;
  size_t peakMemoryUsage_;

public:
  /*!
   * @brief   Constructor for the MemoryProfiler class.
   *
   * @details Initializes the current and peak memory usage to 0.
   */
  MemoryProfiler() : currentMemoryUsage_(0), peakMemoryUsage_(0) {}


  /*!
   * @brief   Allocates memory of the specified size and updates the current and peak memory usage.
   *
   * @details This function uses the malloc function to allocate memory of the given size. It also updates
   *          the current memory usage by adding the specified size to it. If the current memory usage
   *          exceeds the peak memory usage, the peak memory usage is updated accordingly.
   *
   * @param[in] size The size of the memory to be allocated.
   * @return  A pointer to the allocated memory.
  */
  void* allocate(size_t);

  /*!
   * @brief   Deallocates memory previously allocated using the MemoryProfiler::allocate function.
   *
   * @details This function decreases the current memory usage by the given size and then frees the memory
   *          pointed to by the provided pointer.
   *
   * @param[in] ptr   Pointer to the memory block to be deallocated.
   * @param[in] size  Size of the memory block to be deallocated.
   *
   * @return void
  */
  void deallocate(void* ptr, size_t size);

  /*!
   * @brief   Get the current memory usage tracked by the profiler.
   *
   * @details This function returns the current memory usage in bytes. The memory usage is tracked by
   *          incrementing it whenever memory is allocated and decrementing it whenever memory is deallocated.
   *
   * @return  The current memory usage in bytes.
  */
  size_t getCurrentMemoryUsage() const;

  /*!
   * @brief   Get the peak memory usage tracked by the profiler.
   *
   * @details This function returns the maximum amount of memory (in bytes) that has been allocated
   *          since the profiler was created or since the peak memory usage was last reset.
   *
   * @return  The peak memory usage in bytes.
  */
  size_t getPeakMemoryUsage() const;
};

class MemoryTracker {
  size_t startAlloc;
public:
  /*!
   * @brief   Constructor for the MemoryTracker class.
   *
   * @details Initializes the startAlloc member variable with the current total allocated memory.
   *          This value is used to track the memory usage of a specific function or block of code.
  */
  MemoryTracker();

  /*!
   * @brief   Destructor for MemoryTracker.
   *
   * @details This function calculates and prints the memory used by the function that created this MemoryTracker instance.
   *          It does this by subtracting the startAlloc value from the totalAllocated value at the time of destruction.
   *          The result is then printed to the console.
   *
   * @note    This destructor is automatically called when the MemoryTracker instance goes out of scope.
  */
  ~MemoryTracker();
};

// Profiler class for timing and memory profiling
class Profiler {
private:
  std::string functionName_;
  std::chrono::time_point<std::chrono::high_resolution_clock> startTime_;
  MemoryProfiler memoryProfiler_; // Memory profiling for each function
  size_t startMemory_;

  struct ProfileData {
    int calls = 0;
    double totalTime = 0.0;
    size_t maxMemoryUsage = 0;
  };

  static inline std::unordered_map<std::string, ProfileData> profileData_;

  static void logProfileData(const std::string&, double, size_t);

public:
  // Constructor starts the timer and memory tracking
  Profiler(const std::string& functionName);

  // Function to display the profiling report
  static void report();

  // Destructor stops the timer and logs the duration and memory usage
  ~Profiler();
};

// Macros to simplify usage
#define PROFILE_FUNCTION() Profiler profiler(__FUNCTION__)
#define PROFILE_FUNCTION_MEMORY() MemoryTracker memoryTracker;

#endif // PROFILER_H //
