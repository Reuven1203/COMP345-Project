//
// Created by Reuven Ostrofsky on 2024-03-19.
//

#ifndef COMP345_A1_AGGRESSORSTRATEGY_H
#define COMP345_A1_AGGRESSORSTRATEGY_H


#include "../CharacterStrategy.h"

class AggressorStrategy: public CharacterStrategy{
public:
    void move(Character *aggressor,dungeonMap& map) override;
    void attack(Character* source, Character *target) override;

    static int determineMovePriority(int directionX, int directionY);

    bool tryMove(Character* aggressor, dungeonMap& map, int deltaX, int deltaY, std::pair<int, int> previousPos);
};


#endif //COMP345_A1_AGGRESSORSTRATEGY_H
