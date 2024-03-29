/**
 * @file Armor.cpp
 * @brief Implements Armor class methods
 * @author Julian D'Addario
 */

#include "Armor.h"

Armor::Armor(Item *item, Character *character) :
    ac(item->getAC()), ItemDecorator(character) {
    // Don't let equip happen if character already has armor
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