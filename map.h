#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include "cell.h"
using namespace std;
class dungeonMap
{
public:
    dungeonMap(){};
    ~dungeonMap(){};

    dungeonMap(int x, int y);

    void validMap(int startX,int startY);
    void printMap();
    void setStart(int x,int y);
    void setEnd(int x,int y);
    void setWall();
    void setChest(container *chest,int x,int y);
    void setPlayer(); //Add in player to start position
    //Add setDoor,setOpponent when necessary
    void clearCellVisit();
    int getStartX();
    int getStartY();


private:
    
    int rows;
    int cols;
    vector<vector<cell>> dungeon;
    int startX,startY;
    int endX,endY;
};
#endif
