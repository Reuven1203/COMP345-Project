#ifndef SUBJECT_H
#define SUBJECT_H


#include  <list>
#include "Observer.h"
using namespace std;
class Observer;

class Subject {

public:
	Subject();
	~Subject();
	virtual void Attach(Observer* o);
	virtual void Detach(Observer* o);
	virtual void Notify();



private:
	list<Observer*> *_observers;


};


#endif // !SUBJECT_H
