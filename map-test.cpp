#include <iostream>
#include "map.h"

using namespace std;
int main()
{

    dungeonMap dungeon(5, 5);
    dungeon.setStart(0, 0);
    dungeon.setEnd(4, 4);

    dungeon.setWall();
    cout<<((dungeon.validMap(dungeon.getStartX(), dungeon.getStartY()) == true)?"Found end":"End cannot be reached.")<<endl;
    dungeon.clearCellVisit();
    dungeon.setWall();
    cout<<((dungeon.validMap(dungeon.getStartX(), dungeon.getStartY()) == true)?"Found end":"End cannot be reached.");
    
    return 0;
}