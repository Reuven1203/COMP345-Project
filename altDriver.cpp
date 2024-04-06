#include "CampaignEditor/CampaignEditor.h"
#include "CharacterCreator/CharacterCreatorUI.h"
#include "Strategy/CharacterStrategy/HumanPlayerStrategy/HumanPlayerStrategy.h"
#include "TurnManager/TurnManager.h"

//
// Created by z3p on 05/04/24.
//
int main() {

    CampaignEditor ce { CampaignEditor() };
    CharacterCreatorUI cc { CharacterCreatorUI() };

    ce.run();
    Campaign campaign { ce.getCampaign() };

    cc.run();
    Fighter player { cc.getFighter() };
    player.setStrategy(new HumanPlayerStrategy());

    campaign.setPlayer(&player);
    campaign.startCampaign();

    auto* map { campaign.currentMap() };
    auto* control = new MapObserver(map);
    map->attach(control);
    map->setUserPlayer(campaign.getPlayer());

    auto* turnManager = new TurnManager(map, &player, &campaign);
    while(true) {
        turnManager->play();

        map = campaign.nextMap();
        control = new MapObserver(map);
        map->attach(control);
        map->setUserPlayer(campaign.getPlayer());
        map->notify();

        turnManager = new TurnManager(map, &player, &campaign);
    }
}