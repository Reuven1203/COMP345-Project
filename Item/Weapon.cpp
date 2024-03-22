//
// Created by z3p on 21/03/24.
//

#include "Weapon.h"

Weapon::Weapon(Item* item, Character* character) :
    atk(item->getATKBONUS()), dmg(item->getDMGBonus()), ItemDecorator(character) {
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
