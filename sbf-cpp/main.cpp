#include <ncurses.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    // cout << "Hello, World!" << endl;
    initscr();
    raw();
    noecho();
    keypad(stdscr, true);

    printw("Hello, World!");
    refresh();
    getch();
    endwin();

    return 0;
}
