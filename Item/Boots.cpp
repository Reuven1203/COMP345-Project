/**
 * @file Boots.cpp
 * @brief Implements Boots class methods
 * @author Julian D'Addario
 */

#include "Boots.h"

Boots::Boots(Item *item, Character *character) :
    ac(item->getAC()), dex(item->getDEX()), ItemDecorator(character) {
    // Don't let equip happen if character already has boots
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

