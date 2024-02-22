#include <iostream>
#include "map.h"

using namespace std;
int main(){

    map dungeon(5,5);
    dungeon.setStart(0,0);
    dungeon.setEnd(4,4);
    dungeon.printMap();
    return 0;
}
