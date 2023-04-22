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
const int kClanAnarch = 1;
const std::string kClanAnarchLabel = "Anarch";
const int kClanAssamite = 2;
const std::string kClanAssamiteLabel = "Assamite";
const int kClanBaali = 3;
const std::string kClanBaaliLabel = "Baali";
const int kClanBrujah = 4;
const std::string kClanBrujahLabel = "Brujah";
const int kClanCaitiff = 5;
const std::string kClanCaitiffLabel = "Caitiff";
const int kClanCappadocian = 6;
const std::string kClanCappadocianLabel = "Cappadocian";
const int kClanGangrel = 7;
const std::string kClanGangrelLabel = "Gangrel";
const int kClanGiovanni = 8;
const std::string kClanGiovanniLabel = "Giovanni";
const int kClanInconnu = 9;
const std::string kClanInconnuLabel = "Inconnu";
const int kClanLasombra = 10;
const std::string kClanLasombraLabel = "Lasombra";
const int kClanMalkavian = 11;
const std::string kClanMalkavianLabel = "Malkavian";
const int kClanNosferatu = 12;
const std::string kClanNosferatuLabel = "Nosferatu";
const int kClanRavanos = 13;
const std::string kClanRavanosLabel = "Ravanos";
const int kClanSettite = 14;
const std::string kClanSettiteLabel = "Settite";
const int kClanToreador = 15;
const std::string kClanToreadorLabel = "Toreador";
const int kClanTremere = 16;
const std::string kClanTremereLabel = "Tremere";
const int kClanTzismice = 17;
const std::string kClanTzismiceLabel = "Tzismice";
const int kClanVentrue = 18;
const std::string kClanVentrueLabel = "Ventrue";
const int kClansCount = 18;
const std::string kClanLabels[] = {
    "",
    kClanAnarchLabel,
    kClanAssamiteLabel,
    kClanBaaliLabel,
    kClanBrujahLabel,
    kClanCaitiffLabel,
    kClanCappadocianLabel,
    kClanGangrelLabel,
    kClanGiovanniLabel,
    kClanInconnuLabel,
    kClanLasombraLabel,
    kClanMalkavianLabel,
    kClanNosferatuLabel,
    kClanRavanosLabel,
    kClanSettiteLabel,
    kClanToreadorLabel,
    kClanTremereLabel,
    kClanTzismiceLabel,
    kClanVentrueLabel,
};

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
