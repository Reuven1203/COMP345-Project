/* Author: Richard Mauricio
   ID:     40224398
*/

#ifndef ITEM_H
#define ITEM_H
#include <iostream>
using namespace std;
class item
{

public:
    item();
    ~item();
    item(string itemtype);

    // Setters
    void setEquipType(string type);
    void setEquipStats();
    // Getters
    void getStats();
    string getEquipType();

private:
    string itemName; // used if necessary in future

    string equipType;        // helm,armor,shield,ring,belt,boots,weapon
    int enchantmentModifier; //+1-+5 bonus rng based

    // Stats
    // Depending on equipType, the according stats will go up based on enchant modifier
    int strength;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;
    int dexterity;

    int armorClass;

    int atkBonus;
    int dmgBonus;
};

#endif //ITEM_H