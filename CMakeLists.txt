cmake_minimum_required(VERSION 3.27)
project(COMP345-A1)

set(CMAKE_CXX_STANDARD 17)

# Add the current directory to the list of paths that CMake uses to find modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

# Now CMake should be able to find and use your custom FindCppUnit.cmake module
find_package(CppUnit REQUIRED)

include_directories(${CPPUNIT_INCLUDE_DIRS})


# Automatically include all .cpp and .h files from the specified directories
file(GLOB_RECURSE CHARACTER_SOURCES "Character/*.cpp" "Character/*.h")
file(GLOB_RECURSE DICE_SOURCES "Dice/*.cpp" "Dice/*.h")
file(GLOB_RECURSE ITEM_SOURCES "Item/*.cpp" "Item/*.h")
file(GLOB_RECURSE MAP_SOURCES "Map/*.cpp" "Map/*.h")
file(GLOB_RECURSE OBSERVER_SOURCES "Observer/*.cpp" "Observer/*.h")
file(GLOB_RECURSE UTILS_SOURCES "Utils/*.cpp" "Utils/*.h")
file(GLOB_RECURSE BUILDER_SOURCES "Builder/*.cpp" "Builder/*.h")
file(GLOB_RECURSE DIRECTOR_SOURCES "Director/*.cpp" "Director/*.h")
file(GLOB_RECURSE STRATEGY_SOURCES "Strategy/*.cpp" "Strategy/*.h")

# Combine all sources
set(COMMON_SOURCES
        ${CHARACTER_SOURCES}
        ${DICE_SOURCES}
        ${ITEM_SOURCES}
        ${MAP_SOURCES}
        ${OBSERVER_SOURCES}
        ${UTILS_SOURCES}
        ${BUILDER_SOURCES}
        ${DIRECTOR_SOURCES}
        ${STRATEGY_SOURCES}

)

# Main application executable
add_executable(A1-map
        ${COMMON_SOURCES}
        map-test.cpp
)

add_executable(FighterBuilder
        ${COMMON_SOURCES}
        FighterBuilderDriver.cpp
)

add_executable(CharacterStrategyDriver
        ${COMMON_SOURCES}
        CharacterStrategyDriver.cpp
)

# Testing Others
add_executable(dice_run
        Character/Character.cpp
        Character/Fighter.cpp
        Dice/Dice.cpp
        Item/Item.cpp
        Item/itemContainer.cpp
        Map/cell.cpp
        Map/map.cpp)

add_executable(MapBuilderTest
        ${COMMON_SOURCES}
        MapBuilderDriver.cpp
        MapSaves/testsave.csv
)

add_executable(A2-MapEditor
        ${COMMON_SOURCES}
        CampaignEditor/MapEditor.h
        CampaignEditor/MapEditor.cpp
        MapEditorDriver.cpp
)

add_executable(A2-Campaign
        ${COMMON_SOURCES}
        Campaign/Campaign.cpp
        Campaign/Campaign.h
        CampaignDriver.cpp
        CampaignEditor/CampaignEditor.cpp
        CampaignEditor/CampaignEditor.h
        CampaignEditor/MapEditor.h
        CampaignEditor/MapEditor.cpp
)

# Enable testing
enable_testing()

# Assuming your tests are in the Tests directory
include_directories(Tests)

# Test executable
add_executable(
        COMP345_A1_Tests
        ${COMMON_SOURCES}
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
add_executable(CharacterObserver
        ${COMMON_SOURCES}
        CharacterObserverDriver.cpp
)
# Link the CppUnit library
target_link_libraries(COMP345_A1_Tests ${CPPUNIT_LIBRARIES})