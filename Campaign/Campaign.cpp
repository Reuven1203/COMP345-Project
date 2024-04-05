/**
 * @author Julian D'Addario
 */

#include "Campaign.h"
#include "../Observer/MapObserver/MapObserver.h"
#include "../Strategy/CharacterStrategy/HumanPlayerStrategy/HumanPlayerStrategy.h"

#include <utility>

Campaign::Campaign() = default;

Campaign::Campaign(Character* player, std::vector<dungeonMap> maps) : player(player) {
    campaign = std::move(maps);
}

dungeonMap Campaign::getMap(int index) {
    if (index > 0 && index < campaign.size())
        return campaign[index];
    else {
        std::cerr << "Invalid Index For Map. Returning Blank Map";
        return {};
    }
}

void Campaign::printCampaign() {
    std::cout << "Maps, in order:\n\n";
    for (dungeonMap map : campaign) {
        map.printMap();
        std::cout << '\n';
    }
}

void Campaign::addMap(dungeonMap map) {
    campaign.push_back(map);
}

void Campaign::setPlayer(Character* character) {
    player = character;
}

void Campaign::setPlayerPosition(int mapNum, int xPos, int yPos) {
    campaign[mapNum].setPlayer(player, xPos, yPos);
    playerPos[0] = mapNum;
    playerPos[1] = xPos;
    playerPos[2] = yPos;
    currentMapIndex = mapNum;
}

void Campaign::startCampaign() {
    if(playerPos[0] == -1 && playerPos[1] == -1 && playerPos[2] == -1) {
        setPlayerPosition(0, campaign[0].getStartX(), campaign[0].getStartY());
        currentMapIndex = 0;
    }
}

dungeonMap* Campaign::nextMap() {
    currentMapIndex++;
    setPlayerPosition(currentMapIndex, campaign[currentMapIndex].getStartX(), campaign[currentMapIndex].getStartY());
    return &campaign[currentMapIndex];
}

dungeonMap *Campaign::currentMap() {
    return &campaign[currentMapIndex];
}

void Campaign::removeMap(int index) {
    campaign.erase(campaign.begin()+index);
}

void Campaign::clear() {
    campaign.clear();
}

Character* Campaign::getPlayer() {
    return player;
}

void Campaign::run(){
    dungeonMap* currentMap = this->currentMap();
    auto* observer = new MapObserver(currentMap);
    currentMap->attach(observer);
    auto* pStrategy = new HumanPlayerStrategy();
    Character* pCharacter = this->getPlayer();
    pCharacter->setStrategy(pStrategy);
    currentMap->setPlayer(pCharacter, currentMap->getStartX(), currentMap->getStartY());
    while(true) {
        pCharacter->move(*currentMap);
    }
}
