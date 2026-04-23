#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <deque>
#include <ctime>
#include <mutex>
#include <string>
#include "logger.h"

/*!
 * @struct  LeaderEntry leader.h
 * @brief   A single ranked entry — actor name, recorded value, and submission timestamp
*/
struct LeaderEntry {
  std::string name;
  int         value;
  std::time_t timestamp;
};

/*!
 * @class   LeaderBoard leader.cpp leader.h
 * @brief   Singleton session leaderboard tracking peak performance across eight categories
 * @details Each section holds up to 10 entries sorted descending by value. Callers submit
 *          values via the record_* methods; the board inserts in sorted order and trims to
 *          the top 10 automatically.
 *
 *          Burst categories (damage_burst_30s, heal_burst_30s) expect the caller to
 *          accumulate totals over a 30-second window and submit the final sum.
 *
 *          player_wealth is a stub pending a wealth field on the Player class.
*/
class LeaderBoard {
protected:
  /*!
   * @brief   Protected Constructor
  */
  LeaderBoard();

private:
  static LeaderBoard* _singleton; //!< Singleton Instance
  static std::mutex   _mutex;     //!< Lock Mutex
  Logger*             log;        //!< Logging Handler
  char                buf[1024];  //!< Scratch buffer for log output

  static constexpr int HISTORY = 10; //!< Max entries kept per section

  std::deque<LeaderEntry> _single_damage;   //!< Largest single damage hit
  std::deque<LeaderEntry> _burst_damage;    //!< Most damage dealt in a 30s window
  std::deque<LeaderEntry> _single_heal;     //!< Greatest single heal
  std::deque<LeaderEntry> _burst_heal;      //!< Most healing done in a 30s window
  std::deque<LeaderEntry> _toon_level;      //!< Highest level Toon
  std::deque<LeaderEntry> _player_level;    //!< Highest level Player
  std::deque<LeaderEntry> _player_health;   //!< Greatest current health (Player)
  std::deque<LeaderEntry> _player_wealth;   //!< Greatest wealth — stub, pending Player field

  /*!
   * @brief   Insert an entry into a section in descending value order and trim to HISTORY
   * @param[in,out] section  Target leaderboard section
   * @param[in]     entry    Entry to insert
  */
  void submit(std::deque<LeaderEntry>& section, const LeaderEntry& entry);

  /*!
   * @brief   Print all entries in a named section to the log
   * @param[in] title    Display title for the section
   * @param[in] section  Section to print
  */
  void print_section(const char* title, const std::deque<LeaderEntry>& section) const;

public:
  //! Singletons should not be cloneable
  LeaderBoard(LeaderBoard&) = delete;

  //! Singletons should not be assignable
  void operator=(const LeaderBoard&) = delete;

  /*!
   * @brief   Return the singleton LeaderBoard instance, creating it on first call
  */
  static LeaderBoard* GetInstance();

  /*!
   * @brief   Record a single-hit damage value
   * @param[in] name    Actor name
   * @param[in] damage  Damage dealt in one hit
  */
  void record_single_damage(const std::string& name, int damage);

  /*!
   * @brief   Record total damage dealt over a 30-second window
   * @param[in] name   Actor name
   * @param[in] total  Accumulated damage total for the window
  */
  void record_burst_damage(const std::string& name, int total);

  /*!
   * @brief   Record a single heal value
   * @param[in] name   Actor name
   * @param[in] heal   HP restored in one heal
  */
  void record_single_heal(const std::string& name, int heal);

  /*!
   * @brief   Record total healing done over a 30-second window
   * @param[in] name   Actor name
   * @param[in] total  Accumulated healing total for the window
  */
  void record_burst_heal(const std::string& name, int total);

  /*!
   * @brief   Record a Toon's level
   * @param[in] name   Toon name
   * @param[in] level  Toon's current level
  */
  void record_toon_level(const std::string& name, int level);

  /*!
   * @brief   Record a Player's level
   * @param[in] name   Player name
   * @param[in] level  Player's current level
  */
  void record_player_level(const std::string& name, int level);

  /*!
   * @brief   Record a Player's current health
   * @param[in] name   Player name
   * @param[in] hp     Player's current HP
  */
  void record_player_health(const std::string& name, int hp);

  /*!
   * @brief   Record a Player's wealth — stub pending Player::get_wealth()
   * @param[in] name   Player name
   * @param[in] gold   Player's current gold/wealth value
  */
  void record_player_wealth(const std::string& name, int gold);

  /*!
   * @brief   Print all leaderboard sections to the log
  */
  void display() const;

  /*!
   * @brief   Helper Hook used in CLI Help System
  */
  void _help();

  /*!
   * @brief   Default Deconstructor
  */
  ~LeaderBoard();
};

#endif  // LEADERBOARD_H //
