#ifndef HELPITEM_H
#define HELPITEM_H

#include "basehelp.h"

/*!
 * @class   HelpItem itemhelp.h itemhelp.cpp
 * @brief   Help details about the Base Item Module. 
 * @details Includes features like how it works, hints 
 *          working with the engine and more.
*/
class HelpItem : public BaseHelp {
protected:
private:
  Item* _item;  //!< Placeholder Item Object

public:
  /*!
   * @brief   Default Constructor
  */
  HelpItem();

  /*!
   * @brief   Default Deconstructor
  */
  ~HelpItem();
};

#endif // HELPITEM_H //
