#include "FighterBuilder.h"




void FighterBuilder::buildAbilityModifiers() {
    fighter->calculateAbilityModifiers();
}

void FighterBuilder::buildStats() {
    fighter->stats[Character::HP] = fighter->initializeHitPoints();
    fighter->stats[Character::PB] = fighter->initializeProficiencyBonus();
    fighter->stats[Character::AC] = 10 + fighter->getAbilityModifier(Character::Dexterity);
    fighter->stats[Character::AB] = fighter->getAbilityModifier(Character::Strength) + fighter->stats[Character::PB];
    fighter->stats[Character::DB] = fighter->getAbilityModifier(Character::Strength) + 1;
    fighter->setCurrentHP(fighter->stats[Character::HP]);
}

Fighter *FighterBuilder::getFighter() {
    Fighter* result = fighter;  // Hold the created fighter object
    fighter = new Fighter();    // Reset for the next build
    return result;
}

void FighterBuilder::buildName(string name) {
    fighter->setName(name);
}


