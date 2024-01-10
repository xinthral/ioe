#ifndef HELPACTOR_H
#define HELPACTOR_H 

#include "basehelp.h"

/*!
 * @class   HelpActor helpactor.h helpactor.cpp
 * @brief   Additional details about the Actor class, it's implementation
 *          and any developers details relevant to it's use.
 * @details HelpActor Callback for the HelpSuite 
*/
class HelpActor : public BaseHelp {
protected:
  Actor* dummy;   //!< Placeholder Actor Object 

private:
public:
  /*!
   * @brief   Default Constructor
  */
  HelpActor();

  /*!
   * @brief   Default Deconstructor
  */
  ~HelpActor();
};

#endif  // HELPACTOR_H //
