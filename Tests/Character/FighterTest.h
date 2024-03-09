/**
 * @file FighterTest.h
 * @brief Declaration of the FighterTest class.
 * @author Reuven Ostrofsky
 * @date 2024-02-21
 */

#ifndef COMP345_A1_FIGHTERTEST_H
#define COMP345_A1_FIGHTERTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../../Character/Fighter.h"

/**
 * @class FighterTest
 * @brief Unit tests for the Fighter class.
 */
class FighterTest: public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(FighterTest);
        CPPUNIT_TEST(testClassName);
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
     * @brief Tests the getClassName method.
     */
    void testClassName();

private:
    Fighter* fighter{}; ///< Pointer to a Fighter object for testing.
};

#endif //COMP345_A1_FIGHTERTEST_H
