//
// Created by Reuven Ostrofsky on 2024-01-30.
//

#include "Character.h"
#include <cstdlib>
#include<ctime>





Character::Character(std::string name,int level): name(std::move(name)){
    if(level < 1) {
        this->level = 1;
    } else if(level > 20) {
        this->level = 20;
    }else {
        this->level = level;
    }
    //seed random number generator
    srand(static_cast<unsigned int>(time(nullptr)));
    generateAbilityScores();
    calculateAbilityModifiers();


}

int Character::getLevel() const {
    return level;
}

void Character::generateAbilityScores() {
    //should soon be replaced with the dice class
    for(int& score : abilityScore) {
        score = rand() % 16 + 3;
    }
}

int Character::getAbilityScore(Ability ability) const{
    return abilityScore[ability];
}

void Character::calculateAbilityModifiers() {
    for(int i = 0; i < abilityScore.size(); i++) {
        abilityModifiers[i] = floor((abilityScore[i] - 10) / 2);
    }
}

int Character::getAbilityModifier(Ability ability) const {
    return abilityModifiers[ability];
}

void Character::calculateHitPoints() {


}

std::string Character::getName() const {
    return name;
}

