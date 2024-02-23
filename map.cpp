#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "map.h"
#include "cell.h"

// Initialize 2D vector map with space ' ' chars
dungeonMap::dungeonMap(int x, int y) : rows(x), cols(y), dungeon(rows, vector<cell>(cols))
{
}
/////////////////////////////////////////////////////////////////////////////////////
// SETTERS
void dungeonMap::setChest(container *chest, int x, int y)
{
    if (dungeon[x][y].getCellType() == Nothing)
        dungeon[x][y].setChest(chest);

    else
        cout << "Invalid location for chest." << endl;
}

void dungeonMap::setWall()
{
    bool done = false;
    int wallCoordinateX;
    int wallCoordinateY;
    cout << "Wall Generation Mode" << endl;
    int choice = 0;
    while (done != true)
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
            cout << "X coordinate: ";
            cin >> wallCoordinateX;
            if (wallCoordinateX == -1)
            {
                done = true;
                break;
            }
            if (wallCoordinateX >= rows || wallCoordinateX < 0)
            {
                cout << "Invalid X coordinate." << endl;
                continue;
            }
            cout << "Y coordinate: ";
            cin >> wallCoordinateY;

            if (wallCoordinateY == -1)
            {
                done == true;
                break;
            }
            if (wallCoordinateY >= cols || wallCoordinateY < 0)
            {
                cout << "Invalid Y coordinate." << endl;
                continue;
            }
            if (dungeon[wallCoordinateX][wallCoordinateY].getCellType() == Start || dungeon[wallCoordinateX][wallCoordinateY].getCellType() == End)
                cout << "Invalid location for Wall due to " << ((dungeon[wallCoordinateX][wallCoordinateY].getCellType() == Start) ? "Start" : "End") << " point" << endl;
            else
                dungeon[wallCoordinateX][wallCoordinateY].setCellType(Wall);
            
            break;
        }
        case (2):
        {
            cout << "Input coordinates to remove wall (-1) to exit" << endl;
            cout << "X: ";
            cin >> wallCoordinateX;
            if(wallCoordinateX==-1)
            {
                break;
            }
            if (wallCoordinateX < 0 || wallCoordinateX >= rows)
            {
                cout << "Invalid X coordinate." << endl;
                continue;
            }
            cout << "Y: ";
            cin >> wallCoordinateY;
            if(wallCoordinateY==-1)
            {
                break;
            }
            if (wallCoordinateY >= cols || wallCoordinateY < 0)
            {
                cout << "Invalid Y coordinate." << endl;
                continue;
            }
            if (dungeon[wallCoordinateX][wallCoordinateY].getCellType() != Wall)
                cout << "No wall exists here." << endl;
            else
            {
                dungeon[wallCoordinateX][wallCoordinateY].setCellType(Nothing);
            }
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
    dungeon[startX][startY].setCellType(Start);
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
    dungeon[endX][endY].setCellType(End);
}
/////////////////////////////////////////////////////////////////////////////////////
// Getters

int dungeonMap::getStartX()
{
    return startX;
}
int dungeonMap::getStartY()
{
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
            switch (dungeon[row][col].getCellType())
            {
            case Nothing:
            {
                cout << "|  "
                     << "   ";
                break;
            }
            case Start:
            {
                cout << "|  "
                     << "S  ";
                break;
            }
            case End:
            {
                cout << "|  "
                     << "E  ";
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
bool dungeonMap::validMap(int row, int col)
{

    if (row < 0 || col < 0 || row >= rows || col >= cols || dungeon[row][col].checkVisit() == true || dungeon[row][col].getCellType() == Wall)
    {
        return false;
    }
    if (dungeon[row][col].getCellType() == End)
    {

        return true;
    }
    dungeon[row][col].setVisit();
    if (validMap(row + 1, col) ||
        validMap(row - 1, col) ||
        validMap(row, col + 1) ||
        validMap(row, col - 1))
    {
        return true;
    }
    return false;
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
