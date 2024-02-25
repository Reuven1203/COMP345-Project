/**
 * @file MapTest.cpp
 * @brief Implementation of the MapTest class methods.
 * @author Julian D'Addario
 * @date 2024-02-24
 */

#include "MapTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(MapTest);

void MapTest::setUp() {
    /**
     * Set up basic 5x5 dungeon map
     * With player/start on (1, 2)
     * End on (1, 4)
     */
    map = new dungeonMap(5, 5);
    Character *fighter {};
    map->setPlayer(fighter, 1, 2);
    map->setStart(1, 2);
    map->setEnd(1, 4);
}

void MapTest::tearDown() {
    delete map;
    map = nullptr;
}

void MapTest::testConstructor() {
    CPPUNIT_ASSERT(map->getColSize() == 5 && map->getRowSize() == 5);
}

void MapTest::testValid() {
    CPPUNIT_ASSERT(map->isValid());
}

void MapTest::testInvalid() {
    // Creates blocking wall between start and end before test
    for(int i{0}; i<5; i++)
        map->setWall(i, 3);
    CPPUNIT_ASSERT(!map->isValid());
}

void MapTest::testSetStart() {
    CPPUNIT_ASSERT(map->getStartX() == 1 && map->getStartY() == 2);
    // Change start location
    map->setStart(2, 2);
    CPPUNIT_ASSERT(map->getStartX() == 2 && map->getStartY() == 2);
}

void MapTest::testSetEnd() {
    CPPUNIT_ASSERT(map->endX == 1 && map->endY == 4);
    // Change end location
    map->setEnd(3, 3);
    CPPUNIT_ASSERT(map->endX == 3 && map->endY == 3);
}

void MapTest::testGetCell() {
    // Tests every cell in map against map location and cellType
    for(int i {0}; i < 5; i++) {
        for (int j {0}; j < 5; j++) {
            CPPUNIT_ASSERT(map->getCell(i, j).getColPos() == map->dungeon[i][j].getColPos()
                           && map->getCell(i, j).getRowPos() == map->dungeon[i][j].getRowPos()
                           && map->getCell(i, j).getCellType() == map->dungeon[i][j].getCellType());
        }
    }
}

void MapTest::testSetChest() {
    // Create temporary chest
    container *a{};
    map->setChest(a, 1, 1);
    CPPUNIT_ASSERT_EQUAL(map->getCell(1, 1).getCellType(), Chest);
}

void MapTest::testSetWall() {
    map->setWall(2, 3);
    CPPUNIT_ASSERT_EQUAL(map->getCell(2, 3).getCellType(), Wall);
}

void MapTest::testRemoveWall() {
    // Use testSetWall to set the wall at (2, 3) and ensure it is there first
    testSetWall();
    map->removeWall(2, 3);
    CPPUNIT_ASSERT_EQUAL(map->getCell(2, 3).getCellType(), Nothing);
}

void MapTest::testSetPlayer() {
    CPPUNIT_ASSERT_EQUAL(map->getCell(1, 2).getCellType(), Player);
    // Use testSetWall to set the wall at (2, 3) and ensure it is there first
    testSetWall();
    // Add new player and set to different location
    Character *fighter {};
    map->setPlayer(fighter, 2, 3);
    CPPUNIT_ASSERT_EQUAL(map->getCell(2, 3).getCellType(), Wall);
}

void MapTest::testValidRow() {
    // Valid and invalid params
    CPPUNIT_ASSERT(map->isValidRow(4));
    CPPUNIT_ASSERT(!map->isValidRow(10));
}

void MapTest::testValidCol() {
    // Valid and invalid params
    CPPUNIT_ASSERT(map->isValidCol(3));
    CPPUNIT_ASSERT(!map->isValidCol(6));
}

void MapTest::testValidLocation() {
    // Valid and invalid params
    CPPUNIT_ASSERT(map->isValidLocation(1, 1));
    CPPUNIT_ASSERT(map->isValidLocation(2, 0));
    CPPUNIT_ASSERT(!map->isValidLocation(1, 2));
}

void MapTest::testRowSize() {
    CPPUNIT_ASSERT_EQUAL(map->getRowSize(), 5);
}

void MapTest::testColSize() {
    CPPUNIT_ASSERT_EQUAL(map->getColSize(), 5);
}

void MapTest::testClearCellVisit() {
    // First set all cells to visited state
    for(int i {0}; i < 5; i++) {
        for(int j{0}; j < 5; j++) {
            map->dungeon[i][j].setVisit();
        }
    }
    // Clear visit state and test all cells again to ensure unvisited
    map->clearCellVisit();
    for(int i {0}; i < 5; i++) {
        for(int j{0}; j < 5; j++) {
            CPPUNIT_ASSERT(!map->getCell(i, j).checkVisit());
        }
    }
}

void MapTest::testRemoveCellContent() {
    // Use testSetWall to create wall at (2, 3) and test it is there first
    testSetWall();
    map->removeCellContent(2, 3);
    CPPUNIT_ASSERT_EQUAL(map->getCell(2, 3).getCellType(), Nothing);
}

