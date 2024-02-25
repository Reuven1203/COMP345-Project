//
// Created by Reuven Ostrofsky on 2024-02-24.
//

#include "ItemTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(ItemTest);



void ItemTest::setUp() {
    item = new Item(Item::ItemType::HELMET);
}

void ItemTest::tearDown() {
    delete item;
}

void ItemTest::testConstructor() {
    Item helmet(Item::ItemType::HELMET);
    CPPUNIT_ASSERT_EQUAL(std::string("Helmet"), helmet.getEquipType());
    Item armor(Item::ItemType::ARMOR);
    CPPUNIT_ASSERT_EQUAL(std::string("Armor"), armor.getEquipType());
    Item shield(Item::ItemType::SHIELD);
    CPPUNIT_ASSERT_EQUAL(std::string("Shield"), shield.getEquipType());
    Item ring(Item::ItemType::RING);
    CPPUNIT_ASSERT_EQUAL(std::string("Ring"), ring.getEquipType());
    Item belt(Item::ItemType::BELT);
    CPPUNIT_ASSERT_EQUAL(std::string("Belt"), belt.getEquipType());
    Item boots(Item::ItemType::BOOTS);
    CPPUNIT_ASSERT_EQUAL(std::string("Boots"), boots.getEquipType());
    Item weapon(Item::ItemType::WEAPON);
    CPPUNIT_ASSERT_EQUAL(std::string("Weapon"), weapon.getEquipType());
}

void ItemTest::testRollStatMod() {
    Item it;
    int mod = it.rollStatMod();
    CPPUNIT_ASSERT(mod >= 1 && mod <= 5);
}

void ItemTest::testGetters() {
    Item ring(Item::ItemType::RING);
    CPPUNIT_ASSERT(ring.getAC() >= 1 && ring.getAC() <= 5);
    CPPUNIT_ASSERT(ring.getWIS() >= 1 && ring.getWIS() <= 5);
    CPPUNIT_ASSERT(ring.getCHA() >= 1 && ring.getCHA() <= 5);
    CPPUNIT_ASSERT(ring.getEquipType() == "Ring");

    Item helmet(Item::ItemType::HELMET);
    CPPUNIT_ASSERT(helmet.getAC() >= 1 && helmet.getAC() <= 5);
    CPPUNIT_ASSERT(helmet.getINT() >= 1 && helmet.getINT() <= 5);
    CPPUNIT_ASSERT(helmet.getWIS() >= 1 && helmet.getWIS() <= 5);
    CPPUNIT_ASSERT(helmet.getEquipType() == "Helmet");

    Item armor(Item::ItemType::ARMOR);
    CPPUNIT_ASSERT(armor.getAC() >= 1 && armor.getAC() <= 5);
    CPPUNIT_ASSERT(armor.getEquipType() == "Armor");

    Item shield(Item::ItemType::SHIELD);
    CPPUNIT_ASSERT(shield.getAC() >= 1 && shield.getAC() <= 5);
    CPPUNIT_ASSERT(shield.getEquipType() == "Shield");

    Item belt(Item::ItemType::BELT);
    CPPUNIT_ASSERT(belt.getSTR() >= 1 && belt.getSTR() <= 5);
    CPPUNIT_ASSERT(belt.getCON() >= 1 && belt.getCON() <= 5);
    CPPUNIT_ASSERT(belt.getEquipType() == "Belt");

    Item boots(Item::ItemType::BOOTS);
    CPPUNIT_ASSERT(boots.getAC() >= 1 && boots.getAC() <= 5);
    CPPUNIT_ASSERT(boots.getDEX() >= 1 && boots.getDEX() <= 5);
    CPPUNIT_ASSERT(boots.getEquipType() == "Boots");

    Item weapon(Item::ItemType::WEAPON);
    CPPUNIT_ASSERT(weapon.getATKBONUS() >= 1 && weapon.getATKBONUS() <= 5);
    CPPUNIT_ASSERT(weapon.getDMGBonus() >= 1 && weapon.getDMGBonus() <= 5);
    CPPUNIT_ASSERT(weapon.getEquipType() == "Weapon");
}


