#include <iostream>
#include "map.h"
#include "Fighter.h"

using namespace std;
int main()
{
    Character *fighter = new Fighter("Reuven", 6);
    dungeonMap dungeon(10, 10);
//    dungeon.setPlayer();
    dungeon.setStart(0, 0);
    dungeon.setEnd(4, 4);
    dungeon.setPlayer(fighter, 0, 1);
    cout <<(dungeon.isValid() ? "Found end" : "End cannot be reached.") << endl;
    dungeon.userInputWalls();
    cout<<(dungeon.isValid() ? "Found end" : "End cannot be reached.");
    
    return 0;
}