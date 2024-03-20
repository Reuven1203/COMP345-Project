//
// Created by Reuven Ostrofsky on 2024-03-19.
//

#include "HumanPlayerStrategy.h"
#include "../Utils/utils.h"


void HumanPlayerStrategy::move(Character *player, dungeonMap &map) {
    int ch = 0;
    cout << "Use arrow keys to move Player(P) (ESC to quit)..." << endl;
    ch = keyPress();
    std::cout << "Key pressed: " << ch << std::endl;
    switch (ch) {
        case KEY_UP: // UP arrow key
            map.movePlayer(player, 1);
            break;
        case KEY_DOWN: // DOWN arrow key
            map.movePlayer(player, 2);
            break;
        case KEY_LEFT: // LEFT arrow key
            map.movePlayer(player, 3);
            break;
        case KEY_RIGHT: // RIGHT arrow key
            map.movePlayer(player, 4);
            break;
        case 27: // ESC key pressed
            break;
        default: // Any other key pressed
            // Handle other keys or do nothing
            break;
    }
}

void HumanPlayerStrategy::attack() {

}

void HumanPlayerStrategy::freeAction() {

}
