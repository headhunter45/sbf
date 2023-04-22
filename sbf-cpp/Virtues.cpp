#include "Virtues.h"

#include <string>
#include <vector>

namespace SBF {

const std::string GetVirtueLabel(int id) {
  if (id > 0 && id <= kVirtuesCount) {
    return kVirtueLabels[id];
  }
  return "";
}

void FillVirtueLabels(std::vector<std::string>& labels) {
  labels.clear();
  for (int id = 1; id <= kVirtuesCount; id++) {
    labels.push_back(GetVirtueLabel(id));
  }
}

}  // End namespace SBF
