//
// Created by Reuven Ostrofsky on 2024-03-09.
//

#ifndef COMP345_A1_CHARACTERDISPLAY_H
#define COMP345_A1_CHARACTERDISPLAY_H
#include "../Observer.h"
#include "../../Character/Character.h"


class CharacterDisplay : public Observer{
    Character *character;
public:
    explicit CharacterDisplay(Character *character) : character(character) {}
    void update() override;


};


#endif //COMP345_A1_CHARACTERDISPLAY_H
