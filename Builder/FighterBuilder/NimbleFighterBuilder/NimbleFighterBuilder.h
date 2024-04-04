//
// Created by Reuven Ostrofsky on 2024-03-19.
//

#ifndef COMP345_A1_NIMBLEFIGHTERBUILDER_H
#define COMP345_A1_NIMBLEFIGHTERBUILDER_H


#include "../FighterBuilder.h"

class NimbleFighterBuilder: public FighterBuilder{
public:
    NimbleFighterBuilder();
    NimbleFighterBuilder(string name, int level);
    ~NimbleFighterBuilder() override;
    void buildAbilityScores() override;

};


#endif //COMP345_A1_NIMBLEFIGHTERBUILDER_H
