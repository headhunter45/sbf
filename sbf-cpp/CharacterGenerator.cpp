#include "CharacterGenerator.h"

#include <iostream>
#include <string>
#include <vector>

#include "Archetypes.h"
#include "Character.h"
#include "Freebies.h"
#include "Genders.h"
#include "Menus.h"
#include "Random.h"
#include "Utils.h"
#include "sbf-cpp/Abilities.h"
#include "sbf-cpp/Backgrounds.h"
#include "sbf-cpp/Disciplines.h"

namespace SBF {
namespace {
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::vector;
}  // End namespace

void CGGetHeader(CharacterType& ch) {
  MaybeClearScreen();
  MenuStyle ms;
  ch.name = GetString("What is the character's name?");
  ch.player = GetString("Who is the player?");
  ch.chronicle = GetString("What chronicle is the character going to be used for?");
  ch.haven = GetString("What is the character's Haven?");
  ch.concept = GetString("What is the character's concept?");
  ch.age = GetString("How old is the character?");
  vector<string> genders;
  FillGenderLabels(genders);
  ch.genderId = ChooseStringId(genders, ms, "What is the character's gender?");
  vector<string> clans;
  FillClanLabels(clans);
  ch.SetClanId(ChooseStringId(clans, ms, "What clan is the character from?"));
  vector<string> archetypes;
  FillArchetypeLabels(archetypes);
  ch.natureId = ChooseStringId(archetypes, ms, "What is the character's nature?");
  ch.demeanorId = ChooseStringId(archetypes, ms, "What is the character's demeanor?");
}

void CGGetDisciplines(CharacterType& ch) {
  MenuStyle ms;
  int discipline_points = GetDisciplinePoints();
  vector<int> discipline_values;
  vector<string> discipline_labels;
  FillDisciplineLabels(discipline_labels);
  while (discipline_points > 0) {
    MaybeClearScreen();
    discipline_values = ch.GetDisciplineValues();
    int discipline_id = ChooseStringIdWithValues(
        discipline_labels,
        discipline_values,
        ms,
        "Which discipline do you want to spend 1 of your " + to_string(discipline_points) + " points on?");
    ch.SetDisciplineValue(discipline_id, ch.GetDisciplineValue(discipline_id) + 1);
    discipline_points--;
  }
}

void CGGetAttributes(CharacterType& ch) {
  MenuStyle ms_without_values;
  MenuStyle ms_with_values;
  // indexed by group_id - 1 holds the rank_id
  vector<int> attribute_ranks(GetNumAttributeGroups());

  // Attribute groups menu (physical/social/mental)
  vector<MenuItem> attribute_groups_menu_items;
  for (size_t i = 1; i <= GetNumAttributeGroups(); i++) {
    attribute_groups_menu_items.push_back(MenuItem(GetAttributeGroupLabel(i), i));
  }

  // Choose attribute group priorities.
  int group_sum = 0;
  int rank_sum = 1;
  for (size_t i = 1; i < GetNumAttributeGroups(); i++) {
    int next_group_id = ChooseMenuItemId(attribute_groups_menu_items,
                                         ms_without_values,
                                         "Choose your " + ToLower(GetRank(i).label) + " attribute?",
                                         true);
    int next_group_index = next_group_id - 1;
    attribute_groups_menu_items.at(next_group_index).is_visible = false;
    attribute_ranks[next_group_index] = i;
    rank_sum += i + 1;
    group_sum += next_group_id;
  }

  // General formula for last choice given 1 to count based indexing is this. (Sum from 1 to count) - (Sum of all
  // previous choice IDs). Sum(1..AllAttributesCount)-Sum(Choice[1..Choice[AllAttributesCount-1]).
  int last_group = rank_sum - group_sum;
  attribute_ranks[last_group - 1] = GetNumAttributeGroups();

  // Spend attribute points
  for (int group_id = 1; group_id <= GetNumAttributeGroups(); group_id++) {
    int group_index = group_id - 1;
    vector<string> attribute_labels = GetAttributeLabelsInGroup(group_id);
    int rank_id = attribute_ranks.at(group_index);
    int attribute_points = GetAttributePointsForRank(rank_id);
    while (attribute_points > 0) {
      vector<int> values = ch.GetAttributeValuesInGroup(group_id);
      string prompt = "Which " + ToLower(GetAttributeGroupLabel(group_id))
                    + " attribute do you want to spend 1 of your " + to_string(attribute_points) + " points on?";
      int attribute_id = ChooseStringIdWithValues(attribute_labels, values, ms_with_values, prompt);
      ch.SetAttributeValue(group_id, attribute_id, ch.GetAttributeValue(group_id, attribute_id) + 1);
      attribute_points--;
    }
  }
}

void CGGetBackgrounds(CharacterType& ch) {
  // Spend background points
  MenuStyle ms;
  int background_points = GetBackgroundPoints();
  vector<string> background_labels = GetBackgroundLabels();
  while (background_points > 0) {
    MaybeClearScreen();
    vector<int> background_values = ch.GetBackgroundValues();
    int background_id = ChooseStringIdWithValues(
        background_labels,
        background_values,
        ms,
        "Which background do you want to spend 1 of your " + to_string(background_points) + " points on?");
    ch.SetBackgroundValue(background_id, ch.GetBackgroundValue(background_id) + 1);
    background_points--;
  }
}

void CGGetRoad(CharacterType& ch) {
  // TODO: Update this to actually pick a road for VtDA.
  ch.SetRoadName("Humanity");
}

void CGSpendVirtuePoints(CharacterType& ch) {
  // Spend virtue points
  MenuStyle ms;
  int virtue_points = GetVirtuePoints();
  vector<string> labels = GetVirtueLabels();
  while (virtue_points > 0) {
    vector<int> values = ch.GetVirtueValues();
    int virtue_id = ChooseStringIdWithValues(
        labels, values, ms, "Which virtue do you want to spend 1 of your " + to_string(virtue_points) + " points on?");
    ch.SetVirtueValue(virtue_id, ch.GetVirtueValue(virtue_id) + 1);
    virtue_points--;
  }
}

void CGGetDerangement(CharacterType& ch) {
  if (ch.GetClanId() == kClanMalkavianId) {
    // If the clan is malkavian then pick a derangement.
    MenuStyle ms;
    ms.use_colors = true;
    ch.derangementId =
        ChooseStringIdWithColors(GetDerangementLabels(), GetDerangementColors(), ms, "Which derangement do you want?");
  }
}

void CGSpendFreebiePoints(CharacterType& ch) {
  int freebie_points = ch.GetFreebiePoints();
  MenuStyle ms;
  while (freebie_points > 0) {
    MaybeClearScreen();
    // Build the menu
    vector<FreebieType> available_freebies = GetAvailableFreebies(freebie_points);
    vector<MenuItem> menu_items;
    for (int freebie_index = 0; freebie_index < available_freebies.size(); freebie_index++) {
      FreebieType freebie = available_freebies.at(freebie_index);
      MenuItem mi(freebie.label, freebie.id);
      if (freebie_index + 1 == kFreebieShowCharacterSheetId) {
        mi.include_in_random = false;
      }
      menu_items.push_back(mi);
    }
    string prompt = "You have " + to_string(freebie_points)
                  + " freebie points remaining. What would you like to spend the points on?";
    int id = ChooseMenuItemId(menu_items, ms, prompt, true);
    switch (id) {
      case kFreebieDisciplineId:
        CGSpendDisciplinePoint(ch);
        break;
      case kFreebieAttributeId:
        CGSpendAttributePoint(ch);
        break;
      case kFreebieAbilityId:
        CGSpendAbilityPoint(ch);
        break;
      case kFreebieVirtueId:
        CGSpendVirtuePoint(ch);
        break;
      case kFreebieHumanityId:
        CGSpendHumanityPoint(ch);
        break;
      case kFreebieBackgroundId:
        CGSpendBackgroundPoint(ch);
        break;
      case kFreebieShowCharacterSheetId:
        ShowCharacterSheet(ch);
        break;
    }
    freebie_points = ch.GetFreebiePoints();
  }
}

void CGSpendDisciplinePoint(CharacterType& ch) {
  MaybeClearScreen();
  MenuStyle ms;
  ms.show_cancel = true;
  ms.cancel_item_id = GetNumDisciplines() + 1;
  vector<int> values = ch.GetDisciplineValues();
  vector<string> labels;
  FillDisciplineLabels(labels);
  string prompt = "Which discipline would you like to add 1 dot to?";
  int discipline_id = ChooseStringIdWithValues(labels, values, ms, prompt);
  if (discipline_id != ms.cancel_item_id) {
    ch.SetDisciplineValue(discipline_id, ch.GetDisciplineValue(discipline_id) + 1);
    ch.SetFreebiePoints(ch.GetFreebiePoints() - GetFreebieCost(kFreebieDisciplineId));
  }
}

struct GroupedStatReference {
  int id;
  int group_id;
  int item_id;
};

void CGSpendAttributePoint(CharacterType& ch) {
  MaybeClearScreen();
  MenuStyle ms;
  ms.show_cancel = true;
  int num_attributes = 0;
  vector<int> num_attributes_in_group;
  for (int group_id = 1; group_id <= GetNumAttributeGroups(); group_id++) {
    int count = GetNumAttributesInGroup(group_id);
    num_attributes_in_group.push_back(count);
    num_attributes += count;
  }

  vector<GroupedStatReference> attribute_refs;
  vector<string> labels;
  vector<int> values;

  int attribute_id = 1;
  for (int attribute_group_id = 1; attribute_group_id <= GetNumAttributeGroups(); attribute_group_id++) {
    int attribute_group_index = attribute_group_id - 1;
    for (int id = 1; id <= num_attributes_in_group.at(attribute_group_index); id++) {
      GroupedStatReference attribute_ref = {attribute_id, attribute_group_id, id};
      attribute_refs.push_back(attribute_ref);
      labels.push_back(GetAttributeLabel(attribute_group_id, id));
      values.push_back(ch.GetAttributeValue(attribute_group_id, id));
      attribute_id++;
    }
  }

  string prompt = "Which attribute do you want to add one dot to?";
  ms.cancel_item_id = num_attributes + 1;
  int id = ChooseStringIdWithValues(labels, values, ms, prompt);
  if (id == ms.cancel_item_id) {
    return;
  }
  GroupedStatReference ref = attribute_refs.at(id - 1);
  ch.SetAttributeValue(ref.group_id, ref.item_id, ch.GetAttributeValue(ref.group_id, ref.item_id) + 1);
  ch.SetFreebiePoints(ch.GetFreebiePoints() - GetFreebieCost(kFreebieAttributeId));
}

void CGSpendAbilityPoint(CharacterType& ch) {
  MenuStyle ms;
  ms.show_cancel = true;
  bool done = false;
  while (!done) {
    MaybeClearScreen();
    ms.cancel_item_id = GetNumAbilityGroups();
    int ability_group_id =
        ChooseStringId(GetAbilityGroupPluralLabels(), ms, "What kind of ability would you like to add 1 dot to?");
    if (ability_group_id == ms.cancel_item_id) {
      return;
    }
    AbilityType ability = GetAbility(ability_group_id);

    vector<string> labels = GetAbilityLabelsForAbilityGroup(ability_group_id);
    ms.cancel_item_id = labels.size() + 1;
    int ability_id =
        ChooseStringId(labels, ms, "What " + ToLower(ability.singular) + " would you like to add 1 dot to?");
    if (ability_id != ms.cancel_item_id) {
      ch.SetAbilityValue(ability_group_id, ability_id, ch.GetAbilityValue(ability_group_id, ability_id) + 1);
      ch.SetFreebiePoints(ch.GetFreebiePoints() - GetFreebieCost(kFreebieAbilityId));
    }
  }
}

void CGSpendVirtuePoint(CharacterType& ch) {
  MenuStyle ms;
  ms.show_cancel = true;
  ms.cancel_item_id = GetNumVirtues() + 1;
  string prompt = "What virtue would you like to add 1 dot to?";
  int id = ChooseStringIdWithValues(GetVirtueLabels(), ch.GetVirtueValues(), ms, prompt);
  if (id != ms.cancel_item_id) {
    ch.SetVirtueValue(id, ch.GetVirtueValue(id) + 1);
    ch.SetFreebiePoints(ch.GetFreebiePoints() - GetFreebieCost(kFreebieVirtueId));
  }
}

void CGSpendHumanityPoint(CharacterType& ch) {
  vector<string> labels = {"Yes", "No"};
  string prompt = "Are you sure you want to add a dot to your " + ch.GetRoadName() + "?";
  MenuStyle ms;
  ms.show_random = false;
  if (ChooseYesOrNo(prompt)) {
    ch.SetRoadValue(ch.GetRoadValue() - 1);
    ch.SetFreebiePoints(ch.GetFreebiePoints() - GetFreebieCost(kFreebieHumanityId));
  }
}

void CGSpendBackgroundPoint(CharacterType& ch) {
  MenuStyle ms;
  ms.show_cancel = true;
  vector<string> labels = GetBackgroundLabels();
  ms.cancel_item_id = labels.size() + 1;
  string prompt = "Which background would you like to add 1 dot to?";
  int id = ChooseStringId(labels, ms, prompt);
  if (id != ms.cancel_item_id) {
    ch.SetBackgroundValue(id, ch.GetBackgroundValue(id) + 1);
    ch.SetFreebiePoints(ch.GetFreebiePoints() - GetFreebieCost(kFreebieBackgroundId));
  }
}

string FormatAttributeValue(const string& label, int value) {
  return MakeFitC(label + MakeFitL(to_string(value), 2), 12);
}

string FormatAbilityWithValue(const string& label, int value) {
  return MakeFitC(MakeFitL(label + ":", 14) + to_string(value), 24);
}

void SaveCharacterSheet(CharacterType& ch) {
  // TODO: Fill this in.
  cout << "// TODO: SaveCharacterSheet(CharacterType&)" << endl;
}

void ShowCharacterSheet(CharacterType& ch) {
  const int kLeftColumnWidth = 36;
  const int kRightColumnWidth = 37;
  vector<string> discipline_strings;
  size_t index;
  for (index = 1; index <= GetNumDisciplines(); index++) {
    int value = ch.GetDisciplineValue(index);
    if (value > 0) {
      string suffix = "";
      if (value > 1) {
        suffix = " x" + to_string(value);
      }
      discipline_strings.push_back(GetDisciplineLabel(index) + suffix);
    }
  }
  while (discipline_strings.size() <= 3) {
    discipline_strings.push_back(RepeatChar(kLeftColumnWidth, '_'));
  }
  vector<string> background_strings(5);
  for (index = 1; index <= kBackgroundsCount; index++) {
    int value = ch.GetBackgroundValue(index);
    if (value > 0) {
      string suffix = "";
      if (value > 1) {
        suffix = " x" + to_string(value);
      }
      background_strings.push_back(GetBackgroundLabel(index) + suffix);
    }
  }
  while (background_strings.size() <= 5) {
    background_strings.push_back(RepeatChar(kLeftColumnWidth, '_'));
  }
  string all_derangements_line = ch.GetAllDerangementsLine();
  vector<string> derangement_strings = WordWrap(all_derangements_line, kLeftColumnWidth);
  while (derangement_strings.size() <= 5) {
    derangement_strings.push_back(RepeatChar(kLeftColumnWidth, '_'));
  }
  MaybeClearScreen();
  cout << "╔══════════════════════════════════════╦═══════════════════════════════════════╗" << endl;
  cout << "║ Name: " << MakeFitL(ch.name, 30) << " ║ Gender: " << MakeFitL(GetGenderLabel(ch.genderId), 14)
       << " Generation: " << MakeFitR(to_string(ch.GetGeneration()), 2) << " ║" << endl;
  cout << "║ Clan: " << MakeFitL(GetClanLabel(ch.GetClanId()), 30) << " ║ Age: " << MakeFitL(ch.age, 32) << " ║"
       << endl;
  cout << "╠══════════════════════════════════════╣ Player: " << MakeFitL(ch.player, 29) << " ║" << endl;
  cout << "║              Attributes              ║ Chronicle: " << MakeFitL(ch.chronicle, 26) << " ║" << endl;
  cout << "║ " << MakeFitC("Physical", 12) << MakeFitC("Social", 12) << MakeFitC("Mental", 12)
       << " ║ Haven: " << MakeFitL(ch.haven, 30) + " ║" << endl;
  cout << "║ " << FormatAttributeValue("Str. ", ch.GetPhysicalAttributeValue(kPhysicalAttributeStrengthId))
       << FormatAttributeValue("App. ", ch.GetSocialAttributeValue(kSocialAttributeAppearanceId))
       << FormatAttributeValue("Int. ", ch.GetMentalAttributeValue(kMentalAttributeIntelligenceId))
       << " ║ Concept: " << MakeFitL(ch.concept, 28) << " ║" << endl;
  cout << "║ " << FormatAttributeValue("Dex. ", ch.GetPhysicalAttributeValue(kPhysicalAttributeDexterityId))
       << FormatAttributeValue("Cha. ", ch.GetSocialAttributeValue(kSocialAttributeCharismaId))
       << FormatAttributeValue("Per. ", ch.GetMentalAttributeValue(kMentalAttributePerceptionId))
       << " ╠═══════════════════════════════════════╣" << endl;
  cout << "║ " << FormatAttributeValue("Sta. ", ch.GetPhysicalAttributeValue(kPhysicalAttributeStaminaId))
       << FormatAttributeValue("Man. ", ch.GetSocialAttributeValue(kSocialAttributeManipulationId))
       << FormatAttributeValue("Wit. ", ch.GetMentalAttributeValue(kMentalAttributeWitsId))
       << " ║ Derangements:                         ║" << endl;
  cout << "╠══════════════════════════════════════╣ " << MakeFitL(derangement_strings[0], kRightColumnWidth, '_')
       << " ║" << endl;
  cout << "║ Disciplines:                         ║ " << MakeFitL(derangement_strings[1], kRightColumnWidth, '_')
       << " ║" << endl;
  cout << "║ " << MakeFitL(discipline_strings[0], kLeftColumnWidth) << " ║ "
       << MakeFitL(derangement_strings[2], kRightColumnWidth, '_') << " ║" << endl;
  cout << "║ " << MakeFitL(discipline_strings[1], kLeftColumnWidth) << " ║ "
       << MakeFitL(derangement_strings[3], kRightColumnWidth, '_') << " ║" << endl;
  cout << "║ " << MakeFitL(discipline_strings[2], kLeftColumnWidth) << " ║ "
       << MakeFitL(derangement_strings[4], kRightColumnWidth, '_') << " ║" << endl;
  cout << "╠══════════════════════════════════════╬═══════════════════════════════════════╣" << endl;
  cout << "║ " << MakeFitL(ch.GetRoadName() + ": " + to_string(ch.GetRoadValue()), kLeftColumnWidth)
       << " ║ Nature: " << MakeFitL(GetArchetypeLabel(ch.natureId), 29) << " ║" << endl;
  cout << "║ Willpower: " << MakeFitL(to_string(ch.willpower), 25)
       << " ║ Demeanor: " << MakeFitL(GetArchetypeLabel(ch.demeanorId), 27) << " ║" << endl;
  cout << "╠══════════════════════════════════════╩═══════════════════════════════════════╣" << endl;
  cout << "║                                                                              ║" << endl;
  cout << "║                                                                              ║" << endl;
  cout << "║                                                                              ║" << endl;
  cout << "║                        <<PRESS ANY KEY TO CONTINUE>>                         ║" << endl;
  cout << "╚══════════════════════════════════════════════════════════════════════════════╝" << endl;
  WaitForKeypress();
  cout << "╔══════════════════════════════════════════════════════════════════════════════╗" << endl;
  cout << "║ " << MakeFitC("Abilities", 76) << " ║" << endl;
  cout << "║   " << MakeFitC("Talents", 24) << MakeFitC("Skills", 24) << MakeFitC("Knowledges", 24) << "   ║" << endl;
  for (index = 1; index <= 10; index++) {
    cout << "║   " << FormatAbilityWithValue(GetTalentLabel(index), ch.GetTalentValue(index))
         << FormatAbilityWithValue(GetSkillLabel(index), ch.GetSkillValue(index))
         << FormatAbilityWithValue(GetKnowledgeLabel(index), ch.GetKnowledgeValue(index)) << "   ║" << endl;
  }
  cout << "╠══════════════════════════════════════╦═══════════════════════════════════════╣" << endl;
  cout << "║ " << MakeFitL("Backgrounds:", kLeftColumnWidth) << " ║ " << MakeFitL("Virtues:", kRightColumnWidth) << " ║"
       << endl;
  cout << "║ " << MakeFitL(background_strings[0], kLeftColumnWidth) << " ║ "
       << MakeFitB("Conscience:", to_string(ch.conscience), kRightColumnWidth) << " ║" << endl;
  cout << "║ " << MakeFitL(background_strings[1], kLeftColumnWidth) << " ║ "
       << MakeFitB("Self-Control:", to_string(ch.selfControl), kRightColumnWidth) << " ║" << endl;
  cout << "║ " << MakeFitL(background_strings[2], kLeftColumnWidth) << " ║ "
       << MakeFitB("Courage:", to_string(ch.courage), kRightColumnWidth) << " ║" << endl;
  cout << "║ " << MakeFitL(background_strings[3], kLeftColumnWidth) << " ║ " << MakeFitL("", kRightColumnWidth) << " ║"
       << endl;
  cout << "║ " << MakeFitL(background_strings[4], kLeftColumnWidth) << " ║ " << MakeFitL("", kRightColumnWidth) << " ║"
       << endl;
  cout << "╠══════════════════════════════════════╩═══════════════════════════════════════╣" << endl;
  cout << "║                        <<PRESS ANY KEY TO CONTINUE>>                         ║" << endl;
  cout << "╚══════════════════════════════════════════════════════════════════════════════╝" << endl;
  WaitForKeypress();
  /*
  ╔══════════════════════════════════════╦═══════════════════════════════════════╗
  ║ Name: Ted                            ║ Gender: Female         Generation: 13 ║
  ║ Clan: Ventrue                        ║ Age: 35                               ║
  ╠══════════════════════════════════════╣ Player: Jeff                          ║
  ║              Attributes              ║ Chronicle: Somesuch                   ║
  ║   Physical     Social      Mental    ║ Haven: Mom's basement                 ║
  ║   Str. 1      App. 1      Int. 1     ║ Concept: Asshole                      ║
  ║   Dex. 1      Cha. 1      Per. 1     ╠═══════════════════════════════════════╣
  ║   Sta. 1      Man. 1      Wit. 1     ║ Derangements:                         ║
  ╠══════════════════════════════════════╣ _____________________________________ ║
  ║ Disciplines:                         ║ _____________________________________ ║
  ║ ____________________________________ ║ _____________________________________ ║
  ║ ____________________________________ ║ _____________________________________ ║
  ║ ____________________________________ ║ _____________________________________ ║
  ╠══════════════════════════════════════╬═══════════════════════════════════════╣
  ║ : 2                                  ║ Nature: Tyrant                        ║
  ║ Willpower: 1                         ║ Demeanor: Traditionalist              ║
  ╠══════════════════════════════════════╩═══════════════════════════════════════╣
  ║                                                                              ║
  ║                                                                              ║
  ║                                                                              ║
  ║                        <<PRESS ANY KEY TO CONTINUE>>                         ║
  ╚══════════════════════════════════════════════════════════════════════════════╝
  ╔══════════════════════════════════════════════════════════════════════════════╗
  ║                                  Abilities                                   ║
  ║           Talents                  Skills                Knowledges          ║
  ║       Acting:       0         Animal Ken:   0         Bureaucracy:  0        ║
  ║       Alertness:    0         Drive:        0         Computer:     0        ║
  ║       Athletics:    0         Etiquette:    0         Finance:      0        ║
  ║       Brawl:        0         Firearms:     0         Investigation:0        ║
  ║       Dodge:        0         Melee:        0         Law:          0        ║
  ║       Empathy:      0         Music:        0         Linguistics:  0        ║
  ║       Intimidation: 0         Repair:       0         Medicine:     0        ║
  ║       Leadership:   0         Security:     0         Occult:       0        ║
  ║       Streetwise:   0         Stealth:      0         Politics:     0        ║
  ║       Subterfuge:   0         Survival:     0         Science:      0        ║
  ╠══════════════════════════════════════╦═══════════════════════════════════════╣
  ║ Backgrounds:                         ║ Virtues:                              ║
  ║                                      ║ Conscience:                         1 ║
  ║                                      ║ Self-Control:                       1 ║
  ║                                      ║ Courage:                            1 ║
  ║                                      ║                                       ║
  ║                                      ║                                       ║
  ╠══════════════════════════════════════╩═══════════════════════════════════════╣
  ║                        <<PRESS ANY KEY TO CONTINUE>>                         ║
  ╚══════════════════════════════════════════════════════════════════════════════╝
  */
}

void CharacterGenerator() {
  CharacterType ch;
  CGGetHeader(ch);
  CGGetDisciplines(ch);
  CGGetAttributes(ch);
  CGGetBackgrounds(ch);
  CGGetRoad(ch);
  CGSpendVirtuePoints(ch);
  CGGetDerangement(ch);
  ch.SetGeneration(GetInitialGeneration() - ch.GetBackgroundValue(kBackgroundGenerationId));
  ch.willpower = ch.courage;
  ch.SetRoadValue(ch.conscience + ch.selfControl);
  ch.bloodPool = GetRandomInt(1, 10);
  CGSpendFreebiePoints(ch);
  SaveCharacterSheet(ch);
  ShowCharacterSheet(ch);
}

}  // End namespace SBF
