#ifndef TOON_H
#define TOON_H

#include "actor.h"

/*!
 * @class   Toon toon.h toon.cpp
 * @brief   Toon class is for all non-player characters  
*/
class Toon : public Actor {
protected:
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
   * @brief   Constructor Initializor
  */
  Toon(std::string,int);

  // /*!
  //  * @copydoc Actor::receive_damage()
  // */
  // int receive_damage(int);

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
