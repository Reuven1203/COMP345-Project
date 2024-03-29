//
// Created by Reuven Ostrofsky on 2024-03-09.
//

#include "CharacterDisplay.h"

void CharacterDisplay::update() {
    std::cout << "Character Display Update: " << std::endl;
    std::cout << "Character Name: " << character->getName() << std::endl;
    std::cout << "Character Level: " << character->getLevel() << std::endl;
    std::cout << "Character Health: " << character->getStat(Character::HP) << std::endl;
    std::cout << "Character Armor Class: " << character->getStat(Character::AC) << std::endl;
    std::cout << "Character Ability Scores: " << std::endl;
    std::cout << "Strength: " << character->getAbilityScore(Character::Strength) << std::endl;
    std::cout << "Dexterity: " << character->getAbilityScore(Character::Dexterity) << std::endl;
    std::cout << "Constitution: " << character->getAbilityScore(Character::Constitution) << std::endl;
    std::cout << "Intelligence: " << character->getAbilityScore(Character::Intelligence) << std::endl;
    std::cout << "Wisdom: " << character->getAbilityScore(Character::Wisdom) << std::endl;
    std::cout << "Charisma: " << character->getAbilityScore(Character::Charisma) << std::endl;
    std::cout << "Character Ability Modifiers: " << std::endl;
    std::cout << "Strength: " << character->getAbilityModifier(Character::Strength) << std::endl;
    std::cout << "Dexterity: " << character->getAbilityModifier(Character::Dexterity) << std::endl;
    std::cout << "Constitution: " << character->getAbilityModifier(Character::Constitution) << std::endl;
    std::cout << "Intelligence: " << character->getAbilityModifier(Character::Intelligence) << std::endl;
    std::cout << "Wisdom: " << character->getAbilityModifier(Character::Wisdom) << std::endl;
    std::cout << "Charisma: " << character->getAbilityModifier(Character::Charisma) << std::endl;
    std::cout << "Character Proficiency Bonus: " << character->getStat(Character::PB) << std::endl;
    std::cout << "Character Attack Bonus: " << character->getStat(Character::AB) << std::endl;
    std::cout << "Character Damage Bonus: " << character->getStat(Character::DB) << std::endl;
    std::cout << "____________________________________________________" << std::endl;


}
