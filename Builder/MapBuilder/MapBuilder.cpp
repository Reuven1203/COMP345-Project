/**
 * @author Julian D'Addario
 */

#include <fstream>
#include <unordered_map>
#include <sstream>
#include "MapBuilder.h"

MapInfo MapBuilder::getMapInfo(std::string filename) {
    std::ifstream file("../MapSaves/" + filename);
    std::unordered_map<std::string, std::vector<int>> info;
    std::unordered_map<std::string, Item> items;

    std::string line, data, playerName;

    while(std::getline(file, line)) {
        std::string datatype {""};

        std::stringstream ss(line);

        while(std::getline(ss, data, ',')) {
            if(datatype == "") {
                if (data == "size")
                    datatype = "size";
                else if (data == "start")
                    datatype = "start";
                else if (data == "end")
                    datatype = "end";
                else if (data == "wall")
                    datatype = "wall";
                else if (data == "chest")
                    datatype = "chest";
                else if (data == "player") {
                    datatype = "playerstats";
                    std::getline(ss, data, ',');
                    playerName = data;
                }
                else if (data == "playerloc")
                    datatype = "playerloc";
                else if (data == "helmet") {
                    Item helm = Item();
                    helm.setEquipType(Item::HELMET);
                    std::getline(ss, data, ',');
                    helm.setINT(std::stoi(data));
                    std::getline(ss, data, ',');
                    helm.setWIS(std::stoi(data));
                    std::getline(ss, data, ',');
                    helm.setAC(std::stoi(data));
                    items["helmet"] = helm;
                }
                else if (data == "armor") {
                    Item armor = Item();
                    armor.setEquipType(Item::ARMOR);
                    std::getline(ss, data, ',');
                    armor.setAC(std::stoi(data));
                    items["armor"] = armor;
                }
                else if (data == "shield") {
                    Item shield = Item();
                    shield.setEquipType(Item::SHIELD);
                    std::getline(ss, data, ',');
                    shield.setAC(std::stoi(data));
                    items["shield"] = shield;
                }
                else if (data == "ring") {
                    Item ring = Item();
                    ring.setEquipType(Item::RING);
                    std::getline(ss, data, ',');
                    ring.setAC(std::stoi(data));
                    std::getline(ss, data, ',');
                    ring.setSTR(std::stoi(data));
                    std::getline(ss, data, ',');
                    ring.setCON(std::stoi(data));
                    std::getline(ss, data, ',');
                    ring.setWIS(std::stoi(data));
                    std::getline(ss, data, ',');
                    ring.setCHA(std::stoi(data));
                    items["ring"] = ring;
                }
                else if (data == "belt") {
                    Item belt = Item();
                    belt.setEquipType(Item::BELT);
                    std::getline(ss, data, ',');
                    belt.setSTR(std::stoi(data));
                    std::getline(ss, data, ',');
                    belt.setCON(std::stoi(data));
                    items["belt"] = belt;
                }
                else if (data == "boots") {
                    Item boots = Item();
                    boots.setEquipType(Item::BOOTS);
                    std::getline(ss, data, ',');
                    boots.setAC(std::stoi(data));
                    std::getline(ss, data, ',');
                    boots.setDEX(std::stoi(data));
                    items["boots"] = boots;
                }
                else if (data == "weapon") {
                    Item weapon = Item();
                    weapon.setEquipType(Item::WEAPON);
                    std::getline(ss, data, ',');
                    weapon.setATKBONUS(std::stoi(data));
                    std::getline(ss, data, ',');
                    weapon.setDMGBonus(std::stoi(data));
                    items["weapon"] = weapon;
                }
                else {
                    std::cout << "Improper Save." << '\n';
                    std::exit(1);
                }
            }
            else
                info[datatype].push_back(std::stoi(data));
        }
    }

    auto *p = new Character("default", 1);

    if(info.find("playerloc") == info.end()) {
        info["playerloc"].push_back(-1);
    }

    if(info.find("playerstats") != info.end()) {
        int stats[6] = {
                info["playerstats"][1],
                info["playerstats"][2],
                info["playerstats"][3],
                info["playerstats"][4],
                info["playerstats"][5],
                info["playerstats"][6]
        };

        p = new Character(playerName, info["playerstats"][0], stats,
                                info["playerstats"][7], info["playerstats"][8]);

        for (auto &i: items) {
            p->equip(i.second);
        }

        p->calculateAbilityModifiers();
    }

    file.close();

    return MapInfo {
        info["size"],
        info["start"],
        info["end"],
        info["wall"],
        info["chest"],
        p,
        info["playerloc"]
    };
}