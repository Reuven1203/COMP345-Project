#include <iostream>
#include "./Map/map.h"
#include "./Character/Fighter.h"
#include "Observer/MapObserver/MapObserver.h"
#include "Director/FighterDirector/FighterDirector.h"
#include "Builder/FighterBuilder/BullyFighterBuilder/BullyFighterBuilder.h"

using namespace std;
int main()
{

//    while (true) {
//        int ch = keyPress();
//    }

    auto* m = new dungeonMap(10, 10); //5x5 map
    auto* control = new MapObserver(m);
    FighterDirector director{};
    BullyFighterBuilder builder;
    director.setBuilder(&builder);
    Fighter* fighter = director.constructFighter("Bully");
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
    
    return 0;
}