//
// Created by Reuven Ostrofsky on 2024-03-19.
//

#include <algorithm>
#include "BullyFighterBuilder.h"

BullyFighterBuilder::BullyFighterBuilder() {
    fighter = new Fighter("Bully", 1, Fighter::BULLY);
}
BullyFighterBuilder::BullyFighterBuilder(string name, int level)
{
    fighter = new Fighter(std::move(name), level, Fighter::BULLY);
}


BullyFighterBuilder::~BullyFighterBuilder() {
    delete fighter;
}


void BullyFighterBuilder::buildAbilityScores() {
   
    int abilityScores[6];
    //for loop
    for (int &abilityScore: abilityScores) {
        abilityScore = Dice::GetGlobal().roll("3d6");
    }
    //sort in descending order
    std::sort(abilityScores, abilityScores + 6, std::greater<int>());
    //assign in abliityScore in this order: STR, CON, DEX, INT, CHA, WIS
    fighter->setAbilityScore(Character::Strength, abilityScores[0]);
    fighter->setAbilityScore(Character::Constitution, abilityScores[1]);
    fighter->setAbilityScore(Character::Dexterity, abilityScores[2]);
    fighter->setAbilityScore(Character::Intelligence, abilityScores[3]);
    fighter->setAbilityScore(Character::Charisma, abilityScores[4]);
    fighter->setAbilityScore(Character::Wisdom, abilityScores[5]);
}