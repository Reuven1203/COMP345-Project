/**
 * @file Weapon.cpp
 * @brief Implements Weapon class methods
 * @author Julian D'Addario
 */

#include "Weapon.h"

Weapon::Weapon(Item* item, Character* character) :
    atk(item->getATKBONUS()), dmg(item->getDMGBonus()), ItemDecorator(character) {
    // Don't let equip happen if character already has weapon
    if(character_->hasWeapon()) {
        std::cerr << "Weapon already equipped. Please remove equipment.";
        std::exit(1);
    }
}

int Weapon::getATK() const {
    return ItemDecorator::getATK() + atk;
}

int Weapon::getDMG() const {
    return ItemDecorator::getDMG() + dmg;
}

bool Weapon::hasWeapon() const {
    return true;
}
