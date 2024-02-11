//
// Created by Reuven Ostrofsky on 2024-01-30.
//

#ifndef CHARACTER_H
#define CHARACTER_H
#endif //CHARACTER_H
#include <iostream>
#include "random"
#include <string>
#include "Dice.h"



class Character {
protected:
    int currentHP;
    explicit Character(std::string name, int level);
    int level;
    [[nodiscard]] virtual DieType getDieType() const { return d6; } // Default DieType for Character
public:
    enum Ability {
        Strength,
        Dexterity,
        Constitution,
        Intelligence,
        Wisdom,
        Charisma
    };
    std::string getName() const;
    int getLevel() const;
    int getAbilityScore(Ability ability) const;
    int getAbilityModifier(Ability ability) const;
    void showCharacterStats() const;
    int getCurrentHP() const;
    virtual std::string getClassName() const ;
private:
    std::string name;
    int proficiencyBonus;
    int armorClass;
    int attackBonus;
    int damageBonus;
    std::array<int,6> abilityScore{};
    std::array<int,6> abilityModifiers{};
    void generateAbilityScores();
    void calculateAbilityModifiers();
    int initializeHitPoints();
    int initializeProficiencyBonus();
};
