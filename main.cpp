//
// Created by Reuven Ostrofsky on 2024-01-30.
//


#include <iostream>
#include "Fighter.h"
#include "Item.h"


int main() {
     Character* fighter = new Fighter("Reuven", 6);
     std::cout << "Fighter's stats before equipment: " << std::endl;
//     fighter->showCharacterStats();
     Item item1 = Item(Item::ItemType::ARMOR);
     Item item2 = Item(Item::ItemType::WEAPON);
     Item item3 = Item(Item::ItemType::SHIELD);


     fighter->equip(item1);
        fighter->equip(item2);
        fighter->equip(item3);
        fighter->showWornItems();

//        std::cout << "\n\nFighter's stats after equipment: " << std::endl;
//        fighter->showCharacterStats();

        fighter->unequip(item1);

        fighter->showWornItems();


    return 0;

}

