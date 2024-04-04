#include <iostream>
#include "TurnManager.h"
using namespace std;

TurnManager::TurnManager(dungeonMap* map, Character* _currentPlayer)
{
	this -> currentMap = map;
	this->currentPlayer = _currentPlayer;

}

void TurnManager::addEnemy(Character* enemy)
{
	enemyNPCs.push_back(enemy);
}

void TurnManager::play()
{
	bool gameOver = false;
	
	while (!gameOver)
	{
		int playerInitiative = 0;
		int enemyInitiative = 0;
		

	}
		
}