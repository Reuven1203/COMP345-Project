cmake_minimum_required(VERSION 3.27)
project(COMP345-A1)

set(CMAKE_CXX_STANDARD 17)

# Add the current directory to the list of paths that CMake uses to find modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

# Now CMake should be able to find and use your custom FindCppUnit.cmake module
find_package(CppUnit REQUIRED)

include_directories(${CPPUNIT_INCLUDE_DIRS})


# Common source files
set(COMMON_SOURCES
        Character/Character.cpp
        Character/Fighter.cpp
        Dice/Dice.cpp
        Item/Item.cpp
        Item/itemContainer.cpp
        Map/cell.cpp
        Map/map.cpp
        Observer/Observable.cpp
        Observer/Observable.h
        Observer/CharacterObserver/CharacterDisplay.cpp
        Observer/CharacterObserver/CharacterDisplay.h
        Utils/utils.cpp
        Utils/utils.h
)

# Main application executable
add_executable(A1-map
        ${COMMON_SOURCES}
        map-test.cpp
        Observer/MapObserver/MapObserver.cpp
        Observer/MapObserver/MapObserver.h
)

add_executable(A1-Character
        ${COMMON_SOURCES}
        main.cpp
)

# Testing Others
add_executable(dice_run
        Character/Character.cpp
        main.cpp
        Character/Fighter.cpp
        Dice/Dice.cpp
        Item/Item.cpp
        Item/itemContainer.cpp
        Map/cell.cpp
        Map/map.cpp)

add_executable(MapBuilderTest
        ${COMMON_SOURCES}
        Character/Character.h
        Character/Fighter.h
        MapBuilderDriver.cpp
        Map/map.cpp
        Map/map.h
        MapSaves/testsave.csv
        CampaignEditor/DefaultMapBuilder.h
        CampaignEditor/MapDirector.h
        CampaignEditor/MapBuilder.cpp
        CampaignEditor/MapBuilder.h
        Map/cell.cpp
        Map/cell.h
)

add_executable(A2-MapEditor
        ${COMMON_SOURCES}
        Character/Character.h
        Character/Fighter.h
        Map/map.cpp
        Map/map.h
        CampaignEditor/MapEditor.h
        CampaignEditor/MapEditor.cpp
        Map/cell.h
        MapEditorDriver.cpp
        Observer/MapObserver/MapObserver.h
        Observer/MapObserver/MapObserver.cpp
        CampaignEditor/MapBuilder.h
        CampaignEditor/MapBuilder.cpp
        CampaignEditor/MapDirector.h
        CampaignEditor/DefaultMapBuilder.h
)

add_executable(A2-Campaign
        ${COMMON_SOURCES}
        Campaign/Campaign.cpp
        Campaign/Campaign.h
        CampaignDriver.cpp
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

