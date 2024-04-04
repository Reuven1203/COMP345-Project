/**
 * @file ItemEditor.cpp
 * @brief Definitions of functions of ItemEditor class
 * @author Julian D'Addario
 */

#include "ItemEditor.h"

ItemEditor::ItemEditor() = default;

// Prompt user for ability bonus of item, flexible for any ability type
int promptBonus(const std::string& ability) {
    std::cout << "Enter " << ability << " bonus (between 1-5): ";
    int bonus { };
    std::cin >> bonus;

    if(bonus < 1)
        bonus = 1;
    else if(bonus > 5)
        bonus = 5;

    if(cin.fail()) {
        cin.clear();
        cin.ignore(INT16_MAX, '\n');
        bonus = 1;
    }

    return bonus;
}

// Prompt user for specific ability type, all call promptBonus()
int promptSTR() { return promptBonus("strength"); }
int promptCON() { return promptBonus("constitution"); }
int promptINT() { return promptBonus("intelligence"); }
int promptWIS() { return promptBonus("wisdom"); }
int promptCHA() { return promptBonus("charisma"); }
int promptDEX() { return promptBonus("dexterity"); }
int promptAC() { return promptBonus("armor class"); }
int promptATKBONUS() { return promptBonus("attack bonus"); }
int promptDMGBONUS() { return promptBonus("damage bonus"); }

void ItemEditor::createHelmet() {
    item = Item(Item::ItemType::HELMET);

    int intelligence { promptINT() };
    item.setINT(intelligence);

    int wisdom { promptWIS() };
    item.setWIS(wisdom);

    int armorClass { promptAC() };
    item.setAC(armorClass);
}

void ItemEditor::createArmor() {
    item = Item(Item::ItemType::ARMOR);

    int armorClass { promptAC() };
    item.setAC(armorClass);
}

void ItemEditor::createShield() {
    item = Item(Item::ItemType::SHIELD);

    int armorClass { promptAC() };
    item.setAC(armorClass);
}

void ItemEditor::createRing() {
    item = Item(Item::ItemType::RING);

    int armorClass { promptAC() };
    item.setAC(armorClass);

    int strength { promptSTR() };
    item.setSTR(strength);

    int constitution { promptCON() };
    item.setCON(constitution);

    int wisdom { promptWIS() };
    item.setWIS(wisdom);

    int charisma { promptCHA() };
    item.setCHA(charisma);
}

void ItemEditor::createBelt() {
    item = Item(Item::ItemType::BELT);

    int constitution { promptCON() };
    item.setCON(constitution);

    int strength { promptSTR() };
    item.setSTR(strength);
}

void ItemEditor::createBoots() {
    item = Item(Item::ItemType::BOOTS);

    int armorClass { promptAC() };
    item.setAC(armorClass);

    int dexterity { promptDEX() };
    item.setDEX(dexterity);
}

void ItemEditor::createWeapon() {
    item = Item(Item::ItemType::WEAPON);

    int atkBonus { promptATKBONUS() };
    item.setATKBONUS(atkBonus);

    int dmgBonus { promptDMGBONUS() };
    item.setDMGBonus(dmgBonus);
}

void ItemEditor::createNewItem() {
    std::cout << "Creating new item!\n";
    int typeNum { 0 };
    while(typeNum < 1 || typeNum > 7) {
        std::cout << "Creatable Item Types:\n";
        std::cout << "  1 - Helmet\n";
        std::cout << "  2 - Armor\n";
        std::cout << "  3 - Shield\n";
        std::cout << "  4 - Ring\n";
        std::cout << "  5 - Belt\n";
        std::cout << "  6 - Boots\n";
        std::cout << "  7 - Weapon\n";
        std::cout << "Number of type to create: ";
        std::cin >> typeNum;
        if (typeNum < 1 || typeNum > 7) {
            std::cout << "Error, please enter integer value associated with the above item types.\n";
            typeNum = 0;
            cin.clear();
            cin.ignore(INT16_MAX, '\n');
        }
    }

    switch(typeNum) {
        case 1:
            createHelmet();
            break;
        case 2:
            createArmor();
            break;
        case 3:
            createShield();
            break;
        case 4:
            createRing();
            break;
        case 5:
            createBelt();
            break;
        case 6:
            createBoots();
            break;
        case 7:
            createWeapon();
            break;
        default:
            std::cerr << "ItemEditor::createNewItem() generation error.\n";
            std::exit(1);
    }
}

void ItemEditor::saveItem() {
    std::cout << "Enter Item File Name (ex: power_ring): ";
    std::string file {};
    std::cin >> file;
    file += ".csv";
    save(file);
    fileName = file;
    std::cout << "Item saved as " << file << '\n';
}

void ItemEditor::save(std::string filename) {
    std::ofstream output("../ItemSaves/" + filename);
    if(!output) {
        std::cerr << "Can not save " << filename << ".\n";
        std::exit(1);
    }

    output << item.getEquipType() << '\n';
    for(auto const &stat:item.itemOverall) {
        output << stat.first << ',' << stat.second << '\n';
    }
}

void ItemEditor::run() {
    createNewItem();
    saveItem();
}