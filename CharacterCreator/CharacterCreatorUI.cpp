//
// Created by Reuven Ostrofsky on 2024-03-30.
//

#include "CharacterCreatorUI.h"
#include "../Builder/FighterBuilder/BullyFighterBuilder/BullyFighterBuilder.h"
#include "../Builder/FighterBuilder/NimbleFighterBuilder/NimbleFighterBuilder.h"
#include "../Builder/FighterBuilder/TankFighterBuilder/TankFighterBuilder.h"

void CharacterCreatorUI::chooseFighterType() {
    cout << "Welcome to the Character Creator!" << endl;
    cout << "Let's start off by choosing a fighter type:" << endl;
    cout << "1. Bully: Uses brute strength to destroy his enemies" << endl;
    cout << "2. Nimble: favors dexterity and better armor class to evade blows" << endl;
    cout << "3. Tank: favors survival by more hit points through a high constitution score" << endl;
    cout << "Enter choice: ";
    int choice;
    cin >> choice;
    do {
        switch (choice) {
            case 1:
                fighterBuilder = new BullyFighterBuilder();
                break;
            case 2:
                fighterBuilder = new NimbleFighterBuilder();
                break;
            case 3:
                fighterBuilder = new TankFighterBuilder();
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }while (choice < 1 || choice > 3);
}

void CharacterCreatorUI::createFighter() {
    cout << "🛠️-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-🛠️\nFighter is built" << endl;
    cout << "Now, what will your fighter's name be?" << endl;
    cout << "Enter name: ";
    string name;
    cin >> name;
    cout << name << " is a great name, and will be the bravest fighter\n" << endl;
    fighterDirector = new FighterDirector();
    fighterDirector->setBuilder(fighterBuilder);
    fighter = fighterDirector->constructFighter(name);
    fighterObserver = new FighterObserver(fighter);
    fighter->attach(fighterObserver);
    fighter->notify();
    fighter->detach(fighterObserver);
    delete fighterDirector;
    delete fighterBuilder;
}

void CharacterCreatorUI::run() {
    chooseFighterType();
    createFighter();
    std::cout << "Fighter created! Press any key to continue." << std::endl;
    std::cin.ignore();
    std::cin.get();
}

Fighter CharacterCreatorUI::getFighter() {
    return *fighter;
}

FighterObserver CharacterCreatorUI::getFighterObserver() {
    return *fighterObserver;
}
