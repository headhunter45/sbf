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

/** \addtogroup Utils
 * @{
 */
namespace SBF {
using std::string;

/// @brief Gets the first index of search in text starting at start.
/// @param text The text to search.
/// @param search The text to search for.
/// @param start The position to start searching at.
/// @return The position of the string if found and std::npos if not found.
size_t get_index_of(const string& text, const string& search, const size_t start);

/// @brief Collapses white space and attempts to word wrap text to a max of max_width columns.
/// @param text The text to wrap.
/// @param max_width The number of columns to wrap to.
/// @return The wrapped text.
string word_wrap(const string& text, const size_t max_width);

/// @brief Gets a substring of another string.
/// @param text The text to split.
/// @param start The starting position.
/// @param length The length of the substring.
/// @return The sub string of text.
string get_substring(const string& text, const size_t start, const size_t length);

/// @brief Pads or truncates text to length using pad_character.
/// @param text The text to operate on.
/// @param length The desired length to make text.
/// @param pad_character The character to pad with.
/// @return The modified string.
string make_fit_l(const string& text, const size_t length, const char pad_character);

/// @brief Gets the leftmost length characters of text.
/// @param text The text to operate on.
/// @param length The maximum number of characters to return.
/// @return The leftmost n characters of text where n is the lesser of text.size and length.
string left(const string& text, const size_t length);

/// @brief Gets a string made by repeating a character.
/// @param length The length of the string to return.
/// @param ch The character to repeat.
/// @return The repeated string.
string string_dollar(const size_t length, const char ch);
}  // End namespace SBF

/** @}*/
#endif  // End !defined UTILS_H__
