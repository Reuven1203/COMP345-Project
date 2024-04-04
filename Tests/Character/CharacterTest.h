/**
 * @file CharacterTest.h
 * @brief Declaration of the CharacterTest class.
 * @author Reuven Ostrofsky
 * @date 2024-02-21
 */

#ifndef CHARACTERTEST_H
#define CHARACTERTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../../Character/Character.h"

/**
 * @class CharacterTest
 * @brief Unit tests for the Character class.
 */
class CharacterTest : public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(CharacterTest);
        CPPUNIT_TEST(testAddition);
        CPPUNIT_TEST(testInitialization);
//        CPPUNIT_TEST(testArmorEquip);
//        CPPUNIT_TEST(testWeaponEquip);
//        CPPUNIT_TEST(testHelmetEquip);
//        CPPUNIT_TEST(testShieldEquip);
//        CPPUNIT_TEST(testRingEquip);
//        CPPUNIT_TEST(testBeltEquip);
//        CPPUNIT_TEST(testBootsEquip);
    CPPUNIT_TEST_SUITE_END();

public:
    /**
     * @brief Sets up the test fixture.
     */
    void setUp() override;

    /**
     * @brief Tears down the test fixture.
     */
    void tearDown() override;

    /**
     * @brief Tests simple addition.
     */
    static void testAddition();

    /**
     * @brief Tests initialization of a Character object.
     */
    void testInitialization();

    /**
     * @brief Tests equipping armor.
     */
//    void testArmorEquip();
//
//    /**
//     * @brief Tests equipping a weapon.
//     */
//    void testWeaponEquip();
//
//    /**
//     * @brief Tests equipping a helmet.
//     */
//    void testHelmetEquip();
//
//    /**
//     * @brief Tests equipping a shield.
//     */
//    void testShieldEquip();
//
//    /**
//     * @brief Tests equipping a ring.
//     */
//    void testRingEquip();
//
//    /**
//     * @brief Tests equipping a belt.
//     */
//    void testBeltEquip();
//
//    /**
//     * @brief Tests equipping boots.
//     */
//    void testBootsEquip();

private:
    Character* character{}; ///< Pointer to a Character object for testing.
};

#endif // CHARACTERTEST_H
