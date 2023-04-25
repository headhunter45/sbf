#ifndef ARCHETYPES_H__
#define ARCHETYPES_H__
/***************************************************************************************
 * @file Archetypes.h
 *
 * @brief Defines constants and functions for working with archetypes.
 * @copyright
 * Copyright 2023 Tom Hicks
 * Licensed under the MIT license see the LICENSE file for details.
 ***************************************************************************************/
#include <string>
#include <vector>

/** \addtogroup Archetypes
 * @{
 */
namespace SBF {
/// @brief Gets the label for the given archetype id.
/// @param archetypeId The id of the archetype to get the label for.
/// @return The label for the requested archetype.
std::string GetArchetypeLabel(int archetypeId);

/// @brief Fills the provided vector with all of the archetype labels. It clears the vector before filling.
/// @param archetypeLabels The vector to fill.
void FillArchetypeLabels(std::vector<std::string>& archetypeLabels);
}  // End namespace SBF

/** @}*/
#endif  // End !defined ARCHETYPES_H__
