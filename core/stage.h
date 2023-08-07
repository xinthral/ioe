#ifndef STAGE_H
#define STAGE_H

#include <mutex>
#include <stdio.h>
#include <string>
#include "logger.h"

class StageManager {
protected:
    StageManager(const std::string);
private:
    static StageManager* _singleton;
    static std::mutex _mutex;
    Logger* log;
    std::string name;
    int maxCrew = 10;
    char buf[128];
public:
    //! Singletons should not be cloneable
    StageManager(StageManager&) = delete;
    //! Singletons should not be assignable
    void operator = (const StageManager&) = delete;
    static StageManager *GetInstance(const std::string&);
    std::string get_name();
    void casting_call();
    void _help();
    ~StageManager();
};

#endif // STAGE_H //