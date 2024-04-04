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
 * @brief Constructor to add specified number of items to new container.
 * @param numItems Number of random items to initialize container with.
 */
container::container(int numItems) {
	for (int i{ 0 }; i < numItems; i++)
		addRandomItem();
}

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
	cout << "List of items inside:" << endl;
	for (auto& i : this->storedItems)
	{
		if (counter % 3 == 0)
		{
			cout << endl;
		}
		cout << counter << ". " << (!(i.armorType == Item::ArmorType::NOTARMOR) ? "("+i.getArmorTypeString()+") " : "")<< (!(i.weaponType == Item::WeaponType::NOTWEAPON) ? "(" + i.getWeaponTypeString() + ") " : "") << i.getEquipType() << (i.isEquipped() ? "(E)" : "") << " | ";
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
	int counter = 0;
	for (auto& i : storedItems)
	{
		cout << counter << ": ";
		i.printStats();
		counter++;
	}
}

Item& container::retrieveItem(int index)
{

	return storedItems[index];
}

/**
 * @brief Stores an item into the container.
 *
 * Adds the provided item to the vector of stored items.
 * @param itemObtained The item to be stored in the container.
 */
void container::storeItem(const Item& itemObtained)
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

int container::getSize() const {
	return this->storedItems.size();
}

void container::addRandomItem() {
	Item::ItemType itemType{};
	int random{ 8 };
	while (random > 7)
		random = dice.roll("1d8");
	switch (random) {
	case 1:
		itemType = Item::ItemType::HELMET;
		break;
	case 2:
		itemType = Item::ItemType::ARMOR;
		break;
	case 3:
		itemType = Item::ItemType::SHIELD;
		break;
	case 4:
		itemType = Item::ItemType::RING;
		break;
	case 5:
		itemType = Item::ItemType::BELT;
		break;
	case 6:
		itemType = Item::ItemType::BOOTS;
		break;
	case 7:
		itemType = Item::ItemType::WEAPON;
		break;
	default:
		std::cerr << "container::addRandomItem() generation error.\n";
		std::exit(1);
	}

	Item item = Item(itemType);
	storeItem(item);
}