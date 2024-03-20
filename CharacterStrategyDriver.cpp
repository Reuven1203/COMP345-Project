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
    fighter->setStrategy(new HumanPlayerStrategy());
    m->setPlayer(fighter,1, 2);
    int ch;
    while(true) {
//       fighter->move(*m);
        ch = keyPress();
        std::cout << "Key pressed: " << ch << std::endl;
    }



    return 0;
}
