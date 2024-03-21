#ifndef EVENTDATA_H
#define EVENTDATA_H
#include <iostream>
using namespace std;
struct EventData {
	enum class EventType {
		//Map related
		MapCreated,
		WallPlaced,
		WallRemoved,
		ChestPlaced,
		PlayerPlaced,
		StartPointPlaced,
		EndPointPlaced,
		//Player movement
		PlayerMovedUp,
		PlayerMovedDown,
		PlayerMovedLeft,
		PlayerMovedRight,
		//Item related
		ItemStatRolled,
		//Dice related
		DiceRolled,
		//Player related
		AttackedResult,

	}type;


	int newX, newY,rolledStat,charCurrentHP,dmgDealt=0;
	int charType;//1 player,2 enemy,3 friendly
	string name,name2,statname,result;
	

	EventData(EventType type, string resultOfAtk, string attackerName,string defenderName, int charType,int _currentHP,int _dmgDealt) :type(type), result(resultOfAtk), name(attackerName),name2(defenderName), charType(charType),charCurrentHP(_currentHP),dmgDealt(_dmgDealt) {};
	
	
	//For dice
	EventData(EventType type, string diceType, int diceResult) :type(type), name(diceType), rolledStat(diceResult) {};

	EventData(EventType type, string _name,string _statName,int stat) :type(type), name(_name),statname(_statName), rolledStat(stat) {}; 
	EventData(EventType type, int x, int y) :type(type), newX(x), newY(y) {}; ///<For map
	EventData(EventType type,string _name, int x, int y) :type(type),name(_name), newX(x), newY(y) {};
};


#endif;