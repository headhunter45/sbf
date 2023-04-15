#ifndef RANKS_H__
#define RANKS_H__
#include <string>
#include <vector>

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
    const RankType kRanks[] {
        {0, ""},
        {kRankPrimaryId, kRankPrimaryLabel},
        {kRankSecondaryId, kRankSecondaryLabel},
        {kRankTertiaryId, kRankTertiaryLabel},
    };
    const RankType& GetRank(int rankId);
    void FillRanks(std::vector<RankType> ranks);
} // End namespace SBF
#endif // !defined RANKS_H__
