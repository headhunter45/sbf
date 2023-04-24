#ifndef COLORS_H__
#define COLORS_H__
/***************************************************************************************
 * @file Colors.h
 *
 * @brief Defines constants and functions for working with screen colors.
 * @copyright
 * Copyright 2023 Tom Hicks
 * Licensed under the MIT license see the LICENSE file for details.
 ***************************************************************************************/
#include <cstdint>
#include <ostream>
#include <vector>

/** \addtogroup Abilities
 * @{
 */
namespace SBF {
const uint8_t kColorDarkBlack = 0;
const uint8_t kColorDarkRed = 1;
const uint8_t kColorDarkGreen = 2;
const uint8_t kColorDarkYellow = 3;
const uint8_t kColorDarkBlue = 4;
const uint8_t kColorDarkMagenta = 5;
const uint8_t kColorDarkCyan = 6;
const uint8_t kColorDarkWhite = 7;
const uint8_t kColorBrightBlack = 8;
const uint8_t kColorBrightRed = 9;
const uint8_t kColorBrightGreen = 10;
const uint8_t kColorBrightYellow = 11;
const uint8_t kColorBrightBlue = 12;
const uint8_t kColorBrightMagenta = 13;
const uint8_t kColorBrightCyan = 14;
const uint8_t kColorBrightWhite = 15;
const uint8_t kColorDefaultForeground = kColorBrightWhite;
const uint8_t kColorDefaultBackground = kColorDarkBlack;

/// @brief Sets the stored foreground color.
/// @param color The new foreground color.
uint8_t SetForegroundColor(uint8_t color);

/// @brief Gets the stored foreground color.
/// @return The foreground color.
uint8_t GetForegroundColor();

/// @brief Sets the stored background color.
/// @param color The new background color.
uint8_t SetBackgroundColor(uint8_t color);

/// @brief Gets the stored background color.
/// @return The background color.
uint8_t GetBackgroundColor();

/// @brief Fills the provided vector with all of the possible color values. It will be cleared before filling.
/// @param colors The vector to fill.
void FillColors(std::vector<uint8_t>& colors);

template <typename TChar, typename TTraits>
auto& Reset(std::basic_ostream<TChar, TTraits>& os) {
  return os << "\033[m";
}

template <typename TChar, typename TTraits>
auto& ForegroundColor(std::basic_ostream<TChar, TTraits>& os) {
  return os << "\033[38;5;" + std::to_string(GetForegroundColor()) + "m";
}

template <typename TChar, typename TTraits>
auto& BackgroundColor(std::basic_ostream<TChar, TTraits>& os) {
  return os << "\033[48;5;" + std::to_string(GetBackgroundColor()) + "m";
}

template <typename TChar, typename TTraits>
auto& Colors(std::basic_ostream<TChar, TTraits>& os) {
  return os << ForegroundColor << BackgroundColor;
}

template <typename TChar, typename TTraits>
auto& TrueColorForeground(std::basic_ostream<TChar, TTraits>& os, uint8_t red, uint8_t green, uint8_t blue) {
  return os << "\033[38;2;" << std::to_string(red) << ";" << std::to_string(green) << ";" << std::to_string(blue)
            << "m";
}

template <typename TChar, typename TTraits>
auto& TrueColorBackground(std::basic_ostream<TChar, TTraits>& os, uint8_t red, uint8_t green, uint8_t blue) {
  return os << "\033[48;2;" << std::to_string(red) << ";" << std::to_string(green) << ";" << std::to_string(blue)
            << "m";
}
}  // End namespace SBF

/** @}*/
#endif  // End !defined COLORS_H__
