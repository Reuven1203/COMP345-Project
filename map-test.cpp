#include <iostream>
#include "map.h"

using namespace std;
int main(){

     dungeonMap dungeon(5,5);
    dungeon.setStart(0,0);
    dungeon.setEnd(4,4);
    
    dungeon.setWall();
    dungeon.validMap(dungeon.getStartX(),dungeon.getStartY());
    return 0;
}