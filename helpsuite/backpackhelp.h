#ifndef HELPBACKPACK_H
#define HELPBACKPACK_H

#include "basehelp.h"
#include "../core/backpack.h"

/*!
 * @class   HelpBackpack backpackhelp.h backpackhelp.cpp
 * @brief   Help details about the Backpack module.
 * @details Covers container behavior, equip rules, and future weight system.
*/
class HelpBackpack : public BaseHelp {
private:
  Backpack* _backpack; //!< Placeholder Backpack Object

public:
  /*!
   * @brief   Default Constructor
  */
  HelpBackpack();

  /*!
   * @brief   Default Deconstructor
  */
  ~HelpBackpack();
};

#endif // HELPBACKPACK_H //
