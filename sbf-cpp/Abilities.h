﻿#ifndef ABILITIES_H__
#define ABILITIES_H__
/***************************************************************************************
 * @file Abilities.h
 *
 * @brief Defines AbiiltyType, ability and ability group constants, and ability and
 * ability group functions.
 * @copyright
 * Copyright 2023 Tom Hicks
 * Licensed under the MIT license see the LICENSE file for details.
 ***************************************************************************************/
#include <string>
#include <vector>

/** \addtogroup Abilities
 * @{
 */
namespace SBF {
const int kAbilityTalentsId = 1;
const std::string kAbilityTalentsSingular = "Talent";
const std::string kAbilityTalentsPlural = "Talents";
const int kAbilitySkillsId = 2;
const std::string kAbilitySkillsSingular = "Skill";
const std::string kAbilitySkillsPlural = "Skills";
const int kAbilityKnowledgesId = 3;
const std::string kAbilityKnowledgesSingular = "Knowledge";
const std::string kAbilityKnowledgesPlural = "Knowledges";
const int kAbilitiesCount = 3;

/// @brief This type represents an ability group such as Talents, Skills or Knowledges.
struct AbilityType {
  /// @brief The id of this ability group
  int id;
  /// @brief The singular form of this group i.e. Talent.
  std::string singular;
  /// @brief The plural form of this group i.e. Talents.
  std::string plural;
};

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

const std::string kAbilityUnknownLabel = "";

const int kTalentActingId = 1;
const std::string kTalentActingLabel = "Acting";
const int kTalentAlertnessId = 2;
const std::string kTalentAlertnessLabel = "Alertness";
const int kTalentAthleticsId = 3;
const std::string kTalentAthleticsLabel = "Athletics";
const int kTalentBrawlId = 4;
const std::string kTalentBrawlLabel = "Brawl";
const int kTalentDodgeId = 5;
const std::string kTalentDodgeLabel = "Dodge";
const int kTalentEmpathyId = 6;
const std::string kTalentEmpathyLabel = "Empathy";
const int kTalentIntimidationId = 7;
const std::string kTalentIntimidationLabel = "Intimidation";
const int kTalentLeadershipId = 8;
const std::string kTalentLeadershipLabel = "Leadership";
const int kTalentStreetwiseId = 9;
const std::string kTalentStreetwiseLabel = "Streetwise";
const int kTalentSubterfugeId = 10;
const std::string kTalentSubterfugeLabel = "Subterfuge";
const int kTalentsCount = 10;
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

const int kSkillAnimalKenId = 1;
const std::string kSkillAnimalKenLabel = "Animal Ken";
const int kSkillDriveId = 2;
const std::string kSkillDriveLabel = "Drive";
const int kSkillEtiquetteId = 3;
const std::string kSkillEtiquetteLabel = "Etiquette";
const int kSkillFirearmsId = 4;
const std::string kSkillFirearmsLabel = "Firearms";
const int kSkillMeleeId = 5;
const std::string kSkillMeleeLabel = "Melee";
const int kSkillMusicId = 6;
const std::string kSkillMusicLabel = "Music";
const int kSkillRepairId = 7;
const std::string kSkillRepairLabel = "Repair";
const int kSkillSecurityId = 8;
const std::string kSkillSecurityLabel = "Security";
const int kSkillStealthId = 9;
const std::string kSkillStealthLabel = "Stealth";
const int kSkillSurvivalId = 10;
const std::string kSkillSurvivalLabel = "Survival";
const int kSkillsCount = 10;
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

const int kKnowledgeBureaucracyId = 1;
const std::string kKnowledgeBureaucracyLabel = "Bureaucracy";
const int kKnowledgeComputerId = 2;
const std::string kKnowledgeComputerLabel = "Computer";
const int kKnowledgeFinanceId = 3;
const std::string kKnowledgeFinanceLabel = "Finance";
const int kKnowledgeInvestigationId = 4;
const std::string kKnowledgeInvestigationLabel = "Investigation";
const int kKnowledgeLawId = 5;
const std::string kKnowledgeLawLabel = "Law";
const int kKnowledgeLinguisticsId = 6;
const std::string kKnowledgeLinguisticsLabel = "Linguistics";
const int kKnowledgeMedicineId = 7;
const std::string kKnowledgeMedicineLabel = "Medicine";
const int kKnowledgeOccultId = 8;
const std::string kKnowledgeOccultLabel = "Occult";
const int kKnowledgePoliticsId = 9;
const std::string kKnowledgePoliticsLabel = "Politics";
const int kKnowledgeScienceId = 10;
const std::string kKnowledgeScienceLabel = "Science";
const int kKnowledgesCount = 10;
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

/// @brief This function writes an AbilityType value to an output stream;
/// @param os The output stream to write to.
/// @param group The AbilityType to write.
/// @return Thw output stream for chaining.
std::ostream& operator<<(std::ostream& os, const AbilityType& group);

/// @brief This function compares two AbilityType values for equality.
/// @param left The first AbilityType.
/// @param right The second AbilityType.
/// @return True if left is equal to right and false otherwise.
bool operator==(const AbilityType& left, const AbilityType& right);

/// @brief This function compares two AbilityType values for equality.
/// @param left The first AbilityType.
/// @param right The second AbilityType.
/// @return True if left and right are not equal and false otherwise.
bool operator!=(const AbilityType& left, const AbilityType& right);

/// @brief Fills the provided vector with all of the available ability groups. It will be cleared before filling.
/// @param abilities The vector to fill.
void FillAbilities(std::vector<AbilityType>& abilities);

/// @brief Fills the provided vector with all of the ability labels in the specified group. It will be cleared before
/// filling.
/// @param abilities The vector to fill.
/// @param id The id of the ability group to fill for.
void FillAbilitiesForAbilityGroup(std::vector<std::string>& abilities, int id);

/// @brief Fills the provided vector with all of the ability labels in the specified group. It will be cleared before
/// filling.
/// @param labels The vector to fill.
/// @param id The id of the ability group to fill for.
void FillAbilityLabels(std::vector<std::string>& labels, int id);

/// @brief Fills the provided vector with all of the knowledge labels. It will be cleared before filling.
/// @param labels The vector to fill.
void FillKnowledgeLabels(std::vector<std::string>& labels);

/// @brief Fills the provided vector with all of the skill labels. It will be cleared before filling.
/// @param labels The vector to fill.
void FillSkillLabels(std::vector<std::string>& labels);

/// @brief Fills the provided vector with all of the talent labels. It will be cleared before filling.
/// @param labels The vector to fill.
void FillTalentLabels(std::vector<std::string>& labels);

/// @brief Gets an ability group for a given id.
/// @param id The id of the ability group to return.
/// @return The ability group with an id of id or kAbilityGroupUnknown if id is invalid.
const AbilityType& GetAbility(int id);

/// @brief Gets the label for an ability given its ability group (talents/skills/knowledges) and its id (acting, brawl,
/// dodge, ...).
/// @param group_id The id for the ability group (talents/skills/knowledges).
/// @param id The id for the ability within the ability group (acting, dodge, brawl, ...).
/// @return The label for the specific ability ("Acting").
const std::string GetAbilityLabel(int group_id, int id);

/// @brief Gets the label for a knowledge ability given its id.
/// @param id The id of the ability to return the label for.
/// @return The label for the specific ability.
const std::string GetKnowledgeLabel(int id);

/// @brief Gets the number of abilities in an ability group.
/// @param id The id of the ability group to return the number of abilities for.
/// @return The number of abilities in the specific ability group.
int GetNumItemsForAbilityGroup(int id);

/// @brief Gets the label for a skill ability given its id.
/// @param id The id of the ability to return the label for.
/// @return The label of the specific ability.
const std::string GetSkillLabel(int id);

/// @brief Gets the label for a talent ability given its id.
/// @param id The id of the ability to return.
/// @return The label for the specific ability.
const std::string GetTalentLabel(int id);
}  // End namespace SBF

/** @}*/
#endif  // End !defined ABILITIES_H__
