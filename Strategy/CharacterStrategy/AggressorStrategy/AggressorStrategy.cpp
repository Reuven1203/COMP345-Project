//
// Created by Reuven Ostrofsky on 2024-03-19.
//

#include "AggressorStrategy.h"





void AggressorStrategy::move(Character *aggressor, dungeonMap &map) {
    Character *target = map.getUserPlayer();
    std::pair<int, int> aggressorPos = map.playerPositions[aggressor];
    int aggressorX = aggressorPos.first;
    int aggressorY = aggressorPos.second;
    std::pair<int, int> targetPos = map.playerPositions[target];
    int targetX = targetPos.first;
    int targetY = targetPos.second;
    std::vector<std::pair<int, int>> path;
    int aggNewPosX=0;
    int aggNewPosY=0;
    if (map.dfs(aggressorX, aggressorY, targetX, targetY, path)) {
        map.clearCellVisit();
        //check if aggressor is bottom right, top right, bottom left, top left
        aggNewPosX = path[1].first;
        aggNewPosY = path[1].second;
        map.setPlayer(aggressor, aggNewPosX, aggNewPosY);
    }
    if(isAdjacent(aggNewPosX, aggNewPosY, targetX, targetY)){
        attack(aggressor, target);
    }
}

void AggressorStrategy::attack(Character *source, Character *target) {
    Dice dice;
    int attackRoll = dice.roll("1d20") + source->getStat(Character::Stats::AB);
    std::cout << source->getName() << " attacks " << target->getName() << " with a roll of " << attackRoll << std::endl;
    if (attackRoll >= target->getStat(Character::Stats::AC)) {
        std::cout << "Attack hit!" << std::endl;
        int damage = dice.roll("1d6") + source->getStat(Character::Stats::DB);
        target->setCurrentHP(target->getCurrentHP() - damage);
        
       

        EventData event(EventData::EventType::AttackedResult, "Attack Hit!", source->getName(),target->getName(), 2,target->getCurrentHP(),damage);
        notifyGameObserver(event);
    } else {
        EventData event(EventData::EventType::AttackedResult, "Attack Missed!", source->getName(),target->getName(), 2,target->getCurrentHP(),0);
        notifyGameObserver(event);

        std::cout << "Attack missed!" << std::endl;
    }
}

