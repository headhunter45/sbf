#include "Colors.h"

namespace SBF {
    
    // TODO: Update these if they're wrong. They should be the initial color pair.
    static uint8_t g_foregroundColor = kColorDarkWhite;
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunused-variable"
    static uint8_t g_backgroundColor = kColorDarkBlack;
    #pragma clang diagnostic pop
    static uint16_t g_color;

    void SetForegroundColor(uint8_t foregroundColor) {
        g_foregroundColor = foregroundColor;
        // TODO: update g_color with g_foregroundColor and g_backgroundColor.
    }
    uint8_t GetForegroundColor() {
        return g_foregroundColor;
    }

    // ncurses color pair
    uint16_t GetColor() {
        return g_color;
    }

} // End namespace SBF
