#include "MapObserver.h"
#include "map.h"
#include <conio.h>
#include <stdlib.h>
#include "cell.h"
#include <iostream>

using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

MapObserver::MapObserver(dungeonMap* m) {
	_subject = m;
	_subject->Attach(this);
}
MapObserver::~MapObserver()
{
	_subject->Detach(this);
}

void MapObserver::moveCharacter()
{
	
	int ch = 0;
	while (true)
	{	
		Update();
		
		if (ch == 27)// ESC key pressed
	     	{
			break;
			}
		
		cout << "Use arrow keys to move Player(P) (ESC to quit)..."<<endl;
		ch = _getch();
		if (ch == 224 || ch == -32) { //Reads the downward press of arrow key
			switch ((ch = _getch()))
			{
			case KEY_UP://UP arrow key
			{
				
				_subject->movePlayer(1);
				if (mapFinishedCheck())
				{
					exit(EXIT_SUCCESS);
				}
				break;
			}
			case KEY_DOWN://DOWN arrow key
			{
				
				_subject->movePlayer(2);
				if (mapFinishedCheck())
				{
					exit(EXIT_SUCCESS);
				}
				break;
			}
			case KEY_LEFT://LEFT arrow key
			{
				
				_subject->movePlayer(3);
				if (mapFinishedCheck())
				{
					exit(EXIT_SUCCESS);
				}
				break;
			}
			case KEY_RIGHT://RIGHT arrow key
			{
				
				_subject->movePlayer(4);
				if (mapFinishedCheck())
				{
					exit(EXIT_SUCCESS);
				}
				break;
			}

			default: //Anything but arrowkeys pressed
				break;

			}
		}
		
	}
}
void MapObserver::Update()
{
	system("cls");
	displayMap();
}
void MapObserver::displayMap()
{
	_subject->printMap();
}

bool MapObserver::mapFinishedCheck()
{
	if (_subject->getEndX()==_subject->getPlayerX() && _subject->getEndY()==_subject->getPlayerY())
	{
		cout << "You've reached the end!" << endl;
		cout << "Dungeon cleared! Press any key to end game.....";
		_getch();
		return true;
		
	}
	return false;
}