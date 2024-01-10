#ifndef HELPPLAYER_H
#define HELPPLAYER_H

#include "basehelp.h"

/*!
 * @class   HelpPlayer helpbalance.h helpbalance.cpp
 * @brief   Additional details about the BalanceController class, 
 *          it's implementation and any developers details relevant 
 *          to it's use.
 * @details HelpPlayer Callback for the HelpSuite 
*/
class HelpPlayer : public BaseHelp {
protected:
  Player* ptest;  //!< Placeholder Player Object
private:
public:
  /*!
   * @brief   Default Constructor
  */
  HelpPlayer();

  /*!
   * @brief   Default Deconstructor
  */
  ~HelpPlayer();
};

#endif // HELPPLAYER_H //
