#ifndef CELL_H
#define CELL_H
#include <iostream>
#include "itemContainer.h"
 #include "Character.h"

enum cellType
{
    Player,Nothing,Chest,Wall
};
class cell
{
    friend class dungeonMap;
public:
    cell();
    ~cell();

    explicit cell(Character *person);
    explicit cell(container *itemStorage);
    explicit cell(cellType types);

    void setWall();
    void setChest(container *chest);
    void setPlayer(Character *player);
    void setVisit();
    bool checkVisit();
    void clearVisit();
    cellType getCellType();
    [[nodiscard]] int getRowPos() const;
    [[nodiscard]] int getColPos() const;

    void removeContent(); //To remove anything thats in cell 


private:
    cellType type;
    container  *chest{};
    Character *player{};
    bool visit{}; //for map validation
    void setCellType(cellType types);
    int rowPos{};
    int colPos{};
    void setRowPos(int row);
    void setColPos(int col);


    /* Add in when necessary
    Opponent enemy;
    Door closedDoor;
    */
};

#endif