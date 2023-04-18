#define _XOPEN_SOURCE_EXTENDED
#include "sbf.h"
#include <ncursesw/curses.h>
#include <iostream>
#include <cstdio>
#include <string>

#define KEY_ESCAPE 0033

using namespace std;

/*
| ╔ | WACS_D_ULCORNER | WACS_BDDB |
| ╚ | WACS_D_LLCORNER | WACS_DDBB |
| ╗ | WACS_D_URCORNER | WACS_BBDD |
| ╝ | WACS_D_LRCORNER | WACS_DBBD |
| ╣ | WACS_D_RTEE     | WACS_DBDD |
| ╠ | WACS_D_LTEE     | WACS_DDDB |
| ╩ | WACS_D_BTEE     | WACS_DDBD |
| ╦ | WACS_D_TTEE     | WACS_BDDD |
| ═ | WACS_D_HLINE    | WACS_BDBD |
| ║ | WACS_D_VLINE    | WACS_DBDB |
| ╬ | WACS_D_PLUS     | WACS_DDDD |
*/

int set_double_border(WINDOW* screen) {
    return wborder_set(screen,
        WACS_D_VLINE/*left side*/,
        WACS_D_VLINE/*right side*/,
        WACS_D_HLINE/*top side*/,
        WACS_D_HLINE/*bottom side*/,
        WACS_D_ULCORNER/*top left corner*/,
        WACS_D_URCORNER/*top right corner*/,
        WACS_D_LLCORNER/*bottom left corner*/,
        WACS_D_LRCORNER/*bottom right corner*/);
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "");
    char buffer[255] = {0};
    WINDOW* pWindow = nullptr;
    // Load ncurses and initialize stdscr.
    initscr();
    pWindow = stdscr;
    // Enable raw mode to give us direct access to extra keys.
    raw();
    // Disable echoing characters as they are typed.
    noecho();
    // Enable keypad characters. (function keys, arrow keys, and numpad keys.)
    keypad(pWindow, true);
    // Remove the delay when pressing esc.
    set_escdelay(0);
    
    int key = KEY_RESIZE;
    while(key != KEY_ESCAPE) {
        if (key == KEY_RESIZE) {
            // Clear the screen.
            werase(pWindow);
            // Draw a box around the window with default chars.
            set_double_border(pWindow);
            // Display the event
            mvwaddstr(pWindow, 2, 2, "Resized");
            // Get the window width and height.
            int width;
            int height;
            getmaxyx(pWindow, height, width);
            // Display the width and height.
            snprintf(buffer, sizeof(buffer), "width: %i, height: %i", width, height);
            mvwaddstr(pWindow, 1, 2, buffer);
        } else {
            // Display the keycode of the key that was pressed in hex and octal.
            snprintf(buffer, sizeof(buffer), "0x%04X %04o pressed", key, key);
            mvwaddstr(pWindow,2, 2, buffer);
        }
        wrefresh(pWindow);
        key = wgetch(pWindow);
    }
    endwin();
    
    return 0;
}
