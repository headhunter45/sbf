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
const std::string kGenderMaleLabel = "Male";
const int kGenderFemaleId = 2;
const std::string kGenderFemaleLabel = "Female";
const int kGenderTransMaleId = 3;
const std::string kGenderTransMaleLabel = "Trans-Male";
const int kGenderTransFemaleId = 4;
const std::string kGenderTransFemaleLabel = "Trans-Female";
const int kGenderNonBinaryId = 5;
const std::string kGenderNonBinaryLabel = "Non-Binary";
const int kGendersCount = 5;
const std::string kGenderLabels[] = {
    "",
    kGenderMaleLabel,
    kGenderFemaleLabel,
    kGenderTransMaleLabel,
    kGenderTransFemaleLabel,
    kGenderNonBinaryLabel,
};

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
