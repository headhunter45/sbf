#include "Abilities.h"

#include <iostream>
#include <string>

namespace SBF {
using std::ostream;
using std::string;
using std::vector;

ostream& operator<<(ostream& os, const AbilityType& ability) {
  os << "AbilityGroup: {id: " << ability.id << ", singular: \"" << ability.singular << "\", plural: \""
     << ability.plural << "\"}";
  return os;
}

bool operator==(const AbilityType& left, const AbilityType& right) {
  return left.id == right.id && left.singular == right.singular && left.plural == right.plural;
}

bool operator!=(const AbilityType& left, const AbilityType& right) {
  return !(left == right);
}

void FillAbilities(vector<AbilityType>& abilities) {
  abilities.clear();
  abilities.push_back(kAbilityGroupTalents);
  abilities.push_back(kAbilityGroupSkills);
  abilities.push_back(kAbilityGroupKnowledges);
}

void FillAbilitiesForAbilityGroup(vector<string>& abilities, int id) {
  abilities.clear();
  int numAbilities = GetNumItemsForAbilityGroup(id);
  switch (id) {
    case kAbilityTalentsId:
      for (int talent_id = 1; talent_id <= numAbilities; talent_id++) {
        abilities.push_back(GetTalentLabel(talent_id));
      }
      break;
    case kAbilitySkillsId:
      for (int skill_id = 1; skill_id <= numAbilities; skill_id++) {
        abilities.push_back(GetSkillLabel(skill_id));
      }
      break;
    case kAbilityKnowledgesId:
      for (int knowledge_id = 1; knowledge_id <= numAbilities; knowledge_id++) {
        abilities.push_back(GetKnowledgeLabel(knowledge_id));
      }
      break;
  }
}

void FillAbilityLabels(vector<string>& labels, int id) {
  labels.clear();
  switch (id) {
    case kAbilityTalentsId:
      FillTalentLabels(labels);
      break;
    case kAbilitySkillsId:
      FillSkillLabels(labels);
      break;
    case kAbilityKnowledgesId:
      FillKnowledgeLabels(labels);
      break;
  }
}

void FillKnowledgeLabels(vector<string>& labels) {
  labels.clear();
  int numAbilities = GetNumItemsForAbilityGroup(kAbilityKnowledgesId);
  for (int knowledge_id = 1; knowledge_id <= numAbilities; knowledge_id++) {
    labels.push_back(GetKnowledgeLabel(knowledge_id));
  }
}

void FillSkillLabels(vector<string>& labels) {
  labels.clear();
  int numAbilities = GetNumItemsForAbilityGroup(kAbilitySkillsId);
  for (int skill_id = 1; skill_id <= numAbilities; skill_id++) {
    labels.push_back(GetSkillLabel(skill_id));
  }
}

void FillTalentLabels(vector<string>& labels) {
  labels.clear();
  int numAbilities = GetNumItemsForAbilityGroup(kAbilityTalentsId);
  for (int talent_id = 1; talent_id <= numAbilities; talent_id++) {
    labels.push_back(GetTalentLabel(talent_id));
  }
}

const AbilityType& GetAbility(int ability_group_id) {
  switch (ability_group_id) {
    case kAbilityTalentsId:
      return kAbilityGroupTalents;
    case kAbilitySkillsId:
      return kAbilityGroupSkills;
    case kAbilityKnowledgesId:
      return kAbilityGroupKnowledges;
  };
  return kAbilityGroupUnknown;
}

const string GetAbilityLabel(int ability_group_id, int ability_id) {
  switch (ability_group_id) {
    case kAbilityTalentsId:
      return GetTalentLabel(ability_id);
    case kAbilitySkillsId:
      return GetSkillLabel(ability_id);
    case kAbilityKnowledgesId:
      return GetKnowledgeLabel(ability_id);
  };
  return "";
}

const std::string GetKnowledgeLabel(int talent_id) {
  if (talent_id > 0 && talent_id <= kKnowledgesCount) {
    return kKnowledges[talent_id];
  }
  return "";
}

int GetNumItemsForAbilityGroup(int ability_group_id) {
  switch (ability_group_id) {
    case kAbilityTalentsId:
      return kTalentsCount;
    case kAbilitySkillsId:
      return kSkillsCount;
    case kAbilityKnowledgesId:
      return kKnowledgesCount;
  }
  return 0;
}

const std::string GetSkillLabel(int skill_id) {
  if (skill_id > 0 && skill_id <= kSkillsCount) {
    return kSkills[skill_id];
  }
  return "";
}

const std::string GetTalentLabel(int talent_id) {
  if (talent_id > 0 && talent_id <= kTalentsCount) {
    return kTalents[talent_id];
  }
  return "";
}

}  // End namespace SBF
