/*
*@author Richard Mauricio 
*/

#include <iostream>
#include <ostream>
#include "GameObserver.h"
using namespace std;

GameObserver::~GameObserver()
{
	for (auto i : subjects)
	{
		i->detach(this);
	}
}

void GameObserver::attachObservable(Observable* subject)
{
	subject->attach(this);
	subjects.push_back(subject);
}

void GameObserver::detachObservable(Observable* subject)
{
	subject->detach(this);
	subjects.erase(std::remove(subjects.begin(), subjects.end(), subject), subjects.end());
}

void GameObserver::update(Observable * type)
{
	SubjectType classType = type->getType();
	switch (classType)
	{
	case SubjectType::map:
	{

	}
	case SubjectType::character:
	{

	}
	case SubjectType::dice:
	{

	}
	
	}
}

void GameObserver::logEvent()
{

}