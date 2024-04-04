//
// Created by Reuven Ostrofsky on 2024-03-19.
//

#ifndef COMP345_A1_HUMANPLAYERSTRATEGY_H
#define COMP345_A1_HUMANPLAYERSTRATEGY_H


#include "../CharacterStrategy.h"

class HumanPlayerStrategy: public CharacterStrategy{
public:
    void move(Character *player, dungeonMap& map) override;
    void attack(Character *source, Character *target) override;
    void openInventory(Character *player);
};


#endif //COMP345_A1_HUMANPLAYERSTRATEGY_H
