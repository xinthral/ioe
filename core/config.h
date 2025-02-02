#ifndef CONFIG_H
#define CONFIG_H

#include <fstream>
#include <iostream>
#include <mutex>
#include <regex>
#include <string>
// #include <stdexcept>
#include <unordered_map>
#include <vector>
#include "logger.h"
#include "utilz.h"

//! External Varables
extern std::string _CNF_;

/*!
 * @class   ConfigManager config.h config.cpp
 * @brief   ConfigManager manages configuration loading and updating throughout the engine.
 * @details In order to handle the number of customizable options for the engine, a config
 *          file system has been implemented. This class will manage the configuration file
 *          and return it's content to the engine. 
 * @note    values can be reloaded without having to restart the engine.
*/
class ConfigManager {
protected:
  /*!
   * @brief Protected Constructor
  */
  ConfigManager();

private:
  Logger*                 log;                    //!< Logging Handler Instantiation
  std::ifstream           conf;                   //!< Configuration File Input Stream
  std::unordered_map<
    std::string, std::string
  > settings;                                     //!< Lookup Map for Settings by Key,Value
  std::string             delim = "=";            //!< Delimer seperating Key and Value
  static ConfigManager*   _singleton;             //!< Singleton Instance
  static std::mutex       _mutex;                 //!< Lock Mutex
  char                   buf[1024];               //!< Buffer Value for Logger outputs

public:
  ConfigManager(ConfigManager&) = delete;         //!< Singletons should not be cloneable
  void operator=(const ConfigManager&) = delete;  //!< Singletons should not be assignable

  /*!
   * @brief Singleton Constructor
  */
  static ConfigManager* GetInstance();              

  /*!
   * @brief   Reads in Config File and Parses Options
   * @param[in] _debug - Debugging Option
   * @return  Confirmation that all values were loaded
  */
  bool load_config(bool);

  /*!
   * @brief   Reload Settings
   * @details Forces a reload of the injested settings list,
   *          and outputs the configs to the logs.
  */
  void reload_state();

  /*!
   * @brief   Injest Setting into struct, and return struct size.
   * @param[in] option - The Key value for lookup
   * @param[in] value  - The data value associated with the key
   * @return  Returns current config queue size 
  */
  size_t add_setting(const std::string&,const std::string&);

  /*!
   * @brief   Remove Setting from injested list
   * @param[in] option - The name of the Configuration Option 
   * @return  Current Size of Settings List
  */
  size_t rem_setting(const std::string&);

  /*!
   * @brief   Return the Value of a Configuration Option 
   * @param[in] option - The name of the Configuration Option
   * @return  The value related to input key
  */
  std::string raw_config(const std::string&);

  /*!
   * @brief   Return the list of authorized commands for the 
   *          CLI Suite
   * @param[out] option - A string array to recieve the commands
  */
  void get_authorizedCommands(std::vector<std::string>&);

  /*!
   * @brief   Helper Function: Attack 
   * @return  Return base attack value 
  */
  int get_attack();

  /*!
   * @brief   Helper Function: Base Scalar
   * @return  Return base scalar value 
  */
  int get_base();

  /*!
   * @brief   Helper Function: Defense 
   * @return  Return base defense value 
  */
  int get_defense();

  /*!
   * @brief   Helper Function: Difficulty
   * @return  Return base difficulty value
  */
  int get_difficulty();

  /*!
   * @brief   Helper Function: Flux 
   * @return  Return base flux value 
  */
  int get_flux();

  /*!
   * @brief   Helper Function: Health
   * @return  Return base health value 
  */
  int get_health();

  /*!
   * @brief   Helper Function: Settings 
   * @return  Return size of settings vector 
  */
  size_t get_settingsSize();

  /*!
   * @brief   Helper Function: Version
   * @return  Return game version
  */
  std::string get_version();

  /*!
   * @brief   Helper Hook used in CLI Help System
  */
  void _help();

  /*!
   * @brief   Default Deconstructor
  */
  ~ConfigManager();
};

#endif // CONFIG_H //
