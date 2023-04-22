#ifndef RANKS_H__
#define RANKS_H__
/***************************************************************************************
 * @file Ranks.h
 *
 * @brief Defines constants and functions for working with ranks.
 * @copyright
 * Copyright 2023 Tom Hicks
 * Licensed under the MIT license see the LICENSE file for details.
 ***************************************************************************************/
#include <string>
#include <vector>

/** \addtogroup
 * @{
 */
namespace SBF {
const int kRankPrimaryId = 1;
const std::string kRankPrimaryLabel = "Primary";
const int kRankSecondaryId = 2;
const std::string kRankSecondaryLabel = "Secondary";
const int kRankTertiaryId = 3;
const std::string kRankTertiaryLabel = "Tertiary";
const int kRanksCount = 3;

struct RankType {
  int id;
  std::string label;
};

const RankType kRankPrimary = {kRankPrimaryId, kRankPrimaryLabel};
const RankType kRankSecondary = {kRankSecondaryId, kRankSecondaryLabel};
const RankType kRankTertiary = {kRankTertiaryId, kRankTertiaryLabel};
const RankType kRankUnknown = {0, ""};

const RankType kRanks[]{
    kRankUnknown,
    kRankPrimary,
    kRankSecondary,
    kRankTertiary,
};

/// @brief Writes a rank to an ostream.
/// @param os The ostream to write to.
/// @param rank The rank to write.
/// @return The provided ostream for chaining.
std::ostream& operator<<(std::ostream& os, const RankType& rank);

/// @brief Determines if two ranks are equal.
/// @param left A rank to compare.
/// @param right A rank to compare.
/// @return True if both ranks are equal and false otherwise.
bool operator==(const RankType& left, const RankType& right);

/// @brief Determines if two ranks are unequal.
/// @param left A rank to compare.
/// @param right A rank to compare.
/// @return True if both ranks are unequal and false otherwise.
bool operator!=(const RankType& left, const RankType& right);

/// @brief Gets a rank with a specific id.
/// @param rank_id The id of the rank to get.
/// @return The rank with id == rank_id or the unknown rank kRankUnknown if rank_id is invalid.
RankType GetRank(int rank_id);

/// @brief Fills the provided vector with all valid rank labels.
/// @param ranks The vector to fill. It will be cleared first.
void FillRanks(std::vector<RankType>& ranks);
}  // End namespace SBF

/** @}*/
#endif  // !defined RANKS_H__
