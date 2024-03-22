/**
 * @file Belt.cpp
 * @brief Implements Belt class methods
 * @author Julian D'Addario
 */

#include "Belt.h"

Belt::Belt(Item *item, Character *character) :
    con(item->getCON()), str(item->getSTR()), ItemDecorator(character) {
    // Don't let equip happen if character already has belt
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
