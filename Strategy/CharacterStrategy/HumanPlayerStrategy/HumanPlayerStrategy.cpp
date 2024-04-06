//
// Created by Reuven Ostrofsky on 2024-03-19.
//

#include "HumanPlayerStrategy.h"
#include "../Strategy/CharacterStrategy/CharacterStrategy.h"
#include "../FriendlyStrategy/FriendlyStrategy.h"
#include "../AggressorStrategy/AggressorStrategy.h"
#include "../Utils/utils.h"


void HumanPlayerStrategy::move(Character* player, dungeonMap& map) {
	int ch = 0;
	int counter = 0;
	while (counter != 1)

	{
		cout << "Use arrow keys to move Player(P) (Enter to quit)..." << endl;

		// Get the key pressed by the user (non-blocking call
		ch = keyPress();
		ch = keyPress(); ///<needs keyPress since we require the arrow key when it is released
		switch (ch) {
		case KEY_UP: // UP arrow key
		{
			map.movePlayer(player, 1);
			counter++;
			break;
		}
		case KEY_DOWN: // DOWN arrow key
		{
			map.movePlayer(player, 2);
			counter++;
			break;
		}
		case KEY_LEFT: // LEFT arrow key
		{
			map.movePlayer(player, 3);
			counter++;
			break;
		}
		case KEY_RIGHT: // RIGHT arrow key
		{
			map.movePlayer(player, 4);
			counter++;
			break;
		}
		case ENTER: {
			counter++;
			break;
		}
		default: // Any other key pressed
			cout << "Invalid Input." << endl;
			break;
		}
	}
}

CharacterStrategy::StrategyType HumanPlayerStrategy::getStrategyType() {
	return CharacterStrategy::PLAYER;
}


void HumanPlayerStrategy::attack(Character* source, Character* target) {

	int attackRoll = Dice::GetGlobal().roll("1d20") + source->getStat(Character::Stats::AB);

	cout << source->getName() << " attempted to attack " << target->getName() << "." << endl;
	cout << source->getName() << " Attack Roll = " << attackRoll << endl;
	if (attackRoll >= target->getStat(Character::Stats::AC)) {
		int damage = Dice::GetGlobal().roll("1d6") + source->getStat(Character::Stats::DB);
		cout << attackRoll << ">" << target->getStat(Character::Stats::AC) << endl;
		cout << "Attack Hit!" << endl;
		target->setCurrentHP(target->getCurrentHP() - damage);
		cout << damage << " damage to " << target->getName() << "." << endl;
		cout << target->getName() << " currently has " << target->getCurrentHP() << "HP" << endl;

		


		EventData event(EventData::EventType::AttackedResult, "Attack Hit!", source->getName(), target->getName(), 2, target->getCurrentHP(), damage);
		notifyGameObserver(event);
	}
	else {
		EventData event(EventData::EventType::AttackedResult, "Attack Missed!", source->getName(), target->getName(), 2, target->getCurrentHP(), 0);
		notifyGameObserver(event);
		cout << attackRoll << "<" << target->getStat(Character::Stats::AC) << endl;
		std::cout << "Attack missed!" << std::endl;
	}
	if (dynamic_cast<FriendlyStrategy*>(target->getStrategy()) == nullptr) {
		target->setStrategy(new AggressorStrategy());
	}
}

void HumanPlayerStrategy::openInventory(Character* player)
{
	bool doneOpening = false;
	int choice = 100;
	int ch = 0;
	while (!doneOpening)
	{

		clearScreen();

		cout << "--------INVENTORY--------" << endl;
		player->printInventory();


		cout << "-------------------------" << endl;
		cout << "Menu: 1.Equip Item | 2.Unequip Item | 3.Check Current Stats | 4.Check Item Stats | ENTER to Exit " << endl;
		
		ch = keyPress();
		switch (ch)
		{
		case ENTER:
			doneOpening = true;
			break;
		case ONE_KEY:
		{
			int itemChoice = -2;
			bool doneEquipping = false;
		
			while (!doneEquipping)
			{

				clearScreen();
				cout << "--------INVENTORY--------" << endl;

				player->printInventory();


				cout << "---CHOOSE ITEM TO EQUIP--" << endl;
				player->showWornItems();
				cout << "Choice (-1 to exit):  ";
				
				cin >> itemChoice;
				if (itemChoice == -1)
				{
					doneEquipping = true;
				}
				else if (itemChoice < 0 || itemChoice >= player->getInventory().getSize())
				{
					cout << "Invalid choice." << endl;
					cout << "Press any key to continue..." << endl;
					keyPress();
				}
				else {
					Item* itemToEquip = player->getInventory().retrieveItem(itemChoice);
					if (!(player->isItemEquipped(*itemToEquip))) //If an item doesn't exists in that slot, equip itemToEquip
					{
						itemToEquip->setAsEquipped();
						cout << "-------------BEFORE---------------" << endl;
						player->showCharacterStats();
						player->equip(*itemToEquip);

						cout << "\n\n" << "-------------AFTER-----------------" << endl;

						player->showCharacterStats();




						cout << "Press any key to continue..." << endl;
						keyPress();
					}
					else {
						cout << "You already have a(n) " << itemToEquip->getEquipType() << " equipped." << endl;
						cout << "Press any key to continue..." << endl;
						keyPress();
					}
				}

			}
			break;
		}
		case TWO_KEY:
		{
			int itemChoice = -2;
			bool doneUnequipping = false;
			while (!doneUnequipping)
			{

				clearScreen();
				cout << "--------INVENTORY--------" << endl;

				player->printInventory();


				cout << "--CHOOSE ITEM TO UNEQUIP--" << endl;
				player->showWornItems();
				cout << "Choice (-1 to exit):  ";

				cin >> itemChoice;
				if (itemChoice == -1)
				{
					doneUnequipping = true;
				}
				else if (itemChoice < 0 || itemChoice >= player->getInventory().getSize())
				{
					cout << "Invalid choice." << endl;
					cout << "Press any key to continue..." << endl;
					keyPress();
                    keyPress();
				}
				else if (player->getInventory().retrieveItem(itemChoice)->isEquipped()) {  ///<If The item we want to get is equipped proceed to unequip
					Item* itemToEquip = player->getInventory().retrieveItem(itemChoice);





					itemToEquip->setAsUnequipped();
					cout << "-------------BEFORE---------------" << endl;
					player->showCharacterStats();
					player->unequip(*itemToEquip);

					cout << "\n\n" << "-------------AFTER-----------------" << endl;

					player->showCharacterStats();




					cout << "Press any key to continue..." << endl;
					keyPress();
				}
				else {
					cout << "This item is not equipped." << endl;
					cout << "Press any key to continue..." << endl;
					keyPress();
				}

			}
			break;
		}


		case THREE_KEY:
		{
			player->showCharacterStats();
			cout << "Press any key to continue..." << endl;
			keyPress();
            keyPress();
			break;
		}
		case FOUR_KEY:
		{
			int itemChoice = -2;
			bool doneChecking = false;
			while (!doneChecking)
			{

				clearScreen();
				cout << "--------INVENTORY--------" << endl;

				player->printInventory();


				cout << "--CHOOSE ITEM TO INSPECT--" << endl;

				cout << "Choice (-1 to exit):  ";

				cin >> itemChoice;
				if (itemChoice == -1)
				{
					doneChecking = true;
				}
				else if (itemChoice < 0 || itemChoice >= player->getInventory().getSize())
				{
					cout << "Invalid choice." << endl;
					cout << "Press any key to continue..." << endl;
					keyPress();
                    keyPress();
				}
				else {
					player->getInventory().retrieveItem(itemChoice)->printStats();
					cout << "Press any key to continue..." << endl;
					keyPress();
                    keyPress();
				}
			}
			break;
		}
		default:
		{
			break;
		}
		}

	}


}