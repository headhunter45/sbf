#define _XOPEN_SOURCE_EXTENDED
#include "sbf.h"

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#include "Abilities.h"
#include "Archetypes.h"
#include "Attributes.h"
#include "Backgrounds.h"
#include "Character.h"
#include "Clans.h"
#include "Disciplines.h"
#include "Genders.h"
#include "Menus.h"
#include "Random.h"
#include "Utils.h"

#define KEY_ESCAPE 0033

namespace {
using namespace SBF;
using std::cin;
using std::cout;
using std::endl;
using std::to_string;
using std::vector;
}  // namespace

void CGGetAttributes(CharacterType& ch);
void CGGetBackgrounds(CharacterType& ch);
void CGGetDerangement(CharacterType& ch);
void CGGetDisciplines(CharacterType& ch);
void CGGetHeader(CharacterType& ch);
void CGGetRoad(CharacterType& ch);
void CGSpendFreebiePoints(CharacterType& ch);
void CGSpendVirtuePoints(CharacterType& ch);
void CharacterGenerator();
void CharacterGeneratorForDummies();
int ChooseStringId(vector<string> labels, MenuStyle style, string prompt);
void CombatComputer();
void DiceRoller();
int GetChoice(int min, int max);
int GetChoice();
int GetMenuChoice(vector<MenuItem> menu_items, MenuStyle style);
string GetString(string prompt);
void MainMenu();
void MaybeClearScreen();
void RandomCharacterGenerator();
void SaveCharacterSheet(CharacterType& ch);
void ShowCharacterSheet(CharacterType& ch);
void ShowSplashScreen();
void VehicleGenerator();
void WaitForKeypress();
int ChooseStringIdWithValues(vector<string> labels, vector<int> values, MenuStyle style, string prompt);
int ChooseMenuItemId(vector<MenuItem> menu_items, MenuStyle style, const string& prompt, bool ignore_value);

int main(int argc, char* argv[]) {
  setlocale(LC_ALL, "");
  ShowSplashScreen();
  MainMenu();
  return 0;
}

int GetChoice(int min, int max) {
  int choice;
  do {
    choice = GetChoice();
  } while (choice < min || choice > max);
  return choice;
}

int GetChoice() {
  int choice;
  string line;
  bool has_error;
  do {
    has_error = false;
    getline(cin, line);
    try {
      if (line.empty()) {
        return 0;
      }
      choice = stoi(line);
    } catch (...) {
      has_error = true;
    }
  } while (has_error);
  return choice;
}

void MainMenu() {
  int choice = 0;
  do {
    MaybeClearScreen();
    cout << "╔══════════════════════════════════════════════════════════════════════════════╗" << endl
         << "║ What are you going to do?                                                    ║" << endl
         << "║        1 = Character Generator                                               ║" << endl
         << "║        2 = Character Generator for Dummies                                   ║" << endl
         << "║        3 = Combat Computer                                                   ║" << endl
         << "║        4 = Dice Roller                                                       ║" << endl
         << "║        5 = Random Character Generator                                        ║" << endl
         << "║        6 =                                                                   ║" << endl
         << "║        7 = Vehicle Generator                                                 ║" << endl
         << "║                                                                              ║" << endl
         << "║                                                                              ║" << endl
         << "║                                                                              ║" << endl
         << "║                                                                              ║" << endl
         << "║                                                                              ║" << endl
         << "║                                                                              ║" << endl
         << "║                                                                              ║" << endl
         << "║                                                                              ║" << endl
         << "║                                                                              ║" << endl
         << "║                                                                              ║" << endl
         << "║                                                                              ║" << endl
         << "║        0 = End                                                               ║" << endl
         << "║                                                                              ║" << endl
         << "╚══════════════════════════════════════════════════════════════════════════════╝" << endl;
    choice = GetChoice(0, 7);
    switch (choice) {
      case 1:
        CharacterGenerator();
        break;
      case 2:
        CharacterGeneratorForDummies();
        break;
      case 3:
        CombatComputer();
        break;
      case 4:
        DiceRoller();
        break;
      case 5:
        RandomCharacterGenerator();
        break;
      case 7:
        VehicleGenerator();
        break;
    }
  } while (choice != 0);
}

/// Clears the screen if not a debug build.
inline void MaybeClearScreen() {
#if !defined(DEBUG)
  cout << "\033[1;1H\033[2J";
#endif
}

void ShowSplashScreen() {
  cout << "Welcome to Tom's Storyteller's Best Friend. This is a program that is meant to" << endl
       << "aid storytellers in running Vampire: the Masquerade Chronicles and Vampire: the" << endl
       << "Dark Ages Chronicles. This program could aid in running campaigns for other" << endl
       << "role-playing games especially those from White Wolf(tm). If you would like" << endl
       << "anything added please open a github issue. https://github.com/headhunter45/sbf" << endl
       << "     Press any key to continue" << endl;
  WaitForKeypress();
}

void WaitForKeypress() {
  // TODO: Make this press any key to continue.
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
  ch.generation = kInitialGeneration - ch.GetBackgroundValue(kBackgroundGenerationId);
  ch.willpower = ch.courage;
  ch.roadValue = ch.conscience + ch.selfControl;
  ch.bloodPool = GetRandomInt(1, 10);
  CGSpendFreebiePoints(ch);
  SaveCharacterSheet(ch);
  ShowCharacterSheet(ch);
}

void CharacterGeneratorForDummies() {
  // TODO: Fill in this function.
  cout << "// TODO: CharacterGeneratorForDummies()" << endl;
}

void CombatComputer() {
  // TODO: Fill in this function.
  cout << "// TODO: CombatComputer()" << endl;
}

void DiceRoller() {
  // TODO: Fill in this function.
  cout << "// TODO: DiceRoller()" << endl;
}

void RandomCharacterGenerator() {
  // TODO: Fill in this function.
  cout << "// TODO: RandomCharacterGenerator()" << endl;
}

void VehicleGenerator() {
  // TODO: Fill in this function.
  cout << "// TODO: VehicleGenerator()" << endl;
}

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
  ch.clanId = ChooseStringId(clans, ms, "What clan is the character from?");
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
  vector<int> attribute_ranks(kAttributeGroupsCount);

  // Attribute groups menu (physical/social/mental)
  vector<MenuItem> attribute_groups_menu_items;
  for (size_t i = 1; i <= kAttributeGroupsCount; i++) {
    attribute_groups_menu_items.push_back(MenuItem(GetAttributeGroupLabel(i), i));
  }

  // Choose attribute group priorities.
  int group_sum = 0;
  int rank_sum = 1;
  for (size_t i = 1; i < kAttributeGroupsCount; i++) {
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
  attribute_ranks[last_group - 1] = kAttributeGroupsCount;

  // Spend attribute points
  for (int group_id = 1; group_id <= kAttributeGroupsCount; group_id++) {
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
  // TODO: Fill this in.
  cout << "// TODO: CGGetBackgrounds(CharacterType&)" << endl;
}

void CGGetRoad(CharacterType& ch) {
  // TODO: Fill this in.
  cout << "// TODO: CGGetRoad(CharacterType&)" << endl;
}

void CGSpendVirtuePoints(CharacterType& ch) {
  // TODO: Fill this in.
  cout << "// TODO: CGSpendVirtuePoints(CharacterType&)" << endl;
}

void CGGetDerangement(CharacterType& ch) {
  // TODO: Fill this in.
  cout << "// TODO: CGGetDerangement(CharacterType&)" << endl;
}

void CGSpendFreebiePoints(CharacterType& ch) {
  // TODO: Fill this in.
  cout << "// TODO: CGSpendFreebiePoints(CharacterType&)" << endl;
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
  for (index = 1; index <= kDisciplinesCount; index++) {
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
       << " Generation: " << MakeFitR(to_string(ch.generation), 2) << " ║" << endl;
  cout << "║ Clan: " << MakeFitL(GetClanLabel(ch.clanId), 30) << " ║ Age: " << MakeFitL(ch.age, 32) << " ║" << endl;
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
  cout << "║ " << MakeFitL(ch.roadName + ": " + to_string(ch.roadValue), kLeftColumnWidth)
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
  // TODO: ShowCharacterSheet(CharacterType&)
  */
}

int GetRandomInt(int min, int max) {
  // TODO: Fill this in.
  return 0;
}

string GetString(string prompt) {
  cout << prompt << endl;
  string response;
  getline(cin, response);
  return response;
}

int ChooseStringId(vector<string> labels, MenuStyle style, string prompt) {
  MaybeClearScreen();
  vector<MenuItem> menu_items = BuildMenu(labels);
  style.Adjust(menu_items);
  cout << prompt << endl;
  PrintMenu(cout, menu_items, style);
  int choice = GetMenuChoice(menu_items, style);
  if (choice == style.random_item_id) {
    choice = GetRandomMenuItemId(menu_items);
  }
  return choice;
}

int GetMenuChoice(vector<MenuItem> menu_items, MenuStyle style) {
  int choice;
  while (true) {
    choice = GetChoice();
    if (style.show_random && choice == style.random_item_id) {
      return choice;
    }
    if (style.show_cancel && choice == style.cancel_item_id) {
      return choice;
    }
    for (MenuItem item : menu_items) {
      if (item.id == choice) {
        return choice;
      }
    }
  }
}

int ChooseStringIdWithValues(vector<string> labels, vector<int> values, MenuStyle style, string prompt) {
  MaybeClearScreen();
  vector<MenuItem> menu_items = BuildMenuWithValues(labels, values);
  style.Adjust(menu_items, false);
  cout << prompt << endl;
  PrintMenu(cout, menu_items, style);
  int choice = GetMenuChoice(menu_items, style);
  if (choice == style.random_item_id) {
    choice = GetRandomMenuItemId(menu_items);
  }
  return choice;
}

int ChooseMenuItemId(vector<MenuItem> menu_items, MenuStyle style, const string& prompt, bool ignore_value) {
  MaybeClearScreen();
  style.Adjust(menu_items, ignore_value);
  cout << prompt << endl;
  PrintMenu(cout, menu_items, style);
  int choice = GetMenuChoice(menu_items, style);
  if (choice == style.random_item_id) {
    choice = GetRandomMenuItemId(menu_items);
  }
  return choice;
}
