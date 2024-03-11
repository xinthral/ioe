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
  int bhealth  = Actor::baseHealth;     //!< Base Value inherited from Actor
  int bdefense = Actor::baseDefense;    //!< Base Value inherited from Actor
  int bflux    = Actor::baseFlux;       //!< Base Value inherited from Actor
  int block    = 1;                     //!< Block Value Adds to Damage Mitigation
  int health   = 1;                     //!< Health Value is the Damage Allowed Before Death
  int power    = 1;                     //!< Power Value Amplifies Abilies Used
  int level    = 1;                     //!< Level Value Associates Progression 
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
   * @param[in] power - Cummulative Power of Player
   * @param[in] block - Defense of the Player
  */
  Player(int, int, int);

  /*!
   * @overload
   * @brief   Constructor Initializor
   * @param[in] name  - Name of the Player
   * @param[in] level - Level of the Player
   * @param[in] power - Cummulative Power of Player
   * @param[in] block - Defense of the Player
  */
  Player(std::string, int, int, int);

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
