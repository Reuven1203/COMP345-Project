#include "CampaignEditor/CampaignEditor.h"
#include "CharacterCreator/CharacterCreatorUI.h"
#include "Strategy/CharacterStrategy/HumanPlayerStrategy/HumanPlayerStrategy.h"
#include "TurnManager/TurnManager.h"
#include "Director/FighterDirector/FighterDirector.h"
#include "./Strategy/CharacterStrategy/HumanPlayerStrategy/HumanPlayerStrategy.h"
#include "./Strategy/CharacterStrategy/AggressorStrategy/AggressorStrategy.h"
#include "./Strategy/CharacterStrategy/FriendlyStrategy/FriendlyStrategy.h"
#include "Builder/FighterBuilder/BullyFighterBuilder/BullyFighterBuilder.h"
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
    vector<Character*>enemyNPC;
    FighterDirector director{};
    BullyFighterBuilder builder;
    director.setBuilder(&builder);
    auto* turnManager = new TurnManager(map, &player, &campaign);
    player.setCurrentHP(1000); ///<for showcasing purposes
    while(true) {
        int enemyCounter = 0;
        while (enemyCounter < 2)
        {
            enemyCounter++;
            enemyNPC.push_back(director.constructFighter("Bully " + std::to_string(enemyCounter)));
        }
        for (auto& enemy : enemyNPC)
        {
            enemy->setStrategy(new AggressorStrategy());
            turnManager->addNPC(enemy);
        }
        turnManager->setAllNPCS();
        turnManager->play();
        enemyNPC.clear();
        map = campaign.nextMap();
        control = new MapObserver(map);
        map->attach(control);
        map->setUserPlayer(campaign.getPlayer());
        map->notify();

        turnManager = new TurnManager(map, &player, &campaign);
    }
}