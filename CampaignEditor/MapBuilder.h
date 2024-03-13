/**
 * @author Julian D'Addario
 */

#include "../Map/map.h"
#include "../Character/Character.h"

#ifndef COMP345_A1_MAPBUILDER_H
#define COMP345_A1_MAPBUILDER_H

struct MapInfo {
    std::vector<int> mapSize; // size {rows, col} of map
    std::vector<int> startPos; // location (x, y) of start
    std::vector<int> endPos; // location (x, y) of end
    std::vector<int> wallPos; // location [x1, y1, x2, y2, ..., xn, yn] of walls
    Character* player;
    std::vector<int> playerPos;
};

class MapBuilder {
public:
    virtual ~MapBuilder() = default;
    dungeonMap* getMap() { return map; }
    Character* getPlayer() { return player; }
    MapInfo getMapInfo(std::string fileName);
    void createNewMap() { map = new dungeonMap(); }
    virtual void buildMapSize() = 0;
    virtual void buildStartEnd() = 0;
    virtual void buildWalls() = 0;
    virtual void buildPlayer() = 0;
protected:
    dungeonMap* map;
    Character* player = nullptr;
};


#endif //COMP345_A1_MAPBUILDER_H
