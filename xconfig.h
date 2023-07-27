#ifndef XCONFIG_H
#define XCONFIG_H

#include <fstream>
#include <mutex>
#include <string>

extern std::string _CNF_;

class ConfigManager {
protected:
    ConfigManager();
private:
    static ConfigManager* _singleton;
    static std::mutex _mutex;
public:
    std::ifstream conf;
    // Singletons should not be cloneable
    ConfigManager(ConfigManager&) = delete;
    // Singletons should not be assignable
    void operator=(const ConfigManager&) = delete;
    static ConfigManager* GetInstance();
    bool load_config();
    ~ConfigManager();
};

#endif // XCONFIG_H //