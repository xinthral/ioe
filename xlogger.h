#ifndef XLOGGER_H
#define XLOGGER_H

#include <mutex>
#include <string>

class Logger {
protected:
    Logger();
private:
    std::unordered_map<std::string, std::string> settings;
    std::string delim = "=";
    static Logger* _singleton;
    static std::mutex _mutex;
public:
    // Singletons should not be cloneable
    Logger(Logger&) = delete;
    // Singletons should not be assignable
    void operator=(const Logger&) = delete;
    // Singleton Constructor
    static Logger* GetInstance();
    ~Logger();
};

#endif // XLOGGER_H //