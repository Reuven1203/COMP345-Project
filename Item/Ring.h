/**
 * @file Ring.h
 * @brief Defines Ring class, which is an ItemDecorator to equip a Ring item by wrapping.
 * @author Julian D'Addario
 */

#ifndef COMP345_A1_RING_H
#define COMP345_A1_RING_H

#include "ItemDecorator.h"

/**
 * @class Ring
 * @brief Ring class represents the equipping of an Item with ItemType::RING
 */
class Ring : public ItemDecorator {
protected:
    // Holds AC, STR, CON, WIS, and CHA of Ring
    int ac;
    int str;
    int con;
    int wis;
    int cha;
public:
    /**
     * @brief Ring Constructor
     * @param item Item to be added to character
     * @param character Character that item is added to
     */
    Ring(Item* item, Character* character);
    /**
     * @brief AC accessor
     * @override getAC() from ItemDecorator, Character
     * @return new AC of character
     */
    int getAC() const override;
    /**
     * @brief STR accessor
     * @override getSTR() from ItemDecorator, Character
     * @return new STR of character
     */
    int getSTR() const override;
    /**
     * @brief CON accessor
     * @override getCON() from ItemDecorator, Character
     * @return new CON of character
     */
    int getCON() const override;
    /**
     * @brief WIS accessor
     * @override getWIS() from ItemDecorator, Character
     * @return new WIS of character
     */
    int getWIS() const override;
    /**
     * @brief CHA accessor
     * @override getCHA() from ItemDecorator, Character
     * @return new CHA of character
     */
    int getCHA() const override;
    /**
     * @brief Check if Character has Ring equipped
     * @override hasRing() from ItemDecorator, Character
     * @return true now that ring is equipped
     */
    bool hasRing() const override;
};


#endif //COMP345_A1_RING_H
