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
        std::cout << "1. Create/load a campaign" << std::endl;
        std::cout << "2. Create a mew fighter" << std::endl;
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
                std::cout << "___________.__       .__     __                 __________      .__.__       .___              \n"
                             "\\_   _____/|__| ____ |  |___/  |_  ___________  \\______   \\__ __|__|  |    __| _/___________   \n"
                             " |    __)  |  |/ ___\\|  |  \\   __\\/ __ \\_  __ \\  |    |  _/  |  \\  |  |   / __ |/ __ \\_  __ \\  \n"
                             " |     \\   |  / /_/  >   Y  \\  | \\  ___/|  | \\/  |    |   \\  |  /  |  |__/ /_/ \\  ___/|  | \\/  \n"
                             " \\___  /   |__\\___  /|___|  /__|  \\___  >__|     |______  /____/|__|____/\\____ |\\___  >__|     \n"
                             "     \\/      /_____/      \\/          \\/                \\/                    \\/    \\/         " << std::endl;
                cc.run();
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }




    return 0;
}
