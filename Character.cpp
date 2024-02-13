//
// Created by Reuven Ostrofsky on 2024-01-30.
//

#include "Character.h"
#include "Dice.h"





Character::Character(std::string name,int level): name(std::move(name)){
    if(level < 1) {
        this->level = 1;
    } else if(level > 20) {
        this->level = 20;
    }else {
        this->level = level;
    }
    generateAbilityScores();
    calculateAbilityModifiers();
    stats[HP] = initializeHitPoints();
    stats[PB] = initializeProficiencyBonus();
    stats[AC] = 10 + getAbilityModifier(Dexterity);
    stats[AB] = getAbilityModifier(Strength) + stats[PB];
    stats[DB] = getAbilityModifier(Strength) + 1;


}



int Character::getLevel() const {
    return level;
}

void Character::equip(const Item& item) {
    wornItems[item.equipType] = item;
    calculateAbilityScores();
}

void Character::unequip(const Item& item) {
    wornItems.erase(item.equipType);
    calculateAbilityScores();
}

void Character::generateAbilityScores() {
    Dice dice = Dice();
    //should soon be replaced with the dice class
    for(int& score : abilityScore) {
        score = dice.roll("4d6");
    }
}

int Character::getAbilityScore(Ability ability) const{
    return abilityScore[ability];
}

void Character::calculateAbilityModifiers() {
    for(int i = 0; i < abilityScore.size(); i++) {
        abilityModifiers[i] = floor((abilityScore[i] - 10) / 2);
    }
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



void Character::showCharacterStats() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Class: " << getClassName() << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Strength: " << abilityScore[Strength] << " Modifier: " << abilityModifiers[Strength] << std::endl;
    std::cout << "Dexterity: " << abilityScore[Dexterity] << " Modifier: " << abilityModifiers[Dexterity] << std::endl;
    std::cout << "Constitution: " << abilityScore[Constitution] << " Modifier: " << abilityModifiers[Constitution] << std::endl;
    std::cout << "Intelligence: " << abilityScore[Intelligence] << " Modifier: " << abilityModifiers[Intelligence] << std::endl;
    std::cout << "Wisdom: " << abilityScore[Wisdom] << " Modifier: " << abilityModifiers[Wisdom] << std::endl;
    std::cout << "Charisma: " << abilityScore[Charisma] << " Modifier: " << abilityModifiers[Charisma] << std::endl;
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
    std::string levelString = std::to_string(level-1);
    return baseHP + dice.roll(levelString + 'd' + std::to_string(getDieType())+ '+' + std::to_string(getAbilityModifier(Constitution) * (level-1)));
}

std::string Character::getClassName() const {
    return "Character";
}

int Character::initializeProficiencyBonus() const {
    if(level < 5) {
        return 2;
    } else if(level < 9) {
        return 3;
    } else if(level < 13) {
        return 4;
    } else if(level < 17) {
        return 5;
    } else {
        return 6;
    }
}

void Character::showWornItems() const {
    std::cout << getClassName() + " " <<name << " is currently wearing the following items" << std::endl;
    std::cout << "---------------------------------------------\n" << std::endl;
    for(const auto& item : wornItems) {
         item.second.printStats();
        std::cout << "---------------------------------------------\n" << std::endl;
    }


}

void Character::calculateAbilityScores() {
    for (const auto &item: wornItems) {
        for (const auto &stat: item.second.itemOverall) {
            if(isAbility(stat.first) && stat.second != 0){
                abilityScore[stringToEnum(stat.first)] += stat.second;
            }else{
                stats[stringToEnumStats(stat.first)] += stat.second;
            }

        }
    }
}

 bool Character::isAbility(const string &ability) {
    return ability == "Strength" || ability == "Dexterity" || ability == "Constitution" || ability == "Intelligence" || ability == "Wisdom" || ability == "Charisma";
}

Character::Ability Character::stringToEnum(const string &str) {
    if(str == "Strength") {
        return Strength;
    } else if(str == "Dexterity") {
        return Dexterity;
    } else if(str == "Constitution") {
        return Constitution;
    } else if(str == "Intelligence") {
        return Intelligence;
    } else if(str == "Wisdom") {
        return Wisdom;
    } else if(str == "Charisma") {
        return Charisma;
    } else {
        throw std::invalid_argument("Invalid ability");
    }
}

Character::Stats Character::stringToEnumStats(const string &str) {
    if(str == "HP") {
        return HP;
    } else if(str == "PB") {
        return PB;
    } else if(str == "ArmorClass") {
        return AC;
    } else if(str == "AttackBonus") {
        return AB;
    } else if(str == "DamageBonus") {
        return DB;
    } else {
        throw std::invalid_argument("Invalid stat");
    }
}



