/**
 * @file Weapon.h
 * @brief Defines Weapon class, which is an ItemDecorator to equip a Weapon item by wrapping.
 * @author Julian D'Addario
 */

#ifndef COMP345_A1_WEAPON_H
#define COMP345_A1_WEAPON_H


#include "ItemDecorator.h"

/**
 * @class Weapon
 * @brief Weapon class represents the equipping of an Item with ItemType::WEAPON
 */
class Weapon : public ItemDecorator {
protected:
    // Holds ATK, DMG of Weapon
    int atk;
    int dmg;
public:
    /**
     * @brief Weapon Constructor
     * @param item Item to be added to character
     * @param character Character that item is added to
     */
    Weapon(Item* item, Character* character);
    /**
     * @brief ATK accessor
     * @override getATK() from ItemDecorator, Character
     * @return new ATK of character
     */
    int getATK() const override;
    /**
     * @brief DMG accessor
     * @override getDMG() from ItemDecorator, Character
     * @return new DMG of character
     */
    int getDMG() const override;
    /**
     * @brief Check if Character has Weapon equipped
     * @override hasWeapon() from ItemDecorator, Character
     * @return true now that weapon is equipped
     */
    bool hasWeapon() const override;
};


#endif //COMP345_A1_WEAPON_H
