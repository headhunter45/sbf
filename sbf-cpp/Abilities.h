#ifndef ABILITIES_H__
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
const int kAbilityGroupTalentsId = 1;
const int kAbilityGroupSkillsId = 2;
const int kAbilityGroupKnowledgesId = 3;

const int kTalentActingId = 1;
const int kTalentAlertnessId = 2;
const int kTalentAthleticsId = 3;
const int kTalentBrawlId = 4;
const int kTalentDodgeId = 5;
const int kTalentEmpathyId = 6;
const int kTalentIntimidationId = 7;
const int kTalentLeadershipId = 8;
const int kTalentStreetwiseId = 9;
const int kTalentSubterfugeId = 10;

const int kSkillAnimalKenId = 1;
const int kSkillDriveId = 2;
const int kSkillEtiquetteId = 3;
const int kSkillFirearmsId = 4;
const int kSkillMeleeId = 5;
const int kSkillMusicId = 6;
const int kSkillRepairId = 7;
const int kSkillSecurityId = 8;
const int kSkillStealthId = 9;
const int kSkillSurvivalId = 10;

const int kKnowledgeBureaucracyId = 1;
const int kKnowledgeComputerId = 2;
const int kKnowledgeFinanceId = 3;
const int kKnowledgeInvestigationId = 4;
const int kKnowledgeLawId = 5;
const int kKnowledgeLinguisticsId = 6;
const int kKnowledgeMedicineId = 7;
const int kKnowledgeOccultId = 8;
const int kKnowledgePoliticsId = 9;
const int kKnowledgeScienceId = 10;

class AbilityGroup {
 public:
  AbilityGroup();
  AbilityGroup(int id, const std::string& singular, const std::string& plural);
  int GetAbilityCount() const;
  std::vector<std::string> GetAbilityLabels() const;
  int id() const;
  void id(int id);
  std::string plural() const;
  void plural(const std::string& plural);
  std::string singular() const;
  void singular(const std::string& singular);
  bool operator==(const AbilityGroup& other) const;
  bool operator!=(const AbilityGroup& other) const;

  static AbilityGroup FromId(int id);
  static std::vector<std::string> GetPluralLabels();
  static std::vector<std::string> GetAbilityLabels(int id);
  static int GetCount();

  friend std::ostream& operator<<(std::ostream& os, const AbilityGroup& ability_group);

 private:
  int id_;
  std::string singular_;
  std::string plural_;
};

std::ostream& operator<<(std::ostream& os, const AbilityGroup& ability_group);

class Ability {
 public:
  Ability();
  Ability(int id, int group_id, const std::string& label);
  int group_id() const;
  void group_id(int group_id);
  int id() const;
  void id(int id);
  std::string label() const;
  void label(const std::string& label);
  bool operator==(const Ability& other) const;
  bool operator!=(const Ability& other) const;

  static Ability FromIds(int id, int group_id);
  static Ability FromKnowledgeId(int id);
  static Ability FromSkillId(int id);
  static Ability FromTalentId(int id);
  static int GetCount(int group_id);
  static std::string GetKnowledgeLabel(int id);
  static std::vector<std::string> GetKnowledgeLabels();
  static int GetKnowledgesCount();
  static std::string GetSkillLabel(int id);
  static std::vector<std::string> GetSkillLabels();
  static int GetSkillsCount();
  static std::string GetTalentLabel(int id);
  static std::vector<std::string> GetTalentLabels();
  static int GetTalentsCount();

  friend std::ostream& operator<<(std::ostream& os, const Ability& ability);

 private:
  int id_;
  int group_id_;
  std::string label_;
};

std::ostream& operator<<(std::ostream& os, const Ability& ability);
}  // End namespace SBF

/** @}*/
#endif  // End !defined ABILITIES_H__
