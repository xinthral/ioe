#ifndef TOON_H
#define TOON_H

#include "actor.h"

/*!
 * @class   Toon toon.h toon.cpp
 * @brief   Toon class is for all non-player characters  
*/
class Toon : public Actor {
protected:
    std::string name;
    int attack;
    int defense;
    char buf[128];
public:
  /*!
   * @brief   Default Constructor
  */
  Toon();

  /*!
   * @overload
   * @brief   Constructor Initializor
   * @param[in] id - Character Identity Number
  */
  Toon(int);

  /*!
   * @overload
   * @brief   Constructor Initializor
   * @param[in] name - Name of the Character
   * 
  */
  Toon(std::string);

  /*!
   * @overload
   * @brief   Constructor Initializor
   * @param[in] id   - Character Identity Number
   * @param[in] name - Name of the Character
  */
  Toon(int,std::string);

  /*!
   * @copydoc Actor::get_name()
  */
  std::string get_name();

  /*!
   * @copydoc Actor::get_attack()
  */
  int get_attack();

  /*!
   * @copydoc Actor::get_defense()
  */
  int get_defense();

  /*!
   * @copydoc Actor::set_name()
  */
  void set_name(std::string);

  /*!
   * @brief   Helper Hook used in CLI Help System
  */
  void _help();

  /*!
   * @brief   Default Deconstructor
  */
  ~Toon();
};

#endif // TOON_H //
