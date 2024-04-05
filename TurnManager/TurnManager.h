#ifndef TURNMANAGER_H
#define TURNMANAGER_H
#include <queue>
#include <vector>
#include "../Map/map.h"
#include "../Character/Fighter.h"
#include "../Dice/Dice.h"
#include "../Strategy/CharacterStrategy/HumanPlayerStrategy/HumanPlayerStrategy.h"
#include "../Strategy/CharacterStrategy/AggressorStrategy/AggressorStrategy.h"
#include "../Strategy/CharacterStrategy/FriendlyStrategy/FriendlyStrategy.h"

#include "../Utils/utils.h"

struct InitiativeComparator {
	bool operator()( Character* a,  Character* b) {
		return a->getInitiative() < b->getInitiative(); // For descending order
	}
};



class TurnManager {
public:
	TurnManager() = default;
	~TurnManager() {};
	TurnManager(dungeonMap*, Character*);



	void addEnemy(Character*);
	bool initiativeCompare(Character*, Character*);
	void play();
	void setAllEnemys();
private:
	dungeonMap* currentMap;
	vector<Character*>enemyNPCs;
	priority_queue<Character*,vector<Character*>,InitiativeComparator>intiativeOrder;
	queue<Character*>turnOrder;
	vector<int>intiativeRolls;
	Character* currentPlayer;
};
#endif // !TURNMANAGER_H