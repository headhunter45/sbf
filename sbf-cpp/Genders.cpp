#include "Genders.h"

#include <string>
#include <vector>

namespace SBF {
using std::string;
using std::vector;

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
