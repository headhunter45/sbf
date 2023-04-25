#ifndef GENDERS_H__
#define GENDERS_H__
/***************************************************************************************
 * @file Genders.h
 *
 * @brief Defines constants and functions for working with genders.
 * @copyright
 * Copyright 2023 Tom Hicks
 * Licensed under the MIT license see the LICENSE file for details.
 ***************************************************************************************/
#include <string>
#include <vector>

/** \addtogroup Genders
 * @{
 */
namespace SBF {
const int kGenderMaleId = 1;
const int kGenderFemaleId = 2;
const int kGenderTransMaleId = 3;
const int kGenderTransFemaleId = 4;
const int kGenderNonBinaryId = 5;

/// @brief Gets a gender label with a specific id.
/// @param gender_id The id of the gender to return the label for.
/// @return The label of the specified gender or an empty string if gender_id is invalid.
std::string GetGenderLabel(int gender_id);

/// @brief Fills the provided vector with all of the valid gender labels.
/// @param gender_labels The vector to fill. It will be cleared first.
void FillGenderLabels(std::vector<std::string>& gender_labels);
}  // End namespace SBF

/** @}*/
#endif  // End !defined GENDERS_H__
