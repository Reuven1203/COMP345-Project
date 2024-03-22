/**
 * @file Boots.h
 * @brief Defines Boots class, which is an ItemDecorator to equip a Boots item by wrapping.
 * @author Julian D'Addario
 */

#ifndef COMP345_A1_BOOTS_H
#define COMP345_A1_BOOTS_H

#include "ItemDecorator.h"

/**
 * @class Boots
 * @brief Boots class represents the equipping of an Item with ItemType::BOOTS
 */
class Boots : public ItemDecorator {
protected:
    // Holds AC, DEX of Boots
    int ac;
    int dex;
public:
    /**
     * @brief Boots Constructor
     * @param item Item to be added to character
     * @param character Character that item is added to
     */
    Boots(Item* item, Character* character);
    /**
     * @brief AC accessor
     * @override getAC() from ItemDecorator, Character
     * @return new AC of character
     */
    int getAC() const override;
    /**
     * @brief DEX accessor
     * @override getDEX() from ItemDecorator, Character
     * @return new DEX of character
     */
    int getDEX() const override;
    /**
     * @brief Check if Character has Boots equipped
     * @override hasBoots() from ItemDecorator, Character
     * @return true now that boots are equipped
     */
    bool hasBoots() const override;
};


#endif //COMP345_A1_BOOTS_H
