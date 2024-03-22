//
// Created by z3p on 21/03/24.
//

#ifndef COMP345_A1_RING_H
#define COMP345_A1_RING_H

#include "ItemDecorator.h"

class Ring : public ItemDecorator {
protected:
    int ac;
    int str;
    int con;
    int wis;
    int cha;
public:
    Ring(Item* item, Character* character);
    int getAC() const override;
    int getSTR() const override;
    int getCON() const override;
    int getWIS() const override;
    int getCHA() const override;
    bool hasRing() const override;
};


#endif //COMP345_A1_RING_H
