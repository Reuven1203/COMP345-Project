#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "map.h"
#include "cell.h"

// Initialize 2D vector map with space ' ' chars
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
/////////////////////////////////////////////////////////////////////////////////////
// SETTERS
void dungeonMap::setChest(container *chest, int x, int y)
{
    if (dungeon[x][y].getCellType() == Nothing){
        dungeon[x][y].setCellType(Chest);
        dungeon[x][y].setChest(chest);
    }
    else
        cout << "Invalid location for chest." << endl;
}

void dungeonMap::setWall(int x, int y)
{
    if (dungeon[x][y].getCellType() == Nothing)
        dungeon[x][y].setCellType(Wall);
    else
        cout << "Invalid location for wall due to existing object" << endl;
}

void dungeonMap::removeWall(int x, int y) {
    if (dungeon[x][y].getCellType() != Wall)
        cout << "No wall exists here." << endl;
    else
    {
        dungeon[x][y].setCellType(Nothing);
    }
}

void dungeonMap::setPlayer(Character *player, int x, int y)
{
    if(dungeon[x][y].getCellType() != Nothing){
        cout << "Invalid location for player." << endl;
        return;
    }
    dungeon[x][y].setCellType(Player);
    dungeon[x][y].setPlayer(player);
}

bool dungeonMap::isValidRow(int row) const{
    return row >= 0 && row < rows;

}

bool dungeonMap::isValidCol(int col) const {
    return col >= 0 && col < cols;
}

bool dungeonMap::isValidLocation(int row, int col) {
    if ((row == startX && col == startY) || (row == endX && col == endY)){
        cout << "Invalid location due to " << (isStart(&dungeon[row][col]) ? "Start" : "End") << " point" << endl;
        return false;
    }
    return true;

}




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
                removeWall(wallCoordinateX, wallCoordinateY);
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

// Setting Start point of map
void dungeonMap::setStart(int x, int y)
{
    if (x >= rows || y >= cols || x < 0 || y < 0)
    {
        cout << "Start point is out of bounds.";
        exit(1);
    }
    this->startY = y;
    this->startX = x;
    this->start = &dungeon[startX][startY];
}

// Setting End point of map
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
/////////////////////////////////////////////////////////////////////////////////////
// Getters
int dungeonMap::getRowSize() const
{
    return rows;
}
int dungeonMap::getColSize() const
{
    return cols;
}
cell dungeonMap::getCell(int row, int col) const {
    return dungeon[row][col];
}

int dungeonMap::getStartX() const {
    return startX;
}

int dungeonMap::getStartY() const {
    return startY;
}
/////////////////////////////////////////////////////////////////////////////////////
// Prints map
void dungeonMap::printMap()
{
    int maxRowDigits = to_string(rows).length();
    int maxColDigits = to_string(cols).length();

    for (int row = 0; row < rows; row++)
    {
        cout << setw(maxColDigits) << row;

        for (int col = 0; col < cols; col++)
        {
            if (isStart(&dungeon[row][col]))
            {
                cout << "|  "
                     << "S  ";
                continue;
            }else if(isEnd(&dungeon[row][col]))
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

// Validate's map to check if there is a valid path from start to end
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

bool dungeonMap::isValid()
{
    bool valid = dfs(startX, startY);
    clearCellVisit();
    return valid;
}

// Clear visit bool for cells during validMap Function
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

bool dungeonMap::isStart(cell *cell) const {
    return cell->getColPos() == startY && cell->getRowPos() == startX;
}

bool dungeonMap::isEnd(cell *cell) const {
    return cell->getColPos() == endY && cell->getRowPos() == endX;
}


void dungeonMap::addWallChoice(int *x, int *y)
{
    cout << "X coordinate: ";
    cin >> *x;
    if (!isValidRow(*x))
    {
        cout << "Invalid X coordinate." << endl;
        return;
    }
    cout << "Y coordinate: ";
    cin >> *y;
    if (!isValidCol(*y))
    {
        cout << "Invalid Y coordinate." << endl;
        return;
    }
}

void dungeonMap::removeWallChoice(int *x, int *y) {
    cout << "X coordinate: ";
    cin >> *x;
    if (!isValidRow(*x))
    {
        cout << "Invalid X coordinate." << endl;
        return;
    }
    cout << "Y coordinate: ";
    cin >> *y;
    if (!isValidCol(*y))
    {
        cout << "Invalid Y coordinate." << endl;
        return;
    }
    removeWall(*x, *y);
}
