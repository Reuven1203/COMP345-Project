cmake_minimum_required(VERSION 3.27)
project(COMP345-A1)

set(CMAKE_CXX_STANDARD 17)

# Add the current directory to the list of paths that CMake uses to find modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

# Now CMake should be able to find and use your custom FindCppUnit.cmake module
find_package(CppUnit REQUIRED)

include_directories(${CPPUNIT_INCLUDE_DIRS})

# Main application executable
add_executable(A1-map
        Character.cpp
        map-test.cpp
        Fighter.cpp
        Dice.cpp
        Item.cpp
        itemContainer.cpp
        cell.cpp
        map.cpp)

add_executable(A1-Character
        Character.cpp
        Fighter.cpp
        Dice.cpp
        Item.cpp
        itemContainer.cpp
        cell.cpp
        main.cpp
        map.cpp)

# Testing Others
add_executable(dice_run
        Character.cpp
        main.cpp
        Fighter.cpp
        Dice.cpp
        Item.cpp
        itemContainer.cpp
        cell.cpp
        map.cpp)

# Enable testing
enable_testing()

# Assuming your tests are in the Tests directory
include_directories(Tests)

# Test executable
add_executable(
        COMP345_A1_Tests
        Character.cpp
        Fighter.cpp
        Item.cpp
        Dice.cpp
        map.cpp
        map.h
        cell.cpp
        cell.h
        itemContainer.cpp
        itemContainer.h
        Tests/Character/CharacterTest.cpp
        Tests/Character/CharacterTest.h
        Tests/TestRunner.cpp
        Tests/Character/FighterTest.cpp
        Tests/Character/FighterTest.h
        Tests/Dice/DiceTest.cpp
        Tests/Item/ItemTest.cpp
        Tests/Map/MapTest.cpp
        Tests/Map/MapTest.h
        Tests/Map/CellTest.cpp
        Tests/Map/CellTest.h
)

# Link the CppUnit library
target_link_libraries(COMP345_A1_Tests ${CPPUNIT_LIBRARIES})