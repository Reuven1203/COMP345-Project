//
// Created by Reuven Ostrofsky on 2024-03-19.
//

#ifndef COMP345_A1_CHARACTERSTRATEGY_H
#define COMP345_A1_CHARACTERSTRATEGY_H

#include "../../Character/Character.h"
#include "../../Map/map.h"

class dungeonMap;

class CharacterStrategy {
public:
    virtual void move(Character *player, dungeonMap& map) = 0;
    virtual void attack() = 0;
    virtual void freeAction() = 0;
};


#endif //COMP345_A1_CHARACTERSTRATEGY_H
