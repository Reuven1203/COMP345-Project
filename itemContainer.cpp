/**
 * @file itemContainer.cpp
 * @brief Implementation of the container class to manage items in a game.
 *
 * This class provides functionalities to manage a collection of items, such as adding or removing items from the container,
 * and printing details about the items.
 *
 * @author Richard Mauricio
 * @date 2024-02-24
 */

#include <iostream>
#include <vector>
#include "itemContainer.h"
#include "Item.h"

using namespace std;

/**
 * @brief Default constructor initializing container with an empty name.
 */
container::container() : name("") {}

/**
 * @brief Destructor for the container class.
 */
container::~container() {}

/**
 * @brief Prints the types of items currently stored in the container.
 *
 * Iterates through all stored items and prints their equipment type.
 */
void container::getItems()
{
    int counter = 0;
    cout << "List of items in container:" << endl;
    for (auto& i : storedItems)
    {
        cout << counter << ". " << i.getEquipType() << " | ";
        counter++;
    }
    cout << "\n\n";
}

/**
 * @brief Prints the stats of each item stored in the container.
 *
 * Iterates through all stored items and calls their printStats method.
 */
void container::getItemStats()
{
    for (auto& i : storedItems)
    {
        i.printStats();
    }
}

/**
 * @brief Stores an item into the container.
 *
 * Adds the provided item to the vector of stored items.
 * @param itemObtained The item to be stored in the container.
 */
void container::storeItem(Item& itemObtained)
{
    storedItems.push_back(itemObtained);
}

/**
 * @brief Removes an item from the container based on its index and returns it.
 *
 * Erases the item from the vector of stored items at the specified index and returns the item.
 * @param index The index of the item to remove from the container.
 * @return The item that was removed.
 */
Item container::removeItemFromChest(int index)
{
    Item hold = storedItems[index];
    deleteItemInChest(index);
    return hold;
}

/**
 * @brief Deletes an item from the container based on its index.
 *
 * Erases the item from the vector of stored items at the specified index.
 * @param index The index of the item to delete from the container.
 */
void container::deleteItemInChest(int index)
{
    storedItems.erase(storedItems.begin() + index);
}
