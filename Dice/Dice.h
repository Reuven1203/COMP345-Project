/**
 * @file Dice.h
 * @brief Declaration of the Dice class and related enums and structs.
 * @author Julian D'Addario
 * @date Feb 7, 2024
 */

#ifndef DICE_DICE_H
#define DICE_DICE_H

#include <string>
#include "Random.h"
#include "../Observer/Observable.h"
/**
 * @brief Enum to represent different types of dice.
 */
enum DieType { d4=4, d6=6, d8=8, d10=10, d12=12, d20=20, d100=100 };

/**
 * @brief Struct to represent a dice roll.
 */
 struct Roll {
    DieType dieType; ///< Type of the die.
     int numDice;     ///< Number of dice to roll.
    int numAdded;    ///< Number to add to the total roll.
};

/**
 * @class Dice
 * @brief Class for rolling dice.
 * This class provides functionality to roll dice based on a given roll string.
 */
class Dice:public Observable {
    friend class DiceTest; // For testing purposes
private:
    /**
     * @brief Internal method to parse a string into a Roll struct.
     *
     * @param str The roll string to parse.
     * @return A Roll struct representing the parsed roll.
     */
    Roll parseRoll(std::string str);

    /**
     * @brief Internal method to parse a die type string.
     *
     * @param dieTypeStr The die type string to parse.
     * @param str The original roll string (used for error handling).
     * @return The corresponding DieType enum value.
     */
    DieType parseDie(std::string dieTypeStr, std::string str);

    /**
     * @brief Output error message for invalid roll string.
     *
     * @param str The invalid roll string.
     */
    void diceRollStringErr(const std::string& str);
    bool checkIfNumber(char c);




public:
    Dice() = default;
    /**
     * @brief Default constructor.
     * Constructs a Dice object.
     */
    
    Dice(const Dice&) = delete;

   static Dice& GetGlobal() 
   {
      static Dice _dice;
      return _dice; 
   }
   void operator=(Dice const&) = delete;
    /**
     * @brief Roll dice based on the given roll string.
     *
     * @param rollString The roll string in format xdy[+z] or xdy+z.
     * @return The total roll value.
     */
   int roll(std::string rollString);
};

#endif //DICE_DICE_H
