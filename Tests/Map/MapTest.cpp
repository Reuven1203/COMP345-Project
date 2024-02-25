/**
 * @file MapTest.cpp
 * @brief Implementation of the MapTest class methods.
 * @author Julian D'Addario
 * @date 2024-02-24
 */

#include "MapTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(MapTest);

void MapTest::setUp() {
    map = new dungeonMap(5, 5);
    Character *fighter;
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
    for(int i{0}; i<5; i++)
        map->setWall(i, 3);
    CPPUNIT_ASSERT(!map->isValid());
}

void MapTest::testSetStart() {
    CPPUNIT_ASSERT(map->getStartX() == 1 && map->getStartY() == 2);
    int z {0};
    map->setStart(z, z);
    CPPUNIT_ASSERT(map->getStartX() == z && map->getStartY() == z);
}

void MapTest::testSetChest() {
    container *a{};
    map->setChest(a, 1, 1);
    CPPUNIT_ASSERT_EQUAL(map->getCell(1, 1).getCellType(), Chest);
}