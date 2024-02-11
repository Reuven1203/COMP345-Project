/* Author: Richard Mauricio
   ID:     40224398
*/

#include <iostream>
#include <iomanip>
#include <map>
#include "item.h"
#include "Dice.h"

using namespace std;

item::item() {}
item::~item() {}

item::item(ItemType equip)
{

    this->equipType = equip;
    setEquipStats();
}

//Roll a random number from 1-5 and return modifier
int item::rollStatMod()
{
    Dice dice;
    int em = dice.roll("1d6");
    while (em > 5)
    {
        em = dice.roll("1d6");
    }
   enchantmentModifier= em;
   return enchantmentModifier;
}

// Getters
string item::getEquipType()
{
   switch(equipType)
   {
       case HELMET:
         return "Helmet";
            break;
         case ARMOR:
            return "Armor";
                break;
            case SHIELD:
                return "Shield";
                    break;
                case RING:
                    return "Ring";
                        break;
                    case BELT:
                        return "Belt";
                            break;
                        case BOOTS:
                            return "Boots";
                                break;
                            case WEAPON:
                                return "Weapon";
                                    break;
   }
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
void item::setEquipType(ItemType type)
{
    this->equipType = type;
}


//Called when item is initialized
void item::setEquipStats()
{
         

    if (equipType == HELMET)
    {
        intelligence=rollStatMod();
        wisdom=rollStatMod();
        armorClass=rollStatMod();
        itemOverall["Intelligence"]=this->intelligence;
        itemOverall["Wisdom"]=this->wisdom;
        itemOverall["Armorclass"]=this->armorClass;
        
    }
    if (equipType == ARMOR)
    {
     armorClass=rollStatMod();
     itemOverall["Armorclass"]=this->armorClass;
    }
    if (equipType == SHIELD)
    {
     armorClass=rollStatMod();
     itemOverall["Armorclass"]=this->armorClass;
    }
    if (equipType == RING)
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
    if (equipType == BELT)
    {
        strength=rollStatMod();
        constitution=rollStatMod();
        itemOverall["Strength"]=this->strength;
        itemOverall["Constitution"]=this->constitution;
    }
    {
        constitution=rollStatMod();
        strength=rollStatMod();
        itemOverall["Strength"]=this->strength;
        itemOverall["Constitution"]=this->constitution;
     
    }
    if (equipType == BOOTS)
    {
        armorClass=rollStatMod();
        dexterity=rollStatMod();
        itemOverall["Armorclass"]=this->armorClass;
        itemOverall["Dexterity"]=this->dexterity;
    }
    if (equipType == WEAPON)
    {
      atkBonus=rollStatMod();
      dmgBonus=rollStatMod();
      itemOverall["DamageBonus"]=this->dmgBonus;
      itemOverall["AttackBonus"]=this->atkBonus;
    }
}