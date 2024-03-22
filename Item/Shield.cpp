//
// Created by z3p on 21/03/24.
//

#include "Shield.h"

Shield::Shield(Item *item, Character *character) :
    ac(item->getAC()), ItemDecorator(character) {
    if(character_->hasShield()) {
        std::cerr << "Shield already equipped. Please remove equipment.";
        std::exit(1);
    }
}

int Shield::getAC() const {
    return ItemDecorator::getAC() + ac;
}

bool Shield::hasShield() const {
    return true;
}

