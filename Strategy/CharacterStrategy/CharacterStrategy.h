//
// Created by Reuven Ostrofsky on 2024-03-19.
//

#ifndef COMP345_A1_CHARACTERSTRATEGY_H
#define COMP345_A1_CHARACTERSTRATEGY_H

#include "../../Character/Character.h"
#include "../../Map/map.h"
#include "../Observer/GameObserver/GameObserver.h"

class dungeonMap;

class CharacterStrategy:public Observable {
public:
    virtual void move(Character *player, dungeonMap& map) = 0;
    static inline bool isAdjacent(int sourceX, int sourceY, int targetX, int targetY) {
        return (sourceX == targetX && sourceY == targetY + 1) || (sourceX == targetX && sourceY == targetY - 1) ||
               (sourceX == targetX + 1 && sourceY == targetY) || (sourceX == targetX - 1 && sourceY == targetY);
    }

    virtual void attack(Character *source, Character *target) = 0;

};


#endif //COMP345_A1_CHARACTERSTRATEGY_H
