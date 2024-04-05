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

void TurnManager::addNPC(Character* enemy)
{
	NPCS.push_back(enemy);
}

void TurnManager::setAllNPCS() ///<Goes through enemyNPC vector and places all enemies in valid locations
{
	bool validPlacement = false;
	if (!NPCS.empty())
	{
		for (auto* enemy : NPCS)
		{
			validPlacement = false;
			while (!validPlacement) {
				int enemyX = Random::random(0, currentMap->getRowSize() - 1);
				int enemyY = Random::random(0, currentMap->getColSize() - 1);
				if (currentMap->isValidRow(enemyX) && (currentMap->isValidCol(enemyY) && (!currentMap->chestDetect(enemyX, enemyY) && (!currentMap->wallDetect(enemyX, enemyY) && (!currentMap->playerDetect(enemyX, enemyY) && (!currentMap->isStart(&currentMap->getCell(enemyX, enemyY)) && (!currentMap->isEnd(&currentMap->getCell(enemyX, enemyY)))))))))
					///<Checks if the coordinates are within bounds/no chest/no wall/no player/is not start/is not end
				{
					currentMap->setPlayer(enemy, enemyX, enemyY);
					validPlacement = true;
				}

			}
		}
	}
	else
	{
		cout << "No Cell available to place NPC." << endl;
		cout << "Press any key to continue..." << endl;
		keyPress();
	}
}

void TurnManager::EnemyinRange(Character* player,int range)
{
	int playerX = currentMap->playerPositions[player].first;
	int playerY = currentMap->playerPositions[player].second;
	
	if (range == 0)
	{
		return;
	}
	if (currentMap->isValidRow(playerX + range))
	{
		if (currentMap->playerDetect(playerX + range, playerY))
		{
			storeEnemyInRange(playerX + range, playerY);
		}
			
	}
	if (currentMap->isValidRow(playerX-range))
	{
		if (currentMap->playerDetect(playerX - range, playerY))
			storeEnemyInRange(playerX - range, playerY);
	}
	if (currentMap->isValidCol(playerY + range))
	{
		if (currentMap->playerDetect(playerX, playerY+range))
			storeEnemyInRange(playerX, playerY+range);
	}
	if (currentMap->isValidCol(playerY - range))
	{
		if (currentMap->playerDetect(playerX, playerY - range))
			storeEnemyInRange(playerX, playerY - range);
	}
	 return EnemyinRange(player,range-1);
}

void TurnManager::storeEnemyInRange(int x, int y)
{
	enemiesFound.push_back(currentMap->getCell(x, y).getPlayer());
}
void TurnManager::getTurnOrder(int numPlayers)
{
	for (int i = 1;i <= numPlayers;i++)
	{
	Character* currentTurn = turnOrder.front();
	cout << i << ". " << currentTurn->getName() << " | ";
	turnOrder.pop();
	turnOrder.push(currentTurn);
	}
	

}


void TurnManager::play()
{
	bool mapCleared = false;
	int turnPrio = 0;
	int numofPlayers = 0;
	/*while (!mapCleared)*/

	int playerInitiative = Dice::GetGlobal().roll("1d20") + currentPlayer->getAbilityModifier(Character::Dexterity); //Get player's initiative roll
	currentPlayer->setInitiative(playerInitiative);
	intiativeOrder.push(currentPlayer);
	numofPlayers++;
	for (auto& enemy : NPCS) ///< Will check for all enemy's initative
	{
		int enemyInitiative = Dice::GetGlobal().roll("1d20") + enemy->getAbilityModifier(Character::Dexterity);
		enemy->setInitiative(enemyInitiative);
		intiativeOrder.push(enemy);
		numofPlayers++;
		
	}
	currentMap->notify();
	cout << "TURN ORDER: ";
	
	while (!intiativeOrder.empty())
	{

		Character* currentPlayersTurn = intiativeOrder.top();
		turnPrio++;
		cout << turnPrio << ". " << currentPlayersTurn->getName() << " | ";
		intiativeOrder.pop();
		turnOrder.push(currentPlayersTurn);

	}

	cout <<"\n"<< "Press any key to continue..." << endl;
	keyPress();
	while (!mapCleared)
	{
		Character* currentPlayersTurn = turnOrder.front();
		CharacterStrategy::StrategyType type = currentPlayersTurn->getStrategy()->getStrategyType(); ///<Get PLAYER,ENEMY OR FRIENDLY
		
		switch (type)
		{
		case CharacterStrategy::StrategyType::PLAYER: 
		{
			bool turnOver = false;
			while (!turnOver) 
			{
			currentMap->notify();
			cout << "---------------PLAYERS TURN----------------" << endl;
			cout << "TURN ORDER: "; getTurnOrder(numofPlayers);cout << endl;

			cout << "MENU: 1. OpenInv | 2. Move | 3.Attack | 4.END TURN | 5. Quit & Save" << endl;
				int ch = keyPress();
				switch (ch)
				{
				case ONE_KEY: ///<Opens inventory
				{
					currentPlayer->getStrategy()->openInventory(currentPlayer);
					
					continue;
				}
				case TWO_KEY: ///<Move one cell
				{
					currentMap->notify();
					currentPlayer->move(*currentMap);
					turnOver = true;

					break;
				}
				case THREE_KEY: ///<Attack an enemy within range
				{
					EnemyinRange(currentPlayer, currentPlayer->getStat(Character::Stats::RA));
					if (!enemiesFound.empty())
					{
						int choice = 0;
						cout << "--------------ATTACKING------------" << endl;
						cout << "ENEMIES IN RANGE: ";
						int counter = 0;
						for (auto& enemy : enemiesFound)
						{
							counter++;
							cout <<counter<<". "<< enemy->getName() << " | ";
						}
						cout << "\nChoose who to Attack:" ;
						cin >> choice;
						currentPlayer->attack(enemiesFound[choice - 1]);
						turnOver = true;
						keyPress();
						break;
					}
					else
					{
						cout << "No Enemies within range of attack." << endl;
						keyPress();
						continue;
					}
					
				}
				case FOUR_KEY:///<  Player's Turn end
				{
					turnOver = true;
					break; 
				}
				case FIVE_KEY:
				{
					turnOver = true;


					exit(0); ///<add quit&save function
					
				}
				default:
				{
					///<blank for wrong inputs
				}
				}
			}
			break;
		}
		case CharacterStrategy::StrategyType::ENEMY: {
		currentPlayersTurn->move(*currentMap);
		currentMap->notify();
		cout << "---------------ENEMY "<<currentPlayersTurn->getName() <<" TURN----------------" << endl;
		cout << "TURN ORDER: "; getTurnOrder(numofPlayers);cout << endl;
		cout << "ENEMY TURN OVER (Continue)";
		keyPress();
			break;
		}
		case CharacterStrategy::StrategyType::FRIENDLY: {
			currentPlayersTurn->move(*currentMap);
			currentMap->notify();
			cout << "---------------FRIENDLY " << currentPlayersTurn->getName() << " TURN----------------" << endl;
			cout << "TURN ORDER: "; getTurnOrder(numofPlayers);cout << endl;
			cout << "FRIENDLY TURN OVER (Continue)..";
			keyPress();
			break;
		}
		}

		turnOrder.pop();				   ///<Remove currentplayer from front of queue
		turnOrder.push(currentPlayersTurn);///<Push when player's turn is over
	}



}