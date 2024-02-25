/**
 * @file cell.h
 * @brief Header file for the cell class used in dungeon maps.
 *
 * Defines the cell class which represents a single cell in a dungeon map, capable of holding
 * a player, a chest, a wall, or being empty. Also includes functionality for map traversal validation.
 *
 * @author Richard Mauricio
 * @date 2024-02-24
 */

#ifndef CELL_H
#define CELL_H

#include <iostream>
#include "itemContainer.h"
#include "Character.h"


 /**
  * @enum cellType
  * @brief Enumerates the possible types of contents a cell can hold.
  */
enum cellType
{
    Player, ///< Indicates the cell contains a player.
    Nothing, ///< Indicates the cell is empty.
    Chest, ///< Indicates the cell contains a chest.
    Wall ///< Indicates the cell contains a wall.
};

class CellTest;

/**
 * @class cell
 * @brief Represents a single cell within a dungeon map.
 *
 * A cell can contain a player, a chest, a wall, or nothing. It supports operations to
 * set and query its contents, as well as to mark it as visited for map traversal algorithms.
 */
class cell
{
    friend class dungeonMap; ///< Allows dungeonMap full access to cell's private members.
    friend class CellTest; ///< Allows CellTest class to access private and protected members for testing purposes.

public:
    /**
     * @brief Default constructor initializing the cell to empty.
     */
    cell();

    /**
     * @brief Destructor for the cell class.
     */
    ~cell();

    /**
     * @brief Constructor initializing the cell with a character.
     * @param person Pointer to the Character object to place in the cell.
     */
    explicit cell(Character* person);

    /**
     * @brief Constructor initializing the cell with a container.
     * @param itemStorage Pointer to the container object to place in the cell.
     */
    explicit cell(container* itemStorage);

    /**
     * @brief Constructor initializing the cell with a specific type.
     * @param types cellType indicating the initial content of the cell.
     */
    explicit cell(cellType types);

    /**
     * @brief Sets the cell's content to a wall.
     */
    void setWall();

    /**
     * @brief Sets the cell's content to a chest.
     * @param chest Pointer to the container object to be placed in the cell.
     */
    void setChest(container* chest);

    /**
     * @brief Sets the cell's content to a player.
     * @param player Pointer to the Character object to be placed in the cell.
     */
    void setPlayer(Character* player);

    /**
     * @brief Marks the cell as visited, used in map traversal validation.
     */
    void setVisit();

    /**
     * @brief Checks if the cell has been visited.
     * @return True if the cell has been visited, false otherwise.
     */
    bool checkVisit() const;

    /**
     * @brief Clears the visited mark from the cell.
     */
    void clearVisit();

    /**
     * @brief Retrieves the cell's content type.
     * @return The cellType indicating the current content of the cell.
     */
    cellType getCellType();

    /**
     * @brief Gets the row position of the cell.
     * @return The row index of the cell in the dungeon map.
     */
    [[nodiscard]] int getRowPos() const;

    /**
     * @brief Gets the column position of the cell.
     * @return The column index of the cell in the dungeon map.
     */
    [[nodiscard]] int getColPos() const;

    /**
     * @brief Removes any content from the cell, resetting it to empty.
     */
    void removeContent();

private:
    cellType type; ///< The type of content the cell currently holds.
    container* chest{}; ///< Optional pointer to a container object if the cell holds a chest.
    Character* player{}; ///< Optional pointer to a Character object if the cell holds a player.
    bool visit{}; ///< Flag indicating whether the cell has been visited (for map validation).

    /**
     * @brief Sets the cell's content type.
     * @param types The cellType to set as the cell's content.
     */
    void setCellType(cellType types);

    int rowPos{}; ///< Row index of the cell in the dungeon map.
    int colPos{}; ///< Column index of the cell in the dungeon map.

    /**
     * @brief Sets the row position of the cell.
     * @param row The row index to set for the cell.
     */
    void setRowPos(int row);

    /**
     * @brief Sets the column position of the cell.
     * @param col The column index to set for the cell.
     */
    void setColPos(int col);
    friend CellTest;

    
    /* Add in when necessary
    Opponent enemy;
    Door closedDoor;
    */
};

#endif // CELL_H
