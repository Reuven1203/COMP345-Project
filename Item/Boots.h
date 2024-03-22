//
// Created by z3p on 21/03/24.
//

#ifndef COMP345_A1_BOOTS_H
#define COMP345_A1_BOOTS_H

#include "ItemDecorator.h"

class Boots : public ItemDecorator {
protected:
    int ac;
    int dex;
public:
    Boots(Item* item, Character* character);
    int getAC() const override;
    int getDEX() const override;
    bool hasBoots() const override;
};


#endif //COMP345_A1_BOOTS_H
