#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>

using namespace std;
class map
{
public:
    map(){};
    ~map(){};

    map(int x, int y);

    bool validMap();
    void printMap();
    void setStart(int x,int y);
    void setEnd(int x,int y);
    void setWall(int x,int y);
    
private:
    int breadth;
    int width;
    vector<vector<char>> dungeon;
    int startX,startY;
    int endX,endY;
};
#endif
