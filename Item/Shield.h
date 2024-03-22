//
// Created by z3p on 21/03/24.
//

#ifndef COMP345_A1_SHIELD_H
#define COMP345_A1_SHIELD_H

#include "ItemDecorator.h"

class Shield : public ItemDecorator {
protected:
    int ac;
public:
    Shield(Item* item, Character* character);
    int getAC() const override;
    bool hasShield() const override;
};


#endif //COMP345_A1_SHIELD_H
