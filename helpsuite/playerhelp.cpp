/*!
 * @class   HelpPlayer helpbalance.h helpbalance.cpp
 * @brief   Additional details about the BalanceController class, 
 *          it's implementation and any developers details relevant 
 *          to it's use.
 * @details HelpPlayer Callback for the HelpSuite 
*/

#include "playerhelp.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
HelpPlayer::HelpPlayer() { ptest = new Player("HelpPlayer", 1, 1, 1); ptest->_help(); }

/*!
 * @brief   Default Deconstructor
*/
HelpPlayer::~HelpPlayer() { }
