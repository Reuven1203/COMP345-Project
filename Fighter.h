//
// Created by Reuven Ostrofsky on 2024-02-07.
//

#ifndef COMP345_A1_FIGHTER_H
#define COMP345_A1_FIGHTER_H
#include "Character.h"
#include "Dice.h"

static const std::string className = "Fighter";
class Fighter: public Character {
    public:
    explicit Fighter(std::string name, int level);
    std::string getClassName() const override;
private:
    DieType getDieType() const override { return d10; }
public:
};


#endif //COMP345_A1_FIGHTER_H
