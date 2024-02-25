/**
 * @file Dice.cpp
 * @brief Implementation of the Dice class methods.
 * @author Julian D'Addario
 * @date Feb 7, 2024
 */

#include <iostream>
#include "Dice.h"
#include "Random.h"

/*
 * Output error string
 *
 * @param roll string that caused the error
 */
void Dice::diceRollStringErr(const std:: string& str) {
    throw std::invalid_argument("Error, invalid dice rolling string: " + str);
}
/*
 * Parses string to use the correct type of die
 *
 * @param dieTypeStr to be parsed
 * @param roll str to be passed to error method if error found
 * @return proper DieType according to parameter,
 * or error and exit if dieTypeStr does not match any valid types of dice.
 */
DieType Dice::parseDie(std::string dieTypeStr, std::string str) {
    int dNum {};
    // Attempt to convert string to int, error if invalid
    try {
        dNum = stoi(dieTypeStr);
    } catch(std::invalid_argument &e) {
        diceRollStringErr(str);
    }
    // Switch to choose which DieType to return, giving error if the dNum does not match any valid types of dice.
    switch(dNum) {
        case 4: return d4;
        case 6: return d6;
        case 8: return d8;
        case 10: return d10;
        case 12: return d12;
        case 20: return d20;
        case 100: return d100;
        default: diceRollStringErr(str);
    }
}

/*
 * Parses roll string into Roll struct to be easily used by Dice::roll() method, handles errors in input string.
 *
 * @param dice roll string to be parsed
 * @return Roll struct consisting of int of dice to roll, DieType of type of die to roll, and int added to roll.
 */
Roll Dice::parseRoll(std::string str) {
    // Initialize part of the string being parsed to 1 and numDice/die to empty strings.
    int part {1};
    bool plus = false;
    std::string numDice {};
    std::string die {};
    // numAdded initialized to '0' as no 'z' in roll string xdy[+z] means adding 0 to dice roll.
    std::string numAdded {'0'};

    // Loops through string indices, changing parts when 'd' or '+' are found
    // and appending found digits to end of their respective strings.
    for (int i {0}; i <= str.length(); i++) {
        if (str[i] == 'd') {
            part = 2;
            continue;
        }
        else if (str[i] == '+') {
            if (plus && !checkIfNumber(str[i])) {
                diceRollStringErr(str);
            }
            plus = true;
            part = 3;
            continue;
        }

        if (part == 1 && str[i] >= '0' && str[i] <= '9') {
            numDice += str[i];
        }
        else if (part == 2 && str[i] >= '0' && str[i] <= '9') {
            die += str[i];
        }
        else if (part == 3 && str[i] >= '0' && str[i] <= '9') {
            numAdded += str[i];
        }else if (i == str.length()) {
            break;
        }
    }

    // Calls Dice::parseDie method to convert die string to a DieType
    DieType dieType {parseDie(die, str)};

    // Attempt to convert string for roll to ints, handling errors.
    try {
        return Roll{dieType, stoi(numDice), stoi(numAdded)};
    } catch(std::invalid_argument &e) {
        diceRollStringErr(str);
    }
}

/*
 * Rolls dice according to rollString using Random::random() Mersenne Twister PRNG.
 *
 * @param rollString in format xdy[+z} or xdy+z which specifies how many times to roll which type of die, and
 * final addition.
 * @return sum of dice rolled randomly according to param rollString
 */
int Dice::roll(std::string rollString) {
    // Calls Dice::parseRoll to parse string into a roll usable with Random::random()
    Roll roll_guide {Dice::parseRoll(rollString)};

    // Initialize total to 0
    int total {0};

    // Iterates number of times equal to the number of dice to roll (x).
    for (int i {0}; i < roll_guide.numDice; i++) {
        // Each individual roll is rolled randomly between 1 and the max for the DieType (y)
        // (ex: d4 max (y) = 4, d100 max (y) = 100), and adds each roll to total
        total += Random::random(1, roll_guide.dieType);
    }

    // Add z to rolled total
    total += roll_guide.numAdded;

    // Return final total
    return total;
}

bool Dice::checkIfNumber(char str){
    return str >= '0' && str <= '9';
};