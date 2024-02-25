//
// Created by Reuven Ostrofsky on 2024-02-24.
//

#ifndef COMP345_A1_ITEMTEST_H
#define COMP345_A1_ITEMTEST_H
#include "../Item.h"

#include <cppunit/extensions/HelperMacros.h>


class ItemTest: public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(ItemTest);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testRollStatMod);
    CPPUNIT_TEST(testGetters);
    CPPUNIT_TEST(testSetEquipType);
    CPPUNIT_TEST(testSetEquipStats);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp() override;
    void tearDown() override;
    static void testConstructor();
    static void testRollStatMod();
    static void testGetters();
    static void testSetEquipType();
    static void testSetEquipStats();
private:
    Item* item{};
};


#endif //COMP345_A1_ITEMTEST_H
