#ifndef XLOGGER_H
#define XLOGGER_H

#include <stdio.h>
#include <mutex>
#include <string>
#include <unordered_map>
#include "utilz.h"

class Logger {
protected:
    Logger();
private:
    std::unordered_map<std::string, std::string> settings;
    static const std::string DELIM;
    static Logger* _singleton;
    static std::mutex _mutex;
public:
    // Singletons should not be cloneable
    Logger(Logger&) = delete;
    // Singletons should not be assignable
    void operator=(const Logger&) = delete;
    // Singleton Constructor
    static Logger* GetInstance();
    void raw_log(std::string);
    void formed_log(std::string);
    void named_log(std::string, std::string); 
    ~Logger();
};


#endif // XLOGGER_H //