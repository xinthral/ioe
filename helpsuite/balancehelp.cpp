/*!
 * @class   HelpBalance helpbalance.h helpbalance.cpp
 * @brief   Additional details about the BalanceController class, 
 *          it's implementation and any developers details relevant 
 *          to it's use.
 * @details HelpBalance Callback for the HelpSuite 
*/

#include "balancehelp.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
HelpBalance::HelpBalance() { bal = BalanceController::GetInstance(); bal->_help(); }

/*!
 * @brief   Default Deconstructor
*/
HelpBalance::~HelpBalance() { }
