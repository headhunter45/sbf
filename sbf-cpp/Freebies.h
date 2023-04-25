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
const int kFreebieAttributeId = 2;
const int kFreebieAbilityId = 3;
const int kFreebieVirtueId = 4;
// TODO: Make this configurable for VtDA
const int kFreebieHumanityId = 5;
const int kFreebieBackgroundId = 6;
const int kFreebieShowCharacterSheetId = 7;

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

std::vector<FreebieType> GetFreebies();

std::vector<FreebieType> GetAvailableFreebies(int freebie_points);
int GetFreebieCost(int id);

}  // End namespace SBF

#endif
