#include <iostream>
#include <vector>
#include "TurnManager.h"
#include "../Dice/Dice.h"
#include "../Dice/Random.h"
using namespace std;

TurnManager::TurnManager(dungeonMap* map, Character* _currentPlayer,Campaign* _currentCampaign)
{
	this->currentMap = map;
	this->currentPlayer = _currentPlayer;
	this->currentCampaign = _currentCampaign;
}

void TurnManager::addNPC(Character* enemy)
{
	NPCS.push_back(enemy);
}

void TurnManager::setAllNPCS() {
	if (NPCS.empty()) {
		cout << "No NPCs available to place." << endl;
		cout << "Press any key to continue..." << endl;
		keyPress();
		return; // Exit early if there are no NPCs
	}

	for (auto* enemy : NPCS) {
		bool validPlacement = false;
		while (!validPlacement) {
			int enemyX = Random::random(0, currentMap->getRowSize() - 1);
			int enemyY = Random::random(0, currentMap->getColSize() - 1);

			// conditions to place an npc
			bool isValidRow = currentMap->isValidRow(enemyX);
			bool isValidCol = currentMap->isValidCol(enemyY);
			bool isCellOccupied = currentMap->chestDetect(enemyX, enemyY) ||
				currentMap->wallDetect(enemyX, enemyY) ||
				currentMap->playerDetect(enemyX, enemyY);
			bool isCellSpecial = currentMap->isStart(&currentMap->getCell(enemyX, enemyY)) ||
				currentMap->isEnd(&currentMap->getCell(enemyX, enemyY));


			if (isValidRow && isValidCol && !isCellOccupied && !isCellSpecial) {
				currentMap->setPlayer(enemy, enemyX, enemyY);
				validPlacement = true;
			}
		}
	}
}

void TurnManager::EnemyinRange(Character* player, int range)
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
	if (currentMap->isValidRow(playerX - range))
	{
		if (currentMap->playerDetect(playerX - range, playerY))
			storeEnemyInRange(playerX - range, playerY);
	}
	if (currentMap->isValidCol(playerY + range))
	{
		if (currentMap->playerDetect(playerX, playerY + range))
			storeEnemyInRange(playerX, playerY + range);
	}
	if (currentMap->isValidCol(playerY - range))
	{
		if (currentMap->playerDetect(playerX, playerY - range))
			storeEnemyInRange(playerX, playerY - range);
	}
	return EnemyinRange(player, range - 1);
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


void TurnManager::isDefeated(Character* target)
{
	if (target->isDead())
	{
		cout << "Enemy " << target->getName() << " has been defeated." << endl;
	int targetX = currentMap->playerPositions[target].first;
	int targetY = currentMap->playerPositions[target].second;

	currentMap->getCell(targetX, targetY).removeContent();
	auto* chest = new container(target->getInventory() + target->getWornItems());
	currentMap->getCell(targetX, targetY).setCellType(Chest);
	currentMap->getCell(targetX, targetY).setChest(chest);
	}

}

void TurnManager::removeEnemy(int target)
{
	if (target >= 0 && target < enemiesFound.size()) {
		enemiesFound.erase(enemiesFound.begin() + target);
	}
	else {
		// Handle the error: target is out of range
		std::cerr << "Error: Target index out of range." << std::endl;
	}
}

void TurnManager::play()
{
	bool enemydead = false;
	bool mapCleared = false;
	int turnPrio = 0;
	int numofPlayers = 0;
	/*while (!mapCleared)*/
	int choice = 0;
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

	cout << "\n" << "Press any key to continue..." << endl;
	keyPress();
	while (!mapCleared)
	{
		if (currentPlayer->getCurrentHP() == 0)
		{
			cout << "YOU DIED! GAME ENDING" << endl;
			cout << "Press any key to continue..." << endl;
			mapCleared = true;
			keyPress();
			exit(0);
		}
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
					cout << "----------PLAYER TURN OVER--------------" << endl;
					cout << "Continue..." << endl;
					checkIfPlayerAtEnd();
					turnOver = true;
					keyPress();

					break;
				}
				case THREE_KEY: ///<Attack an enemy within range
				{
					EnemyinRange(currentPlayer, currentPlayer->getStat(Character::Stats::RA));
					if (!enemiesFound.empty())
					{
						
						cout << "--------------ATTACKING------------" << endl;
						cout << "ENEMIES IN RANGE: ";
						int counter = 0;
						for (auto& enemy : enemiesFound)
						{
							counter++;
							cout << counter << ". " << enemy->getName() << " | ";
						}


						bool attackOver = false;
						while (!attackOver)
						{
							cout << "\nChoose who to Attack (-1 to cancel): ";
							cin >> choice;

							if (choice == -1)
							{
								attackOver = true;
								enemiesFound.clear();

							}
							else if (choice < 0 || choice > enemiesFound.size())
							{
								cout << "Invalid choice." << endl;
							}
							else {
								currentPlayer->attack(enemiesFound[choice - 1]);
								enemiesFound.clear();
								attackOver = true;
								turnOver = true;
								isDefeated(enemiesFound[choice - 1]);
								cout << "----------PLAYER TURN OVER--------------" << endl;
								cout << "Continue..." << endl;
								keyPress();
							}
						}
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
					cout << "----------PLAYER TURN OVER--------------" << endl;
					cout << "Continue..." << endl;
					turnOver = true;
					keyPress();
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

			currentMap->notify();
			currentPlayersTurn->move(*currentMap);
			cout << "---------------ENEMY " << currentPlayersTurn->getName() << " TURN----------------" << endl;
			cout << "TURN ORDER: "; getTurnOrder(numofPlayers);cout << endl;
			cout << "ENEMY TURN OVER (Continue)..";
			if (currentPlayer->getCurrentHP() <= 0)
			{
				currentMap->notify();
				cout << "YOU DIED! GAME ENDING" << endl;
				cout << "Press any key to continue..." << endl;
				mapCleared = true;
				keyPress();
				exit(0);
			}
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
		if(!enemydead)
		turnOrder.push(currentPlayersTurn);///<Push when player's turn is over
		else
		{

		}
	}



}

bool TurnManager::checkIfPlayerAtEnd()
{

	if (currentMap->getEndX() == currentMap->playerPositions[currentPlayer].first && currentMap->getEndY() == currentMap->playerPositions[currentPlayer].second)
	{
		cout << "You've reached the end!" << endl;
		cout << "Dungeon cleared! Press any key continue.....";
		keyPress();
		return true;

	}
	return false;

}