#include <iostream>
#include "Map/map.h"
#include "Character/Fighter.h"
#include "Item/Item.h"
#include "Item/itemContainer.h"

using namespace std;
int main()
{
    
    Character *fighter = new Fighter("Reuven", 6);
    container* chest = new container();
    Item *ring=new Item(Item::ItemType::RING);
    Item *helm=new Item(Item::ItemType::HELMET);
    chest->storeItem(*ring);
    chest->storeItem(*helm);
    chest->getItems();
    
    dungeonMap dungeon(5, 5);
    dungeon.setChest(chest, 3, 2);
    dungeon.setPlayer(fighter, 1, 2);
    dungeon.setStart(1, 2);
    dungeon.setEnd(1, 4);
    dungeon.userInputWalls();
    cout << (dungeon.isValid() ? "Found end" : "End cannot be reached.") << endl;

    dungeon.removeCellContent(1, 2);  ///<Removing player to show that Player is gone from map.
    dungeon.printMap();
    dungeon.setPlayer(fighter, 1, 3); ///<Moving player
    dungeon.printMap();               ///<Showing player has moved and Start point still remains on map
    cout << (dungeon.isValid() ? "Found end" : "End cannot be reached.") << endl; 
    return 0;
}