
# COMP345-A1 Project

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

## Contribution Guidelines
Contributions are welcome. Please ensure that any contributions follow the existing project structure and coding standards. Add tests for new features when applicable.

## Design and Implementation Details
- **Character Abilities and Stats:** Dynamically adjusted based on equipped items.
- **Item Effects:** Defined by enchantment modifiers affecting character abilities and stats.
- **Dice Rolling:** Utilizes a custom `Dice` class for simulating dice rolls according to the d20 system.

For more detailed information on the design decisions and implementation details, refer to the header files and Doxygen-generated documentation.
```
