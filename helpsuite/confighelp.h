#ifndef HELPCONFIG_H
#define HELPCONFIG_H

#include "basehelp.h"

/*!
 * @class   HelpConfig confighelp.h confighelp.cpp
 * @brief   Help details about the ConfigManager itself. 
 * @details Includes features like how it works, hints 
 *          working with the engine and more.
*/
class HelpConfig : public BaseHelp {
protected:
private:
  ConfigManager* _cnf;

public:
  /*!
   * @brief   Default Constructor
  */
  HelpConfig();

  /*!
   * @brief   Default Deconstructor
  */
  ~HelpConfig();
};

#endif // HELPCONFIG_H //