/**
 * @file itemContainer.h
 * @brief Header file for the container class.
 *
 * Defines the container class and its member functions for managing a collection of items
 * within a game environment. This includes functionalities for adding, removing, and
 * querying items stored in the container.
 *
 * @author Richard Mauricio
 * @date 2024-02-24
 */

#ifndef ITEMCONTAINER_H
#define ITEMCONTAINER_H

#include <iostream>
#include <vector>
#include "Item.h"

 /**
  * @class container
  * @brief Manages a collection of items.
  *
  * This class is responsible for storing items in a vector, providing functionalities
  * to add and remove items, and to print information about the items contained.
  */
class container {
public:
    /**
     * @brief Default constructor for the container class.
     */
    container();

    /**
     * @brief Destructor for the container class.
     */
    ~container();

    /**
     * @brief Prints the types of all items stored in the container.
     *
     * Iterates through the stored items and prints their types to standard output.
     */
    void getItems();

    /**
     * @brief Prints the stats of all items stored in the container.
     *
     * Iterates through the stored items and invokes their `printStats` method to display their stats.
     */
    void getItemStats();

    /**
     * @brief Stores a new item in the container.
     *
     * Adds the specified item to the vector of stored items.
     * @param itemObtained Reference to the item to be stored.
     */
    void storeItem(Item& itemObtained);

    /**
     * @brief Removes an item from the container at a specified index and returns it.
     *
     * @param index Index of the item to be removed.
     * @return The item that was removed from the container.
     */
    Item removeItemFromChest(int index);

    /**
     * @brief Deletes an item from the container at a specified index.
     *
     * @param index Index of the item to be deleted.
     */
    void deleteItemInChest(int index);

private:
    std::vector<Item> storedItems; ///< Vector of items stored in the container.
    std::string name; ///< Name of the container.
};

#endif // ITEMCONTAINER_H
