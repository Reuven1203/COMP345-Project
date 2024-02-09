/* Author: Richard Mauricio
   ID:     40224398
*/

#include <iostream>
#include <cstring>
#include <random>
#include <iomanip>
#include <map>
#include <chrono>
#include "item.h"

using namespace std;

item::item() {}
item::~item() {}

item::item(string equip):random(random_device{}())
{   
    //initializing seed for random rolls on stats
    
    dist=uniform_int_distribution<int>(1,5);

    string hold = equip;

    // Converting string to all lowercase in case uppercase is used
    for (int i = 0; i < hold.length(); i++)
    {
        hold[i] = tolower(hold[i]);
    }
    this->equipType = hold;
    setEquipStats();
}

//Roll a random number from 1-5 and return modifier
int item::rollStatMod()
{
   enchantmentModifier=dist(random);
   return enchantmentModifier;
}

// Getters
string item::getEquipType()
{
    return equipType;
}
int item::getSTR()
{
    return strength;
}
int item::getCON()
{
    return constitution;
}
int item::getINT()
{
    return intelligence;
}
int item::getWIS()
{
    return wisdom;
}
int item::getCHA()
{
    return charisma;
}
int item::getDEX()
{
    return dexterity;
}
int item::getAC()
{
    return armorClass;
}
int item::getATKBONUS()
{
    return atkBonus;
}
int item::getDMGBonus()
{
    return dmgBonus;
}


//Prints stats of item
void item::printStats()
{

    cout << "Item type:  " << getEquipType() << endl;
    for (auto const &stat:itemOverall)
    {
        cout<<left<<setw(14)<<stat.first<<":"<<right<<setw(5)<<stat.second<<setw(5)<<endl;
    }
    cout<<endl;
}

// Setters
void item::setEquipType(string type)
{
    this->equipType = type;
}


//Called when item is initialized
void item::setEquipStats()
{
         

    if (equipType == "helmet")
    {
        intelligence=rollStatMod();
        wisdom=rollStatMod();
        armorClass=rollStatMod();
        itemOverall["Intelligence"]=this->intelligence;
        itemOverall["Wisdom"]=this->wisdom;
        itemOverall["Armorclass"]=this->armorClass;
        
    }
    if (equipType == "armor")
    {
     armorClass=rollStatMod();
     itemOverall["Armorclass"]=this->armorClass;
    }
    if (equipType == "shield")
    {
         armorClass=rollStatMod();
     itemOverall["Armorclass"]=this->armorClass;
    }
    if (equipType == "ring")
    {
     armorClass=rollStatMod();
     strength=rollStatMod();
     constitution=rollStatMod();
     wisdom=rollStatMod();
     charisma=rollStatMod();
     itemOverall["Armorclass"]=this->armorClass;
     itemOverall["Charisma"]=this->charisma;
     itemOverall["Constitution"]=this->constitution;
     itemOverall["Wisdom"]=this->wisdom;
     itemOverall["Strength"]=this->strength;
    }
    if (equipType == "belt")
    {
        constitution=rollStatMod();
        strength=rollStatMod();
        itemOverall["Strength"]=this->strength;
        itemOverall["Constitution"]=this->constitution;
     
    }
    if (equipType == "boots")
    {
        armorClass=rollStatMod();
        dexterity=rollStatMod();
        itemOverall["Armorclass"]=this->armorClass;
        itemOverall["Dexterity"]=this->dexterity;
    }
    if (equipType == "weapon")
    {
      atkBonus=rollStatMod();
      dmgBonus=rollStatMod();
      itemOverall["DamageBonus"]=this->dmgBonus;
      itemOverall["AttackBonus"]=this->atkBonus;
    }
}