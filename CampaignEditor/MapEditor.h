//
// Created by z3p on 12/03/24.
//

#ifndef COMP345_A1_MAPEDITOR_H
#define COMP345_A1_MAPEDITOR_H

#include "../Map/map.h"
#include "../Observer/MapObserver/MapObserver.h"
#include "MapDirector.h"
#include "MapBuilder.h"
#include "DefaultMapBuilder.h"
#include <fstream>
#include <iostream>

class MapEditor {
public:
    MapEditor();
    void run();
    void createNewMap();
    std::string getFileName();
    dungeonMap getMap();
private:
    dungeonMap map {};
    std::string fileName {};
    int getUserInput();
    void setStart();
    void setEnd();
    void setWalls();
    void saveMap();
    void loadMap();
    void save(std::string filename);
};


#endif //COMP345_A1_MAPEDITOR_H
