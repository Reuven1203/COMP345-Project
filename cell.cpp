#include <iostream>
#include "cell.h"

using namespace std;

cell::cell()
{
    visit=false;
    type = Nothing;
   
    // player = nullptr;
    chest = nullptr;
}
cell::~cell(){};

cell::cell(cellType types)
{
    type=types;
}
// cell::cell(Character *person)
// {

//     if (type==Nothing)
//     {
//         player = person;
//         type = Player;
//     }
// }

cell::cell(container *itemStorage)
{
    if (type==Nothing)
    {
        chest = itemStorage;
        type = Chest;
    }
}

void cell::setWall()
{
    type=Wall;
}
///////////////////////////////////////////////////////////////////

// Setters
void cell::setCellType(cellType types)
{
    type=types;
}
void cell::setChest(container *itemStorage)
{
    chest = itemStorage;
}

// void cell::setPlayer(Character *person)
// {
//     player = person;
// }

void cell::removeContent()
{
    // player = nullptr;
    chest = nullptr;
    type=Nothing;
}

////////////////////////////////////////////////////
cellType cell::getCellType()
{
    return type;
}

void cell::setVisit()
{
    visit=true;
}

bool cell::checkVisit()
{
    return visit;
}

void cell::clearVisit()
{
    visit=false;
}