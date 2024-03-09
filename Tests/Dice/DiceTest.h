//
// Created by Reuven Ostrofsky on 2024-02-24.
//

#ifndef COMP345_A1_DICETEST_H
#define COMP345_A1_DICETEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../../Dice/Dice.h"

/**
 * @class DiceTest
 * @brief Unit tests for the Dice class
 */
class DiceTest: public CppUnit::TestFixture {
    // Test order
    CPPUNIT_TEST_SUITE(DiceTest);
    CPPUNIT_TEST(testParseRollValid);
    CPPUNIT_TEST(testRoll);
    CPPUNIT_TEST(testParseRollInvalid);
    CPPUNIT_TEST(testParseDie);
    CPPUNIT_TEST_SUITE_END();

public:
    /**
     * @brief Sets up test fixture.
     */
    void setUp() override;
    /**
     * @brief Tears down test fixture.
     */
    void tearDown() override;
    /**
     * @brief Tests the parseRoll method with a valid roll
     */
    void testParseRollValid();
    /**
     * @brief Tests the parseRoll method with an invalid roll
     */
    void testParseRollInvalid();
    /**
     * @brief Tests the roll method with several rolls
     */
    void testRoll();
    /**
     * @brief Tests the parseDie method
     */
    void testParseDie();
private:
    Dice* dice{};
};


#endif //COMP345_A1_DICETEST_H
