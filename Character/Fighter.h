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
    friend class FighterBuilder;
    friend class BullyFighterBuilder;
    friend class NimbleFighterBuilder;
    friend class TankFighterBuilder;

public:
    enum FighterType {
        BULLY,
        NIMBLE,
        TANK
    };

    /**
     * @brief Default constructor.
     */
    Fighter() = default;

    /**
     * @brief Constructs a Fighter object.
     * @param name The name of the fighter.
     * @param level The level of the fighter.
     */
    explicit Fighter(std::string name, int level, FighterType type);

    /**
     * @brief Gets the name of the fighter's class.
     * @return The name of the fighter's class ("Fighter").
     */
    [[nodiscard]] std::string getClassName() const override;

    /**
     * @brief Gets the type of fighter.
     * @return The type of fighter.
     */
    [[nodiscard]] FighterType getFighterType() const;


    /**
     * @brief Converts the FighterType enum to a string.
     * @param type The FighterType enum to convert.
     * @return The string representation of the FighterType enum.
     */
    [[nodiscard]] static std::string FighterTypeEnumToString(FighterType type) ;



private:

    /**
     * @brief The type of fighter. Can be BULLY, NIMBLE, or TANK.
     */
    FighterType fighterType;

    /**
     * @brief Gets the die type for the fighter's hit points calculation.
     * @return The die type for hit points calculation (d10).
     */
    DieType getDieType() const override { return d10; }

    /**
     * @brief Generates the ability scores for the fighter.
     */
    /**
     * @brief Sets the ability score modifiers for the fighter.
     */

    void setAbilityScore(Ability ability, int score);


};

#endif //COMP345_A1_FIGHTER_H
