#include "Archetypes.h"

#include <string>
#include <vector>

namespace SBF {
std::string GetArchetypeLabel(int archetype_id) {
  if (archetype_id >= 0 && archetype_id <= kArchetypesCount) {
    return kArchetypes[archetype_id];
  }
  return "";
}

void FillArchetypeLabels(std::vector<std::string>& labels) {
  labels.clear();
  for (int id = 1; id <= kArchetypesCount; id++) {
    labels.push_back(GetArchetypeLabel(id));
  }
}
}  // End namespace SBF
