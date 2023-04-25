#ifndef UTILS_H__
#define UTILS_H__
/***************************************************************************************
 * @file Utils.h
 *
 * @brief Defines various utility functions.
 * @copyright
 * Copyright 2023 Tom Hicks
 * Licensed under the MIT license see the LICENSE file for details.
 ***************************************************************************************/
#include <string>
#include <vector>

/** \addtogroup Utils
 * @{
 */
namespace SBF {

/// @brief Gets the first index of search in text starting at start.
/// @param text The text to search.
/// @param search The text to search for.
/// @param start The position to start searching at.
/// @return The position of the string if found and std::npos if not found.
size_t GetIndexOf(const std::string& text, const std::string& search, const size_t start);

/// @brief Collapses white space and attempts to word wrap text to a max of max_width columns.
/// @param text The text to wrap.
/// @param max_width The number of columns to wrap to.
/// @return The wrapped text.
std::vector<std::string> WordWrap(const std::string& text, const size_t max_width);

/// @brief Gets a substring of another string.
/// @param text The text to split.
/// @param start The starting position.
/// @param length The length of the substring.
/// @return The sub string of text.
std::string GetSubstring(const std::string& text, const size_t start, const size_t length);

/// @brief Pads on the right or truncates text to length using pad_character.
/// @param text The text to operate on.
/// @param length The desired length to make text.
/// @param pad_character The character to pad with.
/// @return The modified string.
std::string MakeFitL(const std::string& text, const size_t length, const char pad_character = ' ');

/// @brief Pads on both sides or truncates text to length using pad_character.
/// @param text The text to operate on.
/// @param length The desired length to make text.
/// @param pad_character The character to pad with.
/// @return The modified string.
std::string MakeFitC(const std::string& text, const size_t length, const char pad_character = ' ');

/// @brief Pads on the left or truncates text to length using pad_character.
/// @param text The text to operate on.
/// @param length The desired length to make text.
/// @param pad_character The character to pad with.
/// @return The modified string.
std::string MakeFitR(const std::string& text, const size_t length, const char pad_character = ' ');

/// @brief Pads or truncates the space between two strings.
/// @param prefix The text to put on the left.
/// @param suffix The text to put on the right.
/// @param length The desired length to make the result.
/// @param pad_character The character to pad with.
/// @return The modified string.
std::string MakeFitB(const std::string& prefix,
                     const std::string& suffix,
                     const size_t length,
                     const char pad_character = ' ');

/// @brief Gets the leftmost length characters of text.
/// @param text The text to operate on.
/// @param length The maximum number of characters to return.
/// @return The leftmost n characters of text where n is the lesser of text.size and length.
std::string Left(const std::string& text, const size_t length);

/// @brief Gets the rightmost length of characters of text.
/// @param text The text to operate on.
/// @param length The maximum number of characters to return.
/// @return The rightmost n characters of text where n is the lesser of text.size and length.
std::string Right(const std::string& text, const size_t length);

/// @brief Removes whitespace from the left side of text.
/// @param text The text to operate on.
std::string LeftTrim(const std::string& text);

/// @brief Removes whitespace from the right side of text.
/// @param text The text to operate on.
std::string RightTrim(const std::string& text);

/// @brief Gets a string made by repeating a character.
/// @param length The length of the string to return.
/// @param ch The character to repeat.
/// @return The repeated string.
std::string RepeatChar(const size_t length, const char ch = ' ');

/// @brief Gets the lowercase version of a string. This is a temporary hack until I figure out how to add ICU4C as a
/// bazel dependency.
/// @param text The text to convert.
/// @return The lowercase version of text. Currently this only supports ASCII characters.
std::string ToLower(const std::string& text);
}  // End namespace SBF

/** @}*/
#endif  // End !defined UTILS_H__
