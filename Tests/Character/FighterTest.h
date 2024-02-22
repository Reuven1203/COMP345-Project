//
// Created by Reuven Ostrofsky on 2024-02-21.
//

#ifndef COMP345_A1_FIGHTERTEST_H
#define COMP345_A1_FIGHTERTEST_H
#include <cppunit/extensions/HelperMacros.h>
#include "../../Fighter.h"


class FighterTest: public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(FighterTest);
    CPPUNIT_TEST(testClassName);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp() override;
    void tearDown() override;
    void testClassName();
private:
    Fighter* fighter{};
};


#endif //COMP345_A1_FIGHTERTEST_H
