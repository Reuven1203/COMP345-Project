#ifndef CELL_H
#define CELL_H
#include <iostream>
#include "itemContainer.h"
// #include "Character.h"

enum cellType
{
    Player,Nothing,Chest,Wall,Start,End
};
class cell
{
public:
    cell();
    ~cell();

    // cell(Character *person);
    cell(container *itemStorage);
    cell(cellType types);
    void setCellType(cellType types);
    void setWall();
    // void setPlayer(Character *person);
    void setChest(container *chest);


    void setVisit();
    bool checkVisit();
    void clearVisit();
    cellType getCellType();

    void removeContent(); //To remove anything thats in cell 


private:
    cellType type;
    container  *chest;
    bool visit; //for map validation

    // Character *player;

    /* Add in when necessary
    Opponent enemy;
    Door closedDoor;
    */
};

#endif