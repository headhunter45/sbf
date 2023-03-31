#ifndef RANKS_H__
#define RANKS_H__
#include <string>
#include <vector>

namespace SBF {
    const int kRankPrimaryId = 1;
    const std::wstring kRankPrimaryLabel = L"Primary";
    const int kRankSecondaryId = 2;
    const std::wstring kRankSecondaryLabel = L"Secondary";
    const int kRankTertiaryId = 3;
    const std::wstring kRankTertiaryLabel = L"Tertiary";
    const int kRanksCount = 3;
    struct RankType {
        int id;
        std::wstring label;
    };
    const RankType kRanks[] {
        {0, L""},
        {kRankPrimaryId, kRankPrimaryLabel},
        {kRankSecondaryId, kRankSecondaryLabel},
        {kRankTertiaryId, kRankTertiaryLabel},
    };
    const RankType& GetRank(int rankId);
    void FillRanks(std::vector<RankType> ranks);
} // End namespace SBF
#endif // !defined RANKS_H__
