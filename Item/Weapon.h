//
// Created by z3p on 21/03/24.
//

#ifndef COMP345_A1_WEAPON_H
#define COMP345_A1_WEAPON_H


#include "ItemDecorator.h"

class Weapon : public ItemDecorator {
protected:
    int atk;
    int dmg;
public:
    Weapon(Item* item, Character* character);
    int getATK() const override;
    int getDMG() const override;
    bool hasWeapon() const override;
};


#endif //COMP345_A1_WEAPON_H
