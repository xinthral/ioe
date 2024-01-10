#include "balancehelp.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor
*/
HelpBalance::HelpBalance() { bal = BalanceController::GetInstance(); bal->_help(); }

/*!
 * @todo    Default Deconstructor
*/
HelpBalance::~HelpBalance() { }
