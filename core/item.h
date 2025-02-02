#ifndef ITEM_H
#define ITEM_H
#define LD_MAX_LEN 1024
#define SD_MAX_LEN 255

#include <stdexcept>
#include <type_traits>
#include "logger.h"

enum class ItemType {
  RELIC,
  RING,
  SHIELD,
  STAFF,
  SWORD,
};

enum class ItemRarity {
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
  Logger*    log;                         //!< Logging Handler Instantiation
private:
  ItemRarity _rarity;                     //!< Rarity of Item
  ItemType   _type;                       //!< Type of Item
  char       buf[1024];                   //!< Buffer Value for Logger outputs
  char       label[100];                  //!< The name of an item
  char       long_descriptor[LD_MAX_LEN]; //!< Details description of item or history
  char       short_descriptor[SD_MAX_LEN];//!< The way an item would be describe in a sentence

public:
  /*!
   * @brief   Default Constructor 
  */
  Item();
  Item(const char*); 
  char * get_label();
  char * get_long_descriptor();
  /*!
   * @brief   Retrieves the rarity of the item.
   * @return  The rarity of the item.
   * @note    The rarity is represented by the enum ItemRarity.
  */
  ItemRarity get_rarity();
  char * get_short_descriptor();
  ItemType get_type();
  void set_label(const char*);
  /*!
   * @brief   Sets the long description of the item.
   *
   * @details This function copies the provided details into the long_descriptor member of the Item object.
   *          It also ensures that the details do not exceed the maximum length defined by LD_MAX_LEN.
   *
   * @param[in] details - A null-terminated string containing the long description of the item.
   *
   * @throws  std::invalid_argument  If details is a null pointer.
   * @throws  std::runtime_error    If the long_descriptor fails to write due to encoding error.
   * @throws  std::overflow_error   If the long_descriptor buffer overflows.
  */
  void set_long_descriptor(const char*);
  /*!
   * @brief   Sets the rarity of the item.
   *
   * @details This function validates the input rarity against the defined range of ItemRarity enum.
   *          If the input rarity is within the valid range, it sets the item's rarity.
   *          Otherwise, it logs a warning message indicating the out-of-range rarity.
   *
   * @param[in] rarity - The rarity to set for the item.
  */
  void set_rarity(ItemRarity);
  /*!
   * @brief   Sets the short description of the item.
   *
   * @details This function copies the provided details into the short_descriptor member of the Item object.
   *          It also ensures that the details do not exceed the maximum length defined by SD_MAX_LEN.
   *
   * @param[in] details - A null-terminated string containing the short description of the item.
   *
   * @throws  std::invalid_argument  If details is a null pointer.
   * @throws  std::runtime_error    If the short_descriptor fails to write due to encoding error.
   * @throws  std::overflow_error   If the short_descriptor buffer overflows.
  */
  void set_short_descriptor(const char*);
  /*!
   * @brief   Sets the type of the item.
   *
   * @details This function validates the input item type against the defined range of item types.
   *          If the input is within the valid range, it sets the item type. Otherwise, it logs a warning message.
   *
   * @param[in] itemType - The type of the item to be set.
  */
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
