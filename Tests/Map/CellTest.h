/**
 * @file CellTest.h
 * @brief Declaration of the CellTest class.
 * @author Julian D'Addario
 * @date 2024-02-25
 */

#ifndef COMP345_A1_CELLTEST_H
#define COMP345_A1_CELLTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../../Map/map.h"
#include "../../Map/cell.h"
#include "../../Item/itemContainer.h"

/**
 * @class CellTest
 * @brief Unit tests for the Cell class
 */
class CellTest: public CppUnit::TestFixture {
    // Test order
    CPPUNIT_TEST_SUITE(CellTest);
    CPPUNIT_TEST(testGetCellType);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testChestConstructor);
    CPPUNIT_TEST(testSetWall);
    CPPUNIT_TEST(testSetCellType);
    CPPUNIT_TEST(testRemoveContent);
    CPPUNIT_TEST(testSetVisit);
    CPPUNIT_TEST(testCheckVisit);
    CPPUNIT_TEST(testClearVisit);
    CPPUNIT_TEST(testSetRowPos);
    CPPUNIT_TEST(testGetRowPos);
    CPPUNIT_TEST(testSetColPos);
    CPPUNIT_TEST(testGetColPos);
    CPPUNIT_TEST_SUITE_END();

public:
    /**
     * @brief Sets up test fixture
     */
    void setUp() override;
    /**
     * @brief Tears down test fixture
     */
    void tearDown() override;
    /**
     * @brief Tests map constructor with CellType
     */
    void testConstructor();
    /**
     * @brief Tests map constructor with container/itemContainer
     */
    void testChestConstructor();
    /**
     * @brief Tests setWall method
     */
    void testSetWall();
    /**
     * @brief Tests setCellType method with all cell types
     */
    void testSetCellType();
    /**
     * @brief Tests removeContent method
     */
    void testRemoveContent();
    /**
     * @brief Tests getCellType method with all cell types
     */
    void testGetCellType();
    /**
     * @brief Tests setVisit method
     */
    void testSetVisit();
    /**
     * @brief Tests checkVisit method
     */
    void testCheckVisit();
    /**
     * @brief Tests clearVisit method
     */
    void testClearVisit();
    /**
     * @brief Tests setRowPos method
     */
    void testSetRowPos();
    /**
     * @brief Tests getRowPos method
     */
    void testGetRowPos();
    /**
     * @brief Tests setColPos method
     */
    void testSetColPos();
    /**
     * @brief Tests getColPos method
     */
    void testGetColPos();
private:
    cell* c {};
    container* chest {};
};

#endif //COMP345_A1_CELLTEST_H
