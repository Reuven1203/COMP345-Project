/**
 * @file UnequipItem.h
 * @brief Defines UnequipItem class, which is an ItemDecorator to unequip an Item by wrapping.
 * @author Julian D'Addario
 *
 * This Decorator will override the character's accessor methods to reduce its attributes based
 * on the stats of the item being unequipped.
 * Will simultaneously set character's bool for that ItemType (hasWeapon(), hasHelmet(), etc) to false.
 */

#ifndef COMP345_A1_UNEQUIPITEM_H
#define COMP345_A1_UNEQUIPITEM_H

#include "ItemDecorator.h"

/**
 * @class UnequipItem
 * @brief UnequipItem class represent the unequipping of an Item (of any ItemType)
 */
class UnequipItem : public ItemDecorator {
protected:
    // Holds ItemType, INT, WIS, AC, STR, CON, CHA, DEX, ATK, and DMG of item to be unequipped
    Item::ItemType itemType;
    int intel;
    int wis;
    int ac;
    int str;
    int con;
    int cha;
    int dex;
    int atk;
    int dmg;
public:
    /**
     * @brief UnequipItem Constructor
     * @param item Item to be removed from character
     * @param character Character that item is removed from
     */
    UnequipItem(Item* item, Character* character);
    /**
     * @brief STR accessor
     * @override getSTR() from ItemDecorator, Character
     * @return new STR of character
     */
    int getSTR() const override;
    /**
     * @brief DEX accessor
     * @override getDEX() from ItemDecorator, Character
     * @return new DEX of character
     */
    int getDEX() const override;
    /**
     * @brief CON accessor
     * @override getCON() from ItemDecorator, Character
     * @return new CON of character
     */
    int getCON() const override;
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
     * @brief CHA accessor
     * @override getCHA() from ItemDecorator, Character
     * @return new CHA of character
     */
    int getCHA() const override;
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
     * @brief AC accessor
     * @override getAC() from ItemDecorator, Character
     * @return new AC of character
     */
    int getAC() const override;
    /**
     * @brief Check if Character has Weapon equipped
     * @override hasWeapon() from ItemDecorator, Character
     * @return false now if item passed is a weapon, otherwise remains same
     */
    bool hasWeapon() const override;
    /**
     * @brief Check if Character has Helmet equipped
     * @override hasHelmet() from ItemDecorator, Character
     * @return false now if item passed is a helmet, otherwise remains same
     */
    bool hasHelmet() const override;
    /**
     * @brief Check if Character has Armor equipped
     * @override hasArmor() from ItemDecorator, Character
     * @return false now if item passed is an armor, otherwise remains same
     */
    bool hasArmor() const override;
    /**
     * @brief Check if Character has Shield equipped
     * @override hasShield() from ItemDecorator, Character
     * @return false now if item passed is a shield, otherwise remains same
     */
    bool hasShield() const override;
    /**
     * @brief Check if Character has Ring equipped
     * @override hasRing() from ItemDecorator, Character
     * @return false now if item passed is a ring, otherwise remains same
     */
    bool hasRing() const override;
    /**
     * @brief Check if Character has Belt equipped
     * @override hasBelt() from ItemDecorator, Character
     * @return false now if item passed is a belt, otherwise remains same
     */
    bool hasBelt() const override;
    /**
     * @brief Check if Character has Boots equipped
     * @override hasBoots() from ItemDecorator, Character
     * @return false now if item passed is boots, otherwise remains same
     */
    bool hasBoots() const override;
};


#endif //COMP345_A1_UNEQUIPITEM_H
