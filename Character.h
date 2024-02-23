/**
 * @file Character.h
 * @brief Defines the Character class, which represents a character in a game with abilities, stats, and items.
 *
 * This file declares the Character class and its associated data structures. The Character class
 * serves as a base for creating characters with different abilities, stats, and equipped items. It
 * includes methods for character creation, stat calculation, and item management.
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <array>
#include <map>
#include "Dice.h" // Dice class for rolling dice
#include "Item.h" // Item class for managing items

/**
 * @class Character
 * @brief The Character class represents an entity in the game with various attributes and behaviors.
 *
 * Characters have abilities, levels, stats, and can equip items to modify their attributes.
 * This class provides the basic functionality for managing a character's attributes and equipment.
 */
class Character {
    friend class CharacterTest; ///< Allows CharacterTest class to access private and protected members for testing purposes.

protected:
    int currentHP; ///< Current hit points of the character.
    int level; ///< Level of the character.

    /**
     * @brief Returns the default die type used for hit points calculation. Can be overridden by derived classes.
     * @return DieType The default die type for the character.
     */
    [[nodiscard]] virtual DieType getDieType() const { return d6; }

public:
    /**
     * @brief Constructor that initializes a character with a name and level.
     * @param name The name of the character.
     * @param level The initial level of the character, clamped between 1 and 20.
     */
    explicit Character(std::string name, int level);

    /**
     * @enum Ability
     * @brief Enumerates the different abilities a character can have.
     */
    enum Ability {
        Strength,
        Dexterity,
        Constitution,
        Intelligence,
        Wisdom,
        Charisma
    };

    /**
     * @enum Stats
     * @brief Enumerates the different stats a character can possess.
     */
    enum Stats {
        HP, ///< Hit Points
        PB, ///< Proficiency Bonus
        AC, ///< Armor Class
        AB, ///< Attack Bonus
        DB  ///< Damage Bonus
    };

    // Getter methods for character properties
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] int getLevel() const;
    [[nodiscard]] int getAbilityScore(Ability ability) const;
    [[nodiscard]] int getAbilityModifier(Ability ability) const;

    /**
     * @brief Displays the character's stats to the standard output.
     */
    void showCharacterStats() const;

    /**
     * @brief Returns the class name of the character. Allows for polymorphic behavior.
     * @return std::string The class name of the character.
     */
    [[nodiscard]] virtual std::string getClassName() const;

    // Methods for managing equipment
    void equip(const Item& item);
    void unequip(const Item& item);
    void showWornItems() const;
    [[nodiscard]] int getStat(Stats stats) const;

private:
    std::string name; ///< Character's name.
    std::array<int, 6> abilityScore{}; ///< Scores for the character's abilities.
    std::array<int, 6> abilityModifiers{}; ///< Modifiers derived from the ability scores.

    // Methods for internal mechanics
    void generateAbilityScores();
    void calculateAbilityModifiers();
    void calculateAbilityScores();
    void reduceAbilityAfterUnequip(const Item& item);
    [[nodiscard]] int initializeHitPoints();
    [[nodiscard]] int initializeProficiencyBonus() const;
    static bool isAbility(const std::string& ability);
    static Ability stringToEnum(const std::string& ability);
    static Stats stringToEnumStats(const std::string& stats);

    std::map<Stats, int> stats; ///< Map of character stats.
    std::map<Item::ItemType, Item> wornItems; ///< Currently equipped items.

    /**
     * @brief Checks if an item is currently equipped.
     * @param item The item to check.
     * @return true If the item is equipped, false otherwise.
     */
    bool isItemEquipped(const Item &item);
};

#endif //CHARACTER_H
