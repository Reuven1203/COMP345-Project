/**
 * @file UnequippedItem.cpp
 * @brief Implements UnequippedItem class methods
 * @author Julian D'Addario
 */

#include "UnequipItem.h"

UnequipItem::UnequipItem(Item *item, Character *character) :
    intel(item->getINT()), wis(item->getWIS()), ac(item->getAC()), str(item->getSTR()), con(item->getCON()),
    cha(item->getCHA()), dex(item->getDEX()), atk(item->getATKBONUS()), dmg(item->getDMGBonus()),
    itemType(item->equipType), ItemDecorator(character)
{
    // Based on itemType, don't allow unequip to happen if character does not have an item of that
    // ItemType equipped already.
    switch(itemType) {
        case Item::HELMET:
            if(!character_->hasHelmet()) {
                std::cerr << "No helmet on character. Please add equipment.";
                std::exit(1);
            }
            break;
        case Item::ARMOR:
            if(!character_->hasArmor()) {
                std::cerr << "No armor on character. Please add equipment.";
                std::exit(1);
            }
            break;
        case Item::SHIELD:
            if(!character_->hasShield()) {
                std::cerr << "No shield on character. Please add equipment.";
                std::exit(1);
            }
            break;
        case Item::RING:
            if(!character_->hasRing()) {
                std::cerr << "No ring on character. Please add equipment.";
                std::exit(1);
            }
            break;
        case Item::BELT:
            if(!character_->hasBelt()) {
                std::cerr << "No belt on character. Please add equipment.";
                std::exit(1);
            }
            break;
        case Item::BOOTS:
            if(!character_->hasBoots()) {
                std::cerr << "No boots on character. Please add equipment.";
                std::exit(1);
            }
            break;
        case Item::WEAPON:
            if(!character_->hasWeapon()) {
                std::cerr << "No weapon on character. Please add equipment.";
                std::exit(1);
            }
            break;
    }
}

int UnequipItem::getSTR() const {
    return ItemDecorator::getSTR() - str;
}

int UnequipItem::getDEX() const {
    return ItemDecorator::getDEX() - dex;
}

int UnequipItem::getCON() const {
    return ItemDecorator::getCON() - con;
}

int UnequipItem::getINT() const {
    return ItemDecorator::getINT() - intel;
}

int UnequipItem::getWIS() const {
    return ItemDecorator::getWIS() - wis;
}

int UnequipItem::getCHA() const {
    return ItemDecorator::getCHA() - cha;
}

int UnequipItem::getATK() const {
    return ItemDecorator::getATK() - atk;
}

int UnequipItem::getDMG() const {
    return ItemDecorator::getDMG() - dmg;
}

int UnequipItem::getAC() const {
    return ItemDecorator::getAC() - ac;
}

bool UnequipItem::hasWeapon() const {
    if(itemType == Item::ItemType::WEAPON)
        return false;
    else
        return ItemDecorator::hasWeapon();
}

bool UnequipItem::hasHelmet() const {
    if(itemType == Item::ItemType::HELMET)
        return false;
    else
        return ItemDecorator::hasHelmet();
}

bool UnequipItem::hasArmor() const {
    if(itemType == Item::ItemType::ARMOR)
        return false;
    else
        return ItemDecorator::hasArmor();
}

bool UnequipItem::hasShield() const {
    if(itemType == Item::ItemType::SHIELD)
        return false;
    else
        return ItemDecorator::hasShield();
}

bool UnequipItem::hasRing() const {
    if(itemType == Item::ItemType::RING)
        return false;
    else
        return ItemDecorator::hasRing();
}

bool UnequipItem::hasBelt() const {
    if(itemType == Item::ItemType::BELT)
        return false;
    else
        return ItemDecorator::hasBelt();
}

bool UnequipItem::hasBoots() const {
    if(itemType == Item::ItemType::BOOTS)
        return false;
    else
        return ItemDecorator::hasBoots();
}

