#ifndef HELPCOMBAT_H
#define HELPCOMBAT_H

#include "basehelp.h"

/*!
 * @class   HelpCombat combathelp.h combathelp.cpp
 * @brief   Help details about the Combat module. 
 * @details Includes features like how it works, hints 
 *          working with the engine and more.
*/
class HelpCombat : public BaseHelp {
protected:
private:
  Combat* cc;
public:
  /*!
   * @brief   Default Constructor
  */
  HelpCombat();

  /*!
   * @brief   Default Deconstructor
  */
  ~HelpCombat();
};

#endif // HELPCOMBAT_H //