#include "Attributes.h"

#include <sstream>
#include <string>
#include <vector>

namespace SBF {
using std::string;

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

}  // End namespace SBF
