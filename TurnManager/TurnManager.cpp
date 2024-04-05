#include <iostream>
#include <vector>
#include "TurnManager.h"
#include "../Dice/Dice.h"
#include "../Dice/Random.h"
using namespace std;

TurnManager::TurnManager(dungeonMap* map, Character* _currentPlayer)
{
	this->currentMap = map;
	this->currentPlayer = _currentPlayer;

}

void TurnManager::addEnemy(Character* enemy)
{
	enemyNPCs.push_back(enemy);
}

void TurnManager::setAllEnemys()
{
	int enemyY = Random::random(0, currentMap->getColSize() - 1);
	int enemyX = Random::random(0, currentMap->getRowSize() - 1);

}


void TurnManager::play()
{
	bool mapCleared = false;
	int numberOfEnemys = 0;
	/*while (!mapCleared)*/

	int playerInitiative = Dice::GetGlobal().roll("1d20") + currentPlayer->getAbilityModifier(Character::Dexterity); //Get player's initiative roll
	currentPlayer->setInitiative(playerInitiative);
	intiativeOrder.push(currentPlayer);
	for (auto& enemy : enemyNPCs) ///< Will check for all enemy's initative
	{
		int enemyInitiative = Dice::GetGlobal().roll("1d20") + enemy->getAbilityModifier(Character::Dexterity);
		enemy->setInitiative(enemyInitiative);
		intiativeOrder.push(enemy);
		numberOfEnemys++;
	}
	clearScreen();
	cout << "TURN ORDER:" << endl;
	while (!intiativeOrder.empty())
	{

		Character* currentPlayersTurn = intiativeOrder.top();
		cout << currentPlayersTurn->getName() << endl;
		intiativeOrder.pop();
		turnOrder.push(currentPlayersTurn);

	}
	cout << "Press any key to continue..." << endl;
	keyPress();
	while (!mapCleared)
	{
		Character* currentPlayersTurn = turnOrder.front();
		CharacterStrategy::StrategyType type = currentPlayersTurn->getStrategy()->getStrategyType(); ///<Get PLAYER,ENEMY OR FRIENDLY

		switch (type)
		{
		case CharacterStrategy::StrategyType::PLAYER: {
			currentMap->notify();
			cout << "---------------PLAYERS TURN----------------" << endl;
			cout << "MENU: 1. OpenInv | 2. Move | 3.Attack | 4. Quit & Save" << endl;

			int ch = keyPress();
			switch (ch)
			{
			case ONE_KEY:
			{
				currentPlayer->getStrategy()->openInventory(currentPlayer);
				break;
			}
			case TWO_KEY:
			{
				currentMap->notify();
				currentPlayer->move(*currentMap);
				break;
			}
			case THREE_KEY:
			{
				break;
			}
			case FOUR_KEY:
			{
				exit(0); ///<add quit&save function
				break;
			}
			}
			break;
		}
		case CharacterStrategy::StrategyType::ENEMY: {
			break;
		}
		case CharacterStrategy::StrategyType::FRIENDLY: {
			break;
		}
		}

		turnOrder.pop();				   ///<Remove currentplayer from front of queue
		turnOrder.push(currentPlayersTurn);///<Push when player's turn is over
	}



}