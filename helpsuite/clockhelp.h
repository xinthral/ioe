#ifndef HELPCLOCK_H
#define HELPCLOCK_H

#include "basehelp.h"

/*!
 * @class   HelpClock clockhelp.h clockhelp.cpp
 * @brief   Help details about the StageManager itself. 
 * @details Includes features like how it works, hints 
 *          working with the engine and more.
*/
class HelpClock : public BaseHelp {
protected:
private:
  xClock* clock;   //!< Placeholder StageManager Object

public:
  /*!
   * @brief   Default Constructor
  */
  HelpClock();

  /*!
   * @brief   Default Deconstructor
  */
  ~HelpClock();
};

#endif // HELPCLOCK_H //
