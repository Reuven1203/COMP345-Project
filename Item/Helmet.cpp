/**
 * @file Armor.cpp
 * @brief Implements Armor class methods
 * @author Julian D'Addario
 */

#include "Helmet.h"

Helmet::Helmet(Item *item, Character *character) :
    intel(item->getINT()), wis(item->getWIS()), ac(item->getAC()), ItemDecorator(character) {
    // Don't let equip happen if character already has helmet
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
