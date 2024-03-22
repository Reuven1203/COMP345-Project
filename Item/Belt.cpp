//
// Created by z3p on 21/03/24.
//

#include "Belt.h"

Belt::Belt(Item *item, Character *character) :
    con(item->getCON()), str(item->getSTR()), ItemDecorator(character) {
    if(character_->hasBelt()) {
        std::cerr << "Belt already equipped. Please remove equipment.";
        std::exit(1);
    }
}

int Belt::getCON() const {
    return ItemDecorator::getCON() + con;
}

int Belt::getSTR() const {
    return ItemDecorator::getSTR() + str;
}

bool Belt::hasBelt() const {
    return true;
}
