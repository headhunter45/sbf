#include "Freebies.h"

#include <ostream>

namespace SBF {
namespace {
using std::ostream;
}  // End namespace

ostream& operator<<(ostream& os, const FreebieType& freebie) {
  os << "Freebie: {id: " << freebie.id << ", cost: " << freebie.cost << ", name: \"" << freebie.name << "\", label: \""
     << freebie.label << "\"}";
  return os;
}

bool operator==(const FreebieType& left, const FreebieType& right) {
  return left.id == right.id && left.cost == right.cost && left.name == right.name && left.label == right.label;
}

bool operator!=(const FreebieType& left, const FreebieType& right) {
  return !(left == right);
}

FreebieType GetFreebie(int freebie_id) {
  if (freebie_id > 0 && freebie_id <= kFreebiesCount) {
    return kFreebies[freebie_id];
  }
  return kFreebieUnknown;
}

void FillFreebies(std::vector<FreebieType>& freebies) {
  freebies.clear();
  for (int id = 1; id <= kFreebiesCount; id++) {
    freebies.push_back(GetFreebie(id));
  }
}
}  // End namespace SBF
