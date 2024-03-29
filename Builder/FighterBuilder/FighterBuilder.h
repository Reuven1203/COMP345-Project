//
// Created by Reuven Ostrofsky on 2024-03-19.
//

#ifndef COMP345_A1_FIGHTERBUILDER_H
#define COMP345_A1_FIGHTERBUILDER_H


#include "../../Character/Fighter.h"

class FighterBuilder{
    friend class FighterDirector;
protected:
    Fighter *fighter{};
    virtual ~FighterBuilder() = default;
    virtual void buildAbilityScores() = 0;
    virtual void buildAbilityModifiers();
    virtual void buildStats();
    virtual void buildName(string name);
    Fighter* getFighter();
};
#endif //COMP345_A1_FIGHTERBUILDER_H
