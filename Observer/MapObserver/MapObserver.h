#ifndef MAPOBSERVER_H
#define MAPOBSERVER_H
#include "../Observer.h"
#include "../../Map/map.h"
using namespace std;

class MapObserver:public Observer
{
public:
	MapObserver()=default;
	MapObserver(dungeonMap* m);
	~MapObserver();
	void moveCharacter();
	void displayMap();
	void update() override;
	void update(EventData&) override { };
	bool mapFinishedCheck();
private:
	dungeonMap* _subject{};
};
#endif // OBSERVER_H
