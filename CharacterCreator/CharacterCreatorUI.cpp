//
// Created by Reuven Ostrofsky on 2024-03-30.
//

#include "CharacterCreatorUI.h"
#include "../Builder/FighterBuilder/BullyFighterBuilder/BullyFighterBuilder.h"
#include "../Builder/FighterBuilder/NimbleFighterBuilder/NimbleFighterBuilder.h"
#include "../Builder/FighterBuilder/TankFighterBuilder/TankFighterBuilder.h"

int CharacterCreatorUI::chooseFighterType() {
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
                return 1;
                break;
            case 2:
                fighterBuilder = new NimbleFighterBuilder();
                return 2;
                break;
            case 3:
                fighterBuilder = new TankFighterBuilder();
                return 3;
                break;
                case -1:
                    return -1;
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

void CharacterCreatorUI::saveCharacter() {
    std::cout << "Enter Character File Name (ex: steve): ";
    std::string file {};
    std::cin >> file;
    file += ".csv";
    save(fighter, file);
    fileName = file;
    std::cout << "Character saved as " << file << '\n';
}

/**
 * @brief Saves character basic information to file
 * @param character Character to be saved
 * @param filename File name to be saved to
 *
 * Format of .csv created:
 * name,{characterName}
 * classinfo,{fighterType}
 * stats,{HP},{AC},{atkBonus},{dmgBonus}
 * abilities,{str},{dex},{con},{int},{wis},{cha}
 */
void CharacterCreatorUI::save(Fighter* character, std::string filename) {
    std::ofstream output("../CharacterSaves/" + filename);
    if(!output) {
        std::cerr << "Can not save " << filename << ".\n";
        std::exit(1);
    }

    output << "name," << character->getName() << '\n';
    output << "classinfo," << Fighter::FighterTypeEnumToString(character->getFighterType()) << ","
           << character->getLevel() << '\n';
    output << "stats," << character->getStat(Character::HP) << "," << character->getAC() << ','
           << character->getATK() << "," << character->getDMG() << '\n';
    output << "abilities," << character->getSTR() << ',' << character->getDEX() << ',' << character->getCON() << ','
           << character->getINT() << ',' << character->getWIS() << ','<< character->getCHA() << '\n';
}

void CharacterCreatorUI::run() {
    int choice = chooseFighterType();
    if(choice == -1) {
        return;
    }
    createFighter();
    std::cout << "Fighter created!\n";
    saveCharacter();
}

Fighter CharacterCreatorUI::getFighter() {
    return *fighter;
}

FighterObserver CharacterCreatorUI::getFighterObserver() {
    return *fighterObserver;
}
