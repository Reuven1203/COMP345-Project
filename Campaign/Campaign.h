//
// Created by z3p on 12/03/24.
//

#ifndef COMP345_A1_CAMPAIGN_H
#define COMP345_A1_CAMPAIGN_H

#include <vector>
#include "../Map/map.h"

class Campaign {
public:
    Campaign();
    Campaign(Character player, std::vector<dungeonMap> maps);

    dungeonMap getMap(int index);
    void printCampaign();
    void addMap(dungeonMap map);
    void setPlayer(Character character);
    void setPlayerPosition(int mapNum, int xPos, int yPos);
    void startCampaign();
    dungeonMap* currentMap();
    dungeonMap* nextMap();
private:
    std::vector<dungeonMap> campaign {};
    Character player {"default", 1};
    int playerPos[3] {-1, -1, -1};
    int currentMapIndex {0};
};


#endif //COMP345_A1_CAMPAIGN_H
