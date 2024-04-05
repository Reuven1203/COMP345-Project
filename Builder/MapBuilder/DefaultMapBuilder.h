/**
 * @author Julian D'Addario
 */

#ifndef COMP345_A1_DEFAULTMAPBUILDER_H
#define COMP345_A1_DEFAULTMAPBUILDER_H

#include "MapBuilder.h"

class DefaultMapBuilder : public MapBuilder {
public:
    DefaultMapBuilder(std::string filename) { mapInfo = getMapInfo(filename); };

    void buildMapSize() override {
        map = new dungeonMap(mapInfo.mapSize[0], mapInfo.mapSize[1]);
    }
    void buildStartEnd() override {
        map->setStart(mapInfo.startPos[0], mapInfo.startPos[1]);
        map->setEnd(mapInfo.endPos[0], mapInfo.endPos[1]);
    };
    void buildWalls() override {
        for (int i {0}; i < mapInfo.wallPos.size(); i+=2) {
            map->setWall(mapInfo.wallPos[i], mapInfo.wallPos[i+1]);
        }
    }
    void buildChests() override {
        for(int i {0}; i < mapInfo.chestInfo.size(); i+=3) {
            auto* chest = new container(mapInfo.chestInfo[i+2]);
            map->setChest(chest, mapInfo.chestInfo[i], mapInfo.chestInfo[i+1]);
        }
    }
    void buildPlayer() override {
        if(mapInfo.playerPos[0] != -1) {
            player = mapInfo.player;
            map->setPlayer(player, mapInfo.playerPos[0], mapInfo.playerPos[1]);
        }
    }
private:
    MapInfo mapInfo;
};


#endif //COMP345_A1_DEFAULTMAPBUILDER_H
