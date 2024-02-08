//
// Created by Reuven Ostrofsky on 2024-01-30.
//

#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include "random"



//int randomNumberGenerator(int start, int end) {
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_int_distribution<> dis(start, end);
//    return dis(gen);
//}

class Character {
    struct AbilityScoreTypes {
        int strength;
        int dexterity;
        int constitution;
        int intelligence;
        int wisdom;
        int charisma;
    };
public:
    explicit Character(int level);
    int level;
    AbilityScoreTypes abilityScore;

};


#endif //CHARACTER_H
