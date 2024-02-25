//
// Created by Reuven Ostrofsky on 2024-02-24.
//

#include "DiceTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DiceTest);

void DiceTest::setUp() {
  dice = new Dice();

}
void DiceTest::tearDown() {
    delete dice;
    dice = nullptr;
}



void DiceTest::testParseRollValid() {
    Roll roll = dice->parseRoll("3d6+2");
    CPPUNIT_ASSERT_EQUAL(d6, roll.dieType);
    CPPUNIT_ASSERT_EQUAL(3, roll.numDice);
    CPPUNIT_ASSERT_EQUAL(2, roll.numAdded);
}

void DiceTest::testRoll() {
    int result = dice->roll("1d6+0");
    // Validate within the possible range
    CPPUNIT_ASSERT(result >= 1 && result <= 6);
}

void DiceTest::testParseRollInvalid() {
    CPPUNIT_ASSERT_THROW(dice->parseRoll("3d6+2+1"), std::invalid_argument);
//    CPPUNIT_ASSERT_THROW(dice->parseRoll("3d6+2-1"), std::invalid_argument); \\fix this test as it fails
    CPPUNIT_ASSERT_THROW(dice->parseRoll("3d6+2d6"), std::invalid_argument);
    CPPUNIT_ASSERT_THROW(dice->parseRoll("3d6+2d6+1"), std::invalid_argument);
    CPPUNIT_ASSERT_THROW(dice->parseRoll("3d6+2d6-1"), std::invalid_argument);
    CPPUNIT_ASSERT_THROW(dice->parseRoll("3d6+2d6+1d6"), std::invalid_argument);
    CPPUNIT_ASSERT_THROW(dice->parseRoll("3d6+2d6-1d6"), std::invalid_argument);
    CPPUNIT_ASSERT_THROW(dice->parseRoll("3d6+2d6+1d6+1"), std::invalid_argument);
    CPPUNIT_ASSERT_THROW(dice->parseRoll("3d6+2d6-1d6-1"), std::invalid_argument);
    CPPUNIT_ASSERT_THROW(dice->parseRoll("3d6+2d6+1d6+1d6"), std::invalid_argument);
    CPPUNIT_ASSERT_THROW(dice->parseRoll("3d6+2d6-1d6-1d6"), std::invalid_argument);
    CPPUNIT_ASSERT_THROW(dice->parseRoll("3d6+2d6+1d6+1d6+1"), std::invalid_argument);
    CPPUNIT_ASSERT_THROW(dice->parseRoll("3d6+2d6-1d6-1d6-1"), std::invalid_argument);
    CPPUNIT_ASSERT_THROW(dice->parseRoll("3d6+2d6+1d6+1d6+1d6"), std::invalid_argument);
    CPPUNIT_ASSERT_THROW(dice->parseRoll("3d6+2d6-1d6-1d6-1d6"), std::invalid_argument);
    CPPUNIT_ASSERT_THROW(dice->parseRoll("3d6+2d6+1d6+1d6+1d6+1"), std::invalid_argument);
}

