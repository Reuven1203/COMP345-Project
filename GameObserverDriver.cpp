#include <iostream>
#include "./Map/map.h"
#include "./Character/Fighter.h"
#include "Observer/MapObserver/MapObserver.h"
#include "Director/FighterDirector/FighterDirector.h"
#include "./Strategy/CharacterStrategy/HumanPlayerStrategy/HumanPlayerStrategy.h"
#include "./Strategy/CharacterStrategy/AggressorStrategy/AggressorStrategy.h"
#include "./Strategy/CharacterStrategy/FriendlyStrategy/FriendlyStrategy.h"
#include "Builder/FighterBuilder/BullyFighterBuilder/BullyFighterBuilder.h"
#include "../Observer/GameObserver/GameObserver.h"
#include "./Utils/utils.h"
using namespace std;
int main()
{



    auto* logger = new GameObserver();
    auto* m = new dungeonMap(10, 10); 
    logger->attachObservable(m);
    auto* control = new MapObserver(m);
    m->attach(control);
    
    FighterDirector director{};
    BullyFighterBuilder builder;
    director.setBuilder(&builder);
    Fighter* fighter = director.constructFighter("Bully");
    Fighter* fighter2 = director.constructFighter("Bully 2");
    Fighter* fighter3 = director.constructFighter("Bully 3");
    fighter2->setStrategy(new AggressorStrategy());
    fighter3->setStrategy(new FriendlyStrategy());
    fighter->setStrategy(new HumanPlayerStrategy());
    m->setPlayer(fighter2, 1, 4);
    m->setPlayer(fighter3, 5, 5);
    m->setUserPlayer(fighter);
    auto* chest1 = new container();
    auto* chest2 = new container();
    Item* ring = new Item(Item::ItemType::RING,logger);
    Item* helmet = new Item(Item::ItemType::HELMET,logger);
    fighter->getStrategy()->attach(logger);
    fighter2->getStrategy()->attach(logger);

    fighter3->getStrategy()->attach(logger);


    //Showcasing detaching from logger does not log the helmet stat change
    logger->detachObservable(helmet);
    helmet->notifyGameObserver(EventData(EventData::EventType::ItemStatRolled, "Helmet", "Wisdom", 2));
    
    chest1->storeItem(*ring);
    chest2->storeItem(*helmet);
    m->setStart(1, 2);
    m->setPlayer(fighter, m->getStartX(), m->getStartY());
    m->setEnd(4, 4);
    m->setChest(chest1, 3, 3);
    m->setChest(chest2, 0, 0);
    m->setWall(5, 2);
    m->setWall(9, 3);
    m->setWall(4, 2);
    m->removeWall(9, 3);
    m->notify();
    fighter->move(*m);
    fighter2->move(*m);
    fighter3->move(*m);
    fighter3->attack(fighter);
    return 0;
}