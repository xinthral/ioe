#ifndef BACKPACK_H
#define BACKPACK_H

#include <vector>
#include "equipment.h"
#include "item.h"

/*!
 * @class   Backpack backpack.h backpack.cpp
 * @brief   A wearable container that holds any Item type.
 * @details Extends Equipment so it can be equipped to an Actor.
 *          In a future update, items stored inside will have their
 *          weight halved while the backpack is worn.
*/
class Backpack : public Equipment {
private:
  std::vector<Item*> contents; //!< Items stored inside the backpack

public:
  /*!
   * @brief   Default Constructor
  */
  Backpack();

  /*!
   * @overload
   * @brief   Named Constructor
   * @param[in] name - Label for this backpack
  */
  Backpack(const char*);

  /*!
   * @brief   Add an item to the backpack
   * @param[in] item - Pointer to the Item to store
   * @returns true if added, false if item is nullptr
  */
  bool add_item(Item*);

  /*!
   * @brief   Remove an item from the backpack by label
   * @param[in] label - Label of the item to remove
   * @returns true if found and removed, false if not found
  */
  bool remove_item(const char*);

  /*!
   * @brief   Return all items stored in the backpack
   * @returns Const reference to the contents vector
  */
  const std::vector<Item*>& get_items() const;

  /*!
   * @brief   Helper Hook used in CLI Help System
  */
  void _help() override;

  /*!
   * @brief   Default Deconstructor
  */
  ~Backpack();
};

#endif // BACKPACK_H //
