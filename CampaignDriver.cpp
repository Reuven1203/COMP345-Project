//
// Created by z3p on 12/03/24.
//

#include "Campaign/Campaign.h"
#include "Character/Fighter.h"
#include <iostream>

int main() {
    dungeonMap map1 = dungeonMap(5, 5);
    dungeonMap map2 = dungeonMap(10, 10);

    Character player = Fighter("Steve", 8);

    Campaign campaign = Campaign();
    campaign.addMap(map1);
    campaign.addMap(map2);
    campaign.printCampaign();

    campaign.setPlayer(player);
    campaign.setPlayerPosition(1, 2, 2);
    campaign.startCampaign();
    campaign.printCampaign();
}