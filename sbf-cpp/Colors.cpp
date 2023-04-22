#include "Colors.h"

namespace SBF {

// TODO: Update these if they're wrong. They should be the initial color pair.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-variable"
uint8_t g_foregroundColor = kColorDarkWhite;
uint8_t g_backgroundColor = kColorDarkBlack;
#pragma clang diagnostic pop

void FillColors(std::vector<uint8_t>& colors) {
  colors.clear();
  for (uint8_t color = kColorDarkBlack; color <= kColorBrightWhite; color++) {
    colors.push_back(color);
  }
}

uint8_t GetBackgroundColor() {
  return g_backgroundColor;
}

uint8_t GetForegroundColor() {
  return g_foregroundColor;
}

// TODO: Define what happens when color is invalid.
void SetBackgroundColor(uint8_t color) {
  g_backgroundColor = color;
}

// TODO: Define what happens when color is invalid.
void SetForegroundColor(uint8_t color) {
  g_foregroundColor = color;
}
}  // End namespace SBF
