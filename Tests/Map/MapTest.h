/**
 * @file MapTest.h
 * @brief Declaration of the MapTest class.
 * @author Julian D'Addario
 * @date 2024-02-24
 */

#ifndef COMP345_A1_MAPTEST_H
#define COMP345_A1_MAPTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../../map.h"
#include "../../cell.h"

/**
 * @class MapTest
 * @brief Unit tests for the Map class
 */
class MapTest: public CppUnit::TestFixture {
    // Test order
    CPPUNIT_TEST_SUITE(MapTest);
    CPPUNIT_TEST(testValid);
    CPPUNIT_TEST(testInvalid);
    CPPUNIT_TEST(testSetStart);
    CPPUNIT_TEST(testSetEnd);
    CPPUNIT_TEST(testGetCell);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testSetChest);
    CPPUNIT_TEST(testSetWall);
    CPPUNIT_TEST(testRemoveWall);
    CPPUNIT_TEST(testSetPlayer);
    CPPUNIT_TEST(testValidRow);
    CPPUNIT_TEST(testValidCol);
    CPPUNIT_TEST(testValidLocation);
    CPPUNIT_TEST(testRowSize);
    CPPUNIT_TEST(testColSize);
    CPPUNIT_TEST(testClearCellVisit);
    CPPUNIT_TEST(testRemoveCellContent);
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
     * @brief Tests map isValid method with valid map
     */
    void testValid();
    /**
     * @brief Tests map isValid method with invalid map
     */
    void testInvalid();
    /**
     * @brief Tests setStart method
     */
    void testSetStart();
    /**
     * @brief Tests setEnd method
     */
    void testSetEnd();
    /**
     * @brief Tests getCell method
     */
    void testGetCell();
    /**
     * @brief Tests constructor for proper map matrix initialization
     */
    void testConstructor();
    /**
     * @brief Tests setChest method
     */
    void testSetChest();
    /**
     * @brief Tests setWall method
     */
    void testSetWall();
    /**
     * @brief Tests removeWall method
     */
    void testRemoveWall();
    /**
     * @brief Tests setPlayer method with valid & invalid params
     */
    void testSetPlayer();
    /**
     * @brief Tests isValidRow method with valid & invalid params
     */
    void testValidRow();
    /**
     * @brief Tests isValidCol method with valid & invalid params
     */
    void testValidCol();
    /**
     * @brief Tests isValidLocation method with valid & invalid params
     */
    void testValidLocation();
    /**
     * @brief Tests getRowSize method
     */
    void testRowSize();
    /**
     * @brief Tests getColSize method
     */
    void testColSize();
    /**
     * @brief Tests clearCellVisit method against entire map matrix
     */
    void testClearCellVisit();
    /**
     * @brief Tests removeCellContent method
     */
    void testRemoveCellContent();
private:
    dungeonMap* map{};

};

#endif //COMP345_A1_MAPTEST_H
