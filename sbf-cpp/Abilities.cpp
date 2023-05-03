#include "Abilities.h"

#include <iostream>
#include <string>

namespace SBF {
namespace {
using std::ostream;
using std::string;
using std::vector;
}  // End namespace

const int kAbilityGroupUnknownId = 0;
const std::string kAbilityGroupUnknownLabel = "";
const std::string kAbilityGroupTalentsSingular = "Talent";
const std::string kAbilityGroupTalentsPlural = "Talents";
const std::string kAbilityGroupSkillsSingular = "Skill";
const std::string kAbilityGroupSkillsPlural = "Skills";
const std::string kAbilityGroupKnowledgesSingular = "Knowledge";
const std::string kAbilityGroupKnowledgesPlural = "Knowledges";

const AbilityGroup kAbilityGroupUnknown =
    AbilityGroup(kAbilityGroupUnknownId, kAbilityGroupUnknownLabel, kAbilityGroupUnknownLabel);
const AbilityGroup kAbilityGroupTalents =
    AbilityGroup(kAbilityGroupTalentsId, kAbilityGroupTalentsSingular, kAbilityGroupTalentsPlural);
const AbilityGroup kAbilityGroupSkills =
    AbilityGroup(kAbilityGroupSkillsId, kAbilityGroupSkillsSingular, kAbilityGroupSkillsPlural);
const AbilityGroup kAbilityGroupKnowledges =
    AbilityGroup(kAbilityGroupKnowledgesId, kAbilityGroupKnowledgesSingular, kAbilityGroupKnowledgesPlural);
const vector<AbilityGroup> kAbilityGroups = {kAbilityGroupTalents, kAbilityGroupSkills, kAbilityGroupKnowledges};

const int kAbilityUnknownId = 0;
const std::string kAbilityUnknownLabel = "";
const Ability kAbilityUnknown = Ability(kAbilityUnknownId, kAbilityGroupUnknownId, kAbilityUnknownLabel);

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
const Ability kTalentActing = Ability(kTalentActingId, kAbilityGroupTalentsId, kTalentActingLabel);
const Ability kTalentAlertness = Ability(kTalentAlertnessId, kAbilityGroupTalentsId, kTalentAlertnessLabel);
const Ability kTalentAthletics = Ability(kTalentAthleticsId, kAbilityGroupTalentsId, kTalentAthleticsLabel);
const Ability kTalentBrawl = Ability(kTalentBrawlId, kAbilityGroupTalentsId, kTalentBrawlLabel);
const Ability kTalentDodge = Ability(kTalentDodgeId, kAbilityGroupTalentsId, kTalentDodgeLabel);
const Ability kTalentEmpathy = Ability(kTalentEmpathyId, kAbilityGroupTalentsId, kTalentEmpathyLabel);
const Ability kTalentIntimidation = Ability(kTalentIntimidationId, kAbilityGroupTalentsId, kTalentIntimidationLabel);
const Ability kTalentLeadership = Ability(kTalentLeadershipId, kAbilityGroupTalentsId, kTalentLeadershipLabel);
const Ability kTalentStreetwise = Ability(kTalentStreetwiseId, kAbilityGroupTalentsId, kTalentStreetwiseLabel);
const Ability kTalentSubterfuge = Ability(kTalentSubterfugeId, kAbilityGroupTalentsId, kTalentSubterfugeLabel);
const vector<Ability> kTalents = {
    kTalentActing,
    kTalentAlertness,
    kTalentAthletics,
    kTalentBrawl,
    kTalentDodge,
    kTalentEmpathy,
    kTalentIntimidation,
    kTalentLeadership,
    kTalentStreetwise,
    kTalentSubterfuge,
};

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
const Ability kSkillAnimalKen = Ability(kSkillAnimalKenId, kAbilityGroupSkillsId, kSkillAnimalKenLabel);
const Ability kSkillDrive = Ability(kSkillDriveId, kAbilityGroupSkillsId, kSkillDriveLabel);
const Ability kSkillEtiquette = Ability(kSkillEtiquetteId, kAbilityGroupSkillsId, kSkillEtiquetteLabel);
const Ability kSkillFirearms = Ability(kSkillFirearmsId, kAbilityGroupSkillsId, kSkillFirearmsLabel);
const Ability kSkillMelee = Ability(kSkillMeleeId, kAbilityGroupSkillsId, kSkillMeleeLabel);
const Ability kSkillMusic = Ability(kSkillMusicId, kAbilityGroupSkillsId, kSkillMusicLabel);
const Ability kSkillRepair = Ability(kSkillRepairId, kAbilityGroupSkillsId, kSkillRepairLabel);
const Ability kSkillSecurity = Ability(kSkillSecurityId, kAbilityGroupSkillsId, kSkillSecurityLabel);
const Ability kSkillStealth = Ability(kSkillStealthId, kAbilityGroupSkillsId, kSkillStealthLabel);
const Ability kSkillSurvival = Ability(kSkillSurvivalId, kAbilityGroupSkillsId, kSkillSurvivalLabel);
const vector<Ability> kSkills = {
    kSkillAnimalKen,
    kSkillDrive,
    kSkillEtiquette,
    kSkillFirearms,
    kSkillMelee,
    kSkillMusic,
    kSkillRepair,
    kSkillSecurity,
    kSkillStealth,
    kSkillSurvival,
};

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
const Ability kKnowledgeBureaucracy =
    Ability(kKnowledgeBureaucracyId, kAbilityGroupKnowledgesId, kKnowledgeBureaucracyLabel);
const Ability kKnowledgeComputer = Ability(kKnowledgeComputerId, kAbilityGroupKnowledgesId, kKnowledgeComputerLabel);
const Ability kKnowledgeFinance = Ability(kKnowledgeFinanceId, kAbilityGroupKnowledgesId, kKnowledgeFinanceLabel);
const Ability kKnowledgeInvestigation =
    Ability(kKnowledgeInvestigationId, kAbilityGroupKnowledgesId, kKnowledgeInvestigationLabel);
const Ability kKnowledgeLaw = Ability(kKnowledgeLawId, kAbilityGroupKnowledgesId, kKnowledgeLawLabel);
const Ability kKnowledgeLinguistics =
    Ability(kKnowledgeLinguisticsId, kAbilityGroupKnowledgesId, kKnowledgeLinguisticsLabel);
const Ability kKnowledgeMedicine = Ability(kKnowledgeMedicineId, kAbilityGroupKnowledgesId, kKnowledgeMedicineLabel);
const Ability kKnowledgeOccult = Ability(kKnowledgeOccultId, kAbilityGroupKnowledgesId, kKnowledgeOccultLabel);
const Ability kKnowledgePolitics = Ability(kKnowledgePoliticsId, kAbilityGroupKnowledgesId, kKnowledgePoliticsLabel);
const Ability kKnowledgeScience = Ability(kKnowledgeScienceId, kAbilityGroupKnowledgesId, kKnowledgeScienceLabel);
const vector<Ability> kKnowledges = {
    kKnowledgeBureaucracy,
    kKnowledgeComputer,
    kKnowledgeFinance,
    kKnowledgeInvestigation,
    kKnowledgeLaw,
    kKnowledgeLinguistics,
    kKnowledgeMedicine,
    kKnowledgeOccult,
    kKnowledgePolitics,
    kKnowledgeScience,
};

vector<string> AbilityGroup::GetAbilityLabels() const {
  return AbilityGroup::GetAbilityLabels(id_);
}

vector<string> AbilityGroup::GetAbilityLabels(int id) {
  switch (id) {
    case kAbilityGroupKnowledgesId:
      return Ability::GetKnowledgeLabels();
    case kAbilityGroupSkillsId:
      return Ability::GetSkillLabels();
    case kAbilityGroupTalentsId:
      return Ability::GetTalentLabels();
  }

  return vector<string>();
}

int GetNumItemsForAbilityGroup(int ability_group_id) {
  switch (ability_group_id) {
    case kAbilityGroupTalentsId:
      return kTalents.size();
    case kAbilityGroupSkillsId:
      return kSkills.size();
    case kAbilityGroupKnowledgesId:
      return kKnowledges.size();
  }
  return 0;
}

int AbilityGroup::GetCount() {
  return kAbilityGroups.size();
}

int AbilityGroup::GetAbilityCount() const {
  switch (id_) {
    case kAbilityGroupKnowledgesId:
      return kTalents.size();
    case kAbilityGroupSkillsId:
      return kSkills.size();
    case kAbilityGroupTalentsId:
      return kTalents.size();
  }
  return 0;
}

AbilityGroup::AbilityGroup() : id_(0), singular_(""), plural_("") {}

AbilityGroup::AbilityGroup(int id, const string& singular, const string& plural)
    : id_(id), singular_(singular), plural_(plural) {}

int AbilityGroup::id() const {
  return id_;
}

void AbilityGroup::id(int id) {
  id_ = id;
}

string AbilityGroup::plural() const {
  return plural_;
}

void AbilityGroup::plural(const string& plural) {
  plural_ = plural;
}

string AbilityGroup::singular() const {
  return singular_;
}

void AbilityGroup::singular(const string& singular) {
  singular_ = singular;
}

vector<string> AbilityGroup::GetPluralLabels() {
  vector<string> labels;

  for_each(kAbilityGroups.begin(), kAbilityGroups.end(), [&labels](const auto& ability) {
    labels.push_back(ability.plural());
  });

  return labels;
}

Ability::Ability() : id_(0), group_id_(0), label_("") {}

Ability::Ability(int id, int group_id, const string& label) : id_(id), group_id_(group_id), label_(label) {}

int Ability::id() const {
  return id_;
}

void Ability::id(int id) {
  id_ = id;
}

int Ability::group_id() const {
  return group_id_;
}

void Ability::group_id(int group_id) {
  group_id_ = group_id;
}

string Ability::label() const {
  return label_;
}

void Ability::label(const string& label) {
  label_ = label;
}

AbilityGroup AbilityGroup::FromId(int id) {
  switch (id) {
    case kAbilityGroupTalentsId:
      return kAbilityGroupTalents;
    case kAbilityGroupSkillsId:
      return kAbilityGroupSkills;
    case kAbilityGroupKnowledgesId:
      return kAbilityGroupKnowledges;
  }
  return kAbilityGroupUnknown;
}

ostream& operator<<(ostream& os, const AbilityGroup& ability_group) {
  os << "AbilityGroup: {id: " << ability_group.id_ << ", singular: \"" << ability_group.singular_ << "\", plural: \""
     << ability_group.plural_ << "\"}";
  return os;
}

bool AbilityGroup::operator==(const AbilityGroup& other) const {
  return id_ == other.id_ && singular_ == other.singular_ && plural_ == other.plural_;
}

bool AbilityGroup::operator!=(const AbilityGroup& other) const {
  return !(*this == other);
}

ostream& operator<<(ostream& os, const Ability& ability) {
  os << "Ability: {id: " << ability.id_ << ", group_id: " << ability.group_id_ << ", label: \"" << ability.label_
     << "\"}";
  return os;
}

bool Ability::operator==(const Ability& other) const {
  return id_ == other.id_ && group_id_ == other.group_id_ && label_ == other.label_;
}

bool Ability::operator!=(const Ability& other) const {
  return !(*this == other);
}

string Ability::GetSkillLabel(int id) {
  return Ability::FromSkillId(id).label();
}

vector<string> Ability::GetSkillLabels() {
  vector<string> labels;
  for_each(kSkills.begin(), kSkills.end(), [&labels](const auto& ability) { labels.push_back(ability.label()); });
  return labels;
}

string Ability::GetTalentLabel(int id) {
  return Ability::FromTalentId(id).label();
}

vector<string> Ability::GetTalentLabels() {
  vector<string> labels;
  for_each(kTalents.begin(), kTalents.end(), [&labels](const auto& ability) { labels.push_back(ability.label()); });
  return labels;
}

string Ability::GetKnowledgeLabel(int id) {
  return Ability::FromKnowledgeId(id).label();
}

vector<string> Ability::GetKnowledgeLabels() {
  vector<string> labels;
  for_each(
      kKnowledges.begin(), kKnowledges.end(), [&labels](const auto& ability) { labels.push_back(ability.label()); });
  return labels;
}

Ability Ability::FromKnowledgeId(int id) {
  if (id > 0 && id <= kKnowledges.size()) {
    return kKnowledges.at(id - 1);
  }
  return kAbilityUnknown;
}

Ability Ability::FromSkillId(int id) {
  if (id > 0 && id <= kSkills.size()) {
    return kSkills.at(id - 1);
  }
  return kAbilityUnknown;
}

Ability Ability::FromTalentId(int id) {
  if (id > 0 && id <= kTalents.size()) {
    return kTalents.at(id - 1);
  }
  return kAbilityUnknown;
}

Ability Ability::FromIds(int id, int group_id) {
  switch (group_id) {
    case kAbilityGroupKnowledgesId:
      return Ability::FromKnowledgeId(id);
    case kAbilityGroupSkillsId:
      return Ability::FromSkillId(id);
    case kAbilityGroupTalentsId:
      return Ability::FromTalentId(id);
  }
  return kAbilityUnknown;
}

int Ability::GetCount(int group_id) {
  switch (group_id) {
    case kAbilityGroupKnowledgesId:
      return kKnowledges.size();
    case kAbilityGroupSkillsId:
      return kSkills.size();
    case kAbilityGroupTalentsId:
      return kTalents.size();
  }
  return 0;
}

int Ability::GetKnowledgesCount() {
  return kKnowledges.size();
}

int Ability::GetSkillsCount() {
  return kSkills.size();
}

int Ability::GetTalentsCount() {
  return kTalents.size();
}
}  // End namespace SBF
