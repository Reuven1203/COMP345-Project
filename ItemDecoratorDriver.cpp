//
// Created by z3p on 21/03/24.
//

#include "Character/Fighter.h"
#include "Character/Character.h"
#include "Builder/FighterBuilder/BullyFighterBuilder/BullyFighterBuilder.h"
#include "Director/FighterDirector/FighterDirector.h"
#include "Item/ItemDecorator.h"
#include "Item/Weapon.h"
#include "Item/Helmet.h"
#include "Item/Armor.h"
#include "Item/Shield.h"
#include "Item/Ring.h"
#include "Item/Belt.h"
#include "Item/Boots.h"
#include "Item/UnequipItem.h"

int main() {
    FighterDirector director{};
    BullyFighterBuilder builder;
    director.setBuilder(&builder);
    Fighter* bullyFighter = director.constructFighter("Bully");

    Item* weapon = new Item(Item::ItemType::WEAPON);
    Character* fighter2 = new Weapon(weapon, bullyFighter);

    Item* helmet = new Item(Item::ItemType::HELMET);
    Character* fighter3 = new Helmet(helmet, fighter2);
 
    Item* armor = new Item(Item::ItemType::ARMOR);
    Character* fighter4 = new Armor(armor, fighter3);

    Item* shield = new Item(Item::ItemType::SHIELD);
    Character* fighter5 = new Shield(shield, fighter4);

    Item* ring = new Item(Item::ItemType::RING);
    Character* fighter6 = new Ring(ring, fighter5);

    Item* belt = new Item(Item::ItemType::BELT);
    Character* fighter7 = new Belt(belt, fighter6);

    Item* boots = new Item(Item::ItemType::BOOTS);
    Character* fighter8 = new Boots(boots, fighter7);

    Character* unequipped1 = new UnequipItem(weapon, fighter8);
    Character* unequipped2 = new UnequipItem(helmet, unequipped1);
    Character* unequipped3 = new UnequipItem(armor, unequipped2);
    Character* unequipped4 = new UnequipItem(shield, unequipped3);
    Character* unequipped5 = new UnequipItem(ring, unequipped4);
    Character* unequipped6 = new UnequipItem(belt, unequipped5);
    Character* unequipped7 = new UnequipItem(boots, unequipped6);

    fighter8->showCharacterStats();
    std::cout << "Atk Before: " << bullyFighter->getATK() << std::endl;
    std::cout << "Weapon Atk: " << weapon->getATKBONUS() << std::endl;
    std::cout << "Atk After Weapon: " << fighter2->getATK() << std::endl;

    std::cout << std::endl;

    std::cout << "Int Before: " << bullyFighter->getINT() << std::endl;
    std::cout << "Helmet Int: " << helmet->getINT() << std::endl;
    std::cout << "Int after Helmet: " << fighter3->getINT() << std::endl;

    std::cout << std::endl;

    std::cout << "AC Before: " << bullyFighter->getAC() << std::endl;
    std::cout << "AC After Helmet: " << fighter3->getAC() << std::endl;
    std::cout << "AC After Armor: " << fighter4 ->getAC() << std::endl;

    std::cout << std::endl;

    std::cout << "BEFORE" << std::endl;
    std::cout << "STR: " << bullyFighter->getSTR() << std::endl;
    std::cout << "DEX: " << bullyFighter->getDEX() << std::endl;
    std::cout << "CON: " << bullyFighter->getCON() << std::endl;
    std::cout << "INT: " << bullyFighter->getINT() << std::endl;
    std::cout << "WIS: " << bullyFighter->getWIS() << std::endl;
    std::cout << "CHA: " << bullyFighter->getCHA() << std::endl;
    std::cout << "ATK: " << bullyFighter->getATK() << std::endl;
    std::cout << "DMG: " << bullyFighter->getDMG() << std::endl;
    std::cout << "AC: " << bullyFighter->getAC() << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << "AFTER EQUIP" << std::endl;
    std::cout << "STR: " << fighter8->getSTR() << std::endl;
    std::cout << "DEX: " << fighter8->getDEX() << std::endl;
    std::cout << "CON: " << fighter8->getCON() << std::endl;
    std::cout << "INT: " << fighter8->getINT() << std::endl;
    std::cout << "WIS: " << fighter8->getWIS() << std::endl;
    std::cout << "CHA: " << fighter8->getCHA() << std::endl;
    std::cout << "ATK: " << fighter8->getATK() << std::endl;
    std::cout << "DMG: " << fighter8->getDMG() << std::endl;
    std::cout << "AC: " << fighter8->getAC() << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << "AFTER UNEQUIP" << std::endl;
    std::cout << "STR: " << unequipped7->getSTR() << std::endl;
    std::cout << "DEX: " << unequipped7->getDEX() << std::endl;
    std::cout << "CON: " << unequipped7->getCON() << std::endl;
    std::cout << "INT: " << unequipped7->getINT() << std::endl;
    std::cout << "WIS: " << unequipped7->getWIS() << std::endl;
    std::cout << "CHA: " << unequipped7->getCHA() << std::endl;
    std::cout << "ATK: " << unequipped7->getATK() << std::endl;
    std::cout << "DMG: " << unequipped7->getDMG() << std::endl;
    std::cout << "AC: " << unequipped7->getAC() << std::endl;
}