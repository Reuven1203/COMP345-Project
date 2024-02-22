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

    /**
    * @class Character
    * @brief Represents a character in the game with abilities, stats, and equipped items.
    *
    * This class manages the character's attributes such as name, level, ability scores, and equipped items.
    * It includes functionalities for modifying these attributes and calculating derived statistics.
    */

private:
    std::string name; ///< Character's name.
    std::array<int, 6> abilityScore{}; ///< Scores for the character's abilities.
    std::array<int, 6> abilityModifiers{}; ///< Modifiers derived from the ability scores.

    /**
     * @brief Generates random ability scores for the character.
     *
     * This function uses dice rolls to randomly generate ability scores for the character.
     */
    void generateAbilityScores();

    /**
     * @brief Calculates the ability modifiers based on ability scores.
     *
     * This function computes each ability modifier as the floor of ((abilityScore - 10) / 2).
     */
    void calculateAbilityModifiers();

    /**
     * @brief Recalculates ability scores and modifiers based on equipped items.
     *
     * Adjusts the character's ability scores and modifiers according to the stats of equipped items.
     */
    void calculateAbilityScores();

    /**
     * @brief Reduces character's ability scores after unequipping an item.
     * @param item The item being unequipped.
     *
     * This function reduces the character's ability scores based on the item's stats.
     */
    void reduceAbilityAfterUnequip(const Item& item);

    /**
     * @brief Initializes the character's hit points based on level and Constitution modifier.
     * @return int The calculated hit points.
     *
     * Calculates initial hit points using the character's die type and Constitution modifier.
     */
    [[nodiscard]] int initializeHitPoints();

    /**
     * @brief Initializes the character's proficiency bonus based on their level.
     * @return int The calculated proficiency bonus.
     *
     * Determines the proficiency bonus based on the character's level according to D&D rules.
     */
    [[nodiscard]] int initializeProficiencyBonus() const;

    /**
     * @brief Checks if a given string corresponds to a valid ability.
     * @param ability The ability name to check.
     * @return true if the string is a valid ability name, false otherwise.
     */
    static bool isAbility(const std::string& ability);

    /**
     * @brief Converts a string to its corresponding Ability enum.
     * @param str The string to convert.
     * @return Ability The corresponding Ability enum.
     *
     * Throws std::invalid_argument if the string does not correspond to a valid ability.
     */
    static Ability stringToEnum(const std::string& str);

    /**
     * @brief Converts a string to its corresponding Stats enum.
     * @param str The string to convert.
     * @return Stats The corresponding Stats enum.
     *
     * Throws std::invalid_argument if the string does not correspond to a valid stat.
     */
    static Stats stringToEnumStats(const std::string& str);

    std::map<Stats, int> stats; ///< Map of character stats.
    std::map<Item::ItemType, Item> wornItems; ///< Currently equipped items.

    /**
     * @brief Checks if an item is currently equipped.
     * @param item The item to check.
     * @return true If the item is equipped, false otherwise.
     *
     * Determines if the specified item is equipped by checking the wornItems map.
     */
    bool isItemEquipped(const Item &item);
};

#endif //CHARACTER_H
