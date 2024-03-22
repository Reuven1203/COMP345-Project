/**
 * @file Belt.h
 * @brief Defines Belt class, which is an ItemDecorator to equip a Belt item by wrapping.
 * @author Julian D'Addario
 */

#ifndef COMP345_A1_BELT_H
#define COMP345_A1_BELT_H

#include "ItemDecorator.h"

/**
 * @class Belt
 * @brief Belt class represents the equipping of an Item with ItemType::BELT
 */
class Belt : public ItemDecorator {
protected:
    // Holds CON, STR of Belt
    int con;
    int str;
public:
    /**
     * @brief Belt Constructor
     * @param item Item to be added to character
     * @param character Character that item is added to
     */
    Belt(Item* item, Character* character);
    /**
     * @brief CON accessor
     * @override getCON() from ItemDecorator, Character
     * @return new CON of character
     */
    int getCON() const override;
    /**
     * @brief STR accessor
     * @override getSTR() from ItemDecorator, Character
     * @return new STR of character
     */
    int getSTR() const override;
    /**
     * @brief Check if Character has Belt equipped
     * @override hasBelt() from ItemDecorator, Character
     * @return true now that belt is equipped
     */
    bool hasBelt() const override;
};


#endif //COMP345_A1_BELT_H
