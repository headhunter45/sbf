#include "Virtues.h"

#include <string>
#include <vector>

namespace SBF {
namespace {
using std::string;
using std::vector;
}  // End namespace

const string GetVirtueLabel(int id) {
  if (id > 0 && id <= kVirtuesCount) {
    return kVirtueLabels[id];
  }
  return "";
}

void FillVirtueLabels(vector<string>& labels) {
  labels.clear();
  for (int id = 1; id <= kVirtuesCount; id++) {
    labels.push_back(GetVirtueLabel(id));
  }
}

vector<string> GetVirtueLabels() {
  vector<string> labels;
  FillVirtueLabels(labels);
  return labels;
}
}  // End namespace SBF
