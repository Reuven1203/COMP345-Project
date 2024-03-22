/**
 * @file Helmet.h
 * @brief Defines Helmet class, which is an ItemDecorator to equip a Helmet item by wrapping.
 * @author Julian D'Addario
 */

#ifndef COMP345_A1_HELMET_H
#define COMP345_A1_HELMET_H


#include "ItemDecorator.h"

/**
 * @class Helmet
 * @brief Helmet class represents the equipping of an Item with ItemType::HELMET
 */
class Helmet : public ItemDecorator {
protected:
    // Holds INT, WIS, AC of Helmet
    int intel;
    int wis;
    int ac;
public:
    /**
     * @brief Helmet Constructor
     * @param item Item to be added to character
     * @param character Character that item is added to
     */
    Helmet(Item* item, Character* character);
    /**
     * @brief INT accessor
     * @override getINT() from ItemDecorator, Character
     * @return new INT of character
     */
    int getINT() const override;
    /**
     * @brief WIS accessor
     * @override getWIS() from ItemDecorator, Character
     * @return new WIS of character
     */
    int getWIS() const override;
    /**
     * @brief AC accessor
     * @override getAC() from ItemDecorator, Character
     * @return new AC of character
     */
    int getAC() const override;
    /**
     * @brief Check if Character has Helmet equipped
     * @override hasHelmet() from ItemDecorator, Character
     * @return true now that helmet is equipped
     */
    bool hasHelmet() const override;
};


#endif //COMP345_A1_HELMET_H
