#ifndef HELPBALANCE_H
#define HELPBALANCE_H

#include "basehelp.h"

/*!
 * @class   HelpBalance helpbalance.h helpbalance.cpp
 * @brief   Additional details about the BalanceController class, 
 *          it's implementation and any developers details relevant 
 *          to it's use.
 * @details HelpBalance Callback for the HelpSuite 
*/
class HelpBalance : public BaseHelp {
protected:
  BalanceController* bal; //!< BalanceController Instantiation
private:
public:
  /*!
   * @brief   Default Constructor
  */
  HelpBalance();

  /*!
   * @brief   Default Deconstructor
  */
  ~HelpBalance();
};

#endif // HELPBALANCE_H //