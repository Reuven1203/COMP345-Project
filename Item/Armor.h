/**
 * @file Armor.h
 * @brief Defines Armor class, which is an ItemDecorator to equip an Armor item by wrapping.
 * @author Julian D'Addario
 */

#ifndef COMP345_A1_ARMOR_H
#define COMP345_A1_ARMOR_H


#include "ItemDecorator.h"

/**
 * @class Armor
 * @brief Armor class represents the equipping of an Item with ItemType::ARMOR
 */
class Armor : public ItemDecorator {
protected:
    // Holds AC of Armor
    int ac;
public:
    /**
     * @brief Armor Constructor
     * @param item Item to be added to character
     * @param character Character that item is added to
     */
    Armor(Item* item, Character* character);
    /**
     * @brief AC accessor
     * @override getAC() from ItemDecorator, Character
     * @return new AC of character
     */
    int getAC() const override;
    /**
     * @brief Check if Character has Armor equipped
     * @override hasArmor() from ItemDecorator, Character
     * @return true now that armor is equipped
     */
    bool hasArmor() const override;
};


#endif //COMP345_A1_ARMOR_H
