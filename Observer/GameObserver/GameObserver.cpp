/*
*@author Richard Mauricio 
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "GameObserver.h"
using namespace std;

GameObserver::GameObserver()
{
	_dice = nullptr;
	_char = nullptr;

	log.open("../Events/EventLog.txt");
	if(!log.is_open())
	{
		cout << "Eventlog.txt not found" << endl;
		exit(1);
	}
}

GameObserver::~GameObserver()
{
	_dice->detach(this);
	_char->detach(this);

	for (auto i : mapList)
	{
		i->detach(this);
	}

	if (log.is_open())
	{
		log.close();
	}
}

void GameObserver::attachObservable(dungeonMap* subject)
{
	subject->attach(this);
	mapList.push_back(subject);
	EventData newMap(EventData::EventType::MapCreated, subject->getRowSize(), subject->getColSize());
	update(newMap);
}
void GameObserver::attachObservable(Dice* subject)
{
	subject->attach(this);
	_dice = subject;

}
void GameObserver::attachObservable(Character* subject)
{
	subject->attach(this);
	_char = subject;

}

void GameObserver::detachObservable(Observable* subject)
{
	subject->detach(this);
	
}

void GameObserver::update(const EventData& event)
{
	
	
	switch (event.type)
	{
	case EventData::EventType::MapCreated:
	{
		log << "----------MAP CREATED-----------------" << endl;
		log <<left<< setw(30) << "Map size: " << event.newY << "x" << event.newX << endl;
		log << "--------------------------------------" << endl;
		break;
	}
	case EventData::EventType::StartPointPlaced:
	{
		log << setw(30) << "Start Point placed at"<<"X:" << event.newY << " Y:" << event.newX << endl;
		break;
	}
	case EventData::EventType::EndPointPlaced:
	{
		log << setw(30) << "End Point placed at" << "X:" << event.newY << " Y:" << event.newX << endl;
		break;
	}
	case EventData::EventType::WallPlaced:
	{
		log << setw(30) << "Wall placed at" << "X:" << event.newY << " Y:" << event.newX << endl;
		break;
		
	}
	case EventData::EventType::WallRemoved:
	{
		log << setw(30) << "Wall Removed at" << "X:" << event.newY << " Y:" << event.newX << endl;
		break;
	}
	case EventData::EventType::ChestPlaced:
	{
		log << setw(30) << "Chest placed at" << "X:" << event.newY << " Y:" << event.newX << endl;
		break;
	}
	case EventData::EventType::PlayerPlaced:
	{
		log << setw(30) << event.name<< "placed at " << "X:" << event.newY << " Y : " << event.newX << endl;
		break;
		
	}
	case EventData::EventType::PlayerMovedUp:
	{
		log << setw(30) <<event.name<<" Moved Up to " << "X:" << event.newY << " Y : " << event.newX << endl;
		break;

	}
	case EventData::EventType::PlayerMovedDown:
	{
		log << setw(30) << event.name << " Moved Down to " << "X:" << event.newY << " Y:" << event.newX << endl;
		break;

	}
	case EventData::EventType::PlayerMovedLeft:
	{
		log << setw(30) << event.name << " Moved Left to " << "X:" << event.newY << " Y:" << event.newX << endl;
		break;

	}
	case EventData::EventType::PlayerMovedRight:
	{
		log << setw(30) << event.name << " Moved Right to " << "X:" << event.newY << " Y:" << event.newX << endl;
		break;

	}
	case EventData::EventType::ItemStatRolled:
	{
		log << left << setw(54) << "Dice 1d6 rolled for: " + event.name + " result: " + event.statname 
       << " = "<< setw(6) << event.rolledStat << endl;
    break;

	}
	case EventData::EventType::DiceRolled:
	{
		log << setw(30) << "Dice " << event.name << " rolled. Result: " << event.rolledStat << endl;
		break;

	}
	case EventData::EventType::AttackedResult:
	{
		if (event.charType == 1) //From Player
		{

		}
		else if (event.charType == 2) // From Enemy
		{
			log << "--------------------------------------" << endl;
			log << setw(30) << "Enemy Character: " << event.name << " attempted to attack " <<event.name2<< endl;
			log << setw(30) << "Result: " << event.result<<endl;
			log << setw(30) << "Damage Dealt:"<<event.dmgDealt<<" to " << event.name2 << endl;
			log << setw(30) <<event.name2<<"current HP:"<<event.charCurrentHP << endl;
			log << "--------------------------------------" << endl;
		}
		else if (event.charType == 3) //From Friendly
		{
			log << "--------------------------------------" << endl;
			log <<setw(30)<< "Friendly Character: " << event.name << " attempted to attack." << endl;
			log << setw(30) <<"Result: "<< event.result << endl;
			log << "--------------------------------------" << endl;
		}
		
		break;

	}
	case EventData::EventType::TurnOrder:
	{
	
		break;
	}
	}
}

void GameObserver::logEvent()
{

}