/**
 * @file CellTest.cpp
 * @brief Implementation of the CellTest class methods.
 * @author Julian D'Addario
 * @date 2024-02-25
 */

#include "CellTest.h"

//CPPUNIT_TEST_SUITE_REGISTRATION(CellTest);

void CellTest::setUp() {
    // Initialize cell and chest to test
    c = new cell();
    chest = new container();
}

void CellTest::tearDown() {
    delete c;
    c = nullptr;
    delete chest;
    chest = nullptr;
}

void CellTest::testGetCellType() {
    CPPUNIT_ASSERT_EQUAL(c->getCellType(), c->type);
}

void CellTest::testConstructor() {
    // test for all CellTypes
    c = new cell(Player);
    CPPUNIT_ASSERT_EQUAL(c->getCellType(), Player);
    c = new cell(Nothing);
    CPPUNIT_ASSERT_EQUAL(c->getCellType(), Nothing);
    c = new cell(Chest);
    CPPUNIT_ASSERT_EQUAL(c->getCellType(), Chest);
    c = new cell(Wall);
    CPPUNIT_ASSERT_EQUAL(c->getCellType(), Wall);
}

void CellTest::testChestConstructor() {
    c = new cell(chest);
    CPPUNIT_ASSERT_EQUAL(c->getCellType(), Chest);
}

void CellTest::testSetWall() {
    c->setWall();
    CPPUNIT_ASSERT_EQUAL(c->getCellType(), Wall);
}

void CellTest::testSetCellType() {
    // Test with all CellTypes
    c->setCellType(Player);
    CPPUNIT_ASSERT_EQUAL(c->getCellType(), Player);
    c->setCellType(Nothing);
    CPPUNIT_ASSERT_EQUAL(c->getCellType(), Nothing);
    c->setCellType(Chest);
    CPPUNIT_ASSERT_EQUAL(c->getCellType(), Chest);
    c->setCellType(Wall);
    CPPUNIT_ASSERT_EQUAL(c->getCellType(), Wall);
}

void CellTest::testRemoveContent() {
    // First add Chest and change CellType, then removeContent and check if removed properly
    c->chest = chest;
    c->setCellType(Chest);
    c->removeContent();
    CPPUNIT_ASSERT_EQUAL(c->getCellType(), Nothing);
    CPPUNIT_ASSERT(c->chest != chest);
}

void CellTest::testSetVisit() {
    c->visit = false;
    c->setVisit();
    CPPUNIT_ASSERT(c->visit);
}

void CellTest::testCheckVisit() {
    // test for both cases
    c->visit = false;
    CPPUNIT_ASSERT(!c->checkVisit());
    c->visit = true;
    CPPUNIT_ASSERT(c->checkVisit());
}

void CellTest::testClearVisit() {
    // setVisit first before clearing
    c->setVisit();
    CPPUNIT_ASSERT(c->checkVisit());
    c->clearVisit();
    CPPUNIT_ASSERT(!c->checkVisit());
}

void CellTest::testSetRowPos() {
    // test two values
    c->setRowPos(4);
    CPPUNIT_ASSERT_EQUAL(c->rowPos, 4);
    c->setRowPos(9);
    CPPUNIT_ASSERT_EQUAL(c->rowPos, 9);
}

void CellTest::testGetRowPos() {
    // test two values
    c->rowPos = 4;
    CPPUNIT_ASSERT_EQUAL(c->getRowPos(), 4);
    c->rowPos = 9;
    CPPUNIT_ASSERT_EQUAL(c->getRowPos(), 9);
}

void CellTest::testSetColPos() {
    // test two values
    c->setColPos(4);
    CPPUNIT_ASSERT_EQUAL(c->colPos, 4);
    c->setColPos(9);
    CPPUNIT_ASSERT_EQUAL(c->colPos, 9);
}

void CellTest::testGetColPos() {
    // test two values
    c->colPos = 4;
    CPPUNIT_ASSERT_EQUAL(c->getColPos(), 4);
    c->colPos = 9;
    CPPUNIT_ASSERT_EQUAL(c->getColPos(), 9);
}