#include "Freebies.h"

#include <ostream>

namespace SBF {
namespace {
using std::ostream;
using std::vector;
}  // End namespace

const int kFreebieDisciplineCost = 7;
const std::string kFreebieDisciplineName = "Discipline";
const std::string kFreebieDisciplineLabel = "Add a discipline dot    7 points";
const FreebieType kFreebieDiscipline = {
    kFreebieDisciplineId, kFreebieDisciplineCost, kFreebieDisciplineName, kFreebieDisciplineLabel};
const int kFreebieAttributeCost = 5;
const std::string kFreebieAttributeName = "Attribute";
const std::string kFreebieAttributeLabel = "Add an attribute dot    5 points";
const FreebieType kFreebieAttribute = {
    kFreebieAttributeId, kFreebieAttributeCost, kFreebieAttributeName, kFreebieAttributeLabel};
const int kFreebieAbilityCost = 2;
const std::string kFreebieAbilityName = "Ability";
const std::string kFreebieAbilityLabel = "Add an ability dot      2 points";
const FreebieType kFreebieAbility = {kFreebieAbilityId, kFreebieAbilityCost, kFreebieAbilityName, kFreebieAbilityLabel};
const int kFreebieVirtueCost = 2;
const std::string kFreebieVirtueName = "Virtue";
const std::string kFreebieVirtueLabel = "Add a virtue dot        2 points";
const FreebieType kFreebieVirtue = {kFreebieVirtueId, kFreebieVirtueCost, kFreebieVirtueName, kFreebieVirtueLabel};
const int kFreebieHumanityCost = 1;
const std::string kFreebieHumanityName = "Humanity";
const std::string kFreebieHumanityLabel = "Add a humanity dot      1 point";
const FreebieType kFreebieHumanity = {
    kFreebieHumanityId, kFreebieHumanityCost, kFreebieHumanityName, kFreebieHumanityLabel};
const int kFreebieBackgroundCost = 1;
const std::string kFreebieBackgroundName = "Background";
const std::string kFreebieBackgroundLabel = "Add a background dot    1 point";
const FreebieType kFreebieBackground = {
    kFreebieBackgroundId, kFreebieBackgroundCost, kFreebieBackgroundName, kFreebieBackgroundLabel};
const int kFreebieShowCharacterSheetCost = 0;
const std::string kFreebieShowCharacterSheetName = "Show character sheet";
const std::string kFreebieShowCharacterSheetLabel = "Show character sheet";
const FreebieType kFreebieShowCharacterSheet = {kFreebieShowCharacterSheetId,
                                                kFreebieShowCharacterSheetCost,
                                                kFreebieShowCharacterSheetName,
                                                kFreebieShowCharacterSheetLabel};

const int kFreebieCosts[] = {
    0,
    kFreebieDisciplineCost,
    kFreebieAttributeCost,
    kFreebieAbilityCost,
    kFreebieVirtueCost,
    kFreebieHumanityCost,
    kFreebieBackgroundCost,
    kFreebieShowCharacterSheetCost,
};

const std::string kFreebieNames[] = {
    "",
    kFreebieDisciplineName,
    kFreebieAttributeName,
    kFreebieAbilityName,
    kFreebieVirtueName,
    kFreebieHumanityName,
    kFreebieBackgroundName,
    kFreebieShowCharacterSheetName,
};

const std::string kFreebieLabels[] = {
    "",
    kFreebieDisciplineLabel,
    kFreebieAttributeLabel,
    kFreebieAbilityLabel,
    kFreebieVirtueLabel,
    kFreebieHumanityLabel,
    kFreebieBackgroundLabel,
    kFreebieShowCharacterSheetLabel,
};

const FreebieType kFreebies[] = {
    kFreebieUnknown,
    kFreebieDiscipline,
    kFreebieAttribute,
    kFreebieAbility,
    kFreebieVirtue,
    kFreebieHumanity,
    kFreebieBackground,
    kFreebieShowCharacterSheet,
};

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

int GetFreebieCost(int id) {
  if (id > 0 && id <= kFreebiesCount) {
    return kFreebieCosts[id];
  }
  return 0;
}
}  // End namespace SBF
