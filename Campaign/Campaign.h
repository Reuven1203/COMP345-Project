/**
 * @author Julian D'Addario
 */

#ifndef COMP345_A1_CAMPAIGN_H
#define COMP345_A1_CAMPAIGN_H

#include <vector>
#include "../Map/map.h"
#include "../Character/Fighter.h"

class Campaign {
public:
    Campaign();
    Campaign(Character* player, std::vector<dungeonMap*> maps);

    dungeonMap* getMap(int index);
    void printCampaign();
    void addMap(dungeonMap* map);
    void removeMap(int index);
    void setPlayer(Character* character);
    void setPlayerPosition(int mapNum, int xPos, int yPos);
    void startCampaign();
    void clear();
    void run();
    Character* getPlayer();
    dungeonMap* currentMap();
    dungeonMap* nextMap();
    dungeonMap* lastMap();
    int getSize() const;
private:
    std::vector<dungeonMap*> campaign {};
    Character* player { new Fighter() };
    int playerPos[3] {-1, -1, -1};
    int currentMapIndex {0};
};


#endif //COMP345_A1_CAMPAIGN_H
