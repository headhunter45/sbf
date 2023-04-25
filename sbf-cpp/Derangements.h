#ifndef DERANGEMENTS_H__
#define DERANGEMENTS_H__
#include "Colors.h"
/***************************************************************************************
 * @file Derangements.h
 *
 * @brief Defines constants and functions for working with derangements.
 * @copyright
 * Copyright 2023 Tom Hicks
 * Licensed under the MIT license see the LICENSE file for details.
 ***************************************************************************************/
#include <string>
#include <vector>

/** \addtogroup Derangements
 * @{
 */
namespace SBF {
struct DerangementType {
  int id;
  std::string label;
  std::string description;
  uint8_t textColor;
};

const int kDerangementAmnesiaId = 1;
const int kDerangementDelusionsOfGrandeurId = 2;
const int kDerangementFantasyId = 3;
const int kDerangementManicDepressionId = 4;
const int kDerangementMultiplePersonalitiesId = 5;
const int kDerangementObsessionId = 6;
const int kDerangementOvercompensationId = 7;
const int kDerangementParanoiaId = 8;
const int kDerangementPerfectionId = 9;
const int kDerangementRegressionId = 10;

/// @brief Determines the equality of two derangements.
/// @param left A derangement to compare.
/// @param right A derangement to compare.
/// @return True if the derangements are equal and false otherwise.
bool operator==(const DerangementType& left, const DerangementType& right);

/// @brief Determines the inequality of two derangements.
/// @param left A derangement to compare.
/// @param right A derangement to compare.
/// @return Tre if the derangements are unequal and false otherwise.
bool operator!=(const DerangementType& left, const DerangementType& right);

/// @brief Writes a derangement to an ostream.
/// @param os The ostream to write to.
/// @param derangement The derangement to write.
/// @return The provided ostream for chaining.
std::ostream& operator<<(std::ostream& os, const DerangementType& derangement);

/// @brief Gets the derangement with a specific id.
/// @param derangement_id The id of the derangement to get.
/// @return The derangement with an id of derangement_id or kDerangementUnknown if derangement_id is invalid.
DerangementType GetDerangement(int derangement_id);

/// @brief Fills the provided vector with all valid derangements.
/// @param derangements The vector to fill. It will be emptied first.
void FillDerangements(std::vector<DerangementType>& derangements);

std::vector<std::string> GetDerangementLabels();

std::vector<uint8_t> GetDerangementColors();
}  // End namespace SBF

/** @}*/
#endif  // End !defined DERANGEMENTS_H__
