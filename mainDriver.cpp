//
// Created by Reuven Ostrofsky on 2024-04-02.
//

#include <iostream>
#include "./CampaignEditor/CampaignEditor.h"
#include "./CharacterCreator/CharacterCreatorUI.h"
#include "../Utils/utils.h"

int main() {

    while (true) {
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
        std::cout << "1. Create a new campaign" << std::endl;
        std::cout << "2. Load a campaign" << std::endl;
        std::cout << "3. Create a mew fighter" << std::endl;
        std::cout << "-1. Exit" << std::endl;

        int choice;
        std::cin >> choice;
        CampaignEditor ce;
        CharacterCreatorUI cc{};
        clearConsole();
        switch (choice) {
            case 1:
                std::cout << "Creating a new campaign..." << std::endl;
                ce.run();
                break;
            case 2:
                std::cout << "Loading a campaign..." << std::endl;
                break;
            case 3:
                std::cout << "Creating a new fighter..." << std::endl;
                cc.run();
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }




    return 0;
}
