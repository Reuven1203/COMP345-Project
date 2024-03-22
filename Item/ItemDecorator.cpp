//
// Created by z3p on 21/03/24.
//

#include "ItemDecorator.h"

ItemDecorator::ItemDecorator(Character *character) : character_(character) {
}

int ItemDecorator::getSTR() const {
    return character_->getSTR();
}

int ItemDecorator::getDEX() const {
    return character_->getDEX();
}

int ItemDecorator::getCON() const {
    return character_->getCON();
}

int ItemDecorator::getINT() const {
    return character_->getINT();
}

int ItemDecorator::getWIS() const {
    return character_->getWIS();
}

int ItemDecorator::getCHA() const {
    return character_->getCHA();
}

int ItemDecorator::getATK() const {
    return character_->getATK();
}

int ItemDecorator::getDMG() const {
    return character_->getDMG();
}

void ItemDecorator::showCharacterStats() const {
    character_->showCharacterStats();
}

int ItemDecorator::getAC() const {
    return character_->getAC();
}

bool ItemDecorator::hasWeapon() const {
    return character_->hasWeapon();
}

bool ItemDecorator::hasHelmet() const {
    return character_->hasHelmet();
}

bool ItemDecorator::hasArmor() const {
    return character_->hasArmor();
}

bool ItemDecorator::hasShield() const {
    return character_->hasShield();
}

bool ItemDecorator::hasRing() const {
    return character_->hasRing();
}

bool ItemDecorator::hasBelt() const {
    return character_->hasBelt();
}

bool ItemDecorator::hasBoots() const {
    return character_->hasBoots();
}