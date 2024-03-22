/**
 * @file Armor.h
 * @brief Defines ItemDecorator class, which allows items to be equipped by wrapping
 * @author Julian D'Addario
 *
 * This class allows for items to be equipped to characters, based on the type of item being equipped.
 * This class should not be used on its own, rather instead using the subclasses (Armor, Helmet, Weapon, etc).
 * Holds a pointer to a character whose accessors are overridden in order to modify attribute values
 * based on the items equipped/unequipped to/from the character.
 */

#ifndef COMP345_A1_ITEMDECORATOR_H
#define COMP345_A1_ITEMDECORATOR_H


#include "../Character/Character.h"

/**
 * @class ItemDecorator
 * @brief ItemDecorator class is a base Decorator to be used by subclasses to equip items.
 */
class ItemDecorator : public Character {
protected:
    // Character pointer
    Character* character_;
public:
    /**
     * @brief ItemDecorator constructor
     * @param character Character being modified (having items added to / removed from)
     */
    ItemDecorator(Character* character);
    /**
     * @brief STR accessor
     * @override getSTR() from Character
     * @return new STR of character
     */
    int getSTR() const override;
    /**
     * @brief DEX accessor
     * @override getDEX() from Character
     * @return new DEX of character
     */
    int getDEX() const override;
    /**
     * @brief CON accessor
     * @override getCON() from Character
     * @return new CON of character
     */
    int getCON() const override;
    /**
     * @brief INT accessor
     * @override getINT() from Character
     * @return new INT of character
     */
    int getINT() const override;
    /**
     * @brief WIS accessor
     * @override getWIS() from Character
     * @return new WIS of character
     */
    int getWIS() const override;
    /**
     * @brief CHA accessor
     * @override getCHA() from Character
     * @return new CHA of character
     */
    int getCHA() const override;
    /**
     * @brief ATK accessor
     * @override getATK() from Character
     * @return new ATK of character
     */
    int getATK() const override;
    /**
     * @brief DMG accessor
     * @override getDMG() from Character
     * @return new DMG of character
     */
    int getDMG() const override;
    /**
     * @brief AC accessor
     * @override getAC() from Character
     * @return new AC of character
     */
    int getAC() const override;
    /**
     * @brief Check if Character has Weapon equipped
     * @override hasWeapon() from Character
     * @return true if Character has ItemDecorator of that ItemType equipped, false if not
     */
    virtual bool hasWeapon() const override;
    /**
     * @brief Check if Character has Helmet equipped
     * @override hasHelmet() from Character
     * @return true if Character has ItemDecorator of that ItemType equipped, false if not
     */
    virtual bool hasHelmet() const override;
    /**
     * @brief Check if Character has Armor equipped
     * @override hasArmor() from Character
     * @return true if Character has ItemDecorator of that ItemType equipped, false if not
     */
    virtual bool hasArmor() const override;
    /**
     * @brief Check if Character has Shield equipped
     * @override hasShield() from Character
     * @return true if Character has ItemDecorator of that ItemType equipped, false if not
     */
    virtual bool hasShield() const override;
    /**
     * @brief Check if Character has Ring equipped
     * @override hasRing() from Character
     * @return true if Character has ItemDecorator of that ItemType equipped, false if not
     */
    virtual bool hasRing() const override;
    /**
     * @brief Check if Character has Belt equipped
     * @override hasBelt() from Character
     * @return true if Character has ItemDecorator of that ItemType equipped, false if not
     */
    virtual bool hasBelt() const override;
    /**
     * @brief Check if Character has Boots equipped
     * @override hasBoots() from Character
     * @return true if Character has ItemDecorator of that ItemType equipped, false if not
     */
    virtual bool hasBoots() const override;
};


#endif //COMP345_A1_ITEMDECORATOR_H
