#ifndef PROFILER_H
#define PROFILER_H

#include <iostream>
#include <chrono>
#include <string>
#include <unordered_map>
#include <vector>
#include <iomanip>
#include <mutex>

// std::mutex memMutex;
// size_t totalAllocated = 0;
// size_t peakAllocated = 0;

// void* operator new(size_t size) {
//     std::lock_guard<std::mutex> lock(memMutex);
//     totalAllocated += size;
//     peakAllocated = std::max(peakAllocated, totalAllocated);
//     std::cout << "Allocated: " << size << " bytes, Total: " << totalAllocated << " bytes\n";
//     return malloc(size);
// }

// void operator delete(void* ptr, size_t size) noexcept {
//     std::lock_guard<std::mutex> lock(memMutex);
//     totalAllocated -= size;
//     std::cout << "Freed: " << size << " bytes, Total: " << totalAllocated << " bytes\n";
//     free(ptr);
// }


// Class for memory tracking
class MemoryProfiler {
private:
    size_t currentMemoryUsage_;
    size_t peakMemoryUsage_;

public:
    MemoryProfiler() : currentMemoryUsage_(0), peakMemoryUsage_(0) {}

    // Track allocation and memory usage
    void* allocate(size_t size) {
        currentMemoryUsage_ += size;
        if (currentMemoryUsage_ > peakMemoryUsage_) {
            peakMemoryUsage_ = currentMemoryUsage_;
        }
        return malloc(size);
    }

    // Track deallocation and memory usage
    void deallocate(void* ptr, size_t size) {
        currentMemoryUsage_ -= size;
        free(ptr);
    }

    size_t getCurrentMemoryUsage() const {
        return currentMemoryUsage_;
    }

    size_t getPeakMemoryUsage() const {
        return peakMemoryUsage_;
    }
};

class MemoryTracker {
    size_t startAlloc;
    size_t totalAllocated;
public:
    MemoryTracker() { startAlloc = totalAllocated; }
    ~MemoryTracker() {
        size_t endAlloc = totalAllocated;
        std::cout << "Memory used by function: " << (endAlloc - startAlloc) << " bytes\n";
    }
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

    // Destructor stops the timer and logs the duration and memory usage
    ~Profiler();

    // Function to display the profiling report
    static void report();
};

// Macro to simplify usage
#define PROFILE_FUNCTION() Profiler profiler(__FUNCTION__)

#endif // PROFILER_H
