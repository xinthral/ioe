#ifndef XSTAGE_H
#define XSTAGE_H

#include <mutex>
#include <stdio.h>
#include <string>

class StageManager {
protected:
    StageManager(const std::string);
private:
    static StageManager* _singleton;
    static std::mutex _mutex;
    std::string name;
    int maxCrew = 10;
public:
    // Singletons should not be cloneable
    StageManager(StageManager&) = delete;
    // Singletons should not be assignable
    void operator=(const StageManager&) = delete;
    static StageManager *GetInstance(const std::string&);
    std::string get_name();
    void casting_call();
};

#endif // XSTAGE_H //