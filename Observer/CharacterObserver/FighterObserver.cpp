//
// Created by Reuven Ostrofsky on 2024-03-19.
//

#include "FighterObserver.h"

void FighterObserver::update() {
    std::cout << "Fighter Observer Update: " << std::endl;
    std::cout << "Fighter Name: " << fighter->getName() << std::endl;
    std::cout << "Fighter Level: " << fighter->getLevel() << std::endl;
    std::cout <<"Fighter Type: " << fighter->FighterTypeEnumToString(fighter->getFighterType()) << std::endl;
    std::cout << "Fighter Health: " << fighter->getStat(Character::HP) << std::endl;
    std::cout << "Fighter Armor Class: " << fighter->getStat(Character::AC) << std::endl;
    std::cout << "Fighter Ability Scores: " << std::endl;
    std::cout << "Strength: " << fighter->getAbilityScore(Character::Strength) << std::endl;
    std::cout << "Dexterity: " << fighter->getAbilityScore(Character::Dexterity) << std::endl;
    std::cout << "Constitution: " << fighter->getAbilityScore(Character::Constitution) << std::endl;
    std::cout << "Intelligence: " << fighter->getAbilityScore(Character::Intelligence) << std::endl;
    std::cout << "Wisdom: " << fighter->getAbilityScore(Character::Wisdom) << std::endl;
    std::cout << "Charisma: " << fighter->getAbilityScore(Character::Charisma) << std::endl;
    std::cout << "Fighter Ability Modifiers: " << std::endl;
    std::cout << "Strength: " << fighter->getAbilityModifier(Character::Strength) << std::endl;
    std::cout << "Dexterity: " << fighter->getAbilityModifier(Character::Dexterity) << std::endl;
    std::cout << "Constitution: " << fighter->getAbilityModifier(Character::Constitution) << std::endl;
    std::cout << "Intelligence: " << fighter->getAbilityModifier(Character::Intelligence) << std::endl;
    std::cout << "Wisdom: " << fighter->getAbilityModifier(Character::Wisdom) << std::endl;
    std::cout << "Charisma: " << fighter->getAbilityModifier(Character::Charisma) << std::endl;
    std::cout << "Fighter Proficiency Bonus: " << fighter->getStat(Character::PB) << std::endl;
    std::cout << "Fighter Attack Bonus: " << fighter->getStat(Character::AB) << std::endl;
}
