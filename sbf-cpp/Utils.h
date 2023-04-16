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

    size_t get_index_of(const string& text, const string& search, size_t start);
    string word_wrap(const string& text, int maxWidth);
    string get_substring(const string& text, int32_t var1, int32_t var2);
    string make_fit_l(const string& text, size_t length, char paddCh);
    string left(const string& text, size_t length);
    string string_dollar(size_t length, char ch);

} // End namespace SBF
/** @}*/
#endif // End !defined UTILS_H__
