#ifndef EVENTDATA_H
#define EVENTDATA_H
#include <iostream>
using namespace std;
struct EventData
{
	enum class EventType {WallPlaced,
		ChestPlaced,
		PlayerMoved,
		DiceRolled,
		PlayerAttacked,} type;
	
	//For movement,wall placement,chestplacement
	int newX, newY;


	EventData(EventType type, int x, int y) :type(type), newX(x), newY(y);
};
#endif;