#include "Genders.h"

#include <string>
#include <vector>

namespace SBF {
using std::string;
using std::vector;

const int kGendersCount = 5;
const std::string kGenderMaleLabel = "Male";
const std::string kGenderFemaleLabel = "Female";
const std::string kGenderTransMaleLabel = "Trans-Male";
const std::string kGenderTransFemaleLabel = "Trans-Female";
const std::string kGenderNonBinaryLabel = "Non-Binary";
const std::string kGenderLabels[] = {
    "",
    kGenderMaleLabel,
    kGenderFemaleLabel,
    kGenderTransMaleLabel,
    kGenderTransFemaleLabel,
    kGenderNonBinaryLabel,
};

string GetGenderLabel(int genderId) {
  if (genderId > 0 && genderId <= kGendersCount) {
    return kGenderLabels[genderId];
  }
  return "";
}

void FillGenderLabels(vector<string>& labels) {
  labels.clear();
  for (int id = 1; id <= kGendersCount; id++) {
    labels.push_back(GetGenderLabel(id));
  }
}
}  // End namespace SBF
