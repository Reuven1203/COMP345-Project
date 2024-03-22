//
// Created by z3p on 21/03/24.
//

#ifndef COMP345_A1_BELT_H
#define COMP345_A1_BELT_H

#include "ItemDecorator.h"

class Belt : public ItemDecorator {
protected:
    int con;
    int str;
public:
    Belt(Item* item, Character* character);
    int getCON() const override;
    int getSTR() const override;
    bool hasBelt() const override;
};


#endif //COMP345_A1_BELT_H
