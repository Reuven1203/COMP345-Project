//
// Created by z3p on 12/04/24.
//

#ifndef COMP345_A1_GAME_H
#define COMP345_A1_GAME_H

#include "../CampaignEditor/CampaignEditor.h"
#include "../CharacterCreator/CharacterCreatorUI.h"
#include "../TurnManager/TurnManager.h"
#include "../CampaignEditor/MapEditor.h"
#include "../Item/ItemEditor.h"

class Game {
public:
    void run();
private:
    CampaignEditor* campaignEditor { new CampaignEditor() };
    MapEditor* mapEditor { new MapEditor() };
    CharacterCreatorUI* characterCreator { new CharacterCreatorUI() };
    ItemEditor* itemCreator { new ItemEditor() };
    Campaign campaign {};
    Fighter player {};
    TurnManager* turnManager {};
    bool campaignFinished = false;
    void mainMenu();
    static int mainMenuInput();
    bool startNewCampaign();
    static int campaignMenuInput();
    void defaultCampaigns();
    void chooseYourCharacter();
    static int characterMenuInput();
    void defaultCharacters();
    void runCampaign();
    bool loadCharacter();
};


#endif //COMP345_A1_GAME_H
