#include "Character.h"

namespace SBF {
    
    using std::wstring;
    using std::vector;

    int GetNumAttributesInGroup(int groupId) {
        switch (groupId) {
            case kAttributeGroupPhysicalId:
                return kPhysicalAttributesCount;
            case kAttributeGroupSocialId:
                return kSocialAttributesCount;
            case kAttributeGroupMentalId:
                return kMentalAttributesCount;
            default:
                return 0;
        }
    }

    CharacterType::CharacterType() {
        // Scalars
        name = L"";
        player = L"";
        chronicle = L"";
        haven = L"";
        concept = L"";
        age = L"";
        genderId = 0;
        clanId = 0;
        natureId = 0;
        demeanorId = 0;
        generation = 3;
        roadName = L"";
        roadValue = 0;
        willpower = 0;
        bloodPool = 0;
        derangementId = -1;

        // Virtues
        selfControl = 1;
        courage = 1;
        conscience = 1;

        // Arrays/Objects
        // Abilities (Talents/Skills/Knowledges)
        for (int groupId = 1; groupId <= kAbilitiesCount; groupId++) {
            const int numAbilities = GetNumItemsForAbilityGroup(groupId);
            for (int abilityId = 1; abilityId <= numAbilities; abilityId++) {
                SetAbilityValue(groupId, abilityId, 0);
            }
        }

        // Attributes
        for (int groupId = 1; groupId <= kAttributeGroupsCount; groupId++) {
            const int numAttributes = GetNumAttributesInGroup(groupId);
            for (int attributeId = 1; attributeId <= numAttributes; attributeId++) {
                SetAttributeValue(groupId, attributeId, 1);
            }
        }

        // Backgrounds
        for (int id = 0; id <= kBackgroundsCount; id++) {
            SetBackgroundValue(id, 0);
        }

        // Disciplines
        for (int id = 0; id <= kDisciplinesCount; id++) {
            SetDisciplineValue(id, 0);
        }
    }

    void CharacterType::SetDisciplineValue(int disciplineId, int value) {
        switch (disciplineId) {
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

    int CharacterType::GetDisciplineValue(int disciplineId) const {
        switch (disciplineId) {
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

    void CharacterType::FillDisciplineValues(std::vector<int> disciplineValues) const {
        // TODO: This method sucks, but was needed in QBasic.
        disciplineValues.clear();
        for (int id = 0; id <= kDisciplinesCount; id++) {
            disciplineValues[id] = GetDisciplineValue(id);
        }
    }

    int GetVirtuePoints() {
        return kVirtuePoints;
    }

    void CharacterType::SetVirtueValue(int virtueId, int value) {
        switch (virtueId) {
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

    int CharacterType::GetVirtueValue(int virtueId) const {
        switch (virtueId) {
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

    void CharacterType::FillVirtueValues(std::vector<int> virtueValues) const {
        // TODO: This method sucks, but was needed in QBasic.
        virtueValues.clear();
        for (int id = 0; id <= kVirtuesCount; id++) {
            virtueValues[id] = GetVirtueValue(id);
        }
    }

    void CharacterType::FillAttributeValues(std::vector<int> attributeValues, int attributeGroupId) const {
        // TODO: This method sucks, but was needed in QBasic.
        const int numAttributes = GetNumAttributesInGroup(attributeGroupId);
        attributeValues.clear();
        for (int attributeId = 0; attributeId <= numAttributes; attributeId++) {
            attributeValues[attributeId] = GetAttributeValue(attributeGroupId, attributeId);
        }
    }

    wstring GetAttributeLabel(int attributeGroupId, int attributeId) {
        switch (attributeGroupId) {
            case kAttributeGroupPhysicalId:
                return kPhysicalAttributeLabels[attributeId];
            case kAttributeGroupSocialId:
                return kSocialAttributeLabels[attributeId];
            case kAttributeGroupMentalId:
                return kMentalAttributeLabels[attributeId];
            default:
                return L"";
        }
    }

    void FillAttributeLabelsInGroup(std::vector<wstring> attributeLabels, int attributeGroupId) {
        attributeLabels.clear();
        switch (attributeGroupId) {
            case kAttributeGroupPhysicalId:
                for (int attributeId = 0; attributeId <= kPhysicalAttributesCount; attributeId++) {
                    attributeLabels[attributeId] = kPhysicalAttributeLabels[attributeId];
                }
                break;
            case kAttributeGroupSocialId:
                for (int attributeId = 0; attributeId <= kSocialAttributesCount; attributeId++) {
                    attributeLabels[attributeId] = kSocialAttributeLabels[attributeId];
                }
                break;
            case kAttributeGroupMentalId:
                for (int attributeId = 0; attributeId <= kMentalAttributesCount; attributeId++) {
                    attributeLabels[attributeId] = kMentalAttributeLabels[attributeId];
                }
                break;
        }
    }

    void FillAttributeAbbreviationsInGroup(std::vector<wstring> attributeAbbreviations, int attributeGroupId) {
        attributeAbbreviations.clear();
        switch (attributeGroupId) {
            case kAttributeGroupPhysicalId:
                for (int attributeId = 0; attributeId <= kPhysicalAttributesCount; attributeId++) {
                    attributeAbbreviations[attributeId] = kPhysicalAttributeAbbreviations[attributeId];
                }
                break;
            case kAttributeGroupSocialId:
                for (int attributeId = 0; attributeId <= kSocialAttributesCount; attributeId++) {
                    attributeAbbreviations[attributeId] = kSocialAttributeAbbreviations[attributeId];
                }
                break;
            case kAttributeGroupMentalId:
                for (int attributeId = 0; attributeId <= kMentalAttributesCount; attributeId++) {
                    attributeAbbreviations[attributeId] = kMentalAttributeAbbreviations[attributeId];
                }
                break;
        }
    }

    void CharacterType::SetAttributeValue(int attributeGroupId, int attributeId, int value) {
        switch (attributeGroupId) {
            case kAttributeGroupPhysicalId:
                switch (attributeId) {
                    case kPhysicalAttributeStrengthId:
                        attr_strength = value;
                        break;
                    case kPhysicalAttributeDexterityId:
                        attr_dexterity = value;
                        break;
                    case kPhysicalAttributeStaminaId:
                        attr_stamina = value;
                        break;
                }
                break;
            case kAttributeGroupSocialId:
                switch (attributeId) {
                    case kSocialAttributeCharismaId:
                        attr_charisma = value;
                        break;
                    case kSocialAttributeManipulationId:
                        attr_manipulation = value;
                        break;
                    case kSocialAttributeAppearanceId:
                        attr_appearance = value;
                        break;
                }
                break;
            case kAttributeGroupMentalId:
                switch (attributeId) {
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
                break;
        }
    }

    int CharacterType::GetAttributeValue(int attributeGroupId, int attributeId) const {
        switch (attributeGroupId) {
            case kAttributeGroupPhysicalId:
                switch (attributeId) {
                    case kPhysicalAttributeStrengthId:
                        return attr_strength;
                    case kPhysicalAttributeDexterityId:
                        return attr_dexterity;
                    case kPhysicalAttributeStaminaId:
                        return attr_stamina;
                }
                break;
            case kAttributeGroupSocialId:
                switch (attributeId) {
                    case kSocialAttributeCharismaId:
                        return attr_charisma;
                    case kSocialAttributeManipulationId:
                        return attr_manipulation;
                    case kSocialAttributeAppearanceId:
                        return attr_appearance;
                }
                break;
            case kAttributeGroupMentalId:
                switch (attributeId) {
                    case kMentalAttributeIntelligenceId:
                        return attr_intelligence;
                    case kMentalAttributePerceptionId:
                        return attr_perception;
                    case kMentalAttributeWitsId:
                        return attr_wits;
                }
                break;
        }
        return 0;
    }

    int GetAttributePointsForRank (int rankId) {
        switch (rankId) {
            case kRankPrimaryId:
                return 7;
            case kRankSecondaryId:
                return 5;
            case kRankTertiaryId:
                return 3;
        }
        return 0;
    }

    void CharacterType::SetAbilityValue(int abilityGroupId, int abilityId, int value) {
        switch (abilityGroupId) {
            case kAbilityTalentsId:
                SetTalentValue(abilityId, value);
                break;
            case kAbilitySkillsId:
                SetSkillValue(abilityId, value);
                break;
            case kAbilityKnowledgesId:
                SetKnowledgeValue(abilityId, value);
                break;
        }
    }

    int CharacterType::GetAbilityValue(int abilityGroupId, int abilityId) const {
        switch(abilityGroupId) {
            case kAbilityTalentsId:
                return GetTalentValue(abilityId);
            case kAbilityKnowledgesId:
                return GetKnowledgeValue(abilityId);
            case kAbilitySkillsId:
                return GetSkillValue(abilityId);
        }
        return 0;
    }

    int GetAbilityPointsForRank(int rankId) {
        switch (rankId) {
            case kRankPrimaryId:
                return 13;
            case kRankSecondaryId:
                return 9;
            case kRankTertiaryId:
                return 5;
        }
        return 0;
    }

    void CharacterType::FillAbilityValues(std::vector<int>abilityValues, int abilityGroupId) const {
        int numAbilities = GetNumItemsForAbilityGroup(abilityGroupId);
        abilityValues.clear();
        for (int abilityId = 0; abilityId <= numAbilities; abilityId++) {
            abilityValues[abilityId] = GetAbilityValue(abilityGroupId, abilityId);
        }
    }

    int GetNumItemsForAbilityGroup(int abilityGroupId) {
        switch (abilityGroupId) {
            case kAbilityTalentsId:
                return kTalentsCount;
            case kAbilitySkillsId:
                return kSkillsCount;
            case kAbilityKnowledgesId:
                return kKnowledgesCount;
        }
        return 0;
    }

    void FillAbilitiesForAbilityGroup(std::vector<wstring> abilities, int abilityGroupId) {
        abilities.clear();
        int numAbilities = GetNumItemsForAbilityGroup(abilityGroupId);
        switch (abilityGroupId) {
            case kAbilityTalentsId:
                for (int talentId = 0; talentId <= numAbilities; talentId++) {
                    abilities[talentId] = kTalents[talentId];
                }
                break;
            case kAbilitySkillsId:
                for (int skillId = 0; skillId <= numAbilities; skillId++) {
                    abilities[skillId] = kSkills[skillId];
                }
                break;
            case kAbilityKnowledgesId:
                for (int knowledgeId = 0; knowledgeId <= numAbilities; knowledgeId++) {
                    abilities[knowledgeId] = kKnowledges[knowledgeId];
                }
                break;
        }
    }

    void CharacterType::SetTalentValue(int talentId, int value) {
        switch (talentId) {
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
    
    int CharacterType::GetTalentValue(int talentId) const {
        switch (talentId) {
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

    void CharacterType::SetSkillValue(int skillId, int value) {
        switch (skillId) {
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

    int CharacterType::GetSkillValue(int skillId) const {
        switch (skillId) {
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

    void CharacterType::SetKnowledgeValue(int knowledgeId, int value) {
        switch (knowledgeId) {
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
    
    int CharacterType::GetKnowledgeValue(int knowledgeId) const {
        switch (knowledgeId) {
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

    void CharacterType::SetBackgroundValue(int backgroundId, int value) {
        switch (backgroundId) {
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

    int CharacterType::GetBackgroundValue(int backgroundId) const {
        switch (backgroundId) {
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

    void CharacterType::FillBackgroundValues(std::vector<int> backgroundValues) const {
        backgroundValues.clear();
        for (int backgroundId = 0; backgroundId <= kBackgroundsCount; backgroundId++) {
            backgroundValues[backgroundId] = GetBackgroundValue(backgroundId);
        }
    }

    int GetBackgroundPoints() {
        return kBackgroundPoints;
    }

    void NewDerangement(DerangementType& derangement, int id, wstring label, int textColor, wstring description) {
        derangement.id = id;
        derangement.label = label;
        derangement.textColor = textColor;
        derangement.description = description;
    }

    wstring CharacterType::GetAllDerangementsLine() const {
        // TODO: Replace this with a stringstream.
        std::vector<DerangementType> allDerangements;
        FillDerangements(allDerangements);
        wstring allDerangementsString = L"";
        std::for_each(allDerangements.begin(), allDerangements.end(), [&allDerangementsString](DerangementType derangement) {
            allDerangementsString += derangement.label + L", ";
        });
        return allDerangementsString;
    }

    void CharacterType::FillDerangements(std::vector<DerangementType> derangements) const {
        derangements.clear();
        if (derangementId > 0) {
            derangements[0] = kDerangements[derangementId];
        }
    }
} // End namespace SBF
    