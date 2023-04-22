#include "Derangements.h"

#include <ostream>
#include <sstream>

namespace SBF {
using std::ostream;

bool operator==(const DerangementType& left, const DerangementType& right) {
  return left.description == right.description && left.id == right.id && left.label == right.label
      && left.textColor == right.textColor;
}

bool operator!=(const DerangementType& left, const DerangementType& right) {
  return !(left == right);
}

ostream& operator<<(ostream& os, const DerangementType& derangement) {
  // Derangement: {id: 1, label: \"kDerangementAmnesiaLabel\", description: \"kDerangementAmnesiaDescription\",
  // textColor: kDerangementAmnesiaTextColor}
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

void FillDerangements(std::vector<DerangementType>& derangements) {
  derangements.clear();
  for (int id = 1; id <= kDerangementsCount; id++) {
    derangements.push_back(GetDerangement(id));
  }
}
}  // End namespace SBF
