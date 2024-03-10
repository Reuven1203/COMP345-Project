//
// Created by Reuven Ostrofsky on 2024-02-07.
//

#include "Fighter.h"

#include <utility>
#include "../Dice/Dice.h"


Fighter::Fighter(std::string name, int level) : Character(std::move(name), level) {
}

std::string Fighter::getClassName() const {
    return "Fighter";
}














