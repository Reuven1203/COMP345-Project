/**
 * @file Fighter.h
 * @brief Contains the declaration of the Fighter class.
 * @author Reuven Ostrofsky
 * @date 2024-02-07
 */

#ifndef COMP345_A1_FIGHTER_H
#define COMP345_A1_FIGHTER_H

#include "Character.h"
#include "../Dice/Dice.h"

/**
 * @brief A static constant representing the class name "Fighter".
 */
static const std::string className = "Fighter";

/**
 * @class Fighter
 * @brief Represents a fighter character in the game.
 * @details Inherits from the Character class.
 */
class Fighter: public Character {
public:
    /**
     * @brief Constructs a Fighter object.
     * @param name The name of the fighter.
     * @param level The level of the fighter.
     */
    explicit Fighter(std::string name, int level);

    /**
     * @brief Gets the name of the fighter's class.
     * @return The name of the fighter's class ("Fighter").
     */
    std::string getClassName() const override;

private:
    /**
     * @brief Gets the die type for the fighter's hit points calculation.
     * @return The die type for hit points calculation (d10).
     */
    DieType getDieType() const override { return d10; }

public:
};

#endif //COMP345_A1_FIGHTER_H
