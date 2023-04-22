#include "Clans.h"

#include <string>
#include <vector>

namespace SBF {
std::string GetClanLabel(int clan_id) {
  if (clan_id > 0 && clan_id <= kClansCount) {
    return kClanLabels[clan_id];
  }
  return "";
}

void FillClanLabels(std::vector<std::string>& labels) {
  labels.clear();
  for (int id = 1; id <= kClansCount; id++) {
    labels.push_back(GetClanLabel(id));
  }
}
}  // End namespace SBF
