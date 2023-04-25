#ifndef ATTRIBUTES_H__
#define ATTRIBUTES_H__
/***************************************************************************************
 * @file Attributes.h
 *
 * @brief Defines constants and functions for working with attribute groups and attriubtes.
 * @copyright
 * Copyright 2023 Tom Hicks
 * Licensed under the MIT license see the LICENSE file for details.
 ***************************************************************************************/
#include <string>
#include <vector>

/** \addtogroup Attributes
 * @{
 */
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

/// @brief Gets the label for the attribute group with the specified id.
/// @param attribute_group_id The id of the attribute group to return the label for.
/// @return The label of the specified attribute group.
std::string GetAttributeGroupLabel(int attribute_group_id);

/// @brief Gets the label for the attribute with a specific pair of group and attribute ids.
/// @param attribute_group_id The id of the attribute group to get the label for.
/// @param attribute_id The id of the attribute within the group to return the label for.
/// @return The label of the specified attribute or an empty string if either id is invalid.
std::string GetAttributeLabel(int attribute_group_id, int attribute_id);

/// @brief Gets the label abbreviation for the attribute with a specific pair of group and attribute ids.
/// @param attribute_group_id The id of the attribute group to get the label abbreviation for.
/// @param attribute_id The id of the attribute within the group to return the label abbreviation for.
/// @return The label abbreviation of the specified attribute or an empty string if either id is invalid.
std::string GetAttributeLabelAbbreviation(int attribute_group_id, int attribute_id);

/// @brief Gets the label for the physical attribute with a specific id.
/// @param attribute_id The id of the physical attribute to get the label for.
/// @return The label of the specified attribute or an empty string if the id is invalid.
std::string GetPhysicalAttributeLabel(int attribute_id);

/// @brief Gets the label abbreviation for the physical attribute with a specific id.
/// @param attribute_id The id of the physical attribute to get the label abbreviation for.
/// @return The label abbreviation of the specified attribute or an empty string if the id is invalid.
std::string GetPhysicalAttributeLabelAbbreviation(int attribute_id);

/// @brief Gets the number of attributes in a specific attribute group.
/// @param attribute_group_id The id of the attribute group.
/// @return The number of attributes in the specified group or 0 if the id is invalid.
int GetNumAttributesInGroup(int attribute_group_id);

/// @brief Gets the label for the social attribute with a specific id.
/// @param attribute_id The id of the social attribute to get the label for.
/// @return The label of the specified attribute or an empty string if the id is invalid.
std::string GetSocialAttributeLabel(int attribute_id);

/// @brief Gets the label abbreviation for the social attribute with a specific id.
/// @param attribute_id The id of the social attribute to get the label abbreviation for.
/// @return The label abbreviation of the specified attribute or an empty string if the id is invalid.
std::string GetSocialAttributeLabelAbbreviation(int attribute_id);

/// @brief Gets the label for the mental attribute with a specific id.
/// @param attribute_id The id of the mental attribute to get the label for.
/// @return The label of the specified attribute or an empty string if the id is invalid.
std::string GetMentalAttributeLabel(int attribute_id);

/// @brief Gets the label abbreviation for the mental attribute with a specific id.
/// @param attribute_id The id of the mental attribute to get the label abbreviation for.
/// @return The label abbreviation of the specified attribute or an empty string if the id is invalid.
std::string GetMentalAttributeLabelAbbreviation(int attribute_id);

/// @brief Fills the provided vector with all of the valid attribute group labels
/// @param labels The vector to fill. It will be cleared first.
void FillAttributeGroupLabels(std::vector<std::string>& labels);

/// @brief Fills the provided vector with all of the valid attribute labels in a specific group.
/// @param labels The vector to fill. It will be cleared first.
/// @param group_id The group to fill attribute labels for.
void FillAttributeLabelsInGroup(std::vector<std::string>& labels, int group_id);

/// @brief Gets the valid attribute labels in a specific group.
/// @param group_id The group to fill attribute labels for.
/// @return The filled vector.
std::vector<std::string> GetAttributeLabelsInGroup(int group_id);

/// @brief Fills the provided vector with all of the valid physical attribute labels.
/// @param labels The vector to fill. It will be cleared first.
void FillPhysicalAttributeLabels(std::vector<std::string>& labels);

/// @brief Fills the provided vector with all of the valid social attribute labels.
/// @param labels The vector to fill. It will be cleared first.
void FillSocialAttributeLabels(std::vector<std::string>& labels);

/// @brief Fills the provided vector with all of the valid mental attribute labels.
/// @param labels The vector to fill. It will be cleared first.
void FillMentalAttributeLabels(std::vector<std::string>& labels);
}  // End namespace SBF

/** @}*/
#endif  // End !defined ATTRIBUTES_H__
