/* Author: Richard Mauricio
   ID:     40224398
*/

#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <vector>
#include <random>
#include <map>

using namespace std;
class item
{

public:
    enum ItemType
    {
        HELMET,
        ARMOR,
        SHIELD,
        RING,
        BELT,
        BOOTS,
        WEAPON
    };
    item();
    ~item();
    item(ItemType itemtype);

    int rollStatMod();

    // Setters
    void setEquipType(ItemType type);
    void setEquipStats();

    // Getters
    string getEquipType();
    int getSTR();
    int getCON();
    int getINT();
    int getWIS();
    int getCHA();
    int getDEX();
    int getAC();
    int getATKBONUS();
    int getDMGBonus();

    
    void printStats();
private:
    string itemName; // used if necessary in future
    ItemType equipType;            // helm,armor,shield,ring,belt,boots,weapon
    int enchantmentModifier = 0; //+1-+5 bonus rng based

    // Stats
    // Depending on equipType, the according stats will go up based on enchant modifier
    int strength = 0;
    int constitution = 0;
    int intelligence = 0;
    int wisdom = 0;
    int charisma = 0;
    int dexterity = 0;

    int armorClass = 0;

    int atkBonus = 0;
    int dmgBonus = 0;

    map<string, int> itemOverall;
};

#endif // ITEM_H