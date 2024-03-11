//
// Created by Reuven Ostrofsky on 2024-03-11.
//

#include "ObservableTest.h"
#include "MockObserver.h"

CPPUNIT_TEST_SUITE_REGISTRATION(ObservableTest);

void ObservableTest::setUp() {
    TestFixture::setUp();
       observable = new Observable();
       observer = new MockObserver();


}

void ObservableTest::tearDown() {
    TestFixture::tearDown();
    delete observable;
    delete observer;
}

void ObservableTest::testAttach() {
    observable->attach(observer);
    CPPUNIT_ASSERT(observable->observers.size() == 1);
    CPPUNIT_ASSERT(observable->observers.front() == observer);
    CPPUNIT_ASSERT(observer->updated == false);
}

void ObservableTest::testDetach() {
    observable->attach(observer);
    CPPUNIT_ASSERT(observable->observers.size() == 1);
    CPPUNIT_ASSERT(observable->observers.front() == observer);
    observable->detach(observer);
    CPPUNIT_ASSERT(observable->observers.empty());
    CPPUNIT_ASSERT(observer->updated == false);

}

void ObservableTest::testNotify() {
    observable->attach(observer);
    CPPUNIT_ASSERT(observable->observers.size() == 1);
    CPPUNIT_ASSERT(observable->observers.front() == observer);
    observable->notify();
    CPPUNIT_ASSERT(observer->updated == true);
    observer->updated = false;
    CPPUNIT_ASSERT(observer->updated == false);
    observable->detach(observer);
    CPPUNIT_ASSERT(observable->observers.empty());
    observable->notify();
    CPPUNIT_ASSERT(observer->updated == false);
}
