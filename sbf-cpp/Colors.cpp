#include "Colors.h"

namespace SBF {

uint8_t g_foreground_color = kColorDefaultForeground;
uint8_t g_background_color = kColorDefaultBackground;

void FillColors(std::vector<uint8_t>& colors) {
  colors.clear();
  for (uint8_t color = kColorDarkBlack; color <= kColorBrightWhite; color++) {
    colors.push_back(color);
  }
}

uint8_t GetBackgroundColor() {
  return g_background_color;
}

uint8_t GetForegroundColor() {
  return g_foreground_color;
}

uint8_t SetBackgroundColor(uint8_t color) {
  uint8_t previous_color = color;
  g_background_color = color;
  return previous_color;
}

uint8_t SetForegroundColor(uint8_t color) {
  uint8_t previous_color = color;
  g_foreground_color = color;
  return previous_color;
}
}  // End namespace SBF
