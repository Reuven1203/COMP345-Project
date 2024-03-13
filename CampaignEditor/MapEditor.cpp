//
// Created by z3p on 12/03/24.
//

#include "MapEditor.h"

MapEditor::MapEditor() = default;

int MapEditor::getUserInput() {
    std::cout << "Editing Commands:" << '\n';
    std::cout << " 1 - Set Start Position" << '\n';
    std::cout << " 2 - Set End Position" << '\n';
    std::cout << " 3 - Set Wall" << '\n';
    std::cout << " 4 - Save and Exit" << '\n';
    std::cout << " 5 - Load Map" << '\n';

    std::cout << "Enter command number: ";
    int op {};
    std::cin >> op;
    return op;
}

void MapEditor::setStart() {
    std::cout << "Start Position X: ";
    int startX {};
    std::cin >> startX;

    std::cout << "Start Position Y: ";
    int startY {};
    std::cin >> startY;

    map.setStart(startX, startY);
    std::cout << "Set Start Position (" << startX << ", " << startY << ")\n";
}

void MapEditor::setEnd() {
    std::cout << "End Position X: ";
    int endX {};
    std::cin >> endX;

    std::cout << "End Position Y: ";
    int endY {};
    std::cin >> endY;

    map.setEnd(endX, endY);
    std::cout << "Set End Position (" << endX << ", " << endY << ")\n";
}

void MapEditor::setWalls() {
    map.userInputWalls();
}

void MapEditor::loadMap() {
    std::cout << "Enter map file name to load: ";
    std::string file {};
    std::cin >> file;

    MapDirector director {};
    MapBuilder* testMapBuilder = new DefaultMapBuilder(file);

    director.setMapBuilder(testMapBuilder);
    director.constructMap();

    map = *director.getMap();
}

void MapEditor::saveMap() {
    std::cout << "Enter Map File Name (ex: castle): ";
    std::string file {};
    std::cin >> file;
    file += ".csv";
    save(file);
    fileName = file;
    std::cout << "Map saved as " << file << '\n';
}

void MapEditor::save(std::string filename) {
    std::ofstream output{"../MapSaves/" + filename};
    if(!output) {
        std::cerr << "Can not save " << filename << ".\n";
        std::exit(1);
    }

    std::string sizeLine {
        "size," + std::to_string(map.getRowSize()) + "," + std::to_string(map.getColSize())
    };
    std::string startLine {
        "start," + std::to_string(map.getStartX()) + "," + std::to_string(map.getStartY())
    };
    std::string endLine {
        "end," + std::to_string(map.getEndX()) + "," + std::to_string(map.getEndY())
    };
    std::string wallLine {"wall,"};
    for (int i : map.getWalls())
        wallLine += std::to_string(i) + ',';


    output << sizeLine << '\n';
    output << startLine << '\n';
    output << endLine << '\n';
    output << wallLine << '\n';
}

/**
 * @brief Main map editing interface/loop.
 */
void MapEditor::run() {
    createNewMap();

    while(true) {
        map.printMap();
        int input {getUserInput()};
        switch(input) {
            case 1:
                setStart();
                break;
            case 2:
                setEnd();
                break;
            case 3:
                setWalls();
                break;
            case 4:
                saveMap();
                break;
            case 5:
                loadMap();
                break;
            default:
                std::cout << "Invalid command, try again.\n";
                break;
        }
        if (input == 4)
            break;
    }
}

void MapEditor::createNewMap() {
    std::cout << "Please enter map grid dimensions: " << '\n';

    std::cout << "Size X: ";
    int x {};
    std::cin >> x;

    std::cout << "Size Y: ";
    int y {};
    std::cin >> y;

    map = dungeonMap(x, y);
}

std::string MapEditor::getFileName() {
    return fileName;
}

dungeonMap MapEditor::getMap() {
    return map;
}