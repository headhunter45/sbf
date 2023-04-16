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
    const int kDisciplinePoints = 3;
    const int kDisciplineAnimalismId = 1;
    const std::string kDisciplineAnimalismLabel = "Animalism";
    const int kDisciplineAuspexId = 2;
    const std::string kDisciplineAuspexLabel = "Auspex";
    const int kDisciplineBardoId = 3;
    const std::string kDisciplineBardoLabel = "Bardo";
    const int kDisciplineCelerityId = 4;
    const std::string kDisciplineCelerityLabel = "Celerity";
    const int kDisciplineChimestryId = 5;
    const std::string kDisciplineChimestryLabel = "Chimestry";
    const int kDisciplineDementationId = 6;
    const std::string kDisciplineDementationLabel = "Dementation";
    const int kDisciplineDominateId = 7;
    const std::string kDisciplineDominateLabel = "Dominate";
    const int kDisciplineFortitudeId = 8;
    const std::string kDisciplineFortitudeLabel = "Fortitude";
    const int kDisciplineMelpomineeId = 9;
    const std::string kDisciplineMelpomineeLabel = "Melpominee";
    const int kDisciplineMortisId = 10;
    const std::string kDisciplineMortisLabel = "Mortis";
    const int kDisciplineMytherceriaId = 11;
    const std::string kDisciplineMytherceriaLabel = "Mytherceria";
    const int kDisciplineNecromancyId = 12;
    const std::string kDisciplineNecromancyLabel = "Necromancy";
    const int kDisciplineObeahId = 13;
    const std::string kDisciplineObeahLabel = "Obeah";
    const int kDisciplineObfuscateId = 14;
    const std::string kDisciplineObfuscateLabel = "Obfuscate";
    const int kDisciplineObtenebrationId = 15;
    const std::string kDisciplineObtenebrationLabel = "Obtenebration";
    const int kDisciplinePotenceId = 16;
    const std::string kDisciplinePotenceLabel = "Potence";
    const int kDisciplinePresenceId = 17;
    const std::string kDisciplinePresenceLabel = "Presence";
    const int kDisciplineProteanId = 18;
    const std::string kDisciplineProteanLabel = "Protean";
    const int kDisciplineQuietusId = 19;
    const std::string kDisciplineQuietusLabel = "Quietus";
    const int kDisciplineSerpentisId = 20;
    const std::string kDisciplineSerpentisLabel = "Serpentis";
    const int kDisciplineSpiritusId = 21;
    const std::string kDisciplineSpiritusLabel = "Spiritus";
    const int kDisciplineThanantosisId = 22;
    const std::string kDisciplineThanantosisLabel = "Thanantosis";
    const int kDisciplineThaumaturgyId = 23;
    const std::string kDisciplineThaumaturgyLabel = "Thaumaturgy";
    const int kDisciplineVicissitudeId = 24;
    const std::string kDisciplineVicissitudeLabel = "Vicissitude";
    const int kDisciplinesCount = 24;
    const std::string kDisciplines[] = {
        "",
        kDisciplineAnimalismLabel,
        kDisciplineAuspexLabel,
        kDisciplineBardoLabel,
        kDisciplineCelerityLabel,
        kDisciplineChimestryLabel,
        kDisciplineDementationLabel,
        kDisciplineDominateLabel,
        kDisciplineFortitudeLabel,
        kDisciplineMelpomineeLabel,
        kDisciplineMortisLabel,
        kDisciplineMytherceriaLabel,
        kDisciplineNecromancyLabel,
        kDisciplineObeahLabel,
        kDisciplineObfuscateLabel,
        kDisciplineObtenebrationLabel,
        kDisciplinePotenceLabel,
        kDisciplinePresenceLabel,
        kDisciplineProteanLabel,
        kDisciplineQuietusLabel,
        kDisciplineSerpentisLabel,
        kDisciplineSpiritusLabel,
        kDisciplineThanantosisLabel,
        kDisciplineThaumaturgyLabel,
        kDisciplineVicissitudeLabel,
    };
    const std::string GetDisciplineLabel(int disciplineId);
    void FillDisciplineLabels(std::vector<std::string> disciplineLabels);
} // End namespace SBF
/** @}*/
#endif // End !defined DISCIPLINES_H__
