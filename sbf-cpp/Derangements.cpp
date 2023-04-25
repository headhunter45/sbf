#include "Derangements.h"

#include <ostream>

namespace SBF {
namespace {
using std::ostream;
using std::string;
using std::vector;
}  // End namespace

bool operator==(const DerangementType& left, const DerangementType& right) {
  return left.description == right.description && left.id == right.id && left.label == right.label
      && left.textColor == right.textColor;
}

bool operator!=(const DerangementType& left, const DerangementType& right) {
  return !(left == right);
}

ostream& operator<<(ostream& os, const DerangementType& derangement) {
  os << "Derangement: {id: " << derangement.id << ", label: \"" << derangement.label << "\", description: \""
     << derangement.description << "\", textColor: " << (int)derangement.textColor << "}";
  return os;
}

DerangementType GetDerangement(int derangementId) {
  if (derangementId > 0 && derangementId <= kDerangementsCount) {
    return kDerangements[derangementId];
  }
  return kDerangementUnknown;
}

void FillDerangements(vector<DerangementType>& derangements) {
  derangements.clear();
  for (int id = 1; id <= kDerangementsCount; id++) {
    derangements.push_back(GetDerangement(id));
  }
}

vector<string> GetDerangementLabels() {
  vector<string> labels;

  for (int id = 1; id <= kDerangementsCount; id++) {
    labels.push_back(kDerangementLabels[id]);
  }

  return labels;
}

vector<uint8_t> GetDerangementColors() {
  vector<uint8_t> colors;

  for (int id = 1; id <= kDerangementsCount; id++) {
    colors.push_back(kDerangementTextColors[id]);
  }

  return colors;
}
}  // End namespace SBF
