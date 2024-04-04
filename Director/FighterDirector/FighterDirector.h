//
// Created by Reuven Ostrofsky on 2024-03-19.
//

#ifndef COMP345_A1_FIGHTERDIRECTOR_H
#define COMP345_A1_FIGHTERDIRECTOR_H


#include "../../Builder/FighterBuilder/FighterBuilder.h"

class FighterDirector {
public:
    void setBuilder(FighterBuilder* fb);
    Fighter* constructFighter();
    Fighter* constructFighter(string name);
private:
    FighterBuilder* builder;
};


#endif //COMP345_A1_FIGHTERDIRECTOR_H
