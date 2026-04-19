#include "equipmenthelp.h"

/*!
 * @def     __FILENAME__
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
HelpEquipment::HelpEquipment() {
  _equipment = new Equipment();
  _equipment->_help();
}

/*!
 * @brief   Default Deconstructor
*/
HelpEquipment::~HelpEquipment() { delete _equipment; }
