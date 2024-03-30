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
    void chooseFighterType();
    void createFighter();
    void run();
    FighterObserver getFighterObserver();
    Fighter getFighter();
private:
    FighterDirector* fighterDirector;
    FighterBuilder* fighterBuilder;
    FighterObserver* fighterObserver;
    Fighter* fighter;
};


#endif //COMP345_A1_CHARACTERCREATORUI_H
