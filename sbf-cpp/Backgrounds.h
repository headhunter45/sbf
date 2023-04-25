#ifndef BACKGROUNDS_H__
#define BACKGROUNDS_H__
/***************************************************************************************
 * @file Backgrounds.h
 *
 * @brief Defines constants and funcions for working with backgrounds.
 * @copyright
 * Copyright 2023 Tom Hicks
 * Licensed under the MIT license see the LICENSE file for details.
 ***************************************************************************************/
#include <string>
#include <vector>

/** \addtogroup Backgrounds
 * @{
 */
namespace SBF {
const int kBackgroundAlliesId = 1;
const int kBackgroundContactsId = 2;
const int kBackgroundFameId = 3;
const int kBackgroundGenerationId = 4;
const int kBackgroundHerdId = 5;
const int kBackgroundInfluenceId = 6;
const int kBackgroundMentorId = 7;
const int kBackgroundResourcesId = 8;
const int kBackgroundRetainersId = 9;
const int kBackgroundStatusId = 10;
const int kBackgroundsCount = 10;

/// @brief Gets the label for a background with a specific id.
/// @param background_id The id of the background to get the label for.
/// @return The label for the specified background or an empty string if background_id is invalid.
std::string GetBackgroundLabel(int background_id);

/// @brief Fills the provided vector with all valid background labels.
/// @param background_labels The vector to fill. It will be emptied first.
void FillBackgroundLabels(std::vector<std::string>& background_labels);

/// @brief Gets a vector of all the valid background labels.
/// @return The filled vector with index = background_id -1.
std::vector<std::string> GetBackgroundLabels();
}  // End namespace SBF

/** @}*/
#endif  // End !defined BACKGROUNDS_H__
