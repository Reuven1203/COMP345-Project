//
// Created by Reuven Ostrofsky on 2024-03-20.
//

#include "FriendlyStrategy.h"

void FriendlyStrategy::move(Character *friendly, dungeonMap &map) {
    Character *target = map.getUserPlayer();
    std::pair<int, int> friendlyPos = map.playerPositions[friendly];
    int friendlyX = friendlyPos.first;
    int friendlyY = friendlyPos.second;
    std::pair<int, int> targetPos = map.playerPositions[target];
    int targetX = targetPos.first;
    int targetY = targetPos.second;
    std::vector<std::pair<int, int>> path;
    int aggNewPosX=0;
    int aggNewPosY=0;
    bool donePos = true;
    if (map.dfs(friendlyX, friendlyY, targetX, targetY, path)) {
        map.clearCellVisit();
        aggNewPosX = path[1].first;
        aggNewPosY = path[1].second;
        map.setPlayer(friendly, aggNewPosX, aggNewPosY);
    }
}

void FriendlyStrategy::attack(Character *source, Character *target) {
std::cout << "Friendly characters do not attack" << std::endl;
}
