/**
 * @author Julian D'Addario
 */

#ifndef COMP345_A1_MAPEDITOR_H
#define COMP345_A1_MAPEDITOR_H

#include "../Map/map.h"
#include "../Observer/MapObserver/MapObserver.h"
#include "../Director/MapDirector/MapDirector.h"
#include "../Builder/MapBuilder/MapBuilder.h"
#include "../Builder/MapBuilder/DefaultMapBuilder.h"
#include <fstream>
#include <iostream>

class MapEditor {
public:
    MapEditor();
    void run();
    void createNewMap();
    void setMap(dungeonMap m);
    std::string getFileName();
    void edit();
    dungeonMap* getMap();
    MapObserver observer;
private:
    dungeonMap map {};
    std::string fileName {};
    int getUserInput();
    void setStart();
    void setEnd();
    void setWalls();
    void loadMap();
    void saveMap();
    void save(std::string filename);
};


#endif //COMP345_A1_MAPEDITOR_H
