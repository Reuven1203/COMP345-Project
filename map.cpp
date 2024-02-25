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
    if (dungeon[x][y].getCellType() == Nothing)
    {
        dungeon[x][y].setCellType(Player);
        dungeon[x][y].setPlayer(player);
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
        printMap();
        cout << "Choose: 1. Add wall || 2. Remove Wall || 3. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case (1):
        {
            printMap();
            cout << "Choose where to insert wall(-1 to exit): " << endl;
            addWallChoice(&wallCoordinateX, &wallCoordinateY);
            if(isValidLocation(wallCoordinateX, wallCoordinateY))
                setWall(wallCoordinateX, wallCoordinateY);
            if(!isValid()){
                cout << "Invalid map, wall cannot be placed here." << endl;
                removeWall(wallCoordinateY, wallCoordinateX);
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

        for (int col = 0; col < cols; col++)
        {
            if (row==startX && col==startY && dungeon[row][col].getCellType()==Player)
            {
                cout << "|  "
                     << "S/P";
                continue;
            }
            else if(isStart(&dungeon[row][col])){
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
                     << "P  ";
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

    for (int row = 0; row < rows; row++)
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

bool dungeonMap::dfs(int row, int col)
{

    if (row < 0 || col < 0 || row >= rows || col >= cols || dungeon[row][col].checkVisit() || dungeon[row][col].getCellType() == Wall)
    {
        return false;
    }
    if (isEnd(&dungeon[row][col])) {
        return true;
    }
    dungeon[row][col].setVisit();
    if (dfs(row + 1, col) ||
        dfs(row - 1, col) ||
        dfs(row, col + 1) ||
        dfs(row, col - 1))
    {
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
    bool valid = dfs(startX, startY);
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
        return;
    }
    cout << "X coordinate: ";
    cin >> *y;
    if (!isValidCol(*y))
    {
        cout << "Invalid X coordinate." << endl;
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
}
