#include "Freebies.h"

#include <ostream>

namespace SBF {
namespace {
using std::ostream;
using std::vector;
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

void FillFreebies(vector<FreebieType>& freebies) {
  freebies.clear();
  for (int id = 1; id <= kFreebiesCount; id++) {
    freebies.push_back(GetFreebie(id));
  }
}

vector<FreebieType> GetFreebies() {
  vector<FreebieType> freebies;

  FillFreebies(freebies);

  return freebies;
}

vector<FreebieType> GetAvailableFreebies(int freebie_points) {
  vector<FreebieType> freebies;

  for (int id = 1; id <= kFreebiesCount; id++) {
    FreebieType freebie = GetFreebie(id);
    if (freebie.cost <= freebie_points) {
      freebies.push_back(freebie);
    }
  }

  return freebies;
}
}  // End namespace SBF
