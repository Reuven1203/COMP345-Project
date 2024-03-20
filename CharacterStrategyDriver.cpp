//
// Created by Reuven Ostrofsky on 2024-03-19.
//

#include <iostream>
#include "./Strategy/CharacterStrategy/CharacterStrategy.h"
#include "./Map/map.h"
#include "./Observer/MapObserver/MapObserver.h"
#include "./Strategy/CharacterStrategy/HumanPlayerStrategy/HumanPlayerStrategy.h"
#include "Director/FighterDirector/FighterDirector.h"
#include "./Builder/FighterBuilder/BullyFighterBuilder/BullyFighterBuilder.h"
#include "./Utils/utils.h"



int main() {
    auto* m = new dungeonMap(10, 10); //5x5 map
    auto* control = new MapObserver(m);
    m->attach(control);
    FighterDirector director{};
    BullyFighterBuilder builder;
    director.setBuilder(&builder);
    Fighter* fighter = director.constructFighter("Bully");
    Fighter* fighter2 = director.constructFighter("Bully");
    fighter->setStrategy(new HumanPlayerStrategy());
    m->setStart(1, 2);
    m->setPlayer(fighter,1, 2);
    m->setPlayer(fighter2, 4, 4);
    m->setWall(0, 8);
    auto* chest1 = new container();
    auto* chest2 = new container();
    Item* ring = new Item(Item::ItemType::RING);
    Item* helmet = new Item(Item::ItemType::HELMET);
    chest1->storeItem(*ring);
    chest2->storeItem(*helmet);
    m->setChest(chest1,3,3);
    m->setChest(chest2, 8, 8);
    m->notify();
    int ch = 0;
    while(true) {
       fighter->move(*m);
    }



    return 0;
}
