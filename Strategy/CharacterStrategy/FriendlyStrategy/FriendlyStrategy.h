//
// Created by Reuven Ostrofsky on 2024-03-20.
//

#ifndef COMP345_A1_FRIENDLYSTRATEGY_H
#define COMP345_A1_FRIENDLYSTRATEGY_H

#include "../CharacterStrategy.h"


class FriendlyStrategy: public CharacterStrategy{
public:
    void move(Character *friendly, dungeonMap& map) override;
    void attack(Character* source, Character *target) override;

};


#endif //COMP345_A1_FRIENDLYSTRATEGY_H
