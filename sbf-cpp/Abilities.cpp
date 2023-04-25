#include "Abilities.h"

#include <iostream>
#include <string>

namespace SBF {
using std::ostream;
using std::string;
using std::vector;

const int kAbilitiesCount = 3;

const std::string kAbilityUnknownLabel = "";
const std::string kAbilityTalentsSingular = "Talent";
const std::string kAbilityTalentsPlural = "Talents";
const std::string kAbilitySkillsSingular = "Skill";
const std::string kAbilitySkillsPlural = "Skills";
const std::string kAbilityKnowledgesSingular = "Knowledge";
const std::string kAbilityKnowledgesPlural = "Knowledges";
const AbilityType kAbilityGroupUnknown = {0, "", ""};
const AbilityType kAbilityGroupTalents = {
    kAbilityTalentsId,
    kAbilityTalentsSingular,
    kAbilityTalentsPlural,
};
const AbilityType kAbilityGroupSkills = {
    kAbilitySkillsId,
    kAbilitySkillsSingular,
    kAbilitySkillsPlural,
};
const AbilityType kAbilityGroupKnowledges = {
    kAbilityKnowledgesId,
    kAbilityKnowledgesSingular,
    kAbilityKnowledgesPlural,
};
const AbilityType kAbilities[]{
    kAbilityGroupUnknown,
    kAbilityGroupTalents,
    kAbilityGroupSkills,
    kAbilityGroupKnowledges,
};

const std::string kTalentActingLabel = "Acting";
const std::string kTalentAlertnessLabel = "Alertness";
const std::string kTalentAthleticsLabel = "Athletics";
const std::string kTalentBrawlLabel = "Brawl";
const std::string kTalentDodgeLabel = "Dodge";
const std::string kTalentEmpathyLabel = "Empathy";
const std::string kTalentIntimidationLabel = "Intimidation";
const std::string kTalentLeadershipLabel = "Leadership";
const std::string kTalentStreetwiseLabel = "Streetwise";
const std::string kTalentSubterfugeLabel = "Subterfuge";
const std::string kSkillAnimalKenLabel = "Animal Ken";
const std::string kSkillDriveLabel = "Drive";
const std::string kSkillEtiquetteLabel = "Etiquette";
const std::string kSkillFirearmsLabel = "Firearms";
const std::string kSkillMeleeLabel = "Melee";
const std::string kSkillMusicLabel = "Music";
const std::string kSkillRepairLabel = "Repair";
const std::string kSkillSecurityLabel = "Security";
const std::string kSkillStealthLabel = "Stealth";
const std::string kSkillSurvivalLabel = "Survival";
const std::string kKnowledgeBureaucracyLabel = "Bureaucracy";
const std::string kKnowledgeComputerLabel = "Computer";
const std::string kKnowledgeFinanceLabel = "Finance";
const std::string kKnowledgeInvestigationLabel = "Investigation";
const std::string kKnowledgeLawLabel = "Law";
const std::string kKnowledgeLinguisticsLabel = "Linguistics";
const std::string kKnowledgeMedicineLabel = "Medicine";
const std::string kKnowledgeOccultLabel = "Occult";
const std::string kKnowledgePoliticsLabel = "Politics";
const std::string kKnowledgeScienceLabel = "Science";
const int kTalentsCount = 10;
const int kSkillsCount = 10;
const int kKnowledgesCount = 10;
const std::string kSkills[] = {
    kAbilityUnknownLabel,
    kSkillAnimalKenLabel,
    kSkillDriveLabel,
    kSkillEtiquetteLabel,
    kSkillFirearmsLabel,
    kSkillMeleeLabel,
    kSkillMusicLabel,
    kSkillRepairLabel,
    kSkillSecurityLabel,
    kSkillStealthLabel,
    kSkillSurvivalLabel,
};
const std::string kTalents[] = {
    kAbilityUnknownLabel,
    kTalentActingLabel,
    kTalentAlertnessLabel,
    kTalentAthleticsLabel,
    kTalentBrawlLabel,
    kTalentDodgeLabel,
    kTalentEmpathyLabel,
    kTalentIntimidationLabel,
    kTalentLeadershipLabel,
    kTalentStreetwiseLabel,
    kTalentSubterfugeLabel,
};
const std::string kKnowledges[] = {
    kAbilityUnknownLabel,
    kKnowledgeBureaucracyLabel,
    kKnowledgeComputerLabel,
    kKnowledgeFinanceLabel,
    kKnowledgeInvestigationLabel,
    kKnowledgeLawLabel,
    kKnowledgeLinguisticsLabel,
    kKnowledgeMedicineLabel,
    kKnowledgeOccultLabel,
    kKnowledgePoliticsLabel,
    kKnowledgeScienceLabel,
};

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

vector<string> GetAbilityGroupPluralLabels() {
  vector<string> labels;

  for (int id = 1; id <= kAbilitiesCount; id++) {
    labels.push_back(GetAbility(id).plural);
  }

  return labels;
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

vector<string> GetAbilityLabelsForAbilityGroup(int group_id) {
  vector<string> labels;

  int count = GetNumItemsForAbilityGroup(group_id);
  for (int id = 1; id <= count; id++) {
    labels.push_back(GetAbilityLabel(group_id, id));
  }

  return labels;
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

int GetNumAbilityGroups() {
  return kAbilitiesCount;
}
}  // End namespace SBF
