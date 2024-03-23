//
// Created by z3p on 12/03/24.
//

#include <iostream>
#include "CampaignEditor/MapEditor.h"
#include "Director/MapDirector/MapDirector.h"
#include "Builder/MapBuilder/DefaultMapBuilder.h"

int main() {
    MapEditor mapEdit = MapEditor();
    mapEdit.createNewMap();
    // get a reference from map in map editor
    dungeonMap* map = mapEdit.getMap();
    MapObserver mapObs = MapObserver(map);
    mapEdit.edit();
    MapDirector director {};
    MapBuilder* testMapBuilder = new DefaultMapBuilder( mapEdit.getFileName() );

    director.setMapBuilder(testMapBuilder);
    director.constructMap();

    dungeonMap* testmap = director.getMap();
    testmap->printMap();

    delete testmap;
    delete testMapBuilder;
}