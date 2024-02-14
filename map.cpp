#include <iostream>
#include <vector>
#include <algorithm>
#include "map.h"
//Initialize 2D vector map with space ' ' chars
map::map(int x,int y):breadth(x),width(y)
{
    dungeon.resize(breadth);
    for(int i=0;i<width;i++)
    {
        dungeon[i].resize(width);
        fill(dungeon[i].begin(),dungeon[i].end(),' ');
    }
    
    
}
//Setting Start point of map
void map::setStart(int x,int y)
{
    this->startX=x;
    this->startY=y;
if(startX>breadth||startY>width||startX<0||startY<0)
    {
    cout<<"Start point is out of bounds.";
    exit(1);
    }
  dungeon[startX][startY]='S';

}

//Setting End point of map
void map::setEnd(int x,int y)
{

    this->endX=x;
    this->endY=y;

    if (endX>breadth||endY>width||endX<0||endY<0)
     {   cout<<"End point is out of bounds.";
        exit(1);
     }
     if (endX==startX && endY==startY)
     {
        cout<<"End point cannot be the same as Start point";
        exit(1);
     }
    else dungeon[endX][endY]='E';
}

//Prints map
void map::printMap()
{
      for (int i=0;i<dungeon.size();i++)
    {
        for(int j=0;j<dungeon.size();j++)
        {
            cout<<"| "<< dungeon[i][j]<<" ";
        }
        cout<<"|"<<endl;
    }
    cout<<"Legend:| S-Start | |E-End| | C-Character | |Ch-Chest| |O-Opponent| |D-Door| |W - Wall|";
}

//Validate's map to check if there is a valid path from start to end
bool map::validMap()
{
    


}