#ifndef MAPOBSERVER_H
#define MAPOBSERVER_H
#include "Observer.h"
#include "map.h"
using namespace std;

class MapObserver:public Observer
{
public:
	MapObserver()=default;
	MapObserver(dungeonMap* m);
	~MapObserver();
	void moveCharacter();
	void displayMap();
	void Update();
	bool mapFinishedCheck();
private:
	dungeonMap* _subject;
};
#endif // !INPUTHANDLER_H
