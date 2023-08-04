#ifndef CONFIG_H
#define CONFIG_H

#include <fstream>
#include <mutex>
#include <regex>
#include <string>
#include <unordered_map>
#include "logger.h"
#include "utilz.h"

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
    Logger* log;
public:
    std::ifstream conf;
    // Singletons should not be cloneable
    ConfigManager(ConfigManager&) = delete;
    // Singletons should not be assignable
    void operator=(const ConfigManager&) = delete;
    static ConfigManager* GetInstance();
    bool load_config(bool);
    void reload_state();
    size_t add_setting(const std::string&, const std::string&);
    size_t rem_setting(const std::string&);
    std::string raw_config(const std::string&);
    std::string get_version();
    int get_attack();
    int get_base();
    int get_defense();
    int get_difficulty();
    int get_health();
    void _help();
    ~ConfigManager();
};
#endif // CONFIG_H //
