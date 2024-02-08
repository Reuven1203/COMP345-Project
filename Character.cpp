//
// Created by Reuven Ostrofsky on 2024-01-30.
//

#include "Character.h"
#include "Dice.h"


Character::Character(int level) {
    if(level < 1) {
        this->level = 1;
    } else if(level > 20) {
        this->level = 20;
    }else {
        this->level = level;
    }
    Dice dice {Dice()};
    std::string abilityScoreRoll {"3d6"};
    this->abilityScore.strength = dice.roll(abilityScoreRoll);
    this->abilityScore.dexterity = dice.roll(abilityScoreRoll);
    this->abilityScore.constitution = dice.roll(abilityScoreRoll);
    this->abilityScore.intelligence = dice.roll(abilityScoreRoll);
    this->abilityScore.wisdom = dice.roll(abilityScoreRoll);
    this->abilityScore.charisma = dice.roll(abilityScoreRoll);









}

