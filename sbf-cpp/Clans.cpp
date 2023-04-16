#include "Clans.h"
#include <string>
#include <vector>

namespace SBF {
std::string GetClanLabel(int clanId) {
    if (clanId > 0 && clanId <= kClansCount) {
        return kClanLabels[clanId];
    }
    return "";
}

void FillClanLabels(std::vector<std::string>& labels) {
    labels.clear();
    for (int id = 1; id <= kClansCount; id++) {
        labels.push_back(GetClanLabel(id));
    }
}
} // End namespace SBF
