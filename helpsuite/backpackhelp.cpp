#include "backpackhelp.h"

/*!
 * @def     __FILENAME__
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
HelpBackpack::HelpBackpack() {
  _backpack = new Backpack();
  _backpack->_help();
}

/*!
 * @brief   Default Deconstructor
*/
HelpBackpack::~HelpBackpack() { delete _backpack; }
