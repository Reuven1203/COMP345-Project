/**
 * @file Shield.cpp
 * @brief Implements Shield class methods
 * @author Julian D'Addario
 */

#include "Shield.h"

Shield::Shield(Item *item, Character *character) :
    ac(item->getAC()), ItemDecorator(character) {
    // Don't let equip happen if character already has shield
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

