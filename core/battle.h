#ifndef BATTLE_H
#define BATTLE_H

#include "combat.h"
#include "player.h"
#include "toon.h"

/*! 
 * @class   Battle battle.h battle.cpp
 * @brief   Interweaving Combat events
*/
class Battle {
protected:
  Logger*   log;  //!< Logging Handler Instantiation
private:
public:
  /*! 
   * @brief   Default Constructor
  */
  Battle();

  /*! 
   * @overload
   * @brief   Player v Team Constructor
  */
  Battle(int, Player*, std::vector<Toon*>&);

  /*!
   * @overload
   * @brief    Gang v Gang Constructor
  */
  Battle(std::vector<Toon*>&, std::vector<Toon*>&);

  /*!
   * @brief   Helper Hook used in CLI Help System
  */
  void _help();

  /*! 
   * @brief   Default Deconstructor
  */
  ~Battle();
};

#endif // BATTLE_H //
