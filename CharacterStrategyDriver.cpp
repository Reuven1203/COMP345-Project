//
// Created by Reuven Ostrofsky on 2024-03-19.
//

#include <iostream>
#include "./Strategy/CharacterStrategy/CharacterStrategy.h"
#include "./Map/map.h"
#include "./Observer/MapObserver/MapObserver.h"
#include "./Strategy/CharacterStrategy/HumanPlayerStrategy/HumanPlayerStrategy.h"
#include "./Strategy/CharacterStrategy/AggressorStrategy/AggressorStrategy.h"
#include "./Strategy/CharacterStrategy/FriendlyStrategy/FriendlyStrategy.h"
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
    m->setUserPlayer(fighter);
    Fighter* fighter2 = director.constructFighter("Bully 2");
    Fighter* fighter3 = director.constructFighter("Bully 3");
    Item sword =  Item(Item::ItemType::RING);
    fighter->setStrategy(new HumanPlayerStrategy());
    fighter2->setStrategy(new AggressorStrategy());
    fighter3->setStrategy(new FriendlyStrategy());
    fighter3->storeItem(sword);
    m->setStart(1, 2);
    m->setPlayer(fighter,m->getStartX(), m->getStartY());
    m->setPlayer(fighter2, 4, 4);
    m->setPlayer(fighter3, 5, 5);
    m->setWall(4, 3);
    m->setWall(5, 3);
    m->setWall(5, 4);
    auto* chest1 = new container();
    auto* chest2 = new container();
    Item* ring = new Item(Item::ItemType::RING);
    Item* helmet = new Item(Item::ItemType::HELMET);
    chest1->storeItem(*ring);
    chest2->storeItem(*helmet);
    m->setChest(chest1,3,3);
    m->setChest(chest2, 8, 8);
    m->notify();
    while(true){
        fighter->move(*m);
        fighter2->move(*m);
//        fighter3->move(*m);
    }





    return 0;
}
