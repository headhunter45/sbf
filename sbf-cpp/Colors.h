#ifndef COLORS_H__
#define COLORS_H__
#include <cstdint>

namespace SBF {

    const uint8_t kColorDarkBlack = 0;
    const uint8_t kColorDarkBlue = 1;
    const uint8_t kColorDarkGreen = 2;
    const uint8_t kColorDarkCyan = 3;
    const uint8_t kColorDarkRed = 4;
    const uint8_t kColorDarkMagenta = 5;
    const uint8_t kColorDarkOrange = 6;
    const uint8_t kColorDarkYellow = 6;
    const uint8_t kColorDarkWhite = 7;
    const uint8_t kColorBrightBlack = 8;
    const uint8_t kColorBrightBlue = 9;
    const uint8_t kColorBrightGreen = 10;
    const uint8_t kColorBrightCyan = 11;
    const uint8_t kColorBrightRed = 12;
    const uint8_t kColorBrightMagenta = 13;
    const uint8_t kColorBrightOrange = 14;
    const uint8_t kColorBrightYellow = 14;
    const uint8_t kColorBrightWhite = 15;

    void SetForegroundColor(uint8_t foregroundColor);
    uint8_t GetForegroundColor();
    // ncurses color pair
    uint16_t GetColor();

} // End namespace SBF

#endif
