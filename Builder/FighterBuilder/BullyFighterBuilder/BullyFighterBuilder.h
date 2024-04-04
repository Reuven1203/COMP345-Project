//
// Created by Reuven Ostrofsky on 2024-03-19.
//

#ifndef COMP345_A1_BULLYFIGHTERBUILDER_H
#define COMP345_A1_BULLYFIGHTERBUILDER_H

#include "../FighterBuilder.h"
#include "../../../Character/Fighter.h"


class BullyFighterBuilder: public FighterBuilder{
public:
    BullyFighterBuilder();
    BullyFighterBuilder(string name, int level);
    ~BullyFighterBuilder() override;
    void buildAbilityScores() override;
};


#endif //COMP345_A1_BULLYFIGHTERBUILDER_H
