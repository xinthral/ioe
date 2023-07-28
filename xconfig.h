#ifndef XCONFIG_H
#define XCONFIG_H

#include <fstream>
#include <mutex>
#include <regex>
#include <string>
#include <unordered_map>

/* External Varables */
extern std::string _CNF_;

/* Class Declarations */
class ConfigManager {
protected:
    ConfigManager();
private:
    std::unordered_map<std::string, std::string> settings;
    std::string delim = "=";
    static ConfigManager* _singleton;
    static std::mutex _mutex;
public:
    std::ifstream conf;
    // Singletons should not be cloneable
    ConfigManager(ConfigManager&) = delete;
    // Singletons should not be assignable
    void operator=(const ConfigManager&) = delete;
    static ConfigManager* GetInstance();
    size_t add_setting(const std::string&, const std::string&);
    size_t rem_setting(const std::string&);
    void display_state();
    bool load_config(bool);
    ~ConfigManager();
};
#endif // XCONFIG_H //
