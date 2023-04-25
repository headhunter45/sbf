#ifndef DISCIPLINES_H__
#define DISCIPLINES_H__
/***************************************************************************************
 * @file Disciplines.h
 *
 * @brief Defines constants and functions for working with disciplines.
 * @copyright
 * Copyright 2023 Tom Hicks
 * Licensed under the MIT license see the LICENSE file for details.
 ***************************************************************************************/

#include <string>
#include <vector>

/** \addtogroup Disciplines
 * @{
 */
namespace SBF {

const int kDisciplineAnimalismId = 1;
const int kDisciplineAuspexId = 2;
const int kDisciplineBardoId = 3;
const int kDisciplineCelerityId = 4;
const int kDisciplineChimestryId = 5;
const int kDisciplineDementationId = 6;
const int kDisciplineDominateId = 7;
const int kDisciplineFortitudeId = 8;
const int kDisciplineMelpomineeId = 9;
const int kDisciplineMortisId = 10;
const int kDisciplineMytherceriaId = 11;
const int kDisciplineNecromancyId = 12;
const int kDisciplineObeahId = 13;
const int kDisciplineObfuscateId = 14;
const int kDisciplineObtenebrationId = 15;
const int kDisciplinePotenceId = 16;
const int kDisciplinePresenceId = 17;
const int kDisciplineProteanId = 18;
const int kDisciplineQuietusId = 19;
const int kDisciplineSerpentisId = 20;
const int kDisciplineSpiritusId = 21;
const int kDisciplineThanantosisId = 22;
const int kDisciplineThaumaturgyId = 23;
const int kDisciplineVicissitudeId = 24;

/// @brief Gets the label for a discipline with a specific id.
/// @param discipline_id The id of the discipline to get the label for.
/// @return The label of the discipline or an empty string if discipline_id is invalid.
std::string GetDisciplineLabel(int discipline_id);

/// @brief Fills the provided vector with all of the valid discipline labels.
/// @param discipline_labels The vector to fill. It will be cleared first.
void FillDisciplineLabels(std::vector<std::string>& discipline_labels);

int GetNumDisciplines();
}  // End namespace SBF

/** @}*/
#endif  // End !defined DISCIPLINES_H__
