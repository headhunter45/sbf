#include "Archetypes.h"

#include <string>
#include <vector>

namespace SBF {
std::string GetArchetypeLabel(int archetypeId) {
  if (archetypeId >= 0 && archetypeId <= kArchetypesCount) {
    return kArchetypes[archetypeId];
  }
  return "";
}

void FillArchetypeLabels(std::vector<std::string>& labels) {
  labels.clear();
  for (int id = 0; id <= kArchetypesCount; id++) {
    labels.push_back(GetArchetypeLabel(id));
  }
}
}  // End namespace SBF
