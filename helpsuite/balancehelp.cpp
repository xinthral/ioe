/*!
 * @class   HelpBalance helpbalance.h helpbalance.cpp
 * @brief   Additional details about the BalanceController class, 
 *          it's implementation and any developers details relevant 
 *          to it's use.
 * @details HelpBalance Callback for the HelpSuite 
*/

#include "balancehelp.h"

/*!
 * @brief   Default Constructor
*/
HelpBalance::HelpBalance() { bal = BalanceController::GetInstance(); bal->_help(); }

/*!
 * @brief   Default Deconstructor
*/
HelpBalance::~HelpBalance() { }
