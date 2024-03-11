#include <iostream>
#include "./Map/map.h"
#include "./Character/Fighter.h"
#include "./Item/Item.h"
#include "./Item/itemContainer.h"
#include "Observer/MapObserver/MapObserver.h"
#include "./Utils//utils.h"

using namespace std;
int main()
{
    auto* m = new dungeonMap(10, 10); //5x5 map
    auto* control = new MapObserver(m);
    Character* fighter = new Fighter("Reuven", 6);
    auto* chest1 = new container();
    auto* chest2 = new container();
    Item* ring = new Item(Item::ItemType::RING);
    Item* helmet = new Item(Item::ItemType::HELMET);
    chest1->storeItem(*ring);
    chest2->storeItem(*helmet);
    m->setStart(1, 2);
    m->setPlayer(fighter,1, 2);
    m->setEnd(4, 4);
    m->setChest(chest1,3,3);
    m->setChest(chest2, 0, 0);
    m->userInputWalls();
    control->moveCharacter();
   
   
 /*   
    
    
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
    cout << (dungeon.isValid() ? "Found end" : "End cannot be reached.") << endl; */
    return 0;
}