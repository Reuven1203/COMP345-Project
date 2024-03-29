/**
 * @file cell.cpp
 * @brief Implementation of the cell class used in dungeon maps.
 *
 * Implements the functionalities of the cell class, including constructors for different cell types,
 * setters for cell properties, and methods for handling cell content and state.
 *
 * @author Richard Mauricio
 * @date 2024-02-24
 */

#include <iostream>
#include "cell.h"

using namespace std;

/**
 * @brief Default constructor initializing the cell as empty and not visited.
 */
cell::cell()
{
    this->visit = false;
    this->type = Nothing;
    this->player = nullptr;
    this->chest = nullptr;
}

/**
 * @brief Destructor for the cell class.
 */
cell::~cell() = default;

/**
 * @brief Constructor initializing the cell with a specific type.
 * @param types cellType indicating the initial content of the cell.
 */
cell::cell(cellType types)
{
    type = types;
}

/**
 * @brief Constructor initializing the cell with a player.
 * @param person Pointer to the Character object to place in the cell.
 */
cell::cell(Character* person)
{
    if (type == Nothing)
    {
        player = person;
        type = Player;
    }
}

/**
 * @brief Constructor initializing the cell with a container.
 * @param itemStorage Pointer to the container object to place in the cell.
 */
cell::cell(container* itemStorage)
{
    if (type == Nothing)
    {
        chest = itemStorage;
        type = Chest;
    }
}

/**
 * @brief Sets the cell's content to a wall.
 */
void cell::setWall()
{
    type = Wall;
}

/**
 * @brief Sets the cell's content type.
 * @param types The cellType to set as the cell's content.
 */
void cell::setCellType(cellType types)
{
    type = types;
}

/**
 * @brief Sets the cell's content to a chest.
 * @param itemStorage Pointer to the container object to be placed in the cell.
 */
void cell::setChest(container* itemStorage)
{
    chest = itemStorage;
}

/**
 * @brief Sets the cell's content to a player.
 * @param person Pointer to the Character object to be placed in the cell.
 */
void cell::setPlayer(Character* person)
{
    player = person;
    type = Player;
}

/**
 * @brief Removes any content from the cell, resetting it to empty.
 */
void cell::removeContent()
{
    player = nullptr;
    chest = nullptr;
    type = Nothing;
}
/*
*@brief Removes player pointer at cell
*/
void cell::removePlayer()
{
    player = nullptr;
    
}
/**
 * @brief Retrieves the cell's content type.
 * @return The cellType indicating the current content of the cell.
 */
cellType cell::getCellType()
{
    return type;
}

/**
 * @brief Marks the cell as visited, used in map traversal validation.
 */
void cell::setVisit()
{
    visit = true;
}

/**
 * @brief Checks if the cell has been visited.
 * @return True if the cell has been visited, false otherwise.
 */
bool cell::checkVisit()
{
    return visit;
}

/**
 * @brief Clears the visited mark from the cell.
 */
void cell::clearVisit()
{
    visit = false;
}

/**
 * @brief Sets the row position of the cell.
 * @param row The row index to set for the cell.
 */
void cell::setRowPos(int row)
{
    this->rowPos = row;
}

/**
 * @brief Sets the column position of the cell.
 * @param col The column index to set for the cell.
 */
void cell::setColPos(int col)
{
    this->colPos = col;
}

/**
 * @brief Gets the row position of the cell.
 * @return The row index of the cell in the dungeon map.
 */
int cell::getRowPos() const
{
    return this->rowPos;
}

/**
 * @brief Gets the column position of the cell.
 * @return The column index of the cell in the dungeon map.
 */
int cell::getColPos() const
{
    return this->colPos;
}


Character* cell::getPlayer()
{
    return this->player;
}

container* cell::getChest()
{
    return this->chest;
}