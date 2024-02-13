/* Author: Richard Mauricio
   ID:     40224398
*/

#include <iostream>
#include <iomanip>
#include <map>
#include "Item.h"
#include "Dice.h"
#include "Character.h"

using namespace std;

Item::Item() {}
Item::~Item() {}

Item::Item(ItemType equip)
{

    this->equipType = equip;
    setEquipStats();
}

//Roll a random number from 1-5 and return modifier
int Item::rollStatMod()
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
string Item::getEquipType() const
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
int Item::getSTR()
{
    return strength;
}
int Item::getCON()
{
    return constitution;
}
int Item::getINT()
{
    return intelligence;
}
int Item::getWIS()
{
    return wisdom;
}
int Item::getCHA()
{
    return charisma;
}
int Item::getDEX()
{
    return dexterity;
}
int Item::getAC()
{
    return armorClass;
}
int Item::getATKBONUS()
{
    return atkBonus;
}
int Item::getDMGBonus()
{
    return dmgBonus;
}


//Prints stats of Item
void Item::printStats() const {

    cout << "Item type:  " << getEquipType() << endl;
    for (auto const &stat:itemOverall)
    {
        cout<<left<<setw(14)<<stat.first<<":"<<right<<setw(5)<<stat.second<<setw(5)<<endl;
    }
    cout<<endl;
}

// Setters
void Item::setEquipType(ItemType type)
{
    this->equipType = type;
}


//Called when Item is initialized
void Item::setEquipStats()
{
         

    if (equipType == HELMET)
    {
        intelligence=rollStatMod();
        wisdom=rollStatMod();
        armorClass=rollStatMod();
        itemOverall["Intelligence"]=this->intelligence;
        itemOverall["Wisdom"]=this->wisdom;
        itemOverall["ArmorClass"]=this->armorClass;
        
    }
    if (equipType == ARMOR)
    {
     armorClass=rollStatMod();
     itemOverall["ArmorClass"]=this->armorClass;
    }
    if (equipType == SHIELD)
    {
     armorClass=rollStatMod();
     itemOverall["ArmorClass"]=this->armorClass;
    }
    if (equipType == RING)
    {
     armorClass=rollStatMod();
     strength=rollStatMod();
     constitution=rollStatMod();
     wisdom=rollStatMod();
     charisma=rollStatMod();
     itemOverall["ArmorClass"]=this->armorClass;
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
        itemOverall["ArmorClass"]=this->armorClass;
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