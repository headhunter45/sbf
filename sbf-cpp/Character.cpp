#include "Character.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Attributes.h"
#include "sbf-cpp/Abilities.h"
#include "sbf-cpp/Disciplines.h"

namespace SBF {
namespace {
using std::ostringstream;
using std::string;
using std::vector;
}  // namespace

const int kBackgroundPoints = 5;
const int kInitialGeneration = 13;
const int kDisciplinePoints = 3;

CharacterType::CharacterType() {
  // Scalars
  name = "";
  player = "";
  chronicle = "";
  haven = "";
  concept = "";
  age = "";
  genderId = 0;
  clan_id = 0;
  natureId = 0;
  demeanorId = 0;
  generation = 3;
  road_name = "";
  road_value = 0;
  willpower = 0;
  bloodPool = 0;
  derangementId = -1;
  freebie_points = 15;

  // Virtues
  selfControl = 1;
  courage = 1;
  conscience = 1;

  // Arrays/Objects
  // Abilities (Talents/Skills/Knowledges)
  for (int group_id = 1; group_id <= AbilityGroup::GetCount(); group_id++) {
    const AbilityGroup group = AbilityGroup::FromId(group_id);
    const int num_abilities = group.GetAbilityCount();
    for (int id = 1; id <= num_abilities; id++) {
      SetAbilityValue(group_id, id, 0);
    }
  }

  // Attributes
  for (int group_id = 1; group_id <= GetNumAttributeGroups(); group_id++) {
    const int numAttributes = GetNumAttributesInGroup(group_id);
    for (int id = 1; id <= numAttributes; id++) {
      SetAttributeValue(group_id, id, 1);
    }
  }

  // Backgrounds
  for (int id = 0; id <= kBackgroundsCount; id++) {
    SetBackgroundValue(id, 0);
  }

  // Disciplines
  for (int id = 0; id <= GetNumDisciplines(); id++) {
    SetDisciplineValue(id, 0);
  }
}

void CharacterType::SetDisciplineValue(int id, int value) {
  switch (id) {
    case kDisciplineAnimalismId:
      discipline_animalism = value;
      break;
    case kDisciplineAuspexId:
      discipline_auspex = value;
      break;
    case kDisciplineBardoId:
      discipline_bardo = value;
      break;
    case kDisciplineCelerityId:
      discipline_celerity = value;
      break;
    case kDisciplineChimestryId:
      discipline_chimestry = value;
      break;
    case kDisciplineDementationId:
      discipline_dementation = value;
      break;
    case kDisciplineDominateId:
      discipline_dominate = value;
      break;
    case kDisciplineFortitudeId:
      discipline_fortitude = value;
      break;
    case kDisciplineMelpomineeId:
      discipline_melpominee = value;
      break;
    case kDisciplineMortisId:
      discipline_mortis = value;
      break;
    case kDisciplineMytherceriaId:
      discipline_mytherceria = value;
      break;
    case kDisciplineNecromancyId:
      discipline_necromancy = value;
      break;
    case kDisciplineObeahId:
      discipline_obeah = value;
      break;
    case kDisciplineObfuscateId:
      discipline_obfuscate = value;
      break;
    case kDisciplineObtenebrationId:
      discipline_obtenebration = value;
      break;
    case kDisciplinePotenceId:
      discipline_potence = value;
      break;
    case kDisciplinePresenceId:
      discipline_presence = value;
      break;
    case kDisciplineProteanId:
      discipline_protean = value;
      break;
    case kDisciplineQuietusId:
      discipline_quietus = value;
      break;
    case kDisciplineSerpentisId:
      discipline_serpentis = value;
      break;
    case kDisciplineSpiritusId:
      discipline_spiritus = value;
      break;
    case kDisciplineThanantosisId:
      discipline_thanantosis = value;
      break;
    case kDisciplineThaumaturgyId:
      discipline_thaumaturgy = value;
      break;
    case kDisciplineVicissitudeId:
      discipline_vicissitude = value;
      break;
  }
}

int CharacterType::GetDisciplineValue(int id) const {
  switch (id) {
    case kDisciplineAnimalismId:
      return discipline_animalism;
    case kDisciplineAuspexId:
      return discipline_auspex;
    case kDisciplineBardoId:
      return discipline_bardo;
    case kDisciplineCelerityId:
      return discipline_celerity;
    case kDisciplineChimestryId:
      return discipline_chimestry;
    case kDisciplineDementationId:
      return discipline_dementation;
    case kDisciplineDominateId:
      return discipline_dominate;
    case kDisciplineFortitudeId:
      return discipline_fortitude;
    case kDisciplineMelpomineeId:
      return discipline_melpominee;
    case kDisciplineMortisId:
      return discipline_mortis;
    case kDisciplineMytherceriaId:
      return discipline_mytherceria;
    case kDisciplineNecromancyId:
      return discipline_necromancy;
    case kDisciplineObeahId:
      return discipline_obeah;
    case kDisciplineObfuscateId:
      return discipline_obfuscate;
    case kDisciplineObtenebrationId:
      return discipline_obtenebration;
    case kDisciplinePotenceId:
      return discipline_potence;
    case kDisciplinePresenceId:
      return discipline_presence;
    case kDisciplineProteanId:
      return discipline_protean;
    case kDisciplineQuietusId:
      return discipline_quietus;
    case kDisciplineSerpentisId:
      return discipline_serpentis;
    case kDisciplineSpiritusId:
      return discipline_spiritus;
    case kDisciplineThanantosisId:
      return discipline_thanantosis;
    case kDisciplineThaumaturgyId:
      return discipline_thaumaturgy;
    case kDisciplineVicissitudeId:
      return discipline_vicissitude;
    default:
      return 0;
  }
}

int GetDisciplinePoints() {
  return kDisciplinePoints;
}

void CharacterType::FillDisciplineValues(std::vector<int>& values) const {
  // TODO: This method sucks, but was needed in QBasic.
  values.clear();
  values.push_back(0);  // To pad the indexes.
  for (int id = 1; id <= GetNumDisciplines(); id++) {
    values.push_back(GetDisciplineValue(id));
  }
}

vector<int> CharacterType::GetDisciplineValues() const {
  vector<int> values;
  FillDisciplineValues(values);
  return values;
}

int GetVirtuePoints() {
  return kVirtuePoints;
}

void CharacterType::SetVirtueValue(int id, int value) {
  switch (id) {
    case kVirtueSelfControlId:
      selfControl = value;
      break;
    case kVirtueCourageId:
      courage = value;
      break;
    case kVirtueConscienceId:
      conscience = value;
      break;
  }
}

int CharacterType::GetVirtueValue(int id) const {
  switch (id) {
    case kVirtueSelfControlId:
      return selfControl;
    case kVirtueCourageId:
      return courage;
    case kVirtueConscienceId:
      return conscience;
    default:
      return 0;
  }
}

void CharacterType::FillVirtueValues(std::vector<int>& values) const {
  values.clear();
  for (int id = 0; id <= GetNumVirtues(); id++) {
    values.push_back(GetVirtueValue(id));
  }
}

vector<int> CharacterType::GetVirtueValues() const {
  vector<int> values;
  FillVirtueValues(values);
  return values;
}

void CharacterType::FillAttributeValues(std::vector<int>& values, int group_id) const {
  // TODO: This method sucks, but was needed in QBasic.
  const int numAttributes = GetNumAttributesInGroup(group_id);
  values.clear();
  for (int id = 1; id <= numAttributes; id++) {
    values.push_back(GetAttributeValue(group_id, id));
  }
}

vector<int> CharacterType::GetAttributeValuesInGroup(int group_id) const {
  vector<int> values;
  FillAttributeValues(values, group_id);
  return values;
}

void CharacterType::SetPhysicalAttributeValue(int id, int value) {
  switch (id) {
    case kPhysicalAttributeDexterityId:
      attr_dexterity = value;
      break;
    case kPhysicalAttributeStaminaId:
      attr_stamina = value;
      break;
    case kPhysicalAttributeStrengthId:
      attr_strength = value;
      break;
  }
}

void CharacterType::SetSocialAttributeValue(int id, int value) {
  switch (id) {
    case kSocialAttributeAppearanceId:
      attr_appearance = value;
      break;
    case kSocialAttributeCharismaId:
      attr_charisma = value;
      break;
    case kSocialAttributeManipulationId:
      attr_manipulation = value;
      break;
  }
}

void CharacterType::SetMentalAttributeValue(int id, int value) {
  switch (id) {
    case kMentalAttributeIntelligenceId:
      attr_intelligence = value;
      break;
    case kMentalAttributePerceptionId:
      attr_perception = value;
      break;
    case kMentalAttributeWitsId:
      attr_wits = value;
      break;
  }
}

void CharacterType::SetAttributeValue(int group_id, int id, int value) {
  switch (group_id) {
    case kAttributeGroupPhysicalId:
      SetPhysicalAttributeValue(id, value);
      break;
    case kAttributeGroupSocialId:
      SetSocialAttributeValue(id, value);
      break;
    case kAttributeGroupMentalId:
      SetMentalAttributeValue(id, value);
      break;
  }
}

int CharacterType::GetPhysicalAttributeValue(int id) const {
  switch (id) {
    case kPhysicalAttributeDexterityId:
      return attr_dexterity;
    case kPhysicalAttributeStaminaId:
      return attr_stamina;
    case kPhysicalAttributeStrengthId:
      return attr_strength;
  }
  return 0;
}

int CharacterType::GetSocialAttributeValue(int id) const {
  switch (id) {
    case kSocialAttributeAppearanceId:
      return attr_appearance;
    case kSocialAttributeCharismaId:
      return attr_charisma;
    case kSocialAttributeManipulationId:
      return attr_manipulation;
  }
  return 0;
}

int CharacterType::GetMentalAttributeValue(int id) const {
  switch (id) {
    case kMentalAttributeIntelligenceId:
      return attr_intelligence;
    case kMentalAttributePerceptionId:
      return attr_perception;
    case kMentalAttributeWitsId:
      return attr_wits;
  }
  return 0;
}

int CharacterType::GetAttributeValue(int group_id, int id) const {
  switch (group_id) {
    case kAttributeGroupPhysicalId:
      return GetPhysicalAttributeValue(id);
    case kAttributeGroupSocialId:
      return GetSocialAttributeValue(id);
    case kAttributeGroupMentalId:
      return GetMentalAttributeValue(id);
  }
  return 0;
}

int GetAttributePointsForRank(int id) {
  switch (id) {
    case kRankPrimaryId:
      return 7;
    case kRankSecondaryId:
      return 5;
    case kRankTertiaryId:
      return 3;
  }
  return 0;
}

void CharacterType::SetAbilityValue(int group_id, int id, int value) {
  switch (group_id) {
    case kAbilityGroupTalentsId:
      SetTalentValue(id, value);
      break;
    case kAbilityGroupSkillsId:
      SetSkillValue(id, value);
      break;
    case kAbilityGroupKnowledgesId:
      SetKnowledgeValue(id, value);
      break;
  }
}

int CharacterType::GetAbilityValue(int group_id, int id) const {
  switch (group_id) {
    case kAbilityGroupTalentsId:
      return GetTalentValue(id);
    case kAbilityGroupKnowledgesId:
      return GetKnowledgeValue(id);
    case kAbilityGroupSkillsId:
      return GetSkillValue(id);
  }
  return 0;
}

int GetAbilityPointsForRank(int id) {
  switch (id) {
    case kRankPrimaryId:
      return 13;
    case kRankSecondaryId:
      return 9;
    case kRankTertiaryId:
      return 5;
  }
  return 0;
}

void CharacterType::FillAbilityValues(std::vector<int>& values, int group_id) const {
  const AbilityGroup group = AbilityGroup::FromId(group_id);
  int num_abilities = group.GetAbilityCount();
  values.clear();
  for (int id = 0; id <= num_abilities; id++) {
    values[id] = GetAbilityValue(group_id, id);
  }
}

void CharacterType::SetTalentValue(int id, int value) {
  switch (id) {
    case kTalentActingId:
      talent_acting = value;
      break;
    case kTalentAlertnessId:
      talent_alertness = value;
      break;
    case kTalentAthleticsId:
      talent_athletics = value;
      break;
    case kTalentBrawlId:
      talent_brawl = value;
      break;
    case kTalentDodgeId:
      talent_dodge = value;
      break;
    case kTalentEmpathyId:
      talent_empathy = value;
      break;
    case kTalentIntimidationId:
      talent_intimidation = value;
      break;
    case kTalentLeadershipId:
      talent_leadership = value;
      break;
    case kTalentStreetwiseId:
      talent_streetwise = value;
      break;
    case kTalentSubterfugeId:
      talent_subterfuge = value;
      break;
  }
}

int CharacterType::GetTalentValue(int id) const {
  switch (id) {
    case kTalentActingId:
      return talent_acting;
    case kTalentAlertnessId:
      return talent_alertness;
    case kTalentAthleticsId:
      return talent_athletics;
    case kTalentBrawlId:
      return talent_brawl;
    case kTalentDodgeId:
      return talent_dodge;
    case kTalentEmpathyId:
      return talent_empathy;
    case kTalentIntimidationId:
      return talent_intimidation;
    case kTalentLeadershipId:
      return talent_leadership;
    case kTalentStreetwiseId:
      return talent_streetwise;
    case kTalentSubterfugeId:
      return talent_subterfuge;
  }
  return 0;
}

void CharacterType::SetSkillValue(int id, int value) {
  switch (id) {
    case kSkillAnimalKenId:
      skill_animalKen = value;
      break;
    case kSkillDriveId:
      skill_drive = value;
      break;
    case kSkillEtiquetteId:
      skill_etiquette = value;
      break;
    case kSkillFirearmsId:
      skill_firearms = value;
      break;
    case kSkillMeleeId:
      skill_melee = value;
      break;
    case kSkillMusicId:
      skill_music = value;
      break;
    case kSkillRepairId:
      skill_repair = value;
      break;
    case kSkillSecurityId:
      skill_security = value;
      break;
    case kSkillStealthId:
      skill_stealth = value;
      break;
    case kSkillSurvivalId:
      skill_survival = value;
      break;
  }
}

int CharacterType::GetSkillValue(int id) const {
  switch (id) {
    case kSkillAnimalKenId:
      return skill_animalKen;
    case kSkillDriveId:
      return skill_drive;
    case kSkillEtiquetteId:
      return skill_etiquette;
    case kSkillFirearmsId:
      return skill_firearms;
    case kSkillMeleeId:
      return skill_melee;
    case kSkillMusicId:
      return skill_music;
    case kSkillRepairId:
      return skill_repair;
    case kSkillSecurityId:
      return skill_security;
    case kSkillStealthId:
      return skill_stealth;
    case kSkillSurvivalId:
      return skill_survival;
  }
  return 0;
}

void CharacterType::SetKnowledgeValue(int id, int value) {
  switch (id) {
    case kKnowledgeBureaucracyId:
      knowledge_bureaucracy = value;
      break;
    case kKnowledgeComputerId:
      knowledge_computer = value;
      break;
    case kKnowledgeFinanceId:
      knowledge_finance = value;
      break;
    case kKnowledgeInvestigationId:
      knowledge_investigation = value;
      break;
    case kKnowledgeLawId:
      knowledge_law = value;
      break;
    case kKnowledgeLinguisticsId:
      knowledge_linguistics = value;
      break;
    case kKnowledgeMedicineId:
      knowledge_medicine = value;
      break;
    case kKnowledgeOccultId:
      knowledge_occult = value;
      break;
    case kKnowledgePoliticsId:
      knowledge_politics = value;
      break;
    case kKnowledgeScienceId:
      knowledge_science = value;
      break;
  }
}

int CharacterType::GetKnowledgeValue(int id) const {
  switch (id) {
    case kKnowledgeBureaucracyId:
      return knowledge_bureaucracy;
    case kKnowledgeComputerId:
      return knowledge_computer;
    case kKnowledgeFinanceId:
      return knowledge_finance;
    case kKnowledgeInvestigationId:
      return knowledge_investigation;
    case kKnowledgeLawId:
      return knowledge_law;
    case kKnowledgeLinguisticsId:
      return knowledge_linguistics;
    case kKnowledgeMedicineId:
      return knowledge_medicine;
    case kKnowledgeOccultId:
      return knowledge_occult;
    case kKnowledgePoliticsId:
      return knowledge_politics;
    case kKnowledgeScienceId:
      return knowledge_science;
  }
  return 0;
}

void CharacterType::SetBackgroundValue(int id, int value) {
  switch (id) {
    case kBackgroundAlliesId:
      background_allies = value;
      break;
    case kBackgroundContactsId:
      background_contacts = value;
      break;
    case kBackgroundFameId:
      background_fame = value;
      break;
    case kBackgroundGenerationId:
      background_generation = value;
      break;
    case kBackgroundHerdId:
      background_herd = value;
      break;
    case kBackgroundInfluenceId:
      background_influence = value;
      break;
    case kBackgroundMentorId:
      background_mentor = value;
      break;
    case kBackgroundResourcesId:
      background_resources = value;
      break;
    case kBackgroundRetainersId:
      background_retainers = value;
      break;
    case kBackgroundStatusId:
      background_status = value;
      break;
  }
}

int CharacterType::GetBackgroundValue(int id) const {
  switch (id) {
    case kBackgroundAlliesId:
      return background_allies;
    case kBackgroundContactsId:
      return background_contacts;
    case kBackgroundFameId:
      return background_fame;
    case kBackgroundGenerationId:
      return background_generation;
    case kBackgroundHerdId:
      return background_herd;
    case kBackgroundInfluenceId:
      return background_influence;
    case kBackgroundMentorId:
      return background_mentor;
    case kBackgroundResourcesId:
      return background_resources;
    case kBackgroundRetainersId:
      return background_retainers;
    case kBackgroundStatusId:
      return background_status;
  }
  return 0;
}

void CharacterType::FillBackgroundValues(std::vector<int>& values) const {
  values.clear();
  for (int id = 1; id <= kBackgroundsCount; id++) {
    values[id] = GetBackgroundValue(id);
  }
}

vector<int> CharacterType::GetBackgroundValues() const {
  vector<int> values;
  FillBackgroundValues(values);
  return values;
}

int GetBackgroundPoints() {
  return kBackgroundPoints;
}

void NewDerangement(DerangementType& derangement, int id, string label, int textColor, string description) {
  derangement.id = id;
  derangement.label = label;
  derangement.textColor = textColor;
  derangement.description = description;
}

string CharacterType::GetAllDerangementsLine() const {
  if (derangementId > 0) {
    return GetDerangement(derangementId).label;
  }
  return "";
}

int CharacterType::GetFreebiePoints() const {
  return freebie_points;
}

void CharacterType::SetFreebiePoints(int value) {
  freebie_points = value;
}

string CharacterType::GetRoadName() const {
  return road_name;
}

void CharacterType::SetRoadName(string name) {
  road_name = name;
}

int CharacterType::GetRoadValue() const {
  return road_value;
}

void CharacterType::SetRoadValue(int value) {
  road_value = value;
}

void CharacterType::SetGeneration(int value) {
  generation = value;
}

int CharacterType::GetGeneration() const {
  return generation;
}

int GetInitialGeneration() {
  return kInitialGeneration;
}

int CharacterType::GetClanId() const {
  return clan_id;
}

void CharacterType::SetClanId(int value) {
  clan_id = value;
}
}  // End namespace SBF
