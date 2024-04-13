//
// Created by z3p on 12/04/24.
//

#include "Game.h"
#include "../Builder/FighterBuilder/NimbleFighterBuilder/NimbleFighterBuilder.h"
#include "../Builder/FighterBuilder/TankFighterBuilder/TankFighterBuilder.h"
#include "../Builder/FighterBuilder/BullyFighterBuilder/BullyFighterBuilder.h"

int Game::mainMenuInput() {
    clearConsole();
    std::cout << "          _______  _        _______  _______  _______  _______   _________ _______    ______   _______  _______ \n"
                 "|\\     /|(  ____ \\( \\      (  ____ \\(  ___  )(       )(  ____ \\  \\__   __/(  ___  )  (  __  \\ / ___   )(  __   )\n"
                 "| )   ( || (    \\/| (      | (    \\/| (   ) || () () || (    \\/     ) (   | (   ) |  | (  \\  )\\/   )  || (  )  |\n"
                 "| | _ | || (__    | |      | |      | |   | || || || || (__         | |   | |   | |  | |   ) |    /   )| | /   |\n"
                 "| |( )| ||  __)   | |      | |      | |   | || |(_)| ||  __)        | |   | |   | |  | |   | |  _/   / | (/ /) |\n"
                 "| || || || (      | |      | |      | |   | || |   | || (           | |   | |   | |  | |   ) | /   _/  |   / | |\n"
                 "| () () || (____/\\| (____/\\| (____/\\| (___) || )   ( || (____/\\     | |   | (___) |  | (__/  )(   (__/\\|  (__) |\n"
                 "(_______)(_______/(_______/(_______/(_______)|/     \\|(_______/     )_(   (_______)  (______/ \\_______/(_______)\n"
                 "                                                                                                                " << std::endl;
    std::cout << "Welcome to the D&D Campaign Manager!" << std::endl;
    std::cout << "Please select an option:" << std::endl;
    std::cout << " 1 - Start New Campaign" << std::endl;
    std::cout << " 2 - Campaign Editor" << std::endl;
    std::cout << " 3 - Map Editor" << std::endl;
    std::cout << " 4 - Character Creator" << std::endl;
    std::cout << " 5 - Item Creator" << std::endl;
    std::cout << " -1 - Exit" << std::endl;
    std::cout << "Enter command: ";

    int op;
    std::cin >> op;
    return ((op >= 1 && op <= 5) || op == -1) ? op : 0;
}

int Game::campaignMenuInput() {
    clearConsole();
    std::cout << "\n\nWould you like to start a custom campaign or a default one?\n";
    std::cout << " 1 - Default Campaign\n";
    std::cout << " 2 - Custom Campaign\n";
    std::cout << " -1 - Return to Main Menu\n";
    std::cout << "Enter command: ";

    int op;
    std::cin >> op;
    return ((op >= 1 && op <= 2) || op == -1) ? op : 0;
}

void Game::defaultCampaigns() {
    int choice { 0 };
    while(choice < 1 || choice > 2) {
        clearConsole();
        std::cout << "\n\nCurrent Default Campaigns:\n";
        std::cout << " 1 - Castle\n";
        std::cout << " 2 - Dungeon\n";
        std::cout << "Enter command: ";
        std::cin >> choice;
    }

    std::string defaultCampaignFile {};

    switch(choice) {
        case 1:
            defaultCampaignFile = "default_castle.txt";
            break;
        case 2:
            defaultCampaignFile = "default_dungeon.txt";
            break;
    }

    campaign = CampaignEditor::loadCampaignFromFile(defaultCampaignFile);
}

bool Game::startNewCampaign() {
    while(true) {
        clearConsole();
        int input { campaignMenuInput() };
        switch(input) {
            case 1:
                defaultCampaigns();
                return true;
            case 2:
                campaignEditor->run();
                campaign = campaignEditor->getCampaign();
                return true;
            case -1:
                return false;
            default:
                std::cout << "Invalid Command.\n";
        }
    }
}

void Game::mainMenu() {
    while(true) {
        int input { mainMenuInput() };
        switch(input) {
            case 1:
                if(startNewCampaign())
                    input = 0;
                break;
            case 2:
                campaignEditor->run();
                break;
            case 3:
                mapEditor->run();
                break;
            case 4:
                characterCreator->run();
                break;
            case 5:
                itemCreator->run();
                break;
            case -1:
                std::cout << "\nEXITING GAME...\n";
                std::exit(0);
            default:
                std::cout << "Invalid command, try again.\n";
                continue;
        }
        if(input == 0)
            break;
    }
}

int Game::characterMenuInput() {
    clearConsole();
    std::cout << "\n\nWould you like to create a custom character or use a default one?\n";
    std::cout << " 1 - Default Character\n";
    std::cout << " 2 - Custom Character\n";
    std::cout << " 3 - Load Saved Character\n";
    std::cout << "Enter command: ";

    int op;
    std::cin >> op;

    return (op >= 1 && op <= 3) ? op : 0;
}

void Game::defaultCharacters() {
    clearConsole();
    std::string names[] {"Kaladin", "Dalinar", "Jasnah"};

    int choice { 0 };
    while(choice < 1 || choice > 3) {
        std::cout << "\n\nCurrent Default Characters:\n";
        std::cout << " 1 - " + names[0] + " (Nimble Fighter)\n";
        std::cout << " 2 - " + names[1] + " (Tank Fighter)\n";
        std::cout << " 3 - " + names[2] + " (Bully Fighter)\n";
        std::cout << "Enter command: ";
        std::cin >> choice;
    }

    FighterDirector director {};
    FighterBuilder* fighterBuilder;

    switch(choice) {
        case 1:
            fighterBuilder = new NimbleFighterBuilder();
            break;
        case 2:
            fighterBuilder = new TankFighterBuilder();
            break;
        case 3:
            fighterBuilder = new BullyFighterBuilder();
            break;
    }

    director.setBuilder(fighterBuilder);
    player = *director.constructFighter(names[choice-1]);

    delete fighterBuilder;
}

bool Game::loadCharacter() {
    clearConsole();
    std::cout << "List of characters saved: \n";

    const std::filesystem::path path { "../CharacterSaves/" };
    for(auto const& char_file : std::filesystem::directory_iterator { path })
        std::cout << "- " << char_file.path().filename().string() << '\n';

    std::cout << "\nPlease enter full filename of character to load (-1 to return): ";
    std::string fileName {};
    std::cin >> fileName;

    if(fileName == "-1")
        return false;

    player = Fighter(fileName);
    return true;
}

void Game::chooseYourCharacter() {
    while(true) {
        int input{characterMenuInput()};
        switch (input) {
            case 1:
                defaultCharacters();
                input = -1;
                break;
            case 2:
                characterCreator->run();
                player = characterCreator->getFighter();
                input = -1;
                break;
            case 3:
                if(loadCharacter())
                    input = -1;
                break;
            default:
                break;
        }
        if(input == -1)
            break;
    }
}

void Game::runCampaign() {
    campaignFinished = false;
  
    if(player.getSTR() == 0) {
        FighterDirector director{};
        BullyFighterBuilder builder {};
        director.setBuilder(&builder);
        player = *director.constructFighter("Default");
    }
  
    player.setStrategy(new HumanPlayerStrategy);
    campaign.setPlayer(&player);
    campaign.startCampaign();

    auto* map { campaign.currentMap() };
    map->setUserPlayer(campaign.getPlayer());
    vector<Character*> enemyNPC;
    FighterDirector director {};
    BullyFighterBuilder builder;
    director.setBuilder(&builder);
    container* enemyLootPool = new container(15);
    turnManager = new TurnManager(map, &player, &campaign);
    player.setCurrentHP(100);

    while(true) {
        for(int enemy { 0 }; enemy < 2; enemy++)
            enemyNPC.push_back(director.constructFighter("Enemy " + std::to_string(enemy+1)));

        for(auto& enemy : enemyNPC) {
            enemy->setStrategy(new AggressorStrategy());
            enemy->setEXP(150);
         
            enemy->equip(*enemyLootPool->retrieveItem(Random::random(1,10)));

            turnManager->addNPC(enemy);
        }
        turnManager->setAllNPCS();
        turnManager->play();
        if (player.isDead()) {
            campaignFinished = false;
            return;
           
        }
        if(campaign.currentMap() != campaign.lastMap()) {
            enemyNPC.clear();
            map = campaign.nextMap();
            map->setUserPlayer(campaign.getPlayer());
            map->notify();
            turnManager = new TurnManager(map, &player, &campaign);
        } else {
            campaignFinished = true;
            break;
        }
    }
    clearConsole();
   /* if (campaignFinished&&!player.isDead()) {
        std::cout << "CONGRATULATIONS! YOU'VE COMPLETED THE GAME!\n";
        std::cout << "Press any key to return to the main menu.\n";
    keyPress();
    }*/
}

void Game::run() {
    while(true) {
        mainMenu();
        chooseYourCharacter();
        runCampaign();
        if (!campaignFinished)
        {
            continue;
        }
        else
        {
            clearConsole();
            std::cout << "CONGRATULATIONS! YOU'VE COMPLETED THE GAME!\n";
            std::cout << "Press any key to return to the main menu.\n";
            keyPress();
        }
    }
}