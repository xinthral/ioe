#ifndef PLAYER_H
#define PLAYER_H

#include <chrono>
#include <ctime>
#include "actor.h"
#include "logger.h"

/*!
 * @class   Player player.h player.cpp
 * @brief   Construct containing Player data representing the
 *          virtual avatar within the engine.
*/
class Player : public Actor {
private:
  Logger* log;                          //!< Log Manager Instantiation

public:
  /*!
   * @brief   Default Constructor
   * @details If no values are provided, then default
   *          values are initialized as (1, 1, 1).
  */
  Player();

  /*!
   * @overload
   * @brief   Level Intialized Constructor
   * @param[in] level - Level of the Player
  */
  Player(int);

  /*!
   * @overload
   * @brief   Constructor Initializor
   * @param[in] name  - Name of the Player
   * @param[in] level - Level of the Player
  */
  Player(std::string,int);

  // /*!
  //  * @override
  //  * @brief   Calculates and adjust damage received
  //  *          including multiplier and reducers
  //  * @param[in] damage - Amount of incoming damage
  //  * @returns Final Damage Value
  // */
  // int receive_damage(int);

  /*!
   * @brief   Helper Hook used in CLI Help System
  */
  void _help();

  /*!
   * @brief   Default Deconstructor
  */
  ~Player();
};

#endif // PLAYER_H //
