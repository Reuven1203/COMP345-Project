//
// Created by z3p on 21/03/24.
//

#include "Boots.h"

Boots::Boots(Item *item, Character *character) :
    ac(item->getAC()), dex(item->getDEX()), ItemDecorator(character) {
    if(character_->hasBoots()) {
        std::cerr << "Boots already equipped. Please remove equipment.";
        std::exit(1);
    }
}

int Boots::getAC() const {
    return ItemDecorator::getAC() + ac;
}

int Boots::getDEX() const {
    return ItemDecorator::getDEX() + dex;
}

bool Boots::hasBoots() const {
    return true;
}

