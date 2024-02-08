//
// Created by Reuven Ostrofsky on 2024-01-30.
//


#include <iostream>
#include "Character.h"

//print hello
int main() {
    std::cout << "Hello, World!" << std::endl;
    Character player("Reuven",6);
    std::cout <<"Player: " << player.getName() <<" Level: " << player.getLevel() << std::endl;
    std::cout << "Player strength: " << player.getAbilityScore(Character::Strength) << std::endl;
    std::cout << "Player strength modifier: " << player.getAbilityModifier(Character::Strength) << std::endl;
    std::cout << "Player dexterity:" << player.getAbilityScore(Character::Dexterity) << std::endl;
    std::cout << "Player dexterity modifier: " << player.getAbilityModifier(Character::Dexterity) << std::endl;
    std::cout << "Player constitution: " << player.getAbilityScore(Character::Constitution) << std::endl;
    std::cout << "Player constitution modifier: " << player.getAbilityModifier(Character::Constitution) << std::endl;
    std::cout << "Player intelligence: " << player.getAbilityScore(Character::Intelligence) << std::endl;
    std::cout << "Player intelligence modifier: " << player.getAbilityModifier(Character::Intelligence) << std::endl;
    std::cout << "Player wisdom: " << player.getAbilityScore(Character::Wisdom) << std::endl;
    std::cout << "Player wisdom modifier: " << player.getAbilityModifier(Character::Wisdom) << std::endl;
    std::cout << "Player charisma: " << player.getAbilityScore(Character::Charisma) << std::endl;
    std::cout << "Player charisma modifier: " << player.getAbilityModifier(Character::Charisma) << std::endl;


    return 0;

}

