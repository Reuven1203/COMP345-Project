//
// Created by z3p on 21/03/24.
//

#ifndef COMP345_A1_ITEMDECORATOR_H
#define COMP345_A1_ITEMDECORATOR_H


#include "../Character/Character.h"

class ItemDecorator : public Character {
protected:
    Character* character_;
public:
    ItemDecorator(Character* character);
    int getSTR() const override;
    int getDEX() const override;
    int getCON() const override;
    int getINT() const override;
    int getWIS() const override;
    int getCHA() const override;
    int getATK() const override;
    int getDMG() const override;
    int getAC() const override;
    void showCharacterStats() const override;
    virtual bool hasWeapon() const override;
    virtual bool hasHelmet() const override;
    virtual bool hasArmor() const override;
    virtual bool hasShield() const override;
    virtual bool hasRing() const override;
    virtual bool hasBelt() const override;
    virtual bool hasBoots() const override;
};


#endif //COMP345_A1_ITEMDECORATOR_H
