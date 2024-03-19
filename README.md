\mainpage
# COMP345 Project

## Overview
This project is a C++ implementation for the COMP345 d20 assignment. It showcases the creation and functionality of characters, maps, item containers, and dice, adhering to the d20 game system rules.

## Project Structure
- **Core Components:** Implementation of characters, maps, item containers, and dice.
- **CppUnit Test Suite:** Ensures functionality passes all test cases.
- **Documentation:** Provided via Doxygen comments in the code.

## Compilation and Build Instructions
To compile and build the project, follow these steps:

1. Ensure you have CMake and a C++17 compatible compiler installed.
2. Clone the repository:
   ```git clone https://github.com/Reuven1203/COMP345-A1.git```
3. Navigate to the project directory:
   ```cd COMP345-A1  ```
4. Create a build directory and navigate into it:
   ```mkdir build && cd build   ```
5. Run CMake to generate the build system:
   ```cmake ..   ```
6. Compile the project:
   ```cmake --build .  ```

## Running the Project
After building, you can run the project executables directly from the build directory. The project includes several executables, such as `A1-map`, `A1-Character`, and `dice_run`, which can be run as follows:
```./A1-Character```

## Testing
To run the test suite, follow the build instructions and then use the following command:
```./COMP345_A1_Tests```

## Design and Implementation Details
- **Character Abilities and Stats:** Dynamically adjusted based on equipped items.
- **Item Effects:** Defined by enchantment modifiers affecting character abilities and stats.
- **Dice Rolling:** Utilizes a custom `Dice` class for simulating dice rolls according to the d20 system.

## Game Rules and Implementation
This project adheres to specific d20 game rules across its various components. Here is a brief overview:

### Abilities Assignment Based on Equipped Items
Characters have their abilities (e.g., Strength, Dexterity) and stats (e.g., Armor Class) dynamically adjusted based on the items they equip. Each item type (e.g., Helmet, Armor) has specific effects on the character's abilities and stats, determined by enchantment modifiers. For example, equipping a Helmet might increase a character's Intelligence and Wisdom, while a Belt might boost Strength and Constitution. This dynamic adjustment allows for a flexible and strategic approach to character development and gameplay, adhering to the d20 system's rules.

For more detailed information on the design decisions and implementation details, refer to the header files and Doxygen-generated documentation.
