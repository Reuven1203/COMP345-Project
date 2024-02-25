//
// Created by Reuven Ostrofsky on 2024-02-24.
//

#ifndef COMP345_A1_ITEMTEST_H
#define COMP345_A1_ITEMTEST_H
#include "../Item.h"

#include <cppunit/extensions/HelperMacros.h>

/**
 * @class ItemTest
 * @brief Unit tests for the Item class
 */
class ItemTest: public CppUnit::TestFixture {
    // Test order
    CPPUNIT_TEST_SUITE(ItemTest);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testRollStatMod);
    CPPUNIT_TEST(testGetters);
    CPPUNIT_TEST(testSetEquipType);
    CPPUNIT_TEST(testSetEquipStats);
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
     * @brief Tests the constructor with different item types
     */
    static void testConstructor();
    /**
     * @brief Tests rollStatMod method
     */
    static void testRollStatMod();
    /**
     * @brief Tests getters for different potential item stats.
     */
    static void testGetters();
    /**
     * @brief Tests setEquipType method to change equipType
     */
    static void testSetEquipType();
    /**
     * @brief Tests that setEquipStats method rerolls stats properly
     */
    static void testSetEquipStats();
private:
    Item* item{};
};


#endif //COMP345_A1_ITEMTEST_H
