//
// Created by Reuven Ostrofsky on 2024-03-30.
//

#ifndef COMP345_A1_CHARACTERCREATORUI_H
#define COMP345_A1_CHARACTERCREATORUI_H

#include "../Director/FighterDirector/FighterDirector.h"
#include "../Builder/FighterBuilder/FighterBuilder.h"
#include "../Observer/CharacterObserver/FighterObserver.h"


class CharacterCreatorUI {
public:
    int chooseFighterType();
    void createFighter();
    void run();
    FighterObserver getFighterObserver();
    Fighter getFighter();
    static void save(Fighter* character, std::string filename);
private:
    FighterDirector* fighterDirector;
    FighterBuilder* fighterBuilder;
    FighterObserver* fighterObserver;
    Fighter* fighter;
    std::string fileName {};

    void saveCharacter();
};


#endif //COMP345_A1_CHARACTERCREATORUI_H
