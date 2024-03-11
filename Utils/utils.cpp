//
// Created by Reuven Ostrofsky on 2024-03-11.
//

// utils.cpp
#include "utils.h"
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>

int _getch() {
    struct termios oldt{}, newt{};
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    if (ch == 27) { // Escape character detected
        // Use non-blocking read to check if there are more characters
        newt.c_cc[VMIN] = 0;
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        int next_char1 = getchar();

        if (next_char1 == -1) {
            // No more characters, it was just the ESC key
            ch = 27; // ESC key code
        } else {
            int next_char2 = getchar();
            if (next_char1 == 91) { // '[' character, confirming it's an arrow key sequence
                switch (next_char2) {
                    case 65: // Up arrow key
                        ch = 65; // You can define custom values or macros to make this more readable
                        break;
                    case 66: // Down arrow key
                        ch = 66;
                        break;
                    case 67: // Right arrow key
                        ch = 67;
                        break;
                    case 68: // Left arrow key
                        ch = 68;
                        break;
                    default:
                        ch = next_char2; // Not an arrow key, return as is
                        break;
                }
            }
        }
        // Restore blocking read
        newt.c_cc[VMIN] = 1;
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}


#endif

