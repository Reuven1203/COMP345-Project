//
// Created by z3p on 21/03/24.
//

#ifndef COMP345_A1_ARMOR_H
#define COMP345_A1_ARMOR_H


#include "ItemDecorator.h"

class Armor : public ItemDecorator {
protected:
    int ac;
public:
    Armor(Item* item, Character* character);
    int getAC() const override;
    bool hasArmor() const override;
};


#endif //COMP345_A1_ARMOR_H
