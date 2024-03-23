//
// Created by Reuven Ostrofsky on 2024-03-19.
//

#include "TankFighterBuilder.h"
TankFighterBuilder::TankFighterBuilder() {
    fighter = new Fighter("Tank Fighter", 1, Fighter::TANK);
}

TankFighterBuilder::TankFighterBuilder(string name, int level) {
    fighter = new Fighter(std::move(name), level, Fighter::TANK);
}


TankFighterBuilder::~TankFighterBuilder() {
    delete fighter;
}

void TankFighterBuilder::buildAbilityScores() {
    Dice dice = Dice();
    int abilityScores[6];
    //for loop
    for (int &abilityScore: abilityScores) {
        abilityScore = dice.roll("3d6");
    }
    //sort in descending order
    std::sort(abilityScores, abilityScores + 6, std::greater<int>());
    //assign in abliityScore in this order:CON, DEX, STR, INT, CHA, WIS
    fighter->setAbilityScore(Character::Constitution, abilityScores[0]);
    fighter->setAbilityScore(Character::Dexterity, abilityScores[1]);
    fighter->setAbilityScore(Character::Strength, abilityScores[2]);
    fighter->setAbilityScore(Character::Intelligence, abilityScores[3]);
    fighter->setAbilityScore(Character::Charisma, abilityScores[4]);
    fighter->setAbilityScore(Character::Wisdom, abilityScores[5]);
}


