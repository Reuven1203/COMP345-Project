//
// Created by z3p on 21/03/24.
//

#include "Helmet.h"

Helmet::Helmet(Item *item, Character *character) :
    intel(item->getINT()), wis(item->getWIS()), ac(item->getAC()), ItemDecorator(character) {
    if(character_->hasHelmet()) {
        std::cerr << "Helmet already equipped. Please remove equipment.";
        std::exit(1);
    }
}

int Helmet::getINT() const {
    return ItemDecorator::getINT() + intel;
}

int Helmet::getWIS() const {
    return ItemDecorator::getWIS() + wis;
}

int Helmet::getAC() const {
    return ItemDecorator::getAC() + ac;
}

bool Helmet::hasHelmet() const {
    return true;
}
