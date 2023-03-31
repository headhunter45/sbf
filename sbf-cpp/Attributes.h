#ifndef ATTRIBUTES_H__
#define ATTRIBUTES_H__
#include <string>
#include <vector>

namespace SBF {
    const int kPhysicalAttributeStrengthId = 1;
    const std::wstring kPhysicalAttributeStrengthLabel = L"Strength";
    const std::wstring kPhysicalAttributeStrengthAbbreviation = L"Str.";
    const int kPhysicalAttributeDexterityId = 2;
    const std::wstring kPhysicalAttributeDexterityLabel = L"Dexterity";
    const std::wstring kPhysicalAttributeDexterityAbbreviation = L"Dex.";
    const int kPhysicalAttributeStaminaId = 3;
    const std::wstring kPhysicalAttributeStaminaLabel = L"Stamina";
    const std::wstring kPhysicalAttributeStaminaAbbreviation = L"Sta.";
    const int kPhysicalAttributesCount = 3;
    const std::wstring kPhysicalAttributeLabels[] = {
        L"",
        kPhysicalAttributeStrengthLabel,
        kPhysicalAttributeDexterityLabel,
        kPhysicalAttributeStaminaLabel,
    };
    const std::wstring kPhysicalAttributeAbbreviations[] = {
        L"",
        kPhysicalAttributeStrengthAbbreviation,
        kPhysicalAttributeDexterityAbbreviation,
        kPhysicalAttributeStaminaAbbreviation,
    };

    const int kSocialAttributeCharismaId = 1;
    const std::wstring kSocialAttributeCharismaLabel = L"Charisma";
    const std::wstring kSocialAttributeCharismaAbbreviation = L"Cha.";
    const int kSocialAttributeManipulationId = 2;
    const std::wstring kSocialAttributeManipulationLabel = L"Manipulation";
    const std::wstring kSocialAttributeManipulationAbbreviation = L"Man.";
    const int kSocialAttributeAppearanceId = 3;
    const std::wstring kSocialAttributeAppearanceLabel = L"Appearance";
    const std::wstring kSocialAttributeAppearanceAbbreviation = L"App.";
    const int kSocialAttributesCount = 3;
    const std::wstring kSocialAttributeLabels[] = {
        L"",
        kSocialAttributeCharismaLabel,
        kSocialAttributeManipulationLabel,
        kSocialAttributeAppearanceLabel,
    };
    const std::wstring kSocialAttributeAbbreviations[] = {
        L"",
        kSocialAttributeCharismaAbbreviation,
        kSocialAttributeManipulationAbbreviation,
        kSocialAttributeAppearanceAbbreviation,
    };

    const int kMentalAttributeIntelligenceId = 1;
    const std::wstring kMentalAttributeIntelligenceLabel = L"Intelligence";
    const std::wstring kMentalAttributeIntelligenceAbbreviation = L"Int.";
    const int kMentalAttributePerceptionId = 2;
    const std::wstring kMentalAttributePerceptionLabel = L"Perception";
    const std::wstring kMentalAttributePerceptionAbbreviation = L"Per.";
    const int kMentalAttributeWitsId = 3;
    const std::wstring kMentalAttributeWitsLabel = L"Wits";
    const std::wstring kMentalAttributeWitsAbbreviation = L"Wits";
    const int kMentalAttributesCount = 3;
    const std::wstring kMentalAttributeLabels[] = {
        L"",
        kMentalAttributeIntelligenceLabel,
        kMentalAttributePerceptionLabel,
        kMentalAttributeWitsLabel,
    };
    const std::wstring kMentalAttributeAbbreviations[] = {
        L"",
        kMentalAttributeIntelligenceLabel,
        kMentalAttributePerceptionAbbreviation,
        kMentalAttributeWitsAbbreviation,
    };

    const int kAttributeGroupPhysicalId = 1;
    const std::wstring kAttributeGroupPhysicalLabel = L"Physical";
    const int kAttributeGroupSocialId = 2;
    const std::wstring kAttributeGroupSocialLabel = L"Social";
    const int kAttributeGroupMentalId = 3;
    const std::wstring kAttributeGroupMentalLabel = L"Mental";
    const int kAttributeGroupsCount = 3;
    const std::wstring kAttributeGroups[] = {
        L"",
        kAttributeGroupPhysicalLabel,
        kAttributeGroupSocialLabel,
        kAttributeGroupMentalLabel,
    };

    const std::wstring& GetAttributeGroupLabel(int attributeGroupId);
    const std::wstring& GetAtttributeLabel(int attributeGroupId, int attributeId);
    const std::wstring& GetPhysicalAttributeLabel(int attributeId);
    const std::wstring& GetSocialAttributeLabel(int attributeId);
    const std::wstring& GetMentalAttributeLabel(int attributeId);
    void FillAttributeGroupLabels(std::vector<std::wstring> attributeGroupLabels);
    void FillAttributeLabelInGroup(std::vector<std::wstring> attributeLabels);
    void FillPhysicalAttributeLabels(std::vector<std::wstring> physicalAttributeLabels);
    void FillSocialAttributeLabels(std::vector<std::wstring> socialAttributeLabels);
    void FillMentalAttributeLabels(std::vector<std::wstring> mentalAttributeLabels);
} // End namespace SBF
#endif // End !defined ATTRIBUTES_H__
