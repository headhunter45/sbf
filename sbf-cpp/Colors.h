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
#include <vector>

/** \addtogroup Abilities
 * @{
 */
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

/// @brief Sets the stored foreground color.
/// @param color The new foreground color.
void SetForegroundColor(uint8_t color);

/// @brief Gets the stored foreground color.
/// @return The foreground color.
uint8_t GetForegroundColor();

/// @brief Sets the stored background color.
/// @param color The new background color.
void SetBackgroundColor(uint8_t color);

/// @brief Gets the stored background color.
/// @return The background color.
uint8_t GetBackgroundColor();

/// @brief Fills the provided vector with all of the possible color values. It will be cleared before filling.
/// @param colors The vector to fill.
void FillColors(std::vector<uint8_t>& colors);
}  // End namespace SBF

/** @}*/
#endif  // End !defined COLORS_H__
