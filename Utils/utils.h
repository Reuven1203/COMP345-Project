//
// Created by Reuven Ostrofsky on 2024-03-11.
//

#ifndef COMP345_A1_UTILS_H
#define COMP345_A1_UTILS_H

#include <iostream>

#ifdef _WIN32
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13
#define ONE_KEY 49
#define TWO_KEY 50
#define THREE_KEY 51
#define FOUR_KEY 52
#else
#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_LEFT 68
#define KEY_RIGHT 67
#define ENTER 10
#define ONE_KEY 49
#define TWO_KEY 50
#define THREE_KEY 51
#define FOUR_KEY 52
#endif

int keyPress();
void clearConsole();
void clearScreen();
enum class SubjectType
{
    map,
    character,
    dice,
    none
};

#endif //COMP345_A1_UTILS_H
