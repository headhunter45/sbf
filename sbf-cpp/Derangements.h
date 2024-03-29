﻿#ifndef DERANGEMENTS_H__
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
const uint8_t kDerangementAmnesiaTextColor = kColorDarkRed;
const std::string kDerangementAmnesiaLabel = "Amnesia";
const std::string kDerangementAmnesiaDescription =
    R"---(You forget a segment of your past. Additionally in some cases a character can forget abilities and be unable to use them for the duration.)---";
const int kDerangementDelusionsOfGrandeurId = 2;
const uint8_t kDerangementDelusionsOfGrandeurTextColor = kColorDarkMagenta;
const std::string kDerangementDelusionsOfGrandeurLabel = "Delusions of Grandeur";
const std::string kDerangementDelusionsOfGrandeurDescription = R"---(You imagine you are better than you are.)---";
const int kDerangementFantasyId = 3;
const uint8_t kDerangementFantasyTextColor = kColorDarkYellow;
const std::string kDerangementFantasyLabel = "Fantasy";
const std::string kDerangementFantasyDescription =
    R"---(You enter a self-created world where you are the forgotten hero.)---";
const int kDerangementManicDepressionId = 4;
const uint8_t kDerangementManicDepressionTextColor = kColorDarkWhite;
const std::string kDerangementManicDepressionLabel = "Manic-Depression";
const std::string kDerangementManicDepressionDescription =
    R"---(You sink into deep and fitful depressions, showing no interest in anything which used to captivate your interests. You will go along with others rather than use the energy to resist. Occasional fits of great energy grab hold of you, and you will work for hours or even days on your projects. During this time you will resist even the need for sleep as you burn up blood and Willpower on your schemes.)---";
const int kDerangementMultiplePersonalitiesId = 5;
const uint8_t kDerangementMultiplePersonalitiesTextColor = kColorDarkBlue;
const std::string kDerangementMultiplePersonalitiesLabel = "Multiple Personalities";
const std::string kDerangementMultiplePersonalitiesDescription =
    R"---(You possess a number of new personalities. You have amore than one Mature, and will switch between them. Thus you regain Willpower points in defferent ways at defferent times)---";
const int kDerangementObsessionId = 6;
const uint8_t kDerangementObsessionTextColor = kColorBrightGreen;
const std::string kDerangementObsessionLabel = "Obsession";
const std::string kDerangementObsessionDescription = R"---(You become obsessed with some interest or fetish.)---";
const int kDerangementOvercompensationId = 7;
const uint8_t kDerangementOvercompensationTextColor = kColorBrightCyan;
const std::string kDerangementOvercompensationLabel = "Overcompensation";
const std::string kDerangementOvercompensationDescription =
    R"---(You make up for your moral weaknesses by playing up your strengths to an extreme. You don't think you can frenzy and won't stop it.)---";
const int kDerangementParanoiaId = 8;
const uint8_t kDerangementParanoiaTextColor = kColorBrightRed;
const std::string kDerangementParanoiaLabel = "Paranoia";
const std::string kDerangementParanoiaDescription =
    R"---(You are convinced that you are being hunted. You hold even your closest Friends under suspicion.)---";
const int kDerangementPerfectionId = 9;
const uint8_t kDerangementPerfectionTextColor = kColorBrightMagenta;
const std::string kDerangementPerfectionLabel = "Perfection";
const std::string kDerangementPerfectionDescription =
    R"---(All your energy is directed toward preventing anything from going wong. When it does you must make a self-control roll or frenzy.)---";
const int kDerangementRegressionId = 10;
const uint8_t kDerangementRegressionTextColor = kColorBrightYellow;
const std::string kDerangementRegressionLabel = "Regression";
const std::string kDerangementRegressionDescription =
    R"---(You become childlike retreating to an earlier time when less was expected of you Willpower is regained inthe way a Child's is.)---";
const DerangementType kDerangementUnknown = {0, "", "", 0};
const DerangementType kDerangementAmnesia = {
    kDerangementAmnesiaId,
    kDerangementAmnesiaLabel,
    kDerangementAmnesiaDescription,
    kDerangementAmnesiaTextColor,
};
const DerangementType kDerangementDelusionsOfGrandeur = {
    kDerangementDelusionsOfGrandeurId,
    kDerangementDelusionsOfGrandeurLabel,
    kDerangementDelusionsOfGrandeurDescription,
    kDerangementDelusionsOfGrandeurTextColor,
};
const DerangementType kDerangementFantasy = {
    kDerangementFantasyId,
    kDerangementFantasyLabel,
    kDerangementFantasyDescription,
    kDerangementFantasyTextColor,
};
const DerangementType kDerangementManicDepression = {
    kDerangementManicDepressionId,
    kDerangementManicDepressionLabel,
    kDerangementManicDepressionDescription,
    kDerangementManicDepressionTextColor,
};
const DerangementType kDerangementMultiplePersonalities = {
    kDerangementMultiplePersonalitiesId,
    kDerangementMultiplePersonalitiesLabel,
    kDerangementMultiplePersonalitiesDescription,
    kDerangementMultiplePersonalitiesTextColor,
};
const DerangementType kDerangementObsession = {
    kDerangementObsessionId,
    kDerangementObsessionLabel,
    kDerangementObsessionDescription,
    kDerangementObsessionTextColor,
};
const DerangementType kDerangementOvercompensation = {
    kDerangementOvercompensationId,
    kDerangementOvercompensationLabel,
    kDerangementOvercompensationDescription,
    kDerangementOvercompensationTextColor,
};
const DerangementType kDerangementParanoia = {
    kDerangementParanoiaId,
    kDerangementParanoiaLabel,
    kDerangementParanoiaDescription,
    kDerangementParanoiaTextColor,
};
const DerangementType kDerangementPerfection = {
    kDerangementPerfectionId,
    kDerangementPerfectionLabel,
    kDerangementPerfectionDescription,
    kDerangementPerfectionTextColor,
};
const DerangementType kDerangementRegression = {
    kDerangementRegressionId,
    kDerangementRegressionLabel,
    kDerangementRegressionDescription,
    kDerangementRegressionTextColor,
};
const int kDerangementsCount = 10;

const uint8_t kDerangementTextColors[] = {
    0,
    kDerangementAmnesiaTextColor,
    kDerangementDelusionsOfGrandeurTextColor,
    kDerangementFantasyTextColor,
    kDerangementManicDepressionTextColor,
    kDerangementMultiplePersonalitiesTextColor,
    kDerangementObsessionTextColor,
    kDerangementOvercompensationTextColor,
    kDerangementParanoiaTextColor,
    kDerangementPerfectionTextColor,
    kDerangementRegressionTextColor,
};

const std::string kDerangementLabels[] = {
    "",
    kDerangementAmnesiaLabel,
    kDerangementDelusionsOfGrandeurLabel,
    kDerangementFantasyLabel,
    kDerangementManicDepressionLabel,
    kDerangementMultiplePersonalitiesLabel,
    kDerangementObsessionLabel,
    kDerangementOvercompensationLabel,
    kDerangementParanoiaLabel,
    kDerangementPerfectionLabel,
    kDerangementRegressionLabel,
};

const std::string kDerangementDescriptions[] = {
    "",
    kDerangementAmnesiaDescription,
    kDerangementDelusionsOfGrandeurDescription,
    kDerangementFantasyDescription,
    kDerangementManicDepressionDescription,
    kDerangementMultiplePersonalitiesDescription,
    kDerangementObsessionDescription,
    kDerangementOvercompensationDescription,
    kDerangementParanoiaDescription,
    kDerangementPerfectionDescription,
    kDerangementRegressionDescription,
};

const DerangementType kDerangements[] = {
    {0, "", "", 0},
    kDerangementAmnesia,
    kDerangementDelusionsOfGrandeur,
    kDerangementFantasy,
    kDerangementManicDepression,
    kDerangementMultiplePersonalities,
    kDerangementObsession,
    kDerangementOvercompensation,
    kDerangementParanoia,
    kDerangementPerfection,
    kDerangementRegression,
};

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
}  // End namespace SBF

/** @}*/
#endif  // End !defined DERANGEMENTS_H__
