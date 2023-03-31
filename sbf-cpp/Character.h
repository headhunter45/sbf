#ifndef CHARACTER_H__
#define CHARACTER_H__
#include "Colors.h"
#include "Ranks.h"
#include "Clans.h"
#include "Derangements.h"
#include "Disciplines.h"
#include "Virtues.h"
#include "Attributes.h"
#include "Abilities.h"
#include "Backgrounds.h"
#include <string>
#include <cstdint>
#include <vector>

namespace SBF {
    int GetDisciplinePoints();
    int GetVirtuePoints();
    
    class CharacterType {
        public:
            CharacterType();
            void FillAbilityValues(std::vector<int>abilityValues, int abilityGroupId) const;
            void FillAttributeValues(std::vector<int> attributeValues, int groupId) const;
            void FillBackgroundValues(std::vector<int> backgroundValues) const;
            void FillDisciplineValues(std::vector<int> disciplineValues) const;
            void FillDerangements(std::vector<DerangementType> derangements) const;
            void FillVirtueValues(std::vector<int> virtueValues) const;
            int GetAbilityValue(int abilityGroupId, int abilityId) const;
            int GetAttributeValue(int attributeGroupId, int abilityId) const;
            int GetBackgroundValue(int backgroundId) const;
            std::wstring GetAllDerangementsLine() const;
            int GetDisciplineValue(int disciplineId) const;
            int GetKnowledgeValue(int knowledgeId) const;
            int GetSkillValue(int skillId) const;
            int GetTalentValue(int talentId) const;
            int GetVirtueValue(int virtueId) const;
            void SetAbilityValue(int abilityGroupId, int abilityId, int value);
            void SetAttributeValue(int attributeGroupId, int attributeId, int value);
            void SetBackgroundValue(int backgroundId, int value);
            void SetDisciplineValue(int disciplineId, int value);
            void SetKnowledgeValue(int knowledgeId, int value);
            void SetSkillValue(int skillId, int value);
            void SetTalentValue(int talentId, int value);
            void SetVirtueValue(int virtueId, int value);
            
            std::wstring name;
            std::wstring player;
            std::wstring chronicle;
            std::wstring haven;
            std::wstring concept;
            std::wstring age;
            int genderId;
            int clanId;
            int natureId;
            int demeanorId;
            int conscience;
            int selfControl;
            int courage;
            int generation;
            std::wstring roadName;
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
    }; // End class CharacterType
} // End namespace SBF
#endif // !defined CHARACTER_H__
