#ifndef CLANS_H__
#define CLANS_H__
/***************************************************************************************
 * @file Clans.h
 *
 * @brief Defines constants and functions for working with clans.
 * @copyright
 * Copyright 2023 Tom Hicks
 * Licensed under the MIT license see the LICENSE file for details.
 ***************************************************************************************/
#include <string>
#include <vector>

/** \addtogroup Clans
 * @{
 */
namespace SBF {
const int kClanAnarchId = 1;
const int kClanAssamiteId = 2;
const int kClanBaaliId = 3;
const int kClanBrujahId = 4;
const int kClanCaitiffId = 5;
const int kClanCappadocianId = 6;
const int kClanGangrelId = 7;
const int kClanGiovanniId = 8;
const int kClanInconnuId = 9;
const int kClanLasombraId = 10;
const int kClanMalkavianId = 11;
const int kClanNosferatuId = 12;
const int kClanRavanosId = 13;
const int kClanSettiteId = 14;
const int kClanToreadorId = 15;
const int kClanTremereId = 16;
const int kClanTzismiceId = 17;
const int kClanVentrueId = 18;

/// @brief Gets the label for a clan with a specific id.
/// @param clan_id The id of the clan to get the label for.
/// @return The label of the specified clan or an empty string if clan_id is invalid.
std::string GetClanLabel(int clan_id);

/// @brief Fills the provided vector with all valid clans.
/// @param clans The vector to fill. It will be emptied first.
void FillClanLabels(std::vector<std::string>& clans);
}  // End namespace SBF

/** @}*/
#endif  // End !defined CLANS_H__
