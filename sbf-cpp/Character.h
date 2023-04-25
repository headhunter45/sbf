#ifndef CHARACTER_H__
#define CHARACTER_H__
/***************************************************************************************
 * @file Character.h
 *
 * @brief Defines CharacterType.
 * @copyright
 * Copyright 2023 Tom Hicks
 * Licensed under the MIT license see the LICENSE file for details.
 ***************************************************************************************/
#include <cstdint>
#include <string>
#include <vector>

#include "Abilities.h"
#include "Attributes.h"
#include "Backgrounds.h"
#include "Clans.h"
#include "Colors.h"
#include "Derangements.h"
#include "Disciplines.h"
#include "Ranks.h"
#include "Virtues.h"

/** \addtogroup Character
 * @{
 */
namespace SBF {
int GetAttributePointsForRank(int rank_id);
int GetBackgroundPoints();
int GetDisciplinePoints();
int GetVirtuePoints();

class CharacterType {
 public:
  CharacterType();
  void FillAbilityValues(std::vector<int>& values, int group_id) const;
  void FillAttributeValues(std::vector<int>& values, int group_id) const;
  void FillBackgroundValues(std::vector<int>& values) const;
  void FillDisciplineValues(std::vector<int>& values) const;
  void FillVirtueValues(std::vector<int>& values) const;
  int GetAbilityValue(int group_id, int id) const;
  std::string GetAllDerangementsLine() const;
  int GetAttributeValue(int group_id, int id) const;
  std::vector<int> GetAttributeValuesInGroup(int group_id) const;
  int GetBackgroundValue(int id) const;
  std::vector<int> GetBackgroundValues() const;
  int GetDisciplineValue(int id) const;
  std::vector<int> GetDisciplineValues() const;
  int GetKnowledgeValue(int id) const;
  int GetMentalAttributeValue(int id) const;
  int GetPhysicalAttributeValue(int id) const;
  int GetSkillValue(int id) const;
  int GetSocialAttributeValue(int id) const;
  int GetTalentValue(int id) const;
  int GetVirtueValue(int id) const;
  std::vector<int> GetVirtueValues() const;
  void SetAbilityValue(int group_id, int id, int value);
  void SetAttributeValue(int group_id, int id, int value);
  void SetBackgroundValue(int id, int value);
  void SetDisciplineValue(int id, int value);
  void SetKnowledgeValue(int id, int value);
  void SetMentalAttributeValue(int id, int value);
  void SetPhysicalAttributeValue(int id, int value);
  void SetSkillValue(int id, int value);
  void SetSocialAttributeValue(int id, int value);
  void SetTalentValue(int id, int value);
  void SetVirtueValue(int id, int value);
  std::string name;
  std::string player;
  std::string chronicle;
  std::string haven;
  std::string concept;
  std::string age;
  int genderId;
  int clanId;
  int natureId;
  int demeanorId;
  int conscience;
  int selfControl;
  int courage;
  int generation;
  std::string roadName;
  int roadValue;
  int willpower;
  int bloodPool;
  int derangementId;

 private:
  // Disciplines
  int discipline_animalism;
  int discipline_auspex;
  int discipline_bardo;
  int discipline_celerity;
  int discipline_chimestry;
  int discipline_dementation;
  int discipline_dominate;
  int discipline_fortitude;
  int discipline_melpominee;
  int discipline_mortis;
  int discipline_mytherceria;
  int discipline_necromancy;
  int discipline_obeah;
  int discipline_obfuscate;
  int discipline_obtenebration;
  int discipline_potence;
  int discipline_presence;
  int discipline_protean;
  int discipline_quietus;
  int discipline_serpentis;
  int discipline_spiritus;
  int discipline_thanantosis;
  int discipline_thaumaturgy;
  int discipline_vicissitude;

  // Attributes
  int attr_strength;
  int attr_dexterity;
  int attr_stamina;
  int attr_appearance;
  int attr_charisma;
  int attr_manipulation;
  int attr_intelligence;
  int attr_perception;
  int attr_wits;

  // Talents
  int talent_acting;
  int talent_alertness;
  int talent_athletics;
  int talent_brawl;
  int talent_dodge;
  int talent_empathy;
  int talent_intimidation;
  int talent_leadership;
  int talent_streetwise;
  int talent_subterfuge;

  // Skills
  int skill_animalKen;
  int skill_drive;
  int skill_etiquette;
  int skill_firearms;
  int skill_melee;
  int skill_music;
  int skill_repair;
  int skill_security;
  int skill_stealth;
  int skill_survival;

  // Knowledges
  int knowledge_bureaucracy;
  int knowledge_computer;
  int knowledge_finance;
  int knowledge_investigation;
  int knowledge_law;
  int knowledge_linguistics;
  int knowledge_medicine;
  int knowledge_occult;
  int knowledge_politics;
  int knowledge_science;

  // Backgrounds
  int background_allies;
  int background_contacts;
  int background_fame;
  int background_generation;
  int background_herd;
  int background_influence;
  int background_mentor;
  int background_resources;
  int background_retainers;
  int background_status;
};  // End class CharacterType
}  // End namespace SBF

/** @}*/
#endif  // !defined CHARACTER_H__
