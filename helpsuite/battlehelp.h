#ifndef HELPBATTLE_H
#define HELPBATTLE_H

#include "basehelp.h"

/*!
 * @class   HelpBattle battlehelp.h battlehelp.cpp
 * @brief   Help details about the Battle module.
 * @details Includes features like how it works, hints
 *          working with the engine and more.
*/
class HelpBattle : public BaseHelp {
protected:
  Battle* battlefield;  //!< The field containing all combat

private:
public:
  /*!
   * @brief   Default Constructor
  */
  HelpBattle();

  /*!
   * @brief   Default Deconstructor
  */
  ~HelpBattle();
};

#endif // HELPBATTLE_H //