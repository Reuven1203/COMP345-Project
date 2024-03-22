//
// Created by z3p on 21/03/24.
//

#include "Ring.h"

Ring::Ring(Item *item, Character *character) :
    ac(item->getAC()), str(item->getSTR()), con(item->getCON()), wis(item->getWIS()), cha(item->getCHA()),
    ItemDecorator(character) {
    if(character_->hasRing()) {
        std::cerr << "Ring already equipped. Please remove equipment.";
        std::exit(1);
    }
}

int Ring::getAC() const {
    return ItemDecorator::getAC() + ac;
}

int Ring::getSTR() const {
    return ItemDecorator::getSTR() + str;
}

int Ring::getCON() const {
    return ItemDecorator::getCON() + con;
}

int Ring::getWIS() const {
    return ItemDecorator::getWIS() + wis;
}

int Ring::getCHA() const {
    return ItemDecorator::getCHA() + cha;
}

bool Ring::hasRing() const {
    return true;
}

