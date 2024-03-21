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
#else
#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_LEFT 68
#define KEY_RIGHT 67
#define ENTER 10
#endif

int keyPress();

enum class SubjectType
{
    map,
    character,
    dice
};

#endif //COMP345_A1_UTILS_H
