#ifndef CHARACTERGENERATOR_H__
#define CHARACTERGENERATOR_H__
#include "Character.h"

namespace SBF {
void CGGetAttributes(CharacterType& ch);
void CGGetBackgrounds(CharacterType& ch);
void CGGetDerangement(CharacterType& ch);
void CGGetDisciplines(CharacterType& ch);
void CGGetHeader(CharacterType& ch);
void CGGetRoad(CharacterType& ch);
void CGSpendAbilityPoint(CharacterType& ch);
void CGSpendAttributePoint(CharacterType& ch);
void CGSpendBackgroundPoint(CharacterType& ch);
void CGSpendDisciplinePoint(CharacterType& ch);
void CGSpendFreebiePoints(CharacterType& ch);
void CGSpendHumanityPoint(CharacterType& ch);
void CGSpendVirtuePoint(CharacterType& ch);
void CGSpendVirtuePoints(CharacterType& ch);
void CharacterGenerator();
void ShowCharacterSheet(CharacterType& ch);
void SaveCharacterSheet(CharacterType& ch);
}  // namespace SBF
#endif  // End !defined(CHARACTERGENERATOR_H__)
