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
#include "Item.h"



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

    enum Stats {
        HP, // hit points
        PB, // proficiency bonus
        AC, // armor class
        AB, // attack bonus
        DB // damage bonus
    };

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] int getLevel() const;
    [[nodiscard]] int getAbilityScore(Ability ability) const;
    [[nodiscard]] int getAbilityModifier(Ability ability) const;
    void showCharacterStats() const;
    [[nodiscard]] virtual std::string getClassName() const ;
    void equip(const Item& item);
    void unequip(const Item& item);
    void showWornItems() const;
    [[nodiscard]] int getStat(Stats stats) const;
private:
    std::string name;
    std::array<int,6> abilityScore{};
    std::array<int,6> abilityModifiers{};
    void generateAbilityScores();
    void calculateAbilityModifiers();
    void calculateAbilityScores();
    int initializeHitPoints();
    [[nodiscard]] int initializeProficiencyBonus() const;
    static bool isAbility(const std::string& ability);
    static Ability stringToEnum(const std::string& ability);
    static Stats stringToEnumStats(const std::string& stats);
    std::map<Stats, int> stats;
    std::map<Item::ItemType, Item> wornItems;
};
