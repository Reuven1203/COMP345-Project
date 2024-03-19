//
// Created by Reuven Ostrofsky on 2024-03-19.
//

#include "Builder/FighterBuilder/FighterBuilder.h"
#include "Builder/FighterBuilder/BullyFighterBuilder/BullyFighterBuilder.h"
#include "Director/FighterDirector/FighterDirector.h"
#include "Builder/FighterBuilder/NimbleFighterBuilder/NimbleFighterBuilder.h"
#include "Builder/FighterBuilder/TankFighterBuilder/TankFighterBuilder.h"
#include "./Observer/CharacterObserver/FighterObserver.h"

int main() {
    FighterDirector director{};
    BullyFighterBuilder builder;
    director.setBuilder(&builder);
    Fighter* bullyFighter = director.constructFighter("Bully");

    //Observe bully fighter
    FighterObserver bullyObserver( bullyFighter);
    bullyFighter->attach(&bullyObserver);
    bullyFighter->notify();
    bullyFighter->detach(&bullyObserver);


    std::cout << "-------------------\n-------------------\n" << std::endl;


    NimbleFighterBuilder nimbleBuilder;
    director.setBuilder(&nimbleBuilder);
    Fighter* nimbleFighter = director.constructFighter();

    //Observe nimble fighter
    FighterObserver ninbleObserver(nimbleFighter);
    nimbleFighter->attach(&ninbleObserver);
    nimbleFighter->notify();
    nimbleFighter->detach(&ninbleObserver);
    std::cout << "-------------------\n-------------------\n" << std::endl;


    TankFighterBuilder tankBuilder;
    director.setBuilder(&tankBuilder);
    Fighter* tankFighter = director.constructFighter();

    //Observe tank fighter
    FighterObserver tankObserver(tankFighter);
    tankFighter->attach(&tankObserver);
    tankFighter->notify();
    tankFighter->detach(&tankObserver);


    return 0;


}
