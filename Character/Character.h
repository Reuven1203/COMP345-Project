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
#include "../Dice/Dice.h" // Dice class for rolling dice
#include "../Item/Item.h" // Item class for managing items
#include "../Observer/Observable.h"

/**
 * @class Character
 * @brief The Character class represents an entity in the game with various attributes and behaviors.
 *
 * Characters have abilities, levels, stats, and can equip items to modify their attributes.
 * This class provides the basic functionality for managing a character's attributes and equipment.
 */
class Character : public Observable {
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
    /**
 * @brief Gets the character's name.
 * @return std::string The name of the character.
 *
 * This function returns the name of the character. The name is used to identify
 * the character in the game and does not affect any game mechanics.
 */
    [[nodiscard]] std::string getName() const;

/**
 * @brief Gets the character's current level.
 * @return int The current level of the character.
 *
 * This function returns the character's level. Levels represent the character's
 * progress and experience in the game. Higher levels typically indicate stronger characters.
 */
    [[nodiscard]] int getLevel() const;

/**
 * @brief Gets the score of a specific ability for the character.
 * @param ability The ability for which the score is requested.
 * @return int The score of the specified ability.
 *
 * This function returns the score for a specified ability. Ability scores
 * determine the character's capabilities in various aspects such as strength,
 * intelligence, and dexterity.
 */
    [[nodiscard]] int getAbilityScore(Ability ability) const;

/**
 * @brief Gets the modifier for a specific ability for the character.
 * @param ability The ability for which the modifier is requested.
 * @return int The modifier of the specified ability.
 *
 * This function returns the modifier for a specified ability. Ability modifiers
 * are derived from ability scores and are used in calculating the outcomes of
 * actions that depend on the character's abilities.
 */
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

    /**
 * @brief Equips an item to the character.
 * @param item The item to be equipped.
 *
 * This function equips an item to the character, potentially altering the character's
 * ability scores and other statistics based on the item's properties. If the character
 * already has an item equipped in the same slot, the behavior of this function is
 * defined by the game mechanics (e.g., the previous item may need to be unequipped first).
 */
    void equip(const Item& item);

/**
 * @brief Unequips an item from the character.
 * @param item The item to be unequipped.
 *
 * This function removes an item from the character's equipment, reversing any changes
 * to the character's statistics that were made by equipping the item. If the item is not
 * currently equipped, the function may simply do nothing or handle the situation as appropriate.
 */
    void unequip(const Item& item);

/**
 * @brief Displays the items currently equipped by the character.
 *
 * This function prints out a list of the items that the character is currently wearing,
 * along with their stats or effects. This can be used to provide the player with an overview
 * of their equipped items and their contributions to the character's abilities.
 */
    void showWornItems() const;

/**
 * @brief Gets the value of a specified stat for the character.
 * @param stats The stat for which the value is requested.
 * @return int The value of the specified stat.
 *
 * This function returns the current value of a specified stat (e.g., hit points, armor class).
 * Stats are derived from the character's level, ability scores, and equipped items. This method
 * allows querying the character's stats to determine their capabilities and status in the game.
 */
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