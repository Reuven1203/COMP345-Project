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
#include "../Dice/Dice.h" // Dice class for rolling dice
#include "../Item/Item.h" // Item class for managing items
#include "../Observer/Observable.h"
#include "../Strategy/CharacterStrategy/CharacterStrategy.h"
#include "../Item/itemContainer.h"
/**
 * @class Character
 * @brief The Character class represents an entity in the game with various attributes and behaviors.
 *
 * Characters have abilities, levels, stats, and can equip items to modify their attributes.
 * This class provides the basic functionality for managing a character's attributes and equipment.
 */
 class CharacterStrategy;
class dungeonMap;
class Character : public Observable {
    friend class CharacterTest; ///< Allows CharacterTest class to access private and protected members for testing purposes.
    friend class MapBuilder;
    friend class ItemDecorator;

public:
    enum Stats {
        HP, ///< Hit Points
        PB, ///< Proficiency Bonus
        AC, ///< Armor Class
        AB, ///< Attack Bonus
        DB,
        RA///< Damage Bonus
    };

    /**
     * @brief Default constructor.
     */
    Character() = default;

    /**
     * @brief Constructor that initializes a character with a name and level.
     * @param name The name of the character.
     * @param level The initial level of the character, clamped between 1 and 20.
     */
    explicit Character(std::string name, int level);

    /**
     * Constructor that initializes a character with a name, level, abilityScores, and hp values.
     * @param name The name of the character
     * @param level The initial level of the character, clamped between 1 and 20
     * @param abilityScores The ability scores of the character
     * @param maxHp The max HP of the character
     * @param currentHp The current HP of the character
     */
    explicit Character(std::string name, int level, const int abilityScores[6], int maxHp, int currentHp);

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
     * @brief Changes the character's name
     * @param name
     */
    void setName(const std::string &n);

    /**
     * @brief Displays the character's stats to the standard output.
     */
    virtual void showCharacterStats() const;

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
     * @brief Increases character's level by 1
     */

    void levelUp();

    void move(dungeonMap& map);

    void setStrategy(CharacterStrategy* strategy);
    CharacterStrategy *getStrategy() const;
    void setCurrentHP(int hp);
    int getCurrentHP() const;
    void attack(Character* target);

    /**
 * @brief Accessor method for Strength attribute
 * @return Strength value of character
 */
    virtual int getSTR() const;
    /**
     * @brief Accessor method for Dexterity attribute
     * @return int Dexterity value of character
     */
    virtual int getDEX() const;
    /**
     * @brief Accessor method for Constitution attribute
     * @return int Constitution value of character
     */
    virtual int getCON() const;
    /**
     * @brief Accessor method for Intelligence attribute
     * @return int Intelligence value of character
     */
    virtual int getINT() const;
    /**
     * @brief Accessor method for Wisdom attribute
     * @return int Wisdom value of character
     */
    virtual int getWIS() const;
    /**
     * @brief Accessor method for Charisma attribute
     * @return int Charisma value of character
     */
    virtual int getCHA() const;
    /**
     * @brief Accessor method for Attack attribute
     * @return int Attack value of character
     */
    virtual int getATK() const;
    /**
     * @brief Accessor method for Damage attribute
     * @return int Damage value of character
     */
    virtual int getDMG() const;
    /**
     * @brief Accessor method for Armor Class attribute
     * @return int Armor Class value of character
     */
    virtual int getAC() const;

    /**
     * @brief Checks if Character has weapon decorator
     * @return bool true if Character has weapon decorator, false if not
     */
    virtual bool hasWeapon() const;
    /**
     * @brief Checks if Character has helmet decorator
     * @return bool true if Character has helmet decorator, false if not
     */
    virtual bool hasHelmet() const;
    /**
     * @brief Checks if Character has armor decorator
     * @return bool true if Character has armor decorator, false if not
     */
    virtual bool hasArmor() const;
    /**
     * @brief Checks if Character has shield decorator
     * @return bool true if Character has shield decorator, false if not
     */
    virtual bool hasShield() const;
    /**
     * @brief Checks if Character has ring decorator
     * @return bool true if Character has ring decorator, false if not
     */
    virtual bool hasRing() const;
    /**
     * @brief Checks if Character has belt decorator
     * @return bool true if Character has belt decorator, false if not
     */
    virtual bool hasBelt() const;
    /**
     * @brief Checks if Character has boots decorator
     * @return bool true if Character has boots decorator, false if not
     */
    virtual bool hasBoots() const;

    container& getInventory();
    void storeItem(Item);
    void printInventory();
    void setInventory(container&);

    bool isItemEquipped(const Item& item);

    void setInitiative(int);
    int getInitiative();

    void gainEXP(int exp);
    int getEXP();
   /* CharacterStrategy::StrategyType getStrategy();*/
protected:

    int currentHP{}; ///< Current hit points of the character.
    int level{}; ///< Level of the character.

    /**
     * @brief Returns the default die type used for hit points calculation. Can be overridden by derived classes.
     * @return DieType The default die type for the character.
     */
    [[nodiscard]] virtual DieType getDieType() const { return d6; }

/**
 * @brief Calculates the ability modifiers based on ability scores.
 *
 * This function computes each ability modifier as the floor of ((abilityScore - 10) / 2).
 */
    void calculateAbilityModifiers();

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

    std::map<Stats, int> stats;

    std::array<int, 6> abilityScore{};


private:
    explicit Character(std::string name, int level, const int abilityScores[6], int maxHp,int currentHp, std::map<Item::ItemType, Item> wornItems);
    std::string name; ///< Character's name.
    ///< Scores for the character's abilities.
    std::array<int, 6> abilityModifiers{}; ///< Modifiers derived from the ability scores.
    CharacterStrategy* strategy = nullptr;
    int initativeRoll = 0;
    int EXP = 0;
    int expToLVL = 0;
    /**
     * @brief Generates random ability scores for the character.
     *
     * This function uses dice rolls to randomly generate ability scores for the character.
     */
    virtual void generateAbilityScores();

    /**
     * @brief Recalculates ability scores and modifiers based on equipped items.
     *
     * Adjusts the character's ability scores and modifiers according to the stats of equipped items.
     */
    void calculateAbilityScores(const Item& item);

    /**
     * @brief Reduces character's ability scores after unequipping an item.
     * @param item The item being unequipped.
     *
     * This function reduces the character's ability scores based on the item's stats.
     */
    void reduceAbilityAfterUnequip(const Item& item);



    container inventory;

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

    ///< Map of character stats.
    std::map<Item::ItemType, Item> wornItems; /*= {
      {Item::ItemType::ARMOR, Item()},
      {Item::ItemType::BELT, Item()},
      {Item::ItemType::BOOTS, Item()},
      {Item::ItemType::HELMET, Item()},
      {Item::ItemType::RING, Item()},
      {Item::ItemType::SHIELD, Item()},
      {Item::ItemType::WEAPON, Item()}
    };*/
    ///< Currently equipped items.

    /**
     * @brief Checks if an item is currently equipped.
     * @param item The item to check.
     * @return true If the item is equipped, false otherwise.
     *
     * Determines if the specified item is equipped by checking the wornItems map.
     */
  

};

#endif //CHARACTER_H
