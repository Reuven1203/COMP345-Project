//
// Created by Reuven Ostrofsky on 2024-03-19.
//

#include "HumanPlayerStrategy.h"
#include "../FriendlyStrategy/FriendlyStrategy.h"
#include "../AggressorStrategy/AggressorStrategy.h"
#include "../Utils/utils.h"

void HumanPlayerStrategy::move(Character* player, dungeonMap& map) {
	int ch = 0;
	while (ch != ENTER)
	{

		cout << "Use arrow keys to move Player(P) (Enter to quit)..." << endl;
		cout << "Press 1 to open inventory" << endl;
		// Get the key pressed by the user (non-blocking call
		ch = keyPress();
		switch (ch) {
		case KEY_UP: // UP arrow key
			map.movePlayer(player, 1);
			break;
		case KEY_DOWN: // DOWN arrow key
			map.movePlayer(player, 2);
			break;
		case KEY_LEFT: // LEFT arrow key
			map.movePlayer(player, 3);
			break;
		case KEY_RIGHT: // RIGHT arrow key
			map.movePlayer(player, 4);
			break;
		case ONE_KEY: {
			openInventory(player);
			map.notify();
			break;
		}
		default: // Any other key pressed
			// Handle other keys or do nothing
			break;
		}
	}
}

void HumanPlayerStrategy::attack(Character* source, Character* target) {

	int attackRoll = Dice::GetGlobal().roll("1d20") + source->getStat(Character::Stats::AB);
	if (attackRoll >= target->getStat(Character::Stats::AC)) {
		int damage = Dice::GetGlobal().roll("1d6") + source->getStat(Character::Stats::DB);
		target->setCurrentHP(target->getCurrentHP() - damage);
	}
	else {
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

	while (!doneOpening)
	{

		clearScreen();

		cout << "--------INVENTORY--------" << endl;
		player->printInventory();


		cout << "-------------------------" << endl;
		cout << "Menu: 1.Equip Item | 2.Unequip Item | 3.Check Current Stats | -1.Exit " << endl;
		cin >> choice;
		switch (choice)
		{
		case -1:
			doneOpening = true;
			break;
		case 1:
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
					Item& itemToEquip = player->getInventory().retrieveItem(itemChoice);



					if (!(player->isItemEquipped(itemToEquip))) //If an item doesn't exists in that slot, equip itemToEquip
					{
						itemToEquip.setAsEquipped();
						cout << "-------------BEFORE---------------" << endl;
						player->showCharacterStats();
						player->equip(itemToEquip);

						cout << "\n\n" << "-------------AFTER-----------------" << endl;

						player->showCharacterStats();




						cout << "Press any key to continue..." << endl;
						keyPress();
					}
					else {
						cout << "You already have a(n) " << itemToEquip.getEquipType() << " equipped." << endl;
						cout << "Press any key to continue..." << endl;
						keyPress();
					}
				}
			}
			break;
		}
		case 2:
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
				}
				else if (player->getInventory().retrieveItem(itemChoice).isEquipped()) {  ///<If The item we want to get is equipped proceed to unequip
					Item& itemToEquip = player->getInventory().retrieveItem(itemChoice);





					itemToEquip.setAsUnequipped();
					cout << "-------------BEFORE---------------" << endl;
					player->showCharacterStats();
					player->unequip(itemToEquip);

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


		case 3:
		{
			player->showCharacterStats();
			cout << "Press any key to continue..." << endl;
			keyPress();
			break;
		}
		default:
		{
			break;
		}
		}

	}


}