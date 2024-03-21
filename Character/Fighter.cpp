//
// Created by Reuven Ostrofsky on 2024-02-07.
//

#include "Fighter.h"

#include <utility>
#include "../Dice/Dice.h"


Fighter::Fighter(std::string name, int level, FighterType type) : Character(std::move(name), level) {
    fighterType = type;
}

std::string Fighter::getClassName() const {
    return "Fighter";
}



Fighter::FighterType Fighter::getFighterType() const {
    return fighterType;
}

std::string Fighter::FighterTypeEnumToString(FighterType type) {
    switch (type) {
        case BULLY:
            return "Bully";
        case NIMBLE:
            return "Nimble";
        case TANK:
            return "Tank";
    }
}

void Fighter::setAbilityScore(Character::Ability ability, int score) {
    this->abilityScore[ability] = score;
}


void Fighter::attachDie(Dice* die)
{
    dice = die;
}











