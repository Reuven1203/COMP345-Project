//
// Created by Reuven Ostrofsky on 2024-01-30.
//


#include <iostream>
#include "Fighter.h"
#include "item.h"


int main() {
     Character* fighter = new Fighter("Reuven", 6);
     fighter->showCharacterStats();
item item1 = item(item::ItemType::ARMOR);

item1.printStats();

    return 0;

}

