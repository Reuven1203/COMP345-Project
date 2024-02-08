/* Author: Richard Mauricio
   ID:     40224398
*/

#include <iostream>
#include <cstring>
#include "item.h"
#include "Random.h"

using namespace Random;
using namespace std;

item::item(){}
item::~item(){}


item::item(string equip)
{
    string hold=equip;

    //Converting string to all lowercase in case uppercase is used
    for (int i=0;i<hold.length();i++)
    {
        hold[i]=tolower(hold[i]);
        
    }
    this->equipType=hold;
}


//Getters
string item::getEquipType()
{
    return equipType;
}
void item::getStats()
{
    cout<<"Armor Class:"<<armorClass<<endl;
    cout<<"Attack Bonus:"<<atkBonus<<endl;
    cout<<"Damage Bonus"<<dmgBonus<<endl;
    cout<<"Constitution:"<<constitution<<endl;
    cout<<"Strength:"<<strength<<endl;
    cout<<"Intelligence:"<<intelligence<<endl;
    cout<<"Wisdom:"<<wisdom<<endl;
    cout<<"Charisma:"<<charisma<<endl;
    cout<<"Dexterity:"<<dexterity<<endl;
    



}


//Setters
void item::setEquipType(string type)
{
    this->equipType=type;
}

void item::setEquipStats()
{

    if(equipType=="helmet")
    {
        intelligence=random(1,5);
        wisdom=random(1,5);
        armorClass=random(1,5);
    }
    if(equipType=="armor")
    {
        armorClass=random(1,5);
    }
    if(equipType=="shield")
    {
        armorClass=random(1,5);
    }
    if(equipType=="ring")
    {
        armorClass=random(1,5);
        strength=random(1,5);
        constitution=random(1,5);
        wisdom=random(1,5);
        charisma=random(1,5);
    }
    if(equipType=="belt")
    {
        constitution=random(1,5);
        strength=random(1,5);
    }
    if(equipType=="boots")
    {
        armorClass=random(1,5);
        dexterity=random(1,5);
    }
    if(equipType=="weapon")
    {
        atkBonus=random(1,5);
        dmgBonus=random(1,5);
    }
    
}