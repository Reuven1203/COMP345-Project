//
// Created by Reuven Ostrofsky on 2024-03-11.
//

#ifndef COMP345_A1_OBSERVABLETEST_H
#define COMP345_A1_OBSERVABLETEST_H
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../../Observer/Observable.h"
#include "MockObserver.h"






class ObservableTest : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(ObservableTest);
    CPPUNIT_TEST(testAttach);
    CPPUNIT_TEST(testDetach);
    CPPUNIT_TEST(testNotify);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp() override;
    void tearDown() override;
    void testAttach();
    void testDetach();
    void testNotify();
    private:
    Observable* observable{};
    MockObserver* observer{};

};


#endif //COMP345_A1_OBSERVABLETEST_H
