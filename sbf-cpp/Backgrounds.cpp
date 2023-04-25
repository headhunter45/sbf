#include "Backgrounds.h"

#include <string>
#include <vector>

namespace SBF {
namespace {
using std::string;
using std::vector;
}  // End namespace

const std::string kBackgroundAlliesLabel = "Allies";
const std::string kBackgroundContactsLabel = "Contacts";
const std::string kBackgroundFameLabel = "Fame";
const std::string kBackgroundGenerationLabel = "Generation";
const std::string kBackgroundHerdLabel = "Herd";
const std::string kBackgroundInfluenceLabel = "Influence";
const std::string kBackgroundMentorLabel = "Mentor";
const std::string kBackgroundResourcesLabel = "Resources";
const std::string kBackgroundRetainersLabel = "Retainers";
const std::string kBackgroundStatusLabel = "Status";
const std::string kBackgroundLabels[] = {
    "",
    kBackgroundAlliesLabel,
    kBackgroundContactsLabel,
    kBackgroundFameLabel,
    kBackgroundGenerationLabel,
    kBackgroundHerdLabel,
    kBackgroundInfluenceLabel,
    kBackgroundMentorLabel,
    kBackgroundResourcesLabel,
    kBackgroundRetainersLabel,
    kBackgroundStatusLabel,
};

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
