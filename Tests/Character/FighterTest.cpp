//
// Created by Reuven Ostrofsky on 2024-02-21.
//

#include "FighterTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(FighterTest);


void FighterTest::setUp() {
    fighter = new Fighter("Fighter", 1);
}

void FighterTest::tearDown() {
    delete fighter;
}

void FighterTest::testClassName() {
      CPPUNIT_ASSERT(fighter->getClassName() == "Fighter");
}
