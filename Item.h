/**
* @file Item.h
* @brief Declaration of the Item class and related enums.
* @details The Item class represents an item that can be equipped by a character in a role-playing game.
* It includes different types of items such as helmets, armor, shields, rings, belts, boots, and weapons.
* Each item has associated statistics that can affect the character's attributes and abilities when equipped.
* @author Richard Mauricio
* @date Feb 7, 2024
*/

#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <vector>
#include <random>
#include <map>

using namespace std;
/**
* @class Item
* @brief Class representing an item that can be equipped by a character.
*/
class Item
{

public:
    /**
 * @enum ItemType
 * @brief Enum to represent different types of items.
 */
    enum ItemType {
        HELMET, ///< Represents a helmet item.
        ARMOR,  ///< Represents an armor item.
        SHIELD, ///< Represents a shield item.
        RING,   ///< Represents a ring item.
        BELT,   ///< Represents a belt item.
        BOOTS,  ///< Represents a boots item.
        WEAPON  ///< Represents a weapon item.
    };
    ItemType equipType;
    /**
     * @brief Default constructor.
     */// helm,armor,shield,ring,belt,boots,weapon
    Item();
    /**
    * @brief Destructor.
    */
    ~Item();
    /**
     * @brief Parameterized constructor.
     *
     * @param itemtype The type of item to create.
     */
    explicit Item(ItemType itemtype);
/**
     * @brief Method to roll a random modifier for an item's stats.
     *
     * @return The rolled modifier value.
     */
    int rollStatMod();

    // Setters
    void setEquipType(ItemType type);
    void setEquipStats();

    // Getters
    string getEquipType() const;
    int getSTR();
    int getCON();
    int getINT();
    int getWIS();
    int getCHA();
    int getDEX();
    int getAC();
    int getATKBONUS();
    int getDMGBonus();
    bool getIfNull();

/**
     * @brief Method to print the stats of the item.
     */
    void printStats() const;
/**
     * @brief Map to store overall item statistics.
     */
    map<string, int> itemOverall;
private:
    std::string itemName; ///< Name of the item.
    int enchantmentModifier = 0; ///< Enchantment modifier for the item.
    bool nullItem; ///< If item has no stats, will be initialized to true.
    // Stats
    int strength = 0;       ///< Strength attribute modifier.
    int constitution = 0;   ///< Constitution attribute modifier.
    int intelligence = 0;   ///< Intelligence attribute modifier.
    int wisdom = 0;         ///< Wisdom attribute modifier.
    int charisma = 0;       ///< Charisma attribute modifier.
    int dexterity = 0;      ///< Dexterity attribute modifier.
    int armorClass = 0;     ///< Armor class modifier.
    int atkBonus = 0;       ///< Attack bonus modifier.
    int dmgBonus = 0;       ///< Damage bonus modifier.

};

#endif // ITEM_H