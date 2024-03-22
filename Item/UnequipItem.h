//
// Created by z3p on 22/03/24.
//

#ifndef COMP345_A1_UNEQUIPITEM_H
#define COMP345_A1_UNEQUIPITEM_H

#include "ItemDecorator.h"

class UnequipItem : public ItemDecorator {
protected:
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
    UnequipItem(Item* item, Character* character);
    int getSTR() const override;
    int getDEX() const override;
    int getCON() const override;
    int getINT() const override;
    int getWIS() const override;
    int getCHA() const override;
    int getATK() const override;
    int getDMG() const override;
    int getAC() const override;
    bool hasWeapon() const override;
    bool hasHelmet() const override;
    bool hasArmor() const override;
    bool hasShield() const override;
    bool hasRing() const override;
    bool hasBelt() const override;
    bool hasBoots() const override;
};


#endif //COMP345_A1_UNEQUIPITEM_H
