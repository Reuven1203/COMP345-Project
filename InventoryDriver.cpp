/*
* Author: Richard Mauricio
*/
#include <iostream>
#include "./Map/map.h"
#include "./Character/Fighter.h"
#include "./Dice/Dice.h"
#include "Observer/MapObserver/MapObserver.h"
#include "Director/FighterDirector/FighterDirector.h"
#include "./Strategy/CharacterStrategy/HumanPlayerStrategy/HumanPlayerStrategy.h"
#include "./Strategy/CharacterStrategy/AggressorStrategy/AggressorStrategy.h"
#include "./Strategy/CharacterStrategy/FriendlyStrategy/FriendlyStrategy.h"
#include "Builder/FighterBuilder/BullyFighterBuilder/BullyFighterBuilder.h"
#include "./Observer/GameObserver/GameObserver.h"
#include "CharacterCreator/CharacterCreatorUI.h"
#include "./Utils/utils.h"
using namespace std;

int main()
{
   /* CharacterCreatorUI characterCreatorUI{
    };
    characterCreatorUI.run();*/
    auto* logger = new GameObserver();
    auto* m = new dungeonMap(10, 10);
    logger->attachObservable(m);
    m->notifyMapCreated();
    auto* control = new MapObserver(m);
    m->attach(control);
    Dice::GetGlobal().attach(logger);
    FighterDirector director{};
    BullyFighterBuilder builder;
    director.setBuilder(&builder);

    Fighter* fighter = director.constructFighter("Bully");
    fighter->setStrategy(new HumanPlayerStrategy());
    m->setUserPlayer(fighter);
    auto* chest1 = new container();
    auto* chest2 = new container();
    Item* ring = new Item(Item::ItemType::RING);
    Item* ring2 = new Item(Item::ItemType::RING);
    Item* helmet = new Item(Item::ItemType::HELMET);
    Item* weapon = new Item(Item::ItemType::WEAPON);
  
    fighter->getStrategy()->attach(logger);
    chest1->storeItem(*ring);
    chest2->storeItem(*helmet);
    chest2->storeItem(*weapon);
    chest2->storeItem(*ring2);
    m->setStart(1, 2);
    m->setPlayer(fighter, m->getStartX(), m->getStartY());
    m->setEnd(4, 4);
    m->setChest(chest1, 3, 3);
    m->setChest(chest2, 0, 0);
    m->setWall(5, 2);
    m->setWall(9, 3);
    m->setWall(4, 2);
    fighter->move(*m);

	return 0;
}