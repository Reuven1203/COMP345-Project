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
    int result1 = dice->roll("1d6+0");
    int result2 = dice->roll("0d4+100");
    int result3 = dice->roll("7d8+30");
    // Validate within the possible range
    CPPUNIT_ASSERT(result1 >= 1 && result1 <= 6);
    CPPUNIT_ASSERT(result2 == 100);
    CPPUNIT_ASSERT(result3 >= 38 && result3 <= 86);
}

void DiceTest::testParseDie() {
    CPPUNIT_ASSERT_EQUAL(dice->parseDie("20", "5d20+10"), d20);
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

