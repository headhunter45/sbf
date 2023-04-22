#ifndef FREEBIES_H__
#define FREEBIES_H__

#include <string>
#include <vector>

namespace SBF {
struct FreebieType {
  int id;
  int cost;
  std::string name;
  std::string label;
};

const int kFreebiesCount = 7;

const FreebieType kFreebieUnknown = {0, 0, "", ""};

const int kFreebieDisciplineId = 1;
const int kFreebieDisciplineCost = 7;
const std::string kFreebieDisciplineName = "Discipline";
const std::string kFreebieDisciplineLabel = "Add a discipline dot    7 points";
const FreebieType kFreebieDiscipline = {
    kFreebieDisciplineId, kFreebieDisciplineCost, kFreebieDisciplineName, kFreebieDisciplineLabel};

const int kFreebieAttributeId = 2;
const int kFreebieAttributeCost = 5;
const std::string kFreebieAttributeName = "Attribute";
const std::string kFreebieAttributeLabel = "Add an attribute dot    5 points";
const FreebieType kFreebieAttribute = {
    kFreebieAttributeId, kFreebieAttributeCost, kFreebieAttributeName, kFreebieAttributeLabel};

const int kFreebieAbilityId = 3;
const int kFreebieAbilityCost = 2;
const std::string kFreebieAbilityName = "Ability";
const std::string kFreebieAbilityLabel = "Add an ability dot      2 points";
const FreebieType kFreebieAbility = {kFreebieAbilityId, kFreebieAbilityCost, kFreebieAbilityName, kFreebieAbilityLabel};

const int kFreebieVirtueId = 4;
const int kFreebieVirtueCost = 2;
const std::string kFreebieVirtueName = "Virtue";
const std::string kFreebieVirtueLabel = "Add a virtue dot        2 points";
const FreebieType kFreebieVirtue = {kFreebieVirtueId, kFreebieVirtueCost, kFreebieVirtueName, kFreebieVirtueLabel};

// TODO: Make this configurable for VtDA
const int kFreebieHumanityId = 5;
const int kFreebieHumanityCost = 1;
const std::string kFreebieHumanityName = "Humanity";
const std::string kFreebieHumanityLabel = "Add a humanity dot      1 point";
const FreebieType kFreebieHumanity = {
    kFreebieHumanityId, kFreebieHumanityCost, kFreebieHumanityName, kFreebieHumanityLabel};

const int kFreebieBackgroundId = 6;
const int kFreebieBackgroundCost = 1;
const std::string kFreebieBackgroundName = "Background";
const std::string kFreebieBackgroundLabel = "Add a background dot    1 point";
const FreebieType kFreebieBackground = {
    kFreebieBackgroundId, kFreebieBackgroundCost, kFreebieBackgroundName, kFreebieBackgroundLabel};

const int kFreebieShowCharacterSheetId = 7;
const int kFreebieShowCharacterSheetCost = 0;
const std::string kFreebieShowCharacterSheetName = "Show character sheet";
const std::string kFreebieShowCharacterSheetLabel = "Show character sheet";
const FreebieType kFreebieShowCharacterSheet = {kFreebieShowCharacterSheetId,
                                                kFreebieShowCharacterSheetCost,
                                                kFreebieShowCharacterSheetName,
                                                kFreebieShowCharacterSheetLabel};

const int kFreebieIds[] = {
    0,
    kFreebieDisciplineId,
    kFreebieAttributeId,
    kFreebieAbilityId,
    kFreebieVirtueId,
    kFreebieHumanityId,
    kFreebieBackgroundId,
    kFreebieShowCharacterSheetId,
};

const int kFreebieCosts[] = {
    0,
    kFreebieDisciplineCost,
    kFreebieAttributeCost,
    kFreebieAbilityCost,
    kFreebieVirtueCost,
    kFreebieHumanityCost,
    kFreebieBackgroundCost,
    kFreebieShowCharacterSheetCost,
};

const std::string kFreebieNames[] = {
    "",
    kFreebieDisciplineName,
    kFreebieAttributeName,
    kFreebieAbilityName,
    kFreebieVirtueName,
    kFreebieHumanityName,
    kFreebieBackgroundName,
    kFreebieShowCharacterSheetName,
};

const std::string kFreebieLabels[] = {
    "",
    kFreebieDisciplineLabel,
    kFreebieAttributeLabel,
    kFreebieAbilityLabel,
    kFreebieVirtueLabel,
    kFreebieHumanityLabel,
    kFreebieBackgroundLabel,
    kFreebieShowCharacterSheetLabel,
};

const FreebieType kFreebies[] = {
    kFreebieUnknown,
    kFreebieDiscipline,
    kFreebieAttribute,
    kFreebieAbility,
    kFreebieVirtue,
    kFreebieHumanity,
    kFreebieBackground,
    kFreebieShowCharacterSheet,
};

/// @brief Writes a freebie to an ostream.
/// @param os The ostream to write to.
/// @param freebie The freebie to write.
/// @return The provided ostream for chaining.
std::ostream& operator<<(std::ostream& os, const FreebieType& freebie);

/// @brief Determines if two freebies are equal.
/// @param left A freebie to compare.
/// @param right A freebie to compare.
/// @return True if both freebies are equal and false otherwise.
bool operator==(const FreebieType& left, const FreebieType& right);

/// @brief Determines if two freebies are unequal.
/// @param left A freebie to compare.
/// @param right A freebie to compare.
/// @return True if both freebies are unequal and false otherwise.
bool operator!=(const FreebieType& left, const FreebieType& right);

/// @brief Gets a freebie with a specific id.
/// @param freebie_id The id of the freebie to get.
/// @return The freebie with id == freebie_id or the unknown freebie kFreebieUnknown if freebie_id is invalid.
FreebieType GetFreebie(int freebie_id);

/// @brief Fills the provided vector with all valid freebies.
/// @param freebies The vector to fill. It will be cleared first.
void FillFreebies(std::vector<FreebieType>& freebies);

}  // End namespace SBF

#endif
