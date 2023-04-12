#ifndef ABILITIES_H__
#define ABILITIES_H__
#include <string>
#include <vector>

namespace SBF {
    const int kAbilityTalentsId = 1;
    const std::wstring kAbilityTalentsSingular = L"Talent";
    const std::wstring kAbilityTalentsPlural = L"Talents";
    const int kAbilitySkillsId = 2;
    const std::wstring kAbilitySkillsSingular = L"Skill";
    const std::wstring kAbilitySkillsPlural = L"Skills";
    const int kAbilityKnowledgesId = 3;
    const std::wstring kAbilityKnowledgesSingular = L"Skill";
    const std::wstring kAbilityKnowledgesPlural = L"Skills";
    const int kAbilitiesCount = 3;
    struct AbilityType {
        int id;
        std::wstring singular;
        std::wstring plural;
    };
    const AbilityType kAbilities[] {
        {0, L"", L""},
        {kAbilityTalentsId, kAbilityTalentsSingular, kAbilityTalentsPlural},
        {kAbilitySkillsId, kAbilitySkillsSingular, kAbilitySkillsPlural},
        {kAbilityKnowledgesId, kAbilityKnowledgesSingular, kAbilityKnowledgesPlural},
    };

    const int kTalentActingId = 1;
    const std::wstring kTalentActingLabel = L"Acting";
    const int kTalentAlertnessId = 2;
    const std::wstring kTalentAlertnessLabel = L"Alertness";
    const int kTalentAthleticsId = 3;
    const std::wstring kTalentAthleticsLabel = L"Athletics";
    const int kTalentBrawlId = 4;
    const std::wstring kTalentBrawlLabel = L"Brawl";
    const int kTalentDodgeId = 5;
    const std::wstring kTalentDodgeLabel = L"Dodge";
    const int kTalentEmpathyId = 6;
    const std::wstring kTalentEmpathyLabel = L"Empathty";
    const int kTalentIntimidationId = 7;
    const std::wstring kTalentIntimidationLabel = L"Intimidation";
    const int kTalentLeadershipId = 8;
    const std::wstring kTalentLeadershipLabel = L"Leadership";
    const int kTalentStreetwiseId = 9;
    const std::wstring kTalentStreetwiseLabel = L"Streetwise";
    const int kTalentSubterfugeId = 10;
    const std::wstring kTalentSubterfugeLabel = L"Subterfuge";
    const int kTalentsCount = 10;
    const std::wstring kTalents[] = {
        L"",
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
    const std::wstring kSkillAnimalKenLabel = L"AnimalKen";
    const int kSkillDriveId = 2;
    const std::wstring kSkillDriveLabel = L"Drive";
    const int kSkillEtiquetteId = 3;
    const std::wstring kSkillEtiquetteLabel = L"Etiquette";
    const int kSkillFirearmsId = 4;
    const std::wstring kSkillFirearmsLabel = L"Firearms";
    const int kSkillMeleeId = 5;
    const std::wstring kSkillMeleeLabel = L"Melee";
    const int kSkillMusicId = 6;
    const std::wstring kSkillMusicLabel = L"Music";
    const int kSkillRepairId = 7;
    const std::wstring kSkillRepairLabel = L"Repair";
    const int kSkillSecurityId = 8;
    const std::wstring kSkillSecurityLabel = L"Security";
    const int kSkillStealthId = 9;
    const std::wstring kSkillStealthLabel = L"Stealth";
    const int kSkillSurvivalId = 10;
    const std::wstring kSkillSurvivalLabel = L"Survival";
    const int kSkillsCount = 10;
    const std::wstring kSkills[] = {
        L"",
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
    const std::wstring kKnowledgeBureaucracyLabel = L"Bureaucracy";
    const int kKnowledgeComputerId = 2;
    const std::wstring kKnowledgeComputerLabel = L"Computer";
    const int kKnowledgeFinanceId = 3;
    const std::wstring kKnowledgeFinanceLabel = L"Finance";
    const int kKnowledgeInvestigationId = 4;
    const std::wstring kKnowledgeInvestigationLabel = L"Investigation";
    const int kKnowledgeLawId = 5;
    const std::wstring kKnowledgeLawLabel = L"Law";
    const int kKnowledgeLinguisticsId = 6;
    const std::wstring kKnowledgeLinguisticsLabel = L"Linguistics";
    const int kKnowledgeMedicineId = 7;
    const std::wstring kKnowledgeMedicineLabel = L"Medicine";
    const int kKnowledgeOccultId = 8;
    const std::wstring kKnowledgeOccultLabel = L"Occult";
    const int kKnowledgePoliticsId = 9;
    const std::wstring kKnowledgePoliticsLabel = L"Politics";
    const int kKnowledgeScienceId = 10;
    const std::wstring kKnowledgeScienceLabel = L"Science";
    const int kKnowledgesCount = 10;
    const std::wstring kKnowledges[] = {
        L"",
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

    int GetNumItemsForAbilityGroup(int abilityGroupId);
    const AbilityType GetAbility(int abilityId);
    void FillAbilities(std::vector<AbilityType> abilities);
    const std::wstring GetTalentLabel(int talentId);
    const std::wstring GetSkillLabel(int talentId);
    const std::wstring GetKnowledgeLabel(int talentId);
    const std::wstring GetAbilityLabel(int abilityGroupId, int abilityId);
    void FillTalentLabels(std::vector<std::wstring> talentLabels);
    void FillSkillLabels(std::vector<std::wstring> skillLabels);
    void FillKnowledgeLabels(std::vector<std::wstring> knowledgeLabels);
} // End namespace SBF
#endif // End !defined ABILITIES_H__
