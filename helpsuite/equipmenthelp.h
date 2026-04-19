#ifndef HELPEQUIPMENT_H
#define HELPEQUIPMENT_H

#include "basehelp.h"
#include "../core/equipment.h"

/*!
 * @class   HelpEquipment equipmenthelp.h equipmenthelp.cpp
 * @brief   Help details about the Equipment module.
 * @details Covers stat multipliers, default profiles, and equip rules.
*/
class HelpEquipment : public BaseHelp {
private:
  Equipment* _equipment; //!< Placeholder Equipment Object

public:
  /*!
   * @brief   Default Constructor
  */
  HelpEquipment();

  /*!
   * @brief   Default Deconstructor
  */
  ~HelpEquipment();
};

#endif // HELPEQUIPMENT_H //
