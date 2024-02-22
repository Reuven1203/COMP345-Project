# COMP345-A1

## Overview
This repository contains a C++ project for the COMP345 d20 assignment, designed to be compiled and executed with C++17 or later. The project demonstrates the implementation of a solution to one of the specified problems (Part 1, 2, 3, or 4) related to the d20 game system. It includes a driver to compile and execute the code, showcasing the creation and functionality of characters, maps, item containers, or dice as per the project requirements and d20 game rules.

## Project Structure
- **Character, Map, Item Container, and Dice Implementation:** Core components of the project, including their creation and interaction following the d20 specifications.
- **CppUnit Test Suite:** Accompanies each part of the project, ensuring that the implementation passes all provided test cases. Additional test cases are also included to further validate the functionality.
- **Documentation:** Code and test cases are documented using Doxygen, providing clear insights into the game rules, design decisions, and the rationale behind the selection of libraries.

## Getting Started
To compile and run the project:
1. Ensure you have a C++17 compatible compiler installed.
2. Clone the repository to your local machine.
3. Navigate to the project directory and compile the code using your preferred C++ compiler.
4. Execute the compiled driver to see demonstrations of the implemented features.

## Contribution
- **Driver Implementation:** The `main.cpp` file contains the driver code, demonstrating possible uses of the implemented features through object creation and functionality testing.
- **Test Cases:** The `Tests` directory contains the CppUnit test suites for each component, including additional test cases provided by the contributors.

## Design and Libraries
The project's design and the selection of libraries are documented within the header files, offering insights into the architectural choices and the advantages of chosen libraries.

## Game Rules and Implementation
This project adheres to specific d20 game rules across its various components (characters, maps, item containers, and dice). Detailed documentation of these rules and their implementation is embedded within the code files and Doxygen comments. Here is a brief overview:

### Abilities Assignment Based on Equipped Items
Characters have their abilities (e.g., Strength, Dexterity) and stats (e.g., Armor Class) dynamically adjusted based on the items they equip. Each item type (e.g., Helmet, Armor) has specific effects on the character's abilities and stats, determined by enchantment modifiers. For example, equipping a Helmet might increase a character's Intelligence and Wisdom, while a Belt might boost Strength and Constitution. This dynamic adjustment allows for a flexible and strategic approach to character development and gameplay, adhering to the d20 system's rules.

## Note
This project focuses on the coding aspect of software development, aligning with the course's emphasis. External documentation beyond what is provided within the code and this README is discouraged.
