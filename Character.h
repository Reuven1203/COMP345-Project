//
// Created by Reuven Ostrofsky on 2024-01-30.
//

#ifndef CHARACTER_H
#define CHARACTER_H
#endif //CHARACTER_H
#include <iostream>
#include "random"
#include <string>



class Character {
private:
    std::string name;
    int level;
    std::array<int,6> abilityScore{};
    std::array<int,6> abilityModifiers{};
    int maxHP;
    int currentHP;
    void generateAbilityScores();
    void calculateAbilityModifiers();
    void calculateHitPoints();

public:
    enum Ability {
        Strength,
        Dexterity,
        Constitution,
        Intelligence,
        Wisdom,
        Charisma
    };
    explicit Character(std::string name, int level);
    std::string getName() const;
    int getLevel() const;
    int getAbilityScore(Ability ability) const;
    int getAbilityModifier(Ability ability) const;
};
