#define _XOPEN_SOURCE_EXTENDED
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

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "");
    wchar_t buffer[255] = {0};

    // Load ncurses and initialize stdscr
    initscr();
    // Enable raw mode to give us direct access to extra keys.
    raw();
    // Disable echoing characters as they are typed.
    noecho();
    // Enable keypad characters (function keys, arrow keys, and numpad keys.)
    keypad(stdscr, true);

    // Create a window with width: 17, height: 15, startX: 10, startY: 2
    // These dimensions include the window bounds so the window actually starts at column 11 and row 3
    // The size of the window is actually 17 wide by 15 tall, but after drawing the border the usable
    // area is only 15x13 instead of 17x15.
    // WINDOW* newwin(nlines, ncols, begin_y, begin_x)
    // WINDOW* pWindow = newwin(15, 17, 2, 10);
    refresh();

    // Draw a box around the window with default chars
    wborder_set(stdscr,
        WACS_D_VLINE/*left side*/,
        WACS_D_VLINE/*right side*/,
        WACS_D_HLINE/*top side*/,
        WACS_D_HLINE/*bottom side*/,
        WACS_D_ULCORNER/*top left corner*/,
        WACS_D_URCORNER/*top right corner*/,
        WACS_D_LLCORNER/*bottom left corner*/,
        WACS_D_LRCORNER/*bottom right corner*/);
    
    int width;
    int height;
    getmaxyx(stdscr, height, width);
    swprintf(buffer, sizeof(buffer), L"width: %i, height: %i", width, height);
    mvaddwstr(1, 2, buffer);
    //mvaddwstr(5,5, L"x\u2562╢x");
    //mvadd_wch(3,2, WACS_D_PLUS);
    refresh();
    
    // wrefresh(pWindow);
    set_escdelay(0);
    bool done = false;
    while(!done) {
        int key = getch();
        swprintf(buffer, sizeof(buffer), L"0x%04o pressed", key);
        mvaddwstr(2, 2, buffer);
        if (key == KEY_ESCAPE) {
            done = true;
        }
    }
    endwin();
    
    return 0;
}
