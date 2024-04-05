//
// Created by Reuven Ostrofsky on 2024-03-19.
//

#ifndef COMP345_A1_CHARACTERSTRATEGY_H
#define COMP345_A1_CHARACTERSTRATEGY_H

#include "../../Character/Character.h"
#include "../../Map/map.h"
#include "../../Observer/GameObserver/GameObserver.h"

class dungeonMap;

class CharacterStrategy:public Observable {
public:
    virtual void move(Character *player, dungeonMap& map) = 0;
    static inline bool isAdjacent(int sourceX, int sourceY, int targetX, int targetY) {
        return (sourceX == targetX && sourceY == targetY + 1) || (sourceX == targetX && sourceY == targetY - 1) ||
               (sourceX == targetX + 1 && sourceY == targetY) || (sourceX == targetX - 1 && sourceY == targetY);
    }
    static inline bool isNearby(int sourceX, int sourceY, int targetX, int targetY) {
return (sourceX == targetX && sourceY == targetY + 2) || (sourceX == targetX && sourceY == targetY - 2) ||
               (sourceX == targetX + 2 && sourceY == targetY) || (sourceX == targetX - 2 && sourceY == targetY) ||
               (sourceX == targetX + 2 && sourceY == targetY + 2) || (sourceX == targetX + 2 && sourceY == targetY - 2) ||
               (sourceX == targetX - 2 && sourceY == targetY + 2) || (sourceX == targetX - 2 && sourceY == targetY - 2);
    }

    virtual void attack(Character *source, Character *target) = 0;
    enum StrategyType {
        PLAYER,
        ENEMY,
        FRIENDLY,
    };
    virtual void openInventory(Character* player) = 0;
    virtual StrategyType getStrategyType() = 0;
};


#endif //COMP345_A1_CHARACTERSTRATEGY_H
