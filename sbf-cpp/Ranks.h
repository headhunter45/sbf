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

    const RankType kRanks[] {
        kRankUnknown,
        kRankPrimary,
        kRankSecondary,
        kRankTertiary,
    };

    std::ostream& operator<<(std::ostream& os, const RankType& abilityGroup);
    bool operator==(const RankType& left, const RankType& right);
    bool operator!=(const RankType& left, const RankType& right);
    RankType GetRank(int rankId);
    void FillRanks(std::vector<RankType>& ranks);
} // End namespace SBF
/** @}*/
#endif // !defined RANKS_H__
