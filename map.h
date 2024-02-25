#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include "cell.h"
using namespace std;
class dungeonMap
{
    friend class cell;
public:
    dungeonMap()= default;
    ~dungeonMap()= default;

    dungeonMap(int x, int y);
    bool isValid();
    void printMap();
    void setStart(int x,int y);
    void setEnd(int x,int y);
    void setWall(int x,int y);
    void removeWall(int x,int y);
    void removeCellContent(int x, int y);
    void setPlayer(Character *player, int x, int y);
    [[nodiscard]] int getStartX() const;
    [[nodiscard]] int getStartY() const;
    int getRowSize() const;
    int getColSize() const;
    void userInputWalls();
    void setChest(container *chest,int x,int y);
//    void setPlayer(Character *player); //Add in player to start position
    //Add setDoor,setOpponent when necessary
    void clearCellVisit();
    cell getCell(int row, int col) const;


private:
    vector<vector<cell>> dungeon;
    int rows;
    int cols;
    //pointer to starting cell
    cell *start{};
    //pointer to ending cell
    cell *end{};
    int startX{},startY{};
    int endX{},endY{};
    bool isStart(cell *cell) const;
    bool isEnd(cell *cell) const;
    bool dfs(int row, int col);
    void addWallInteraction();
    void removeWallInteraction();
    void getWallCoordinates(int &x, int &y);
    bool isValidRow(int row) const;
    bool isValidCol(int col) const;
    bool isValidLocation(int row, int col);
    void addWallChoice(int *x, int *y);
    void removeWallChoice(int *x, int *y);

};
#endif
