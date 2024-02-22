//
// Created by Reuven Ostrofsky on 2024-02-21.
//

#ifndef CHARACTERTEST_H
#define CHARACTERTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../../Character.h"

class CharacterTest : public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(CharacterTest);
//Test simple addition test
CPPUNIT_TEST(testAddition);
CPPUNIT_TEST(testInitialization);
CPPUNIT_TEST(testArmorEquip);
CPPUNIT_TEST(testWeaponEquip);
CPPUNIT_TEST(testHelmetEquip);
CPPUNIT_TEST(testShieldEquip);
CPPUNIT_TEST(testRingEquip);
CPPUNIT_TEST(testBeltEquip);
CPPUNIT_TEST(testBootsEquip);
CPPUNIT_TEST_SUITE_END();



public:
    void setUp() override;
    void tearDown() override;
    static void testAddition();
    void testInitialization();
    void testArmorEquip();
    void testWeaponEquip();
    void testHelmetEquip();
    void testShieldEquip();
    void testRingEquip();
    void testBeltEquip();
    void testBootsEquip();
private:
    Character* character{};

};

#endif // CHARACTERTEST_H
