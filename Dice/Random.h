// Author: Julian D'Addario
// Concordia University, 40050146
// Date: Feb 7, 2024

#ifndef DICE_RANDOM_H
#define DICE_RANDOM_H

#include <random>
#include <chrono>

/*
 * Creating global Random to avoid reusing random generators.
 */
namespace Random {
    // Declaring Mersenne Twister generator and seeding with steady_clock to avoid local system time manipulation.
    inline std::mt19937 mt_random { static_cast<std::mt19937::result_type>(
            std::chrono::steady_clock::now().time_since_epoch().count()
            )};
    // Function to generate random integer from min to max, inclusive.
    inline int random(int min, int max) {
        return std::uniform_int_distribution{min, max}(mt_random);
    }
} // Random

#endif //DICE_RANDOM_H
