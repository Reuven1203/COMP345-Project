/*
*@author Richard Mauricio
*/


#ifndef GAMEOBSERVER_H
#define GAMEOBSERVER_H
#include <fstream>
#include <vector>
#include "../Observer.h"
#include "../Observable.h"
#include "../Map/map.h"
#include "../Character/Character.h"
#include "../Dice/Dice.h"
#include "../Events/EventData.h"
using namespace std;


class GameObserver :public Observer {


public:
	GameObserver();
	
	~GameObserver();
	void attachObservable(dungeonMap*);
	void attachObservable(Character*);
	void attachObservable(Dice*);
	void detachObservable(Observable*);
	void update() override {};
	void update(EventData& event) override;
	void logEvent();
private:
	ofstream log;
	Dice* _dice;
	Character* _char;

	vector<dungeonMap*>mapList;
	
};
#endif // !GAMEOBSERVER_H
