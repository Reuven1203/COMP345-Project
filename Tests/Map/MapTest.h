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

class MapTest: public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(MapTest);
    CPPUNIT_TEST(testValid);
    CPPUNIT_TEST(testInvalid);
    CPPUNIT_TEST(testSetStart);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testSetChest);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp() override;
    void tearDown() override;
    void testValid();
    void testInvalid();
    void testSetStart();
    void testConstructor();
    void testSetChest();
private:
    dungeonMap* map{};

};

#endif //COMP345_A1_MAPTEST_H
