#ifndef ITEM_H
#define ITEM_H 

#include "logger.h"

enum ItemType {
  RELIC,
  RING,
  SHIELD,
  STAFF,
  SWORD,
};

enum ItemRarity {
  JUNK,
  COMMON,
  UNCOMMON,
  RARE,
  EPIC,
  LEGENDARY,
  UNIQUE,
};

/*!
 * @class   Item item.cpp item.h
 * @brief   BaseClass for Items
 * @details Items will be inherited from this class, which will include consumables
 *          weapons, armor, quest items, keys, and any other items I come up with.
*/
class Item {
protected:
private:
  Logger*    log;                   //!< Logging Handler Instantiation
  char       buf[1024];             //!< Buffer Value for Logger outputs
  char       label[100];            //!< The name of an item
  char       short_descriptor[255]; //!< The way an item would be describe in a sentence
  char       long_descriptor[1024]; //!< Details description of item or history
  ItemRarity _rarity;               //!< Rarity of Item
  ItemType   _type;                 //!< Type of Item

public:
  /*!
   * @brief   Default Constructor 
  */
  Item();
  Item(const char[]); 

  ItemRarity get_rarity();
  ItemType get_type();
  void set_rarity(ItemRarity);
  void set_type(ItemType);

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
