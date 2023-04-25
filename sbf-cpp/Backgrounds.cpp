#include "Backgrounds.h"

#include <string>
#include <vector>

namespace SBF {
namespace {
using std::string;
using std::vector;
}  // End namespace

string GetBackgroundLabel(int backgroundId) {
  if (backgroundId > 0 && backgroundId <= kBackgroundsCount) {
    return kBackgroundLabels[backgroundId];
  }
  return "";
}

void FillBackgroundLabels(vector<string>& labels) {
  labels.clear();
  for (int id = 1; id <= kBackgroundsCount; id++) {
    labels.push_back(kBackgroundLabels[id]);
  }
}

vector<string> GetBackgroundLabels() {
  vector<string> labels;
  FillBackgroundLabels(labels);
  return labels;
}
}  // End namespace SBF
