/**
 * @file Character.cpp
 * @brief Implementation of the Character class.
 *
 * Implements the functionality of the Character class including constructors,
 * ability score generation, item management, and stat calculations.
 */

#include "Character.h"
#include "Dice.h"

/**
 * @brief Constructor for Character, initializes character with name and level.
 *
 * Ensures the character's level is within the game's limits (1-20). Initializes
 * ability scores and calculates modifiers and other initial statistics.
 *
 * @param name Name of the character.
 * @param level Initial level of the character.
 */
Character::Character(std::string name, int level) : name(std::move(name)) {
    this->level = std::max(1, std::min(level, 20));
    generateAbilityScores();
    calculateAbilityModifiers();
    stats[HP] = initializeHitPoints();
    stats[PB] = initializeProficiencyBonus();
    stats[AC] = 10 + getAbilityModifier(Dexterity);
    stats[AB] = getAbilityModifier(Strength) + stats[PB];
    stats[DB] = getAbilityModifier(Strength) + 1;
}

/**
 * @brief Returns the character's current level.
 *
 * @return int The current level of the character.
 */
int Character::getLevel() const {
    return level;
}

/**
 * @brief Equips an item to the character and recalculates ability scores.
 *
 * @param item The item to equip.
 */
void Character::equip(const Item& item) {
    wornItems[item.equipType] = item;
    calculateAbilityScores();
}

/**
 * @brief Reduces ability scores and stats after unequipping an item.
 *
 * @param item The item to unequip.
 */
void Character::reduceAbilityAfterUnequip(const Item& item) {
    for (const auto &stat : item.itemOverall) {
        if (isAbility(stat.first) && stat.second != 0) {
            abilityScore[stringToEnum(stat.first)] -= stat.second;
        } else {
            stats[stringToEnumStats(stat.first)] -= stat.second;
        }
    }
}

/**
 * @brief Unequips an item from the character.
 *
 * @param item The item to remove.
 */
void Character::unequip(const Item& item) {
    wornItems.erase(item.equipType);
    reduceAbilityAfterUnequip(item);
}

/**
 * @brief Generates random ability scores for the character using dice rolls.
 */
void Character::generateAbilityScores() {
    Dice dice;
    for (int& score : abilityScore) {
        score = dice.roll("4d6");
    }
}

/**
 * @brief Gets the score of a specified ability.
 *
 * @param ability The ability to query.
 * @return int The score of the specified ability.
 */
int Character::getAbilityScore(Ability ability) const {
    return abilityScore[ability];
}

/**
 * @brief Calculates the modifiers for the character's abilities.
 */
void Character::calculateAbilityModifiers() {
    for (size_t i = 0; i < abilityScore.size(); ++i) {
        abilityModifiers[i] = (abilityScore[i] - 10) / 2;
    }
}

/**
 * @brief Gets the modifier for a specified ability.
 *
 * @param ability The ability to query.
 * @return int The modifier for the specified ability.
 */
int Character::getAbilityModifier(Ability ability) const {
    return abilityModifiers[ability];
}

/**
 * @brief Returns the character's name.
 *
 * @return std::string The name of the character.
 */
std::string Character::getName() const {
    return name;
}

/**
 * @brief Gets a specified stat of the character.
 *
 * @param stat The stat to query.
 * @return int The value of the specified stat.
 */
int Character::getStat(Stats stat) const {
    return stats.at(stat);
}

/**
 * @brief Displays character statistics on standard output.
 */
void Character::showCharacterStats() const {
    // Method implementation
}

/**
 * @brief Initializes the character's hit points based on level and Constitution modifier.
 *
 * @return int The initial hit points of the character.
 */
int Character::initializeHitPoints() {
    Dice dice;
    int baseHP = getDieType() + getAbilityModifier(Constitution);
    std::string levelStr = std::to_string(level - 1);
    return baseHP + dice.roll(levelStr + 'd' + std::to_string(getDieType()) + '+' + std::to_string(getAbilityModifier(Constitution) * (level - 1)));
}

/**
 * @brief Returns the class name of the character. Useful for subclasses.
 *
 * @return std::string The class name.
 */
std::string Character::getClassName() const {
    return "Character";
}

/**
 * @brief Calculates the proficiency bonus based on the character's level.
 *
 * @return int The proficiency bonus.
 */
int Character::initializeProficiencyBonus() const {
    if (level < 5) {
        return 2;
    } else if (level < 9) {
        return 3;
    } else if (level < 13) {
        return 4;
    } else if (level < 17) {
        return 5;
    } else {
        return 6;
    }
}

/**
 * @brief Displays the items currently equipped by the character.
 */
void Character::showWornItems() const {
    // Method implementation
}

/**
 * @brief Checks if an item is currently equipped.
 *
 * @param item The item to check.
 * @return true If the item is equipped, false otherwise.
 */
bool Character::isItemEquipped(const Item& item) {
    return wornItems.find(item.equipType) != wornItems.end();
}

/**
 * @brief Recalculates ability scores based on equipped items.
 */
void Character::calculateAbilityScores() {
    // Method implementation
}

/**
 * @brief Determines if a string corresponds to a valid ability.
 *
 * @param ability The ability string to validate.
 * @return true if the string is a valid ability, false otherwise.
 */
bool Character::isAbility(const std::string& ability) {
    // Method implementation
    return false; // Placeholder return
}

/**
 * @brief Converts a string to its corresponding Ability enum.
 *
 * @param str The string to convert.
 * @return Character::Ability The corresponding Ability enum.
 */
Character::Ability Character::stringToEnum(const std::string& str) {
    // Method implementation
    return Strength; // Placeholder return
}

/**
 * @brief Converts a string to its corresponding Stats enum.
 *
 * @param str The string to convert.
 * @return Character::Stats The corresponding Stats enum.
 */
Character::Stats Character::stringToEnumStats(const std::string& str) {
    // Method implementation
    return HP; // Placeholder return
}
