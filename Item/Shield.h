/**
 * @file Shield.h
 * @brief Defines Armor class, which is an ItemDecorator to equip a Shield item by wrapping.
 * @author Julian D'Addario
 */

#ifndef COMP345_A1_SHIELD_H
#define COMP345_A1_SHIELD_H

#include "ItemDecorator.h"

/**
 * @class Shield
 * @brief Shield class represents the equipping of an Item with ItemType::SHIELD
 */
class Shield : public ItemDecorator {
protected:
    // Holds AC of Shield
    int ac;
public:
    /**
     * @brief Shield Constructor
     * @param item Item to be added to character
     * @param character Character that item is added to
     */
    Shield(Item* item, Character* character);
    /**
     * @brief AC accessor
     * @override getAC() from ItemDecorator, Character
     * @return new AC of character
     */
    int getAC() const override;
    /**
     * @brief Check if Character has Shield equipped
     * @override hasShield() from ItemDecorator, Character
     * @return true now that shield is equipped
     */
    bool hasShield() const override;
};


#endif //COMP345_A1_SHIELD_H
