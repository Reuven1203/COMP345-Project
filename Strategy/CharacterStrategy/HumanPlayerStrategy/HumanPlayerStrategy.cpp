//
// Created by Reuven Ostrofsky on 2024-03-19.
//

#include "HumanPlayerStrategy.h"
#include "../FriendlyStrategy/FriendlyStrategy.h"
#include "../AggressorStrategy/AggressorStrategy.h"


void HumanPlayerStrategy::move(Character *player, dungeonMap &map) {
    int ch = 0;
    while(ch != ENTER)
    {
        cout << "Use arrow keys to move Player(P) (Enter to quit)..." << endl;
        // Get the key pressed by the user (non-blocking call
        ch = keyPress();
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
            default: // Any other key pressed
                // Handle other keys or do nothing
                break;
        }
    }
}

void HumanPlayerStrategy::attack(Character *source, Character *target) {
    
    int attackRoll = Dice::GetGlobal().roll("1d20") + source->getStat(Character::Stats::AB);
    if (attackRoll >= target->getStat(Character::Stats::AC)) {
        int damage = Dice::GetGlobal().roll("1d6") + source->getStat(Character::Stats::DB);
        target->setCurrentHP(target->getCurrentHP() - damage);
    } else {
        std::cout << "Attack missed!" << std::endl;
    }
    if(dynamic_cast<FriendlyStrategy*>(target->getStrategy()) == nullptr) {
        target->setStrategy(new AggressorStrategy());
    }
}
