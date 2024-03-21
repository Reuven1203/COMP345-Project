#ifndef GAMEOBSERVER_H
#define GAMEOBSERVER_H
#include "../Observer.h"
#include "../Observable.h"
#include <vector>;
using namespace std;


class GameObserver :public Observer {


public:
	GameObserver() = default;
	
	~GameObserver()=default;
	void attachObservable(Observable*);
	void detachObservable(Observable*);
	void update(Observable *) override;
	void logEvent();
private:
	vector<Observable*>subjects;
};
#endif // !GAMEOBSERVER_H
