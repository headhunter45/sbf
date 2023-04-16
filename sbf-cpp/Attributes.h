#ifndef ATTRIBUTES_H__
#define ATTRIBUTES_H__
#include <string>
#include <vector>

namespace SBF {
    const int kPhysicalAttributeStrengthId = 1;
    const std::string kPhysicalAttributeStrengthLabel = "Strength";
    const std::string kPhysicalAttributeStrengthAbbreviation = "Str.";
    const int kPhysicalAttributeDexterityId = 2;
    const std::string kPhysicalAttributeDexterityLabel = "Dexterity";
    const std::string kPhysicalAttributeDexterityAbbreviation = "Dex.";
    const int kPhysicalAttributeStaminaId = 3;
    const std::string kPhysicalAttributeStaminaLabel = "Stamina";
    const std::string kPhysicalAttributeStaminaAbbreviation = "Sta.";
    const int kPhysicalAttributesCount = 3;
    const std::string kPhysicalAttributeLabels[] = {
        "",
        kPhysicalAttributeStrengthLabel,
        kPhysicalAttributeDexterityLabel,
        kPhysicalAttributeStaminaLabel,
    };
    const std::string kPhysicalAttributeLabelAbbreviations[] = {
        "",
        kPhysicalAttributeStrengthAbbreviation,
        kPhysicalAttributeDexterityAbbreviation,
        kPhysicalAttributeStaminaAbbreviation,
    };

    const int kSocialAttributeCharismaId = 1;
    const std::string kSocialAttributeCharismaLabel = "Charisma";
    const std::string kSocialAttributeCharismaAbbreviation = "Cha.";
    const int kSocialAttributeManipulationId = 2;
    const std::string kSocialAttributeManipulationLabel = "Manipulation";
    const std::string kSocialAttributeManipulationAbbreviation = "Man.";
    const int kSocialAttributeAppearanceId = 3;
    const std::string kSocialAttributeAppearanceLabel = "Appearance";
    const std::string kSocialAttributeAppearanceAbbreviation = "App.";
    const int kSocialAttributesCount = 3;
    const std::string kSocialAttributeLabels[] = {
        "",
        kSocialAttributeCharismaLabel,
        kSocialAttributeManipulationLabel,
        kSocialAttributeAppearanceLabel,
    };
    const std::string kSocialAttributeLabelAbbreviations[] = {
        "",
        kSocialAttributeCharismaAbbreviation,
        kSocialAttributeManipulationAbbreviation,
        kSocialAttributeAppearanceAbbreviation,
    };

    const int kMentalAttributeIntelligenceId = 1;
    const std::string kMentalAttributeIntelligenceLabel = "Intelligence";
    const std::string kMentalAttributeIntelligenceAbbreviation = "Int.";
    const int kMentalAttributePerceptionId = 2;
    const std::string kMentalAttributePerceptionLabel = "Perception";
    const std::string kMentalAttributePerceptionAbbreviation = "Per.";
    const int kMentalAttributeWitsId = 3;
    const std::string kMentalAttributeWitsLabel = "Wits";
    const std::string kMentalAttributeWitsAbbreviation = "Wits";
    const int kMentalAttributesCount = 3;
    const std::string kMentalAttributeLabels[] = {
        "",
        kMentalAttributeIntelligenceLabel,
        kMentalAttributePerceptionLabel,
        kMentalAttributeWitsLabel,
    };
    const std::string kMentalAttributeLabelAbbreviations[] = {
        "",
        kMentalAttributeIntelligenceAbbreviation,
        kMentalAttributePerceptionAbbreviation,
        kMentalAttributeWitsAbbreviation,
    };

    const int kAttributeGroupPhysicalId = 1;
    const std::string kAttributeGroupPhysicalLabel = "Physical";
    const int kAttributeGroupSocialId = 2;
    const std::string kAttributeGroupSocialLabel = "Social";
    const int kAttributeGroupMentalId = 3;
    const std::string kAttributeGroupMentalLabel = "Mental";
    const int kAttributeGroupsCount = 3;
    const std::string kAttributeGroups[] = {
        "",
        kAttributeGroupPhysicalLabel,
        kAttributeGroupSocialLabel,
        kAttributeGroupMentalLabel,
    };

    std::string GetAttributeGroupLabel(int attributeGroupId);
    std::string GetAttributeLabel(int attributeGroupId, int attributeId);
    std::string GetAttributeLabelAbbreviation(int attributeGroupId, int attributeId);
    std::string GetPhysicalAttributeLabel(int attributeId);
    std::string GetPhysicalAttributeLabelAbbreviation(int attributeId);
    int GetNumAttributesInGroup(int attributeGroupId);
    std::string GetSocialAttributeLabel(int attributeId);
    std::string GetSocialAttributeLabelAbbreviation(int attributeId);
    std::string GetMentalAttributeLabel(int attributeId);
    std::string GetMentalAttributeLabelAbbreviation(int attributeId);
    void FillAttributeGroupLabels(std::vector<std::string>& attributeGroupLabels);
    void FillAttributeLabelsInGroup(std::vector<std::string>& attributeLabels, int groupId);
    void FillPhysicalAttributeLabels(std::vector<std::string>& physicalAttributeLabels);
    void FillSocialAttributeLabels(std::vector<std::string>& socialAttributeLabels);
    void FillMentalAttributeLabels(std::vector<std::string>& mentalAttributeLabels);
} // End namespace SBF
#endif // End !defined ATTRIBUTES_H__
