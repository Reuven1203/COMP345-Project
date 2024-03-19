//
// Created by z3p on 11/03/24.
//

#include <iostream>
#include "Director/MapDirector/MapDirector.h"
#include "Builder/MapBuilder/DefaultMapBuilder.h"
#include "Character/Fighter.h"

int main() {
    MapDirector director {};
    MapBuilder* testMapBuilder = new DefaultMapBuilder("testsave.csv");

    director.setMapBuilder(testMapBuilder);
    director.constructMap();

    dungeonMap* testmap = director.getMap();
    testmap->printMap();

    Character* player = director.getPlayer();
    player->showCharacterStats();

    delete testMapBuilder;
    delete testmap;
    delete player;
}