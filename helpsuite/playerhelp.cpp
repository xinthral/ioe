/*!
 * @class   HelpPlayer helpbalance.h helpbalance.cpp
 * @brief   Additional details about the BalanceController class, 
 *          it's implementation and any developers details relevant 
 *          to it's use.
 * @details HelpPlayer Callback for the HelpSuite 
*/

#include "playerhelp.h"

/*!
 * @brief   Default Constructor
*/
HelpPlayer::HelpPlayer() { ptest = new Player(); ptest->_help(); }

/*!
 * @brief   Default Deconstructor
*/
HelpPlayer::~HelpPlayer() { }
