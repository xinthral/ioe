#ifndef ITEM_H
#define ITEM_H 

#include "logger.h"

/*!
 * @class   Item item.cpp item.h
 * @brief   BaseClass for Items
 * @details Items will be inherited from this class, which will include consumables
 *          weapons, armor, quest items, keys, and any other items I come up with.
*/
class Item {
protected:
private:
  Logger*             log;        //!< Logging Handler Instantiation
  char                buf[1024];  //!< Buffer Value for Logger outputs

public:
  /*!
   * @brief   Default Constructor 
  */
  Item();

  /*!
   * @brief   Helper Hook used in CLI Help System
  */
  void _help();

  /*!
   * @brief   Default Constructor 
  */
  ~Item();
};

#endif  // ITEM_H //
