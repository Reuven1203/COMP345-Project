//
// Created by Reuven Ostrofsky on 2024-02-21.
//

#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include "./Character/CharacterTest.h"


int main(int argc, char* argv[]) {
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest(registry.makeTest());
    runner.addTest(CharacterTest::suite());
    bool wasSuccessful = runner.run("", false);
    return wasSuccessful ? 0 : 1;
}