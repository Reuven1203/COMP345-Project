//
// Created by Reuven Ostrofsky on 2024-01-30.
//

#include "Character.h"
#include "Dice.h"





Character::Character(std::string name,int level): name(std::move(name)){
    if(level < 1) {
        this->level = 1;
    } else if(level > 20) {
        this->level = 20;
    }else {
        this->level = level;
    }
    generateAbilityScores();
    calculateAbilityModifiers();
    this -> currentHP = initializeHitPoints();
}



int Character::getLevel() const {
    return level;
}

void Character::generateAbilityScores() {
    Dice dice = Dice();
    //should soon be replaced with the dice class
    for(int& score : abilityScore) {
        score = dice.roll("4d6");
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

std::string Character::getName() const {
    return name;
}

int Character::getCurrentHP() const {
    return currentHP;
}



void Character::showCharacterStats() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Class: " << getClassName() << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Strength: " << abilityScore[Strength] << " Modifier: " << abilityModifiers[Strength] << std::endl;
    std::cout << "Dexterity: " << abilityScore[Dexterity] << " Modifier: " << abilityModifiers[Dexterity] << std::endl;
    std::cout << "Constitution: " << abilityScore[Constitution] << " Modifier: " << abilityModifiers[Constitution] << std::endl;
    std::cout << "Intelligence: " << abilityScore[Intelligence] << " Modifier: " << abilityModifiers[Intelligence] << std::endl;
    std::cout << "Wisdom: " << abilityScore[Wisdom] << " Modifier: " << abilityModifiers[Wisdom] << std::endl;
    std::cout << "Charisma: " << abilityScore[Charisma] << " Modifier: " << abilityModifiers[Charisma] << std::endl;
    std::cout << "Hit Points: " << currentHP << std::endl;

}

int Character::initializeHitPoints() {
    Dice dice = Dice();
    int baseHP = getDieType() + getAbilityModifier(Constitution);
    std::string levelString = std::to_string(level-1);
    return baseHP + dice.roll(levelString + 'd' + std::to_string(getDieType())+ '+' + std::to_string(getAbilityModifier(Constitution) * (level-1)));
}

std::string Character::getClassName() const {
    return "Character";
}


