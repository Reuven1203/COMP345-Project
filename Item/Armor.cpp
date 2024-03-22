//
// Created by z3p on 21/03/24.
//

#include "Armor.h"

Armor::Armor(Item *item, Character *character) :
    ac(item->getAC()), ItemDecorator(character) {
    if(character_->hasArmor()) {
        std::cerr << "Armor already equipped. Please remove equipment.";
        std::exit(1);
    }
}

int Armor::getAC() const {
    return ItemDecorator::getAC() + ac;
}

bool Armor::hasArmor() const {
    return true;
}