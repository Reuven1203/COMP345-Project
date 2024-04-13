//
// Created by Reuven Ostrofsky on 2024-02-07.
//

#include "Fighter.h"

#include <utility>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "../Dice/Dice.h"


Fighter::Fighter(std::string name, int level, FighterType type) : Character(std::move(name), level) {
    fighterType = type;
}

Fighter::Fighter(std::string fileName) {
    load(fileName);
}

std::string Fighter::getClassName() const {
    return "Fighter";
}



Fighter::FighterType Fighter::getFighterType() const {
    return fighterType;
}

std::string Fighter::FighterTypeEnumToString(FighterType type) {
    switch (type) {
        case BULLY:
            return "Bully";
        case NIMBLE:
            return "Nimble";
        case TANK:
            return "Tank";
    }
}

void Fighter::setAbilityScore(Character::Ability ability, int score) {
    this->abilityScore[ability] = score;
}

void Fighter::load(std::string fileName) {
    std::ifstream file("../CharacterSaves/" + fileName);

    std::string line, data;

    while(std::getline(file, line)) {
        std::stringstream ss(line);

        std::string datatype {};

        while(std::getline(ss, data, ',')) {
            if(datatype.empty()) {
                if(data == "name") {
                    std::getline(ss, data, ',');
                    setName(data);
                }
                else if(data == "classinfo") {
                    std::getline(ss, data, ',');
                    if(data == "Tank")
                        fighterType = FighterType::TANK;
                    else if(data == "Nimble")
                        fighterType = FighterType::NIMBLE;
                    else if(data == "Bully")
                        fighterType = FighterType::BULLY;

                    std::getline(ss, data, ',');
                    level = stoi(data);
                }
                else if(data == "stats") {
                    std::getline(ss, data, ',');
                    stats[HP] = stoi(data);
                    std::getline(ss, data, ',');
                    stats[AC] = stoi(data);
                    std::getline(ss, data, ',');
                    stats[AB] = stoi(data);
                    std::getline(ss, data, ',');
                    stats[DB] = stoi(data);
                }
                else if(data == "abilities") {
                    std::getline(ss, data, ',');
                    setAbilityScore(Character::Strength, stoi(data));
                    std::getline(ss, data, ',');
                    setAbilityScore(Character::Dexterity, stoi(data));
                    std::getline(ss, data, ',');
                    setAbilityScore(Character::Constitution, stoi(data));
                    std::getline(ss, data, ',');
                    setAbilityScore(Character::Intelligence, stoi(data));
                    std::getline(ss, data, ',');
                    setAbilityScore(Character::Wisdom, stoi(data));
                    std::getline(ss, data, ',');
                    setAbilityScore(Character::Charisma, stoi(data));
                }
            }
        }

        calculateAbilityModifiers();
        stats[PB] = initializeProficiencyBonus();
        stats[RA] = 1;
        setCurrentHP(stats[HP]);
    }
}








