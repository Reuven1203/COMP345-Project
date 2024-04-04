/**
 * @author Julian D'Addario
 */

#include "MapEditor.h"

MapEditor::MapEditor() = default;

int MapEditor::getUserInput() {
    std::cout << "Map Editing Commands:" << '\n';
    std::cout << " 1 - Set Start Position" << '\n';
    std::cout << " 2 - Set End Position" << '\n';
    std::cout << " 3 - Set Wall" << '\n';
    std::cout << " 4 - Add Chest" << '\n';
    std::cout << " 5 - Save and Exit" << '\n';
    std::cout << " 6 - Load Map" << '\n';

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

    map->setStart(startY, startX);
    map->notify();
    std::cout << "Set Start Position (" << startX << ", " << startY << ")\n";
}

void MapEditor::setEnd() {
    std::cout << "End Position X: ";
    int endX {};
    std::cin >> endX;

    std::cout << "End Position Y: ";
    int endY {};
    std::cin >> endY;

    map->setEnd(endY, endX);
    std::cout << "Set End Position (" << endX << ", " << endY << ")\n";
    map->notify();
}

void MapEditor::setWalls() {
    map->userInputWalls();
}

void MapEditor::setChest() {
    std::cout << "Chest Position X: ";
    int chestX {};
    std::cin >> chestX;

    std::cout << "Chest Position Y: ";
    int chestY {};
    std::cin >> chestY;

    std::cout << "Number of Items in Chest (recommended 1-3): ";
    int numItems {};
    std::cin >> numItems;

    container* chest { new container(numItems) };
    map->setChest(chest, chestY, chestX);
    map->notify();
}

void MapEditor::loadMap() {
    std::cout << "Enter map file name to load: ";
    std::string file {};
    std::cin >> file;

    MapDirector director {};
    MapBuilder* mapBuilder = new DefaultMapBuilder(file);

    director.setMapBuilder(mapBuilder);
    director.constructMap();

    map = director.getMap();
    observer = new MapObserver(map);
    map->notify();
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

void MapEditor::save(const std::string& filename) {
    std::ofstream output{"../MapSaves/" + filename};
    if(!output) {
        std::cerr << "Can not save " << filename << ".\n";
        std::exit(1);
    }

    std::string sizeLine {
        "size," + std::to_string(map->getRowSize()) + "," + std::to_string(map->getColSize())
    };
    std::string startLine {
        "start," + std::to_string(map->getStartX()) + "," + std::to_string(map->getStartY())
    };
    std::string endLine {
        "end," + std::to_string(map->getEndX()) + "," + std::to_string(map->getEndY())
    };
    std::string wallLine {"wall,"};
    for (int i : map->getWalls())
        wallLine += std::to_string(i) + ',';
    std::string chestLine {"chest,"};
    for(int i : map->getChests())
        chestLine += std::to_string(i) + ',';


    output << sizeLine << '\n';
    output << startLine << '\n';
    output << endLine << '\n';
    output << wallLine << '\n';
    output << chestLine << '\n';
}

void MapEditor::edit() {
//    map.attach(&mo);
    while(true) {
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
                setChest();
                break;
            case 5:
                saveMap();
                break;
            case 6:
                loadMap();
                break;
            default:
                std::cout << "Invalid command, try again.\n";
                break;
        }
        if (input == 5)
            break;
    }
}

/**
 * @brief Main map editing interface/loop.
 */
void MapEditor::run() {
    createNewMap();
    edit();

}

void MapEditor::createNewMap() {
    std::cout << "Please enter map grid dimensions: " << '\n';

    std::cout << "Size X: ";
    int x {};
    std::cin >> x;

    std::cout << "Size Y: ";
    int y {};
    std::cin >> y;
    map = new dungeonMap(y, x);
    observer = new MapObserver(map);
    //map->attach(observer);
    map->notify();
}

std::string MapEditor::getFileName() {
    return fileName;
}

dungeonMap* MapEditor::getMap() {
    return map;
}

void MapEditor::setMap(dungeonMap* m) {
    map = m;
}
