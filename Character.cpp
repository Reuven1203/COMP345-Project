//
// Created by Reuven Ostrofsky on 2024-01-30.
//

#include "Character.h"





Character::Character(int level) {
    if(level < 1) {
        this->level = 1;
    } else if(level > 20) {
        this->level = 20;
    }else {
        this->level = level;
    }
    this->abilityScore.strength = randomNumberGenerator(3, 18);
    this->abilityScore.dexterity = randomNumberGenerator(3, 18);
    this->abilityScore.constitution = randomNumberGenerator(3, 18);
    this->abilityScore.intelligence = randomNumberGenerator(3, 18);
    this->abilityScore.wisdom = randomNumberGenerator(3, 18);
    this->abilityScore.charisma = randomNumberGenerator(3, 18);









}

