//
// Created by Reuven Ostrofsky on 2024-03-19.
//

#ifndef COMP345_A1_TANKFIGHTERBUILDER_H
#define COMP345_A1_TANKFIGHTERBUILDER_H


#include "../FighterBuilder.h"

class TankFighterBuilder: public FighterBuilder{
public:
    TankFighterBuilder();
    TankFighterBuilder(string name, int level);
    ~TankFighterBuilder() override;
    void buildAbilityScores() override;


};


#endif //COMP345_A1_TANKFIGHTERBUILDER_H
