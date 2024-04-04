//
// Created by Reuven Ostrofsky on 2024-03-19.
//

#include <algorithm>
#include "NimbleFighterBuilder.h"

NimbleFighterBuilder::NimbleFighterBuilder() {
    fighter = new Fighter("Nimble Fighter", 1, Fighter::NIMBLE);
}

NimbleFighterBuilder::NimbleFighterBuilder(string name, int level) {
    fighter = new Fighter(std::move(name), level, Fighter::NIMBLE);
}

NimbleFighterBuilder::~NimbleFighterBuilder() {
    delete fighter;
}

void NimbleFighterBuilder::buildAbilityScores() {
    Dice& dice = Dice::GetGlobal();
    int abilityScores[6];
    //for loop
    for (int &abilityScore: abilityScores) {
        abilityScore = dice.roll("3d6");
    }
    //sort in descending order
    std::sort(abilityScores, abilityScores + 6, std::greater<int>());
    //assign in abilityScore in this order: DEX, CON, STR, INT, CHA, WIS
    fighter->setAbilityScore(Character::Dexterity, abilityScores[0]);
    fighter->setAbilityScore(Character::Constitution, abilityScores[1]);
    fighter->setAbilityScore(Character::Strength, abilityScores[2]);
    fighter->setAbilityScore(Character::Intelligence, abilityScores[3]);
    fighter->setAbilityScore(Character::Charisma, abilityScores[4]);
    fighter->setAbilityScore(Character::Wisdom, abilityScores[5]);
}




