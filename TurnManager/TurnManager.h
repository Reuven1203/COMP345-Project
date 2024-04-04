#ifndef TURNMANAGER_H
#define TURNMANAGER_H

#include "../Map/map.h"
#include "../Character/Fighter.h"
#include "../Dice/Dice.h"
#include "../Strategy/CharacterStrategy/HumanPlayerStrategy/HumanPlayerStrategy.h"
#include "../Strategy/CharacterStrategy/AggressorStrategy/AggressorStrategy.h"
#include "../Strategy/CharacterStrategy/FriendlyStrategy/FriendlyStrategy.h"

#include "../Utils/utils.h"
class TurnManager {
	TurnManager() = default;

	TurnManager(dungeonMap*, Character*);

	void addEnemy(Character*);

	void play();
private:
	dungeonMap* currentMap;
	vector<Character*>enemyNPCs;
	Character* currentPlayer;
};
#endif // !TURNMANAGER_H
