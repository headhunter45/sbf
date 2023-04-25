#include "Ranks.h"

#include <ostream>
#include <string>
#include <vector>

namespace SBF {
namespace {
using std::ostream;
using std::string;
using std::vector;
}  // End namespace

const std::string kRankPrimaryLabel = "Primary";
const std::string kRankSecondaryLabel = "Secondary";
const std::string kRankTertiaryLabel = "Tertiary";
const int kRanksCount = 3;
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

ostream& operator<<(ostream& os, const RankType& rank) {
  os << "Rank: {id: " << rank.id << ", label: \"" << rank.label << "\"}";
  return os;
}

bool operator==(const RankType& left, const RankType& right) {
  return left.id == right.id && left.label == right.label;
}

bool operator!=(const RankType& left, const RankType& right) {
  return !(left == right);
}

RankType GetRank(int rankId) {
  if (rankId > 0 && rankId <= kRanksCount) {
    return kRanks[rankId];
  }
  return kRankUnknown;
}

void FillRanks(std::vector<RankType>& ranks) {
  ranks.clear();
  for (int id = 1; id <= kRanksCount; id++) {
    ranks.push_back(GetRank(id));
  }
}
}  // End namespace SBF
