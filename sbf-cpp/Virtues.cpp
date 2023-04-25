#include "Virtues.h"

#include <string>
#include <vector>

namespace SBF {
namespace {
using std::string;
using std::vector;
}  // End namespace

const std::string kVirtueUnknownLabel = "";
const std::string kVirtueSelfControlLabel = "Self-Control";
const std::string kVirtueCourageLabel = "Courage";
const std::string kVirtueConscienceLabel = "Conscience";
const int kVirtuesCount = 3;
const std::string kVirtueLabels[] = {
    kVirtueUnknownLabel,
    kVirtueSelfControlLabel,
    kVirtueCourageLabel,
    kVirtueConscienceLabel,
};

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

int GetNumVirtues() {
  return kVirtuesCount;
}
}  // End namespace SBF
