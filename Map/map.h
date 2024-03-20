/**
 * @file map.h
 * @brief Definition of the dungeonMap class for managing a dungeon map.
 *
 * This class manages a dungeon composed of cells, allowing for operations such as setting start and end points,
 * adding or removing walls, and interacting with items and characters within the dungeon.
 *
 * @author Richard Mauricio
 * @date 2024-02-24
 */

#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include "cell.h"
#include "../Observer/Observable.h"
#include "../Character/Character.h"
class Character;  // Forward declaration
class dungeonMap:public Observable
{
    friend class cell; ///< Allows cell class to access private members of dungeonMap.
    friend class MapTest; ///< Allows MapTest full access to dungeonMap's private members.
public:
    std::map<Character*, std::pair<int, int>> playerPositions;
    /**
     * @brief Default constructor.
     */
    dungeonMap() = default;

    /**
     * @brief Default destructor.
     */
    ~dungeonMap() = default;

    /**
     * @brief Constructs a dungeonMap with specified dimensions.
     * @param x The number of rows in the dungeon.
     * @param y The number of columns in the dungeon.
     */
    dungeonMap(int x, int y);

    /**
     * @brief Checks if the dungeon map is valid by ensuring there's a path from start to end.
     * @return True if the map is valid, otherwise false.
     */
    bool isValid();

    /**
     * @brief Prints the current state of the dungeon map.
     */
    void printMap();

    /**
     * @brief Sets the starting point of the dungeon.
     * @param x The row index for the start point.
     * @param y The column index for the start point.
     */
    void setStart(int x, int y);

    /**
     * @brief Sets the ending point of the dungeon.
     * @param x The row index for the end point.
     * @param y The column index for the end point.
     */
    void setEnd(int x, int y);

    /**
     * @brief Adds a wall to the specified location in the dungeon.
     * @param x The row index to add a wall.
     * @param y The column index to add a wall.
     */
    void setWall(int x, int y);

    /**
     * @brief Removes a wall from the specified location in the dungeon.
     * @param x The row index to remove a wall.
     * @param y The column index to remove a wall.
     */
    void removeWall(int x, int y);

    /**
     * @brief Removes content from the specified cell.
     * @param x The row index of the cell.
     * @param y The column index of the cell.
     */
    void removeCellContent(int x, int y);

    /**
     * @brief Places a player in the specified location in the dungeon.
     * @param player Pointer to the player character.
     * @param x The row index to place the player.
     * @param y The column index to place the player.
     */
    void setPlayer(Character* player, int x, int y);

    /**
     * @brief Retrieves the row index of the dungeon's start point.
     * @return The row index of the start point.
     */
    [[nodiscard]] int getStartX() const;

    /**
     * @brief Retrieves the column index of the dungeon's start point.
     * @return The column index of the start point.
     */
    [[nodiscard]] int getStartY() const;
    
    void setPlayerX(int x);
    void setPlayerY(int y);
    int getPlayerX() const;
    int getPlayerY() const;


    /**
     * @brief Gets the total number of rows in the dungeon.
     * @return The number of rows.
     */
    int getRowSize() const;

    /**
     * @brief Gets the total number of columns in the dungeon.
     * @return The number of columns.
     */
    int getColSize() const;

    /**
     * @brief Interactively allows the user to modify walls within the dungeon.
     */
    void userInputWalls();

    /**
     * @brief Places a chest at the specified location within the dungeon.
     * @param chest Pointer to the chest object.
     * @param x The row index to place the chest.
     * @param y The column index to place the chest.
     */
    void setChest(container* chest, int x, int y);

    /**
     * @brief Clears the 'visited' state of all cells, typically used after pathfinding operations.
     */
    void clearCellVisit();

    /**
     * @brief Retrieves the cell at the specified row and column.
     * @param row The row index of the cell.
     * @param col The column index of the cell.
     * @return The cell at the given row and column.
     */

    vector<int>getWalls();
   
    cell getCell(int row, int col) const;
    int getEndX();
    int getEndY();
    void movePlayer(Character *player,int direction); //1=up 2=down 3=left 4=right
private:
   
    vector<vector<cell>> dungeon; ///< 2D vector of cells representing the dungeon layout.
    int rows; ///< Number of rows in the dungeon.
    int cols; ///< Number of columns in the dungeon.
    cell* start{}; ///< Pointer to the starting cell.
    cell* end{}; ///< Pointer to the ending cell.
    int startX{}, startY{}; ///< Coordinates of the starting point.
    int endX{}, endY{}; ///< Coordinates of the ending point.
    bool wallDetect(int x, int y);
    bool chestDetect(int x, int y);
    bool isStart(cell* cell) const; ///< Checks if a cell is the start point.
    bool isEnd(cell* cell) const; ///< Checks if a cell is the end point.
    bool dfs(int row, int col); ///< Performs depth-first search for path validation.
    void addWallInteraction(); ///< Helper function for wall addition interaction.
    void removeWallInteraction(); ///< Helper function for wall removal interaction.
    void getWallCoordinates(int& x, int& y); ///< Prompts user for wall coordinates.
    bool isValidRow(int row) const; ///< Valiådates row index.
    bool isValidCol(int col) const; ///< Validates column index.
    bool isValidLocation(int row, int col); ///< Validates if a location can be modified.
    void addWallChoice(int* x, int* y); ///< Interactively allows adding a wall.
    void removeWallChoice(int* x, int* y); ///< Interactively allows removing a wall.
    int playerX, playerY;///<Keeps track of where player is
};

#endif // MAP_H
