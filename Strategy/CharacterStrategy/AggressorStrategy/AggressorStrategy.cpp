//
// Created by Reuven Ostrofsky on 2024-03-19.
//

#include "AggressorStrategy.h"
#include "../FriendlyStrategy/FriendlyStrategy.h"





int AggressorStrategy::determineMovePriority(int directionX, int directionY) {
    if (directionX == 0) {
        return 1; // Prioritize Y if no X movement.
    } else if (directionY == 0) {
        return 0; // Prioritize X if no Y movement.
    } else {
        return rand() % 2; // Randomly choose if both directions are available.
    }
}

bool AggressorStrategy::tryMove(Character* aggressor, dungeonMap& map, int deltaX, int deltaY, std::pair<int, int> previousPos) {
    std::pair<int, int> newPos = {map.playerPositions[aggressor].first + deltaX, map.playerPositions[aggressor].second + deltaY};

    // Check if the new position is valid and not the same as the previous position
    if (map.isValidRow(newPos.first) && map.isValidCol(newPos.second) &&
        !map.wallDetect(newPos.first, newPos.second) &&
        newPos != previousPos) {

        // Perform the move based on deltaX and deltaY which indicate the direction
        int direction = 0;
        if (deltaX == 1) direction = 2; // Down
        else if (deltaX == -1) direction = 1; // Up
        else if (deltaY == 1) direction = 4; // Right
        else if (deltaY == -1) direction = 3; // Left

        map.movePlayer(aggressor, direction);
        return true;
    }
    return false;
}

void AggressorStrategy::move(Character* aggressor, dungeonMap& map) {
    srand(time(nullptr));
    Character* target = map.getUserPlayer();
//    check if target can be reached with dfs

//    if(!map.dfs(map.playerPositions[aggressor].first,map.playerPositions[aggressor].second,map.playerPositions[target].first,map.playerPositions[target].second)){
//        return;
//    }


    for (int steps = 0; steps < 2; ++steps) {
        std::pair<int, int> aggressorPos = map.playerPositions[aggressor];
        std::pair<int, int> targetPos = map.playerPositions[target];

        int directionX = targetPos.first - aggressorPos.first;
        int directionY = targetPos.second - aggressorPos.second;

        if (directionX == 0 && directionY == 0) {
            break; // Aggressor has reached the target.
        }

        int movePriority = determineMovePriority(directionX, directionY);

        // Try to move in the prioritized direction first.
        bool moveDone = false;
        if (movePriority == 0) { // Prioritize X direction
            moveDone = tryMove(aggressor, map, directionX > 0 ? 1 : -1, 0, aggressorPos);
            if (!moveDone) {
                moveDone = tryMove(aggressor, map, 0, directionY > 0 ? 1 : -1, aggressorPos);
            }
        } else { // Prioritize Y direction
            moveDone = tryMove(aggressor, map, 0, directionY > 0 ? 1 : -1, aggressorPos);
            if (!moveDone) {
                moveDone = tryMove(aggressor, map, directionX > 0 ? 1 : -1, 0, aggressorPos);
            }
        }

        // If the move was not done, try the other direction.
        if (!moveDone) {
            moveDone = movePriority == 0 ? tryMove(aggressor, map, 0, directionY > 0 ? 1 : -1, aggressorPos) : tryMove(aggressor, map, directionX > 0 ? 1 : -1, 0, aggressorPos);
        }

        if (!moveDone) {
            break; // No valid moves available, exit the loop.
        }

    }

}

void AggressorStrategy::attack(Character *source, Character *target) {

    int attackRoll = Dice::GetGlobal().roll("1d20") + source->getStat(Character::Stats::AB);
    std::cout << source->getName() << " attacks " << target->getName() << " with a roll of " << attackRoll << std::endl;
    if (attackRoll >= target->getStat(Character::Stats::AC)) {
        std::cout << "Attack hit!" << std::endl;
        int damage = Dice::GetGlobal().roll("1d6") + source->getStat(Character::Stats::DB);
        target->setCurrentHP(target->getCurrentHP() - damage);



        EventData event(EventData::EventType::AttackedResult, "Attack Hit!", source->getName(),target->getName(), 2,target->getCurrentHP(),damage);
        notifyGameObserver(event);
    } else {
        EventData event(EventData::EventType::AttackedResult, "Attack Missed!", source->getName(),target->getName(), 2,target->getCurrentHP(),0);
        notifyGameObserver(event);

        std::cout << "Attack missed!" << std::endl;
    }
    if(dynamic_cast<FriendlyStrategy*>(target->getStrategy()) != nullptr) {
        target->setStrategy(new AggressorStrategy());
    }
}

