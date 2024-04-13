/**
 * @file Item.cpp
 * @brief Implementation of the Item class for a game environment.
 *
 * This file provides the functionality to create items with different types and statistics for use within the game.
 * Each item can have modifiers that affect the character's attributes.
 *
 * @author Richard Mauricio
 * @date 2024-02-24
 */

#include <iostream>
#include <iomanip>
#include <map>
#include <sstream>
#include "Item.h"
#include "../Dice/Dice.h"
#include "../Character/Character.h"
#include"../Dice/Random.h"

using namespace std;

/**
 * @brief Default constructor that marks the item as null.
 */
Item::Item() {
	this->nullItem = true;
	this->equipType = NONE;
}

Item::Item(std::string fileName) {
    load(fileName);
}

/**
 * @brief Destructor for the Item class.
 */
Item::~Item() {}

/**
 * @brief Constructor that initializes an item of a specific type.
 * @param equip The type of the item being created.
 */
Item::Item(ItemType equip)
{
	this->nullItem = false;
	this->equipType = equip;
	this->armorType = ArmorType::NOTARMOR;
	this->weaponType = WeaponType::NOTWEAPON;
	setEquipStats();
}

/**
 * @brief Rolls a random stat modifier for the item.
 *
 * Uses a dice roll to generate a random number between 1 and 5 as the enchantment modifier.
 * If the roll is greater than 5, it re-rolls until a valid number is obtained.
 *
 * @return The enchantment modifier as an integer.
 */
int Item::rollStatMod()
{
	Dice dice;
	int em = dice.roll("1d6");
	while (em > 5)
	{
		em = dice.roll("1d6");
	}
	enchantmentModifier = em;
	return enchantmentModifier;
}

/**
 * @brief Retrieves the equipment type as a string.
 *
 * Converts the enum value of the equipment type to a human-readable string.
 *
 * @return The equipment type in string format.
 */
string Item::getEquipType() const
{
	switch (equipType)
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
string Item::getArmorTypeString()const
{
	switch (armorType)
	{
	case LIGHT:
		return "Light";
		break;
	case MEDIUM:
		return "Medium";
		break;
	case HEAVY:
		return "Heavy";
		break;
	}
}

string Item::getWeaponTypeString()const
{
	switch (weaponType)
	{
	case BOW:
		return "Bow";
		break;
	case MELEE:
		return "Sword";
		break;

	}
}
Item::ItemType Item::getType() const
{
	return this->equipType;
}

Item::ArmorType Item::getArmorType() const
{
	return this->armorType;
}

Item::WeaponType Item::getWeaponType()const
{
	return this->weaponType;
}
/**
 * @brief Getter for the Strength attribute modifier.
 * @return The strength modifier of the item.
 */
int Item::getSTR()
{
	return strength;
}
/**
 * @brief Getter for the Constitution attribute modifier.
 * @return The constitution modifier of the item.
 */
int Item::getCON()
{
	return constitution;
}

/**
 * @brief Getter for the Intelligence attribute modifier.
 * @return The intelligence modifier of the item.
 */
int Item::getINT()
{
	return intelligence;
}

/**
 * @brief Getter for the Wisdom attribute modifier.
 * @return The wisdom modifier of the item.
 */
int Item::getWIS()
{
	return wisdom;
}

/**
 * @brief Getter for the Charisma attribute modifier.
 * @return The charisma modifier of the item.
 */
int Item::getCHA()
{
	return charisma;
}

/**
 * @brief Getter for the Dexterity attribute modifier.
 * @return The dexterity modifier of the item.
 */
int Item::getDEX()
{
	return dexterity;
}

/**
 * @brief Getter for the Armor Class modifier.
 * @return The armor class modifier of the item.
 */
int Item::getAC()
{
	return armorClass;
}

/**
 * @brief Getter for the Attack Bonus modifier.
 * @return The attack bonus modifier of the item.
 */
int Item::getATKBONUS()
{
	return atkBonus;
}

/**
 * @brief Getter for the Damage Bonus modifier.
 * @return The damage bonus modifier of the item.
 */
int Item::getDMGBonus()
{
	return dmgBonus;
}

int Item::getRange()
{
	return range;
}
/**
 * @brief Checks if the item is a null item.
 * @return True if the item is null, false otherwise.
 */
bool Item::getIfNull()
{
	return nullItem;
}


/**
 * @brief Prints the statistics of the item.
 *
 * Outputs the type and all statistics of the item to standard output.
 */
void Item::printStats() const {

	cout << "Item type:  " << (!(this->armorType == Item::ArmorType::NOTARMOR) ? "(" + this->getArmorTypeString() + ") " : "") << (!(this->weaponType == Item::WeaponType::NOTWEAPON) ? "(" + this->getWeaponTypeString() + ") " : "") << getEquipType() << endl;
	for (auto const& stat : itemOverall)
	{
		cout << left << setw(20) << stat.first << ":" << setw(5) << right << stat.second << endl;
	}
	cout << endl;
}


/**
 * @brief Sets the equipment type of the item.
 * @param type The new type for the item.
 */
void Item::setEquipType(ItemType type)
{
	this->equipType = type;
}

void Item::setArmorType(ArmorType type)
{
	this->armorType = type;
}

void Item::setWeaponType(WeaponType type)
{
	this->weaponType = type;
}
/**
 * @brief Initializes or sets the statistics for the item based on its type.
 *
 * Each item type has different statistics associated with it, which are set by this method.
 */
void Item::setEquipStats()
{


	if (equipType == HELMET)
	{
		intelligence = rollStatMod();
		wisdom = rollStatMod();
		armorClass = rollStatMod();
		itemOverall["Intelligence"] = this->intelligence;
		itemOverall["Wisdom"] = this->wisdom;
		itemOverall["ArmorClass"] = this->armorClass;

	}
	if (equipType == ARMOR)
	{
		int armor = Random::random(1, 3);
		switch (armor)
		{
		case 1:
			setArmorType(LIGHT);
			break;
		case 2:
			setArmorType(MEDIUM);
			break;
		case 3:
			setArmorType(HEAVY);
			break;
		}
		armorClass = rollStatMod();
		itemOverall["ArmorClass"] = this->armorClass;
	}
	if (equipType == SHIELD)
	{
		armorClass = rollStatMod();
		itemOverall["ArmorClass"] = this->armorClass;
	}
	if (equipType == RING)
	{
		armorClass = rollStatMod();
		strength = rollStatMod();
		constitution = rollStatMod();
		wisdom = rollStatMod();
		charisma = rollStatMod();
		itemOverall["ArmorClass"] = this->armorClass;
		itemOverall["Charisma"] = this->charisma;
		itemOverall["Constitution"] = this->constitution;
		itemOverall["Wisdom"] = this->wisdom;
		itemOverall["Strength"] = this->strength;
	}
	if (equipType == BELT)
	{
		strength = rollStatMod();
		constitution = rollStatMod();
		itemOverall["Strength"] = this->strength;
		itemOverall["Constitution"] = this->constitution;
	}
	//    {
	//        constitution=rollStatMod();
	//        strength=rollStatMod();
	//        itemOverall["Strength"]=this->strength;
	//        itemOverall["Constitution"]=this->constitution;
	//
	//    }
	if (equipType == BOOTS)
	{
		armorClass = rollStatMod();
		dexterity = rollStatMod();
		itemOverall["ArmorClass"] = this->armorClass;
		itemOverall["Dexterity"] = this->dexterity;
	}
	if (equipType == WEAPON)
	{
		int randomWeaponType = Random::random(1, 2);
		int randomRange = Random::random(2, 3);
		switch (randomWeaponType)
		{
		case 1:
		{
			setWeaponType(MELEE);
			this->range = 1;
			
			break;
		}
		case 2:
		{
			setWeaponType(BOW);
			this->range = randomRange;
			
			break;
		}
		}
		atkBonus = rollStatMod();
		dmgBonus = rollStatMod();
		itemOverall["DamageBonus"] = this->dmgBonus;
		itemOverall["AttackBonus"] = this->atkBonus;
		itemOverall["Range"] = this->range;
		
	}
}

void Item::setSTR(int str) {
	strength = str;
	itemOverall["Strength"] = strength;
}

void Item::setCON(int con) {
	constitution = con;
	itemOverall["Constitution"] = constitution;
}

void Item::setINT(int intel) {
	intelligence = intel;
	itemOverall["Intelligence"] = intelligence;
}

void Item::setWIS(int wis) {
	wisdom = wis;
	itemOverall["Wisdom"] = wisdom;
}

void Item::setCHA(int cha) {
	charisma = cha;
	itemOverall["Charisma"] = charisma;
}

void Item::setDEX(int dex) {
	dexterity = dex;
	itemOverall["Dexterity"] = dexterity;
}

void Item::setAC(int ac) {
	armorClass = ac;
	itemOverall["ArmorClass"] = armorClass;
}

void Item::setATKBONUS(int atk) {
	atkBonus = atk;
	itemOverall["AttackBonus"] = atkBonus;
}

void Item::setDMGBonus(int dmg) {
	dmgBonus = dmg;
	itemOverall["DamageBonus"] = dmgBonus;
}

void Item::setAsEquipped()
{
	this->equipped = true;
}

void Item::setAsUnequipped()
{
	this->equipped = false;
}

bool Item::isEquipped()const
{
	return equipped;
}

void Item::load(std::string fileName) {
    std::ifstream file("../ItemSaves/" + fileName);

    std::string line, data;

    while(std::getline(file, line)) {
		std::stringstream ss(line);

        std::string datatype {};

        while(std::getline(ss, data, ',')) {
            if(datatype.empty()) {
                if (data == "Helmet") {
                    equipType = HELMET;
                    armorType = NOTARMOR;
                    weaponType = NOTWEAPON;
                }
                else if (data == "Armor") {
                    equipType = ARMOR;
                    weaponType = NOTWEAPON;
                }
                else if (data == "Shield") {
                    equipType = SHIELD;
                    armorType = NOTARMOR;
                    weaponType = NOTWEAPON;
                }
                else if (data == "Ring") {
                    equipType = RING;
                    armorType = NOTARMOR;
                    weaponType = NOTWEAPON;
                }
                else if (data == "Belt") {
                    equipType = BELT;
                    armorType = NOTARMOR;
                    weaponType = NOTWEAPON;
                }
                else if (data == "Boots") {
                    equipType = BOOTS;
                    armorType = NOTARMOR;
                    weaponType = NOTWEAPON;
                }
                else if (data == "Weapon") {
                    equipType = WEAPON;
                    armorType = NOTARMOR;
                    weaponType = MELEE;
                }
                else if (data == "Intelligence") {
                    std::getline(ss, data, ',');
                    intelligence = stoi(data);
                    itemOverall["Intelligence"] = intelligence;
                }
                else if (data == "Wisdom") {
                    std::getline(ss, data, ',');
                    wisdom = stoi(data);
                    itemOverall["Wisdom"] = wisdom;
                }
                else if (data == "ArmorClass") {
                    std::getline(ss, data, ',');
                    armorClass = stoi(data);
                    itemOverall["ArmorClass"] = armorClass;
                    if(equipType == ARMOR) {
                        if(armorClass <= 1)
                            armorType = LIGHT;
                        else if(armorClass <= 3)
                            armorType = MEDIUM;
                        else if(armorClass <= 5)
                            armorType = HEAVY;
                    }
                }
                else if (data == "Strength") {
                    std::getline(ss, data, ',');
                    strength = stoi(data);
                    itemOverall["Strength"] = strength;
                }
                else if (data == "Constitution") {
                    std::getline(ss, data, ',');
                    constitution = stoi(data);
                    itemOverall["Constitution"] = constitution;
                }
                else if (data == "Charisma") {
                    std::getline(ss, data, ',');
                    charisma = stoi(data);
                    itemOverall["Charisma"] = charisma;
                }
                else if (data == "Dexterity") {
                    std::getline(ss, data, ',');
                    dexterity = stoi(data);
                    itemOverall["Dexterity"] = dexterity;
                }
                else if (data == "AttackBonus") {
                    std::getline(ss, data, ',');
                    atkBonus = stoi(data);
                    itemOverall["AttackBonus"] = atkBonus;
                }
                else if (data == "DamageBonus") {
                    std::getline(ss, data, ',');
                    dmgBonus = stoi(data);
                    itemOverall["DamageBonus"] = dmgBonus;
                }
            }
        }
    }

    file.close();
}