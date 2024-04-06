#include "MapObserver.h"
#include "../../Map/map.h"
#include <cstdlib>
#include <iostream>
#include "../../Utils/utils.h"


using namespace std;




MapObserver::MapObserver(dungeonMap* m) {
    _subject = m;
    _subject->attach(this);
   
}
MapObserver::~MapObserver()
{
    _subject->detach(this);
}

//void MapObserver::moveCharacter()
//{
//
//    int ch = 0;
//    while (true)
//    {
//        update();
//
//        if (ch == 27)// ESC key pressed
//        {
//            break;
//        }
//        cout << "Use arrow keys to move Player(P) (ESC to quit)..."<<endl;
//        switch ((ch = keyPress()))
//        {
//            case KEY_UP://UP arrow key
//            {
//
////                _subject->movePlayer(_subject.,1);
//                if (mapFinishedCheck())
//                {
//                    exit(EXIT_SUCCESS);
//                }
//                break;
//            }
//            case KEY_DOWN://DOWN arrow key
//            {
//
////                _subject->movePlayer(2);
//                if (mapFinishedCheck())
//                {
//                    exit(EXIT_SUCCESS);
//                }
//                break;
//            }
//            case KEY_LEFT://LEFT arrow key
//            {
//
////                _subject->movePlayer(3);
//                if (mapFinishedCheck())
//                {
//                    exit(EXIT_SUCCESS);
//                }
//                break;
//            }
//            case KEY_RIGHT://RIGHT arrow key
//            {
//
////                _subject->movePlayer(4);
//                if (mapFinishedCheck())
//                {
//                    exit(EXIT_SUCCESS);
//                }
//                break;
//            }
//
//            default: //Anything but arrowkeys pressed
//                break;
//
//        }
//
//
//    }
//}
void MapObserver::update()
{
#ifdef _WIN32
    system("cls");
#else
    int result = system("clear");
    if (result != 0) {
        std::cerr << "Failed to clear screen. Error code: " << result << std::endl;
    }
#endif
    displayMap();
}
void MapObserver::displayMap()
{
    _subject->printMap();
}



//bool MapObserver::mapFinishedCheck()
//{
//    if (_subject->getEndX()==_subject->playerPositions[player].first && _subject->getEndY() == _subject->playerPositions[player].second)
//    {
//        cout << "You've reached the end!" << endl;
//        cout << "Dungeon cleared! Press any key to end game.....";
//        keyPress();
//        return true;
//
//    }
//    return false;
//}