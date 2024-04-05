//
// Created by Reuven Ostrofsky on 2024-01-30.
//

#include "Character.h"

#include <utility>
#include "../Dice/Dice.h"
#include "../Strategy/CharacterStrategy/CharacterStrategy.h"
#include "../Item/ItemDecorator.h"
#include "../Item/ItemDecorator.h"
#include "../Item/Weapon.h"
#include "../Item/Helmet.h"
#include "../Item/Shield.h"
#include "../Item/Armor.h"
#include "../Item/Ring.h"
#include "../Item/Belt.h"
#include "../Item/Boots.h"
#include "../Item/UnequipItem.h"



Character::Character(std::string name, int level) : name(std::move(name)),inventory(){
	if (level < 1) {
		this->level = 1;
	}
	else if (level > 20) {
		this->level = 20;
	}
	else {
		this->level = level;
	}


	//    generateAbilityScores();
	//    calculateAbilityModifiers();
	//    stats[HP] = initializeHitPoints();
	//    stats[PB] = initializeProficiencyBonus();
	//    stats[AC] = 10 + getAbilityModifier(Dexterity);
	//    stats[AB] = getAbilityModifier(Strength) + stats[PB];
	//    stats[DB] = getAbilityModifier(Strength) + 1;


}

Character::Character(std::string name, int level, const int abilityScores[6], int maxHp, int currentHp):inventory() {
	this->name = std::move(name);
	if (level < 1) {
		this->level = 1;
	}
	else if (level > 20) {
		this->level = 20;
	}
	else {
		this->level = level;
	}
	for (int i = 0; i < 6; i++) {
		abilityScore[i] = abilityScores[i];
	}
	this->currentHP = currentHp;
	calculateAbilityModifiers();
	stats[HP] = maxHp;
	stats[PB] = initializeProficiencyBonus();
	stats[AC] = 10 + getAbilityModifier(Dexterity);
	stats[AB] = getAbilityModifier(Strength) + stats[PB];
	stats[DB] = getAbilityModifier(Strength) + 1;

}

Character::Character(std::string name, int level, const int* abilityScores, int maxHp, int currentHp,
	std::map<Item::ItemType, Item> wornItems):inventory() {

	this->name = std::move(name);
	if (level < 1) {
		this->level = 1;
	}
	else if (level > 20) {
		this->level = 20;
	}
	else {
		this->level = level;
	}
	for (int i = 0; i < 6; i++) {
		abilityScore[i] = abilityScores[i];
	}
	this->currentHP = currentHp;
	calculateAbilityModifiers();
	stats[HP] = maxHp;
	stats[PB] = initializeProficiencyBonus();
	stats[AC] = 10 + getAbilityModifier(Dexterity);
	stats[AB] = getAbilityModifier(Strength) + stats[PB];
	stats[DB] = getAbilityModifier(Strength) + 1;
	this->wornItems = std::move(wornItems);
}

//Accessors

int Character::getLevel() const {
	return level;
}

int Character::getAbilityModifier(Ability ability) const {
	return abilityModifiers[ability];
}

std::string Character::getName() const {
	return name;
}

int Character::getStat(Stats stat) const {
	return this->stats.at(stat);
}

std::string Character::getClassName() const {
	return "Character";
}

int Character::getAbilityScore(Ability ability) const {
	return abilityScore[ability];
}

//Mutators

void Character::setName(const std::string& name) {
	Character::name = name;
	notify();
}


	void Character::equip(const Item & item) {
	
		wornItems[item.equipType] = item;
		
		calculateAbilityScores(item);
		notify();
	}

void Character::unequip(const Item& item) {
	wornItems.erase(item.equipType);
	reduceAbilityAfterUnequip(item);

	notify();
}

void Character::showWornItems() const {
	std::cout << getClassName() + " " << name << " is currently wearing the following items" << std::endl;
	std::cout << "---------------------------------------------\n" << std::endl;
	for (const auto& item : wornItems) {
		if (!(item.second.equipType == Item::ItemType::NONE))
		{
			item.second.printStats();
			std::cout << "---------------------------------------------\n" << std::endl;
		}
	}
}


void Character::calculateAbilityScores(const Item& item) {
	for (const auto& stat : item.itemOverall) {
		if (isAbility(stat.first) && stat.second != 0) {
			abilityScore[stringToEnum(stat.first)] += stat.second;
		}
		else {
			stats[stringToEnumStats(stat.first)] += stat.second;
		}

	}
}

void Character::reduceAbilityAfterUnequip(const Item& item) {
	for (const auto& stat : item.itemOverall) {
		if (isAbility(stat.first) && stat.second != 0) {
			abilityScore[stringToEnum(stat.first)] -= stat.second;
		}
		else {
			stats[stringToEnumStats(stat.first)] -= stat.second;
		}
	}
}

void Character::calculateAbilityModifiers() {
	for (int i = 0; i < abilityScore.size(); i++) {
		abilityModifiers[i] = floor((abilityScore[i] - 10) / 2);
	}
}

//Utility methods
void Character::generateAbilityScores() {
	Dice dice = Dice();
	//should soon be replaced with the dice class
	for (int& score : abilityScore) {
		score = dice.roll("4d6");
	}
}
void Character::showCharacterStats() const {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Class: " << getClassName() << std::endl;
	std::cout << "Level: " << level << std::endl;
	std::cout << "Strength: " << getSTR() << " Modifier: " << abilityModifiers[Strength] << std::endl;
	std::cout << "Dexterity: " << getDEX() << " Modifier: " << abilityModifiers[Dexterity] << std::endl;
	std::cout << "Constitution: " << getCON() << " Modifier: " << abilityModifiers[Constitution] << std::endl;
	std::cout << "Intelligence: " << getINT() << " Modifier: " << abilityModifiers[Intelligence] << std::endl;
	std::cout << "Wisdom: " << getWIS() << " Modifier: " << abilityModifiers[Wisdom] << std::endl;
	std::cout << "Charisma: " << getCHA() << " Modifier: " << abilityModifiers[Charisma] << std::endl;
	std::cout << "Hit Points: " << getStat(HP) << std::endl;
	std::cout << "Proficiency Bonus: " << getStat(PB) << std::endl;
	std::cout << "Armor Class: " << getStat(AC) << std::endl;
	std::cout << "Attack Bonus: " << getStat(AB) << std::endl;
	std::cout << "Damage Bonus: " << getStat(DB) << std::endl;
	std::cout << "____________________________________________________" << std::endl;

}

int Character::initializeHitPoints() {
	Dice dice = Dice();
	int baseHP = getDieType() + getAbilityModifier(Constitution);
	std::string levelString = std::to_string(level - 1);
	return baseHP + dice.roll(levelString + 'd' + std::to_string(getDieType()) + '+' + std::to_string(getAbilityModifier(Constitution) * (level - 1)));
}
int Character::initializeProficiencyBonus() const {
	if (level < 5) {
		return 2;
	}
	else if (level < 9) {
		return 3;
	}
	else if (level < 13) {
		return 4;
	}
	else if (level < 17) {
		return 5;
	}
	else {
		return 6;
	}
}





bool Character::isItemEquipped(const Item& item) {
	
	
	return wornItems.find(item.equipType) != wornItems.end();

}




bool Character::isAbility(const string& ability) {
	return ability == "Strength" || ability == "Dexterity" || ability == "Constitution" || ability == "Intelligence" || ability == "Wisdom" || ability == "Charisma";
}

Character::Ability Character::stringToEnum(const string& str) {
	if (str == "Strength") {
		return Strength;
	}
	else if (str == "Dexterity") {
		return Dexterity;
	}
	else if (str == "Constitution") {
		return Constitution;
	}
	else if (str == "Intelligence") {
		return Intelligence;
	}
	else if (str == "Wisdom") {
		return Wisdom;
	}
	else if (str == "Charisma") {
		return Charisma;
	}
	else {
		throw std::invalid_argument("Invalid ability");
	}
}

Character::Stats Character::stringToEnumStats(const string& str) {
	if (str == "HP") {
		return HP;
	}
	else if (str == "PB") {
		return PB;
	}
	else if (str == "ArmorClass") {
		return AC;
	}
	else if (str == "AttackBonus") {
		return AB;
	}
	else if (str == "DamageBonus") {
		return DB;
	}
	else {
		throw std::invalid_argument("Invalid stat");
	}
}

void Character::levelUp() {
	Dice dice = Dice();
	level++;
	stats[HP] += dice.roll("1d10") + getAbilityModifier(Constitution);
	stats[AB]++;
	notify();
}

void Character::move(dungeonMap& map) {
	strategy->move(this, map);
}
void Character::setStrategy(CharacterStrategy* str) {
	this->strategy = str;
}

CharacterStrategy* Character::getStrategy() const {
	return strategy;
}

void Character::setCurrentHP(int hp) {
	this -> currentHP = hp;
	notify();
}

int Character::getCurrentHP() const {
	return currentHP;
}

void Character::attack(Character* target) {
	strategy->attack(this, target);

}

int Character::getSTR() const {
	return abilityScore[Strength];
}

int Character::getDEX() const {
	return abilityScore[Dexterity];
}

int Character::getCON() const {
	return abilityScore[Constitution];
}

int Character::getINT() const {
	return abilityScore[Intelligence];
}

int Character::getWIS() const {
	return abilityScore[Wisdom];
}

int Character::getCHA() const {
	return abilityScore[Charisma];
}

int Character::getATK() const {
	return stats.at(AB);
}

int Character::getDMG() const {
	return stats.at(DB);
}

int Character::getAC() const {
	return stats.at(AC);
}

bool Character::hasWeapon() const {
	return false;
}

bool Character::hasHelmet() const {
	return false;
}

bool Character::hasArmor() const {
	return false;
}

bool Character::hasShield() const {
	return false;
}

bool Character::hasRing() const {
	return false;
}

bool Character::hasBelt() const {
	return false;
}

bool Character::hasBoots() const {
	return false;
}



void Character::storeItem( Item item)
{
	inventory.storeItem(item);
}

void Character::printInventory()
{
	inventory.getItems();
}

container& Character::getInventory()
{
	return inventory;
}

bool Character::isDead() {
    if (currentHP <= 0) {
        return true;
    }else{
        return false;
    }
}

container Character::getWornItems() const {
    container wi;
    for (const auto& item : wornItems) {
        wi.storeItem(item.second);
    }
    return wi;
}

