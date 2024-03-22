//
// Created by z3p on 21/03/24.
//

#ifndef COMP345_A1_HELMET_H
#define COMP345_A1_HELMET_H


#include "ItemDecorator.h"

class Helmet : public ItemDecorator {
protected:
    int intel;
    int wis;
    int ac;
public:
    Helmet(Item* item, Character* character);
    int getINT() const override;
    int getWIS() const override;
    int getAC() const override;
    bool hasHelmet() const override;
};


#endif //COMP345_A1_HELMET_H
