//
// Created by Reuven Ostrofsky on 2024-03-09.
//

using namespace std;

#include "./Character/Character.h"
#include "./Character/Fighter.h"
#include "./Observer/CharacterObserver/CharacterDisplay.h"
#include "./Item/Item.h"

int main() {

    Character fighter("Reuven", 6);
    CharacterDisplay display(&fighter);
    fighter.attach(&display);

    cout << "Fighter's stats" << endl;
    fighter.showCharacterStats();
    cout << "-------------------\n\n" << endl;

    Item sword(Item::ItemType::WEAPON);
    cout << "Equipping sword" << endl;
    fighter.equip(sword);

    Item shield(Item::ItemType::SHIELD);
    cout << "Equipping shield" << endl;
    fighter.equip(shield);

    fighter.unequip(sword);




    return 0;
}
