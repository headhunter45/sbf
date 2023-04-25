#include "Attributes.h"

#include <sstream>
#include <string>
#include <vector>

namespace SBF {
namespace {
using std::string;
using std::vector;
}  // End namespace

const int kPhysicalAttributesCount = 3;
const int kSocialAttributesCount = 3;
const int kMentalAttributesCount = 3;
const int kAttributeGroupsCount = 3;

const std::string kPhysicalAttributeStrengthLabel = "Strength";
const std::string kPhysicalAttributeStrengthAbbreviation = "Str.";
const std::string kPhysicalAttributeDexterityLabel = "Dexterity";
const std::string kPhysicalAttributeDexterityAbbreviation = "Dex.";
const std::string kPhysicalAttributeStaminaLabel = "Stamina";
const std::string kPhysicalAttributeStaminaAbbreviation = "Sta.";
const std::string kPhysicalAttributeLabels[] = {
    "",
    kPhysicalAttributeStrengthLabel,
    kPhysicalAttributeDexterityLabel,
    kPhysicalAttributeStaminaLabel,
};
const std::string kPhysicalAttributeLabelAbbreviations[] = {
    "",
    kPhysicalAttributeStrengthAbbreviation,
    kPhysicalAttributeDexterityAbbreviation,
    kPhysicalAttributeStaminaAbbreviation,
};

const std::string kSocialAttributeCharismaLabel = "Charisma";
const std::string kSocialAttributeCharismaAbbreviation = "Cha.";
const std::string kSocialAttributeManipulationLabel = "Manipulation";
const std::string kSocialAttributeManipulationAbbreviation = "Man.";
const std::string kSocialAttributeAppearanceLabel = "Appearance";
const std::string kSocialAttributeAppearanceAbbreviation = "App.";
const std::string kSocialAttributeLabels[] = {
    "",
    kSocialAttributeCharismaLabel,
    kSocialAttributeManipulationLabel,
    kSocialAttributeAppearanceLabel,
};
const std::string kSocialAttributeLabelAbbreviations[] = {
    "",
    kSocialAttributeCharismaAbbreviation,
    kSocialAttributeManipulationAbbreviation,
    kSocialAttributeAppearanceAbbreviation,
};

const std::string kMentalAttributeIntelligenceLabel = "Intelligence";
const std::string kMentalAttributeIntelligenceAbbreviation = "Int.";
const std::string kMentalAttributePerceptionLabel = "Perception";
const std::string kMentalAttributePerceptionAbbreviation = "Per.";
const std::string kMentalAttributeWitsLabel = "Wits";
const std::string kMentalAttributeWitsAbbreviation = "Wits";
const std::string kMentalAttributeLabels[] = {
    "",
    kMentalAttributeIntelligenceLabel,
    kMentalAttributePerceptionLabel,
    kMentalAttributeWitsLabel,
};
const std::string kMentalAttributeLabelAbbreviations[] = {
    "",
    kMentalAttributeIntelligenceAbbreviation,
    kMentalAttributePerceptionAbbreviation,
    kMentalAttributeWitsAbbreviation,
};

const std::string kAttributeGroupPhysicalLabel = "Physical";
const std::string kAttributeGroupSocialLabel = "Social";
const std::string kAttributeGroupMentalLabel = "Mental";
const std::string kAttributeGroups[] = {
    "",
    kAttributeGroupPhysicalLabel,
    kAttributeGroupSocialLabel,
    kAttributeGroupMentalLabel,
};

string GetAttributeGroupLabel(int attributeGroupId) {
  if (attributeGroupId > 0 && attributeGroupId <= kAttributeGroupsCount) {
    return kAttributeGroups[attributeGroupId];
  }
  return "";
}

string GetAttributeLabel(int attributeGroupId, int attributeId) {
  switch (attributeGroupId) {
    case kAttributeGroupPhysicalId:
      return GetPhysicalAttributeLabel(attributeId);
    case kAttributeGroupSocialId:
      return GetSocialAttributeLabel(attributeId);
    case kAttributeGroupMentalId:
      return GetMentalAttributeLabel(attributeId);
    default:
      return "";
  }
}

string GetAttributeLabelAbbreviation(int attributeGroupId, int attributeId) {
  switch (attributeGroupId) {
    case kAttributeGroupPhysicalId:
      return GetPhysicalAttributeLabelAbbreviation(attributeId);
    case kAttributeGroupSocialId:
      return GetSocialAttributeLabelAbbreviation(attributeId);
    case kAttributeGroupMentalId:
      return GetMentalAttributeLabelAbbreviation(attributeId);
    default:
      return "";
  }
}

int GetNumAttributesInGroup(int attributeGroupId) {
  switch (attributeGroupId) {
    case kAttributeGroupPhysicalId:
      return kPhysicalAttributesCount;
    case kAttributeGroupSocialId:
      return kSocialAttributesCount;
    case kAttributeGroupMentalId:
      return kMentalAttributesCount;
  }
  return 0;
}

string GetPhysicalAttributeLabel(int attributeId) {
  if (attributeId > 0 && attributeId <= kPhysicalAttributesCount) {
    return kPhysicalAttributeLabels[attributeId];
  }
  return "";
}

string GetPhysicalAttributeLabelAbbreviation(int attributeId) {
  if (attributeId > 0 && attributeId <= kPhysicalAttributesCount) {
    return kPhysicalAttributeLabelAbbreviations[attributeId];
  }
  return "";
}

string GetSocialAttributeLabel(int attributeId) {
  if (attributeId > 0 && attributeId <= kSocialAttributesCount) {
    return kSocialAttributeLabels[attributeId];
  }
  return "";
}

string GetSocialAttributeLabelAbbreviation(int attributeId) {
  if (attributeId > 0 && attributeId <= kSocialAttributesCount) {
    return kSocialAttributeLabelAbbreviations[attributeId];
  }
  return "";
}

string GetMentalAttributeLabel(int attributeId) {
  if (attributeId > 0 && attributeId <= kMentalAttributesCount) {
    return kMentalAttributeLabels[attributeId];
  }
  return "";
}

string GetMentalAttributeLabelAbbreviation(int attributeId) {
  if (attributeId > 0 && attributeId <= kMentalAttributesCount) {
    return kMentalAttributeLabelAbbreviations[attributeId];
  }
  return "";
}

void FillAttributeGroupLabels(std::vector<std::string>& labels) {
  labels.clear();
  for (int id = 1; id <= kAttributeGroupsCount; id++) {
    labels.push_back(kAttributeGroups[id]);
  }
}

void FillAttributeLabelsInGroup(std::vector<std::string>& labels, int groupId) {
  labels.clear();
  switch (groupId) {
    case kAttributeGroupPhysicalId:
      FillPhysicalAttributeLabels(labels);
      break;
    case kAttributeGroupSocialId:
      FillSocialAttributeLabels(labels);
      break;
    case kAttributeGroupMentalId:
      FillMentalAttributeLabels(labels);
      break;
  }
}

vector<string> GetAttributeLabelsInGroup(int group_id) {
  vector<string> labels;
  switch (group_id) {
    case kAttributeGroupPhysicalId:
      FillPhysicalAttributeLabels(labels);
      break;
    case kAttributeGroupSocialId:
      FillSocialAttributeLabels(labels);
      break;
    case kAttributeGroupMentalId:
      FillMentalAttributeLabels(labels);
      break;
  }
  return labels;
}

void FillPhysicalAttributeLabels(std::vector<std::string>& labels) {
  labels.clear();
  for (int id = 1; id <= kPhysicalAttributesCount; id++) {
    labels.push_back(kPhysicalAttributeLabels[id]);
  }
}

void FillSocialAttributeLabels(std::vector<std::string>& labels) {
  labels.clear();
  for (int id = 1; id <= kSocialAttributesCount; id++) {
    labels.push_back(kSocialAttributeLabels[id]);
  }
}

void FillMentalAttributeLabels(std::vector<std::string>& labels) {
  labels.clear();
  for (int id = 1; id <= kMentalAttributesCount; id++) {
    labels.push_back(kMentalAttributeLabels[id]);
  }
}

void FillAttributeLabelsInGroup(std::vector<string> labels, int group_id) {
  labels.clear();
  switch (group_id) {
    case kAttributeGroupPhysicalId:
      for (int id = 0; id <= kPhysicalAttributesCount; id++) {
        labels.push_back(kPhysicalAttributeLabels[id]);
      }
      break;
    case kAttributeGroupSocialId:
      for (int id = 0; id <= kSocialAttributesCount; id++) {
        labels.push_back(kSocialAttributeLabels[id]);
      }
      break;
    case kAttributeGroupMentalId:
      for (int id = 0; id <= kMentalAttributesCount; id++) {
        labels.push_back(kMentalAttributeLabels[id]);
      }
      break;
  }
}

void FillAttributeAbbreviationsInGroup(std::vector<string> abbreviations, int group_id) {
  abbreviations.clear();
  switch (group_id) {
    case kAttributeGroupPhysicalId:
      for (int id = 0; id <= kPhysicalAttributesCount; id++) {
        abbreviations.push_back(kPhysicalAttributeLabelAbbreviations[id]);
      }
      break;
    case kAttributeGroupSocialId:
      for (int id = 0; id <= kSocialAttributesCount; id++) {
        abbreviations.push_back(kSocialAttributeLabelAbbreviations[id]);
      }
      break;
    case kAttributeGroupMentalId:
      for (int id = 0; id <= kMentalAttributesCount; id++) {
        abbreviations.push_back(kMentalAttributeLabelAbbreviations[id]);
      }
      break;
  }
}

int GetNumAttributeGroups() {
  return kAttributeGroupsCount;
}

}  // End namespace SBF
