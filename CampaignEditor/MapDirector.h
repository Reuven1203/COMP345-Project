//
// Created by z3p on 11/03/24.
//

#ifndef COMP345_A1_MAPDIRECTOR_H
#define COMP345_A1_MAPDIRECTOR_H

#include "MapBuilder.h"

class MapDirector {
public:
    void setMapBuilder(MapBuilder* mb) { mapBuilder = mb; }
    dungeonMap* getMap() { return mapBuilder->getMap(); }
    Character* getPlayer() { return mapBuilder->getPlayer(); }
    void constructMap() {
        mapBuilder -> createNewMap();
        mapBuilder -> buildMapSize();
        mapBuilder -> buildStartEnd();
        mapBuilder -> buildWalls();
        mapBuilder -> buildPlayer();
    }
private:
    MapBuilder* mapBuilder;
    Character* player;
};


#endif //COMP345_A1_MAPDIRECTOR_H
