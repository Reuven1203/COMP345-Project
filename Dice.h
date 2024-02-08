// Author: Julian D'Addario
// Concordia University, 40050146
// Date: Feb 7, 2024

#ifndef DICE_DICE_H
#define DICE_DICE_H

#include <string>
#include "Random.h"

// DieType enum to avoid semantic errors and type safety issues.
enum DieType { d4=4, d6=6, d8=8, d10=10, d12=12, d20=20, d100=100 };

// Roll struct to be used as return type for parsing the dice roll string.
struct Roll {
    DieType dieType;
    int numDice;
    int numAdded;
};

/*
 * Dice class without parameters, only default constructor to save memory
 * by only requiring one object of this class.
 * Dice.roll(rollString) is the main method of the class, and will parse a dice roll string
 * of format xdy[+z] or xdy+z, where (x, y, z) refer to number of dice to roll, type of die to roll, and final addition
 * respectively.
 */
class Dice {
    // Most methods private to avoid manipulation.
private:
    // Internal method used to parse a string into the important parts of a Roll
    Roll parseRoll(std::string str);
    // Internal method to parse a string for the type of dice being used to roll
    DieType parseDie(std::string dieTypeStr, std::string str);
    // Internal method to output error for invalid roll strings.
    static void diceRollStringErr(std::string str);
public:
    // Only default constructor and roll method need to be accessible by driver.
    Dice() = default;
    /*
     * Main rolling function
     * @param is a dice roll string of format xdy[+z] or xdy+z, where (x, y, z) refer to number of dice to roll,
     * type of die to roll, and final addition, respectively.
     * @return random roll of dice specified in parameter string.
     */
    int roll(std::string rollString);
};

#endif //DICE_DICE_H
