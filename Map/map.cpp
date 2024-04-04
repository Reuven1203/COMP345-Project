/**
 * @file map.cpp
 * @brief Implementation of the dungeonMap class for creating and managing a dungeon map.
 *
 * Provides functionalities to manipulate the dungeon map, including adding or removing walls,
 * setting start and end points, and managing player and chest locations within the map.
 *
 * @author Richard Mauricio
 * @date 2024-02-24
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "map.h"
#include "cell.h"
#include "../Utils/utils.h"
#include "../Strategy/CharacterStrategy/HumanPlayerStrategy/HumanPlayerStrategy.h"
#include "../Strategy/CharacterStrategy/AggressorStrategy/AggressorStrategy.h"
#include "../Strategy/CharacterStrategy/FriendlyStrategy/FriendlyStrategy.h"


using namespace std;

/**
 * @brief Constructor initializing the dungeon map with given dimensions.
 * @param x Number of rows in the dungeon.
 * @param y Number of columns in the dungeon.
 */
dungeonMap::dungeonMap(int x, int y) : rows(x), cols(y)
{
    dungeon.resize(rows, vector<cell>(cols, cell()));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            dungeon[i][j].setRowPos(i);
            dungeon[i][j].setColPos(j);
        }
    }
    EventData event(EventData::EventType::MapCreated, x, y);
    notifyGameObserver(event);
}

/**
 * @brief Places a chest in the specified location within the dungeon.
 * @param chest Pointer to the chest object.
 * @param x Row index for placing the chest.
 * @param y Column index for placing the chest.
 */
void dungeonMap::setChest(container* chest, int x, int y)
{
    if (dungeon[x][y].getCellType() == Nothing)
    {
        dungeon[x][y].setCellType(Chest);
        dungeon[x][y].setChest(chest);
        notify();
        EventData event(EventData(EventData::EventType::ChestPlaced, x, y));
        notifyGameObserver(event);
    }
    else
    {
        cout << "Invalid location for chest." << endl;
    }
}

/**
 * @brief Adds a wall to the specified location in the dungeon.
 * @param x Row index where the wall is to be added.
 * @param y Column index where the wall is to be added.
 */
void dungeonMap::setWall(int x, int y)
{
    if (dungeon[x][y].getCellType() == Nothing)
    {
        dungeon[x][y].setCellType(Wall);
        EventData event(EventData::EventType::WallPlaced, x, y);
        notifyGameObserver(event);
    }
    else
    {
        cout << "Invalid location for wall due to existing object." << endl;
    }
}

/**
 * @brief Removes a wall from the specified location in the dungeon.
 * @param x Row index from which the wall is to be removed.
 * @param y Column index from which the wall is to be removed.
 */
void dungeonMap::removeWall(int x, int y)
{
    if (dungeon[x][y].getCellType() == Wall)
    {
        dungeon[x][y].setCellType(Nothing);
        EventData event(EventData::EventType::WallRemoved, x, y);
        notifyGameObserver(event);
    }
    else
    {
        cout << "No wall exists here." << endl;
    }
}

/**
 * @brief Sets the player's location in the dungeon.
 * @param player Pointer to the player character.
 * @param x Row index for the player's location.
 * @param y Column index for the player's location.
 */
void dungeonMap::setPlayer(Character* player, int x, int y)
{
    //check if player exists in the dungeon, if so then move the player to that location
    if (playerPositions.find(player) != playerPositions.end())
    {
        int oldX = playerPositions[player].first;
        int oldY = playerPositions[player].second;
        dungeon[oldX][oldY].removeContent();
    }
    if (isValidRow(x) && isValidCol(y) && !wallDetect(x, y)) {
        dungeon[x][y].setCellType(Player);
        dungeon[x][y].setPlayer(player);
        playerPositions[player] = std::make_pair(x, y);
        notify();
        EventData event(EventData(EventData::EventType::PlayerPlaced, player->getName(), x, y));
        notifyGameObserver(event);

    }
    else
    {
        cout << "Invalid location for player." << endl;
    }
}

/**
 * @brief Validates if the specified row index is within the bounds of the dungeon.
 * @param row Row index to be validated.
 * @return True if the row index is within bounds, otherwise false.
 */
bool dungeonMap::isValidRow(int row) const
{
    return row >= 0 && row < rows;
}

/**
 * @brief Validates if the specified column index is within the bounds of the dungeon.
 * @param col Column index to be validated.
 * @return True if the column index is within bounds, otherwise false.
 */
bool dungeonMap::isValidCol(int col) const
{
    return col >= 0 && col < cols;
}

/**
 * @brief Validates if a location is valid for placing or removing objects.
 * @param row Row index of the location.
 * @param col Column index of the location.
 * @return True if the location is valid, otherwise false.
 */
bool dungeonMap::isValidLocation(int row, int col)
{
    if ((row == startX && col == startY) || (row == endX && col == endY))
    {
        cout << "Invalid location due to " << (isStart(&dungeon[row][col]) ? "Start" : "End") << " point." << endl;
        cout << "Press any key to continue....";
        keyPress();
        return false;
    }
    return true;
}

/**
 * @brief Interactive mode for the user to add or remove walls within the dungeon.
 */

void dungeonMap::userInputWalls()
{
    bool done = false;
    int wallCoordinateX, wallCoordinateY;
    cout << "Wall Generation Mode" << endl;
    int choice = 0;
    while (!done)
    {
        notify();
        cout << "Choose: 1. Add wall || 2. Remove Wall || 3. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case (1):
        {
            cout << "Choose where to insert wall(-1 to exit): " << endl;
            addWallChoice(&wallCoordinateX, &wallCoordinateY);
            if(isValidLocation(wallCoordinateX, wallCoordinateY))
                setWall(wallCoordinateX, wallCoordinateY);
           
            if(!isValid()){
                cout << "Invalid map, wall cannot be placed here." << endl;
                removeWall(wallCoordinateX, wallCoordinateY);
                cout << "Press any key to continue....";
                keyPress();
            }
            break;
        }
        case (2):
        {
            cout << "Input coordinates to remove wall (-1) to exit" << endl;
            removeWallChoice(&wallCoordinateX, &wallCoordinateY);

            
            break;
        }
        case (3):
        {
            done = true;
            break;
        }
        }
    }
}
/**
 * @brief Sets the start point of the dungeon.
 * @param x Row index of the start point.
 * @param y Column index of the start point.
 */
void dungeonMap::setStart(int x, int y)
{
    if (x >= rows || y >= cols || x < 0 || y < 0)
    {
        cout << "Start point is out of bounds.";
        exit(1);
    }
    this->startY = y;
    this->startX = x;
    EventData event(EventData(EventData::EventType::StartPointPlaced, x, y));
    notifyGameObserver(event);
 
    //this->start = &dungeon[startX][startY];
}
/**
 * @brief Sets the end point of the dungeon.
 * @param x Row index of the end point.
 * @param y Column index of the end point.
 */
void dungeonMap::setEnd(int x, int y)
{
    if (x >= rows || y >= cols || x < 0 || y < 0)
    {
        cout << "End point is out of bounds.";
        exit(1);
    }
    this->endX = x;
    this->endY = y;
    this->end = &dungeon[endX][endY];
    EventData event(EventData(EventData::EventType::EndPointPlaced, x, y));
    notifyGameObserver(event);
   
}
/**
 * @brief Retrieves the number of rows in the dungeon.
 * @return Number of rows.
 */
int dungeonMap::getRowSize() const
{
    return rows;
}
/**
 * @brief Retrieves the number of columns in the dungeon.
 * @return Number of columns.
 */
int dungeonMap::getColSize() const
{
    return cols;
}
/**
 * @brief Retrieves a cell from the dungeon.
 * @param row Row index of the cell.
 * @param col Column index of the cell.
 * @return The cell at the specified location.
 */
cell dungeonMap::getCell(int row, int col) const {
    return dungeon[row][col];
}
/**
 * @brief Returns the row index of the start point.
 * @return Row index of the start point.
 */
int dungeonMap::getStartX() const {
    return startX;
}
/**
 * @brief Returns the column index of the start point.
 * @return Column index of the start point.
 */
int dungeonMap::getStartY() const {
    return startY;
}
//void dungeonMap::setPlayerX(int x)
//{
//    playerX = x;
//}
//void dungeonMap::setPlayerY(int y)
//{
//    playerY = y;
//}
//int dungeonMap::getPlayerX() const {
//    return playerX;
//}
//int dungeonMap::getPlayerY() const {
//    return playerY;
//}
/*
*
*@brief Returns the end points
*
*/
int dungeonMap::getEndX()
{
    return endX;
}
int dungeonMap::getEndY()
{
    return endY;
}



/**
 * @brief Prints the current state of the dungeon map.
 */
void dungeonMap::printMap()
{
    int maxRowDigits = to_string(rows).length();
    int maxColDigits = to_string(cols).length();

    for (int row = 0; row < rows; row++)
    {
        cout << setw(maxColDigits) << row;
        char playerChar;
        for (int col = 0; col < cols; col++)
        {
            if(dungeon[row][col].getCellType() == Player){
                Character* player = dungeon[row][col].getPlayer();
                if(dynamic_cast<HumanPlayerStrategy*>(player->getStrategy()) != nullptr)
                {
                    playerChar = 'P';
                }
                else if(dynamic_cast<AggressorStrategy*>(player->getStrategy()) != nullptr)
                {
                    playerChar = 'A';
                }
                else if(dynamic_cast<FriendlyStrategy*>(player->getStrategy()) != nullptr)
                {
                    playerChar = 'F';
                }

            }
            if (row==startX && col==startY && dungeon[row][col].getCellType()==Player)
            {
                cout << "|  "
                     << "S/" << playerChar ;
                continue;
            }
            else if(isStart(&dungeon[row][col])||(row == startX && col == startY)){
                cout << "|  "
                    << "S  ";
                    continue;
            }
            else if(isEnd(&dungeon[row][col]))
            {
                cout << "|  "
                     << "E  ";
                continue;
            }
            switch (dungeon[row][col].getCellType())
            {
            case Nothing:
            {
                cout << "|  "
                     << "   ";
                break;
            }
            case Player:
            {
                cout << "|  "
                     << playerChar << "  ";
                break;
            }
            case Wall:
            {
                cout << "|  "
                     << "W  ";
                break;
            }
            case Chest:
            {
                cout << "|  "
                    << "C  ";
            }
            }
        }
        cout << "|" << endl;
    }

    for (int row = 0; row < cols; row++)
    {
        cout << setw(6) << row; // Matching the spacing for columns, adjust if necessary
    }
    cout << endl;
    // cout << "Legend:| S-Start | |E-End| | C-Character | |Ch-Chest| |O-Opponent| |D-Door| |W - Wall|";
}

/*
*@brief Validate's map to check if there is a valid path from start to end
*@retun True if the path exists, otherwise false.
*/

bool dungeonMap::dfs(int startX, int startY, int endX, int endY) {
    //dummy path
    std::vector<std::pair<int, int>> path;
   return dfs(startX, startY, endX, endY, path);
}

bool dungeonMap::dfs(int row, int col, int targetRow, int targetCol, std::vector<std::pair<int, int>>& path)
{
    if (row < 0 || col < 0 || row >= rows || col >= cols || dungeon[row][col].checkVisit() || dungeon[row][col].getCellType() == Wall )
    {
        return false;
    }
    if (row == targetRow && col == targetCol) {
        path.emplace_back(row, col);
        return true;
    }
    dungeon[row][col].setVisit();
    if (dfs(row + 1, col,targetRow, targetCol, path) ||
        dfs(row - 1, col, targetRow, targetCol, path) ||
        dfs(row, col + 1, targetRow, targetCol, path) ||
        dfs(row, col - 1, targetRow, targetCol, path))
    {
        path.emplace_back(row, col);
        return true;
    }
    return false;
}
/**
 * @brief Validates if there is a path from the start point to the end point in the dungeon.
 * @return True if such a path exists, otherwise false.
 */
bool dungeonMap::isValid()
{
    bool valid = dfs(startX, startY, endX, endY);
    clearCellVisit();
    return valid;
}

/**
 * @brief Clears the 'visited' state of all cells in the dungeon.
 */
void dungeonMap::clearCellVisit()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            dungeon[i][j].clearVisit();
        }
    }
}
/**
 * @brief Checks if a specified cell is the start point.
 * @param cell Pointer to the cell to be checked.
 * @return True if the cell is the start point, otherwise false.
 */
bool dungeonMap::isStart(cell *cell) const {
    return cell->getColPos() == startY && cell->getRowPos() == startX;
}
/**
 * @brief Checks if a specified cell is the end point.
 * @param cell Pointer to the cell to be checked.
 * @return True if the cell is the end point, otherwise false.
 */
bool dungeonMap::isEnd(cell *cell) const {
    return cell->getColPos() == endY && cell->getRowPos() == endX;
}

/**
 * @brief Helper function to interactively add a wall to the dungeon.
 * @param x Pointer to store the row coordinate chosen by the user.
 * @param y Pointer to store the column coordinate chosen by the user.
 */
void dungeonMap::addWallChoice(int *x, int *y)
{
    cout << "Y coordinate: ";
    cin >> *x;
    if (!isValidRow(*x))
    {
        cout << "Invalid Y coordinate." << endl;
        return;
    }
    cout << "X coordinate: ";
    cin >> *y;
    if (!isValidCol(*y))
    {
        cout << "Invalid X coordinate." << endl;
        return;
    }
}

/**
 * @brief Checks if the specified cell in the dungeon map is a wall.
 *
 * This function examines the cell at the provided coordinates (x, y) and determines whether it is a wall.
 * The determination is based on the cell type, comparing it against the predefined Wall type.
 *
 * @param x The x-coordinate (row) of the cell to check within the dungeon map.
 * @param y The y-coordinate (column) of the cell to check within the dungeon map.
 *
 * @return bool True if the cell at the specified coordinates is a wall; otherwise, false.
 *
 * @pre The coordinates (x, y) must be within the bounds of the dungeon map.
 * @note This function does not perform bounds checking. Calling it with coordinates outside
 *       of the dungeon map may lead to undefined behavior. It is the caller's responsibility
 *       to ensure that the coordinates are valid before invoking this function.
 */
bool dungeonMap::wallDetect(int x, int y)
{
    if (dungeon[x][y].getCellType() == Wall)
        return true;

    else return false;
}

bool dungeonMap::chestDetect(int x, int y)
{
    if (dungeon[x][y].getCellType() == Chest)
        return true;
    else return false;
}

bool dungeonMap::playerDetect(int x, int y) {
    if (dungeon[x][y].getCellType() == Player)
        return true;
    else return false;

}

/**
 * @brief Helper function to interactively remove a wall from the dungeon.
 * @param x Pointer to store the row coordinate chosen by the user.
 * @param y Pointer to store the column coordinate chosen by the user.
 */
void dungeonMap::removeWallChoice(int *x, int *y) {
    cout << "Y coordinate: ";
    cin >> *x;
    if (!isValidRow(*x))
    {
        cout << "Invalid Y coordinate." << endl;
        cout << "Press any key to continue....";
        keyPress();
        return;
    }
    cout << "X coordinate: ";
    cin >> *y;
    if (!isValidCol(*y))
    {
        cout << "Invalid X coordinate." << endl;
        cout << "Press any key to continue....";
        keyPress();
        return;
    }
    removeWall(*x, *y);
}
/**
 * @brief Removes the content of a specified cell.
 * @param x Row index of the cell.
 * @param y Column index of the cell.
 */
void dungeonMap::removeCellContent(int x, int y) {
    dungeon[x][y].removeContent();
    notify();
}

/**
 * @brief Moves the player in the specified direction within the dungeon map.
 *
 * This function attempts to move the player to a new position based on the provided direction.
 * The movement is constrained by the dimensions of the dungeon and any walls that may exist.
 * If the movement is successful, the player's position is updated, and any necessary state changes
 * are made to the dungeon map to reflect the player's new location.
 *
 * @param direction An integer representing the direction of movement:
 *                  1 for up, 2 for down, 3 for left, 4 for right.
 *
 * @post If the movement is successful, the player's position in the dungeon is updated.
 *       If the movement is blocked by a wall or is outside the dungeon bounds, the player's position remains unchanged.
 *
 * The function checks if the new position is within the bounds of the dungeon and not blocked by a wall.
 * If either condition is not met, the function returns without moving the player.
 * Otherwise, the player is moved to the new location, and any game state updates are performed.
 */
 void dungeonMap::interactWithChest(Character* player, container *chestTemp){
    chestTemp->getItems();
    int size = chestTemp->getSize();
    cout << "-------------Item details--------------" << "\n\n";
    chestTemp->getItemStats();
    int choice;
    do{
    cout << "Select which item(number) to obtain: ";
    cin >> choice;
    if (choice == -1){
        return;
    }
    else if(choice < 0 || choice > size){
        cout << "Invalid choice, please try again." << endl;
    }
    }while(choice < 0 || choice > size);
    int newSize = chestTemp->getSize();
    if(newSize == 0){
        return;
    }
    player->equip(chestTemp->removeItemFromChest(choice));
    player->showWornItems();
    cout << "Press any key to continue...." << endl;
    keyPress();
    keyPress();
 }
void dungeonMap::movePlayer(Character* player, int direction) {
    int playerX = playerPositions[player].first;
    int playerY = playerPositions[player].second;
    int newX = playerX, newY = playerY;

    // Determine new position based on the direction
    switch (direction) {
        case 1: // Up
        {
            newX--;
            EventData event(EventData::EventType::PlayerMovedUp,player->getName(), newX, newY);
            notifyGameObserver(event);
            break;
        }
        case 2: // Down
        {
            newX++;
            EventData event(EventData::EventType::PlayerMovedDown, player->getName(), newX, newY);
            notifyGameObserver(event);
            break;
        }
        case 3: // Left
        {
            newY--;
            EventData event(EventData::EventType::PlayerMovedLeft, player->getName(), newX, newY);
            notifyGameObserver(event);
            break;
        }
        case 4: // Right
        {
            newY++;
            EventData event(EventData::EventType::PlayerMovedRight, player->getName(), newX, newY);
            notifyGameObserver(event);
            break;
        }
        default:
            return; // Invalid direction
    }

    // Check for valid move
    if (!isValidRow(newX) || !isValidCol(newY) || wallDetect(newX, newY)) {
        notify();
        return; // Invalid move
    }

    // Check for a chest at the new position
    if (chestDetect(newX, newY)) {
        if(dynamic_cast<HumanPlayerStrategy*>(player->getStrategy()) != nullptr){
            cout << "*************Chest found!**************" << endl;
            container* chest = dungeon[newX][newY].getChest();
            interactWithChest(player, chest);
            if (chest->getSize() == 0){
                delete chest;
                dungeon[newX][newY].removeContent();
            }
        }
    }else if(playerDetect(newX, newY)){
        cout << "*************Player found!**************" << endl;
        cout << "Press any key to continue...." << endl;
        keyPress();
    }else{
        // Move the player
        dungeon[newX][newY].setPlayer(player);
        dungeon[playerX][playerY].removeContent();
        playerPositions[player] = std::make_pair(newX, newY);
    }

    notify();
}

vector<int> dungeonMap::getWalls() {
    vector<int>wallCoordinates;
    for (int row = 0;row < rows;row++)
    {
        for (int col = 0;col < cols;col++)
        {
            if (dungeon[row][col].getCellType() == Wall) 
            {
                wallCoordinates.push_back(dungeon[row][col].rowPos);
                wallCoordinates.push_back(dungeon[row][col].colPos);
            }
        }
    }
    return wallCoordinates;
}

void dungeonMap::setUserPlayer(Character *player) {
    userPlayer = player;
}

Character* dungeonMap::getUserPlayer() {
    return this->userPlayer;

}


