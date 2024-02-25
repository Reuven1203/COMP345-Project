//
// Created by Reuven Ostrofsky on 2024-02-24.
//

#ifndef COMP345_A1_DICETEST_H
#define COMP345_A1_DICETEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../../Dice.h"


class DiceTest: public CppUnit::TestFixture {

    CPPUNIT_TEST_SUITE(DiceTest);
    CPPUNIT_TEST(testParseRollValid);
    CPPUNIT_TEST(testRoll);
    CPPUNIT_TEST(testParseRollInvalid);
    CPPUNIT_TEST(testParseDie);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp() override;
    void tearDown() override;
    void testParseRollValid();
    void testParseRollInvalid();
    void testRoll();
    void testParseDie();
private:
    Dice* dice{};


};


#endif //COMP345_A1_DICETEST_H
