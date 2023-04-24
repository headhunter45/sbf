#include "Abilities.h"
#include "Attributes.h"
#define _XOPEN_SOURCE_EXTENDED
#include <cstdio>
#include <iostream>
#include <string>

#include "Archetypes.h"
#include "Backgrounds.h"
#include "Clans.h"
#include "Genders.h"
#include "Menus.h"
#include "Random.h"
#include "Utils.h"
#include "sbf.h"

#define KEY_ESCAPE 0033

namespace {
using namespace std;
using namespace SBF;
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
  // TODO: Fill this in.
  cout << "// TODO: CGGetDisciplines(CharacterType&)" << endl;
}

void CGGetAttributes(CharacterType& ch) {
  // TODO: Fill this in.
  cout << "// TODO: CGGetAttributes(CharacterType&)" << endl;
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
  return make_fit_c(label + make_fit_l(itos(value), 2), 12);
}

string FormatAbilityWithValue(const string& label, int value) {
  return make_fit_c(make_fit_l(label + ":", 14) + itos(value), 24);
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
        suffix = " x" + itos(value);
      }
      discipline_strings.push_back(GetDisciplineLabel(index) + suffix);
    }
  }
  while (discipline_strings.size() <= 3) {
    discipline_strings.push_back(string_dollar(kLeftColumnWidth, '_'));
  }
  vector<string> background_strings(5);
  for (index = 1; index <= kBackgroundsCount; index++) {
    int value = ch.GetBackgroundValue(index);
    if (value > 0) {
      string suffix = "";
      if (value > 1) {
        suffix = " x" + itos(value);
      }
      background_strings.push_back(GetBackgroundLabel(index) + suffix);
    }
  }
  while (background_strings.size() <= 5) {
    background_strings.push_back(string_dollar(kLeftColumnWidth, '_'));
  }
  string all_derangements_line = ch.GetAllDerangementsLine();
  vector<string> derangement_strings = word_wrap(all_derangements_line, kLeftColumnWidth);
  while (derangement_strings.size() <= 5) {
    derangement_strings.push_back(string_dollar(kLeftColumnWidth, '_'));
  }
  MaybeClearScreen();
  cout << "╔══════════════════════════════════════╦═══════════════════════════════════════╗" << endl;
  cout << "║ Name: " << make_fit_l(ch.name, 30) << " ║ Gender: " << make_fit_l(GetGenderLabel(ch.genderId), 14)
       << " Generation: " << make_fit_r(itos(ch.generation), 2) << " ║" << endl;
  cout << "║ Clan: " << make_fit_l(GetClanLabel(ch.clanId), 30) << " ║ Age: " << make_fit_l(ch.age, 32) << " ║" << endl;
  cout << "╠══════════════════════════════════════╣ Player: " << make_fit_l(ch.player, 29) << " ║" << endl;
  cout << "║              Attributes              ║ Chronicle: " << make_fit_l(ch.chronicle, 26) << " ║" << endl;
  cout << "║ " << make_fit_c("Physical", 12) << make_fit_c("Social", 12) << make_fit_c("Mental", 12)
       << " ║ Haven: " << make_fit_l(ch.haven, 30) + " ║" << endl;
  cout << "║ " << FormatAttributeValue("Str. ", ch.GetPhysicalAttributeValue(kPhysicalAttributeStrengthId))
       << FormatAttributeValue("App. ", ch.GetSocialAttributeValue(kSocialAttributeAppearanceId))
       << FormatAttributeValue("Int. ", ch.GetMentalAttributeValue(kMentalAttributeIntelligenceId))
       << " ║ Concept: " << make_fit_l(ch.concept, 28) << " ║" << endl;
  cout << "║ " << FormatAttributeValue("Dex. ", ch.GetPhysicalAttributeValue(kPhysicalAttributeDexterityId))
       << FormatAttributeValue("Cha. ", ch.GetSocialAttributeValue(kSocialAttributeCharismaId))
       << FormatAttributeValue("Per. ", ch.GetMentalAttributeValue(kMentalAttributePerceptionId))
       << " ╠═══════════════════════════════════════╣" << endl;
  cout << "║ " << FormatAttributeValue("Sta. ", ch.GetPhysicalAttributeValue(kPhysicalAttributeStaminaId))
       << FormatAttributeValue("Man. ", ch.GetSocialAttributeValue(kSocialAttributeManipulationId))
       << FormatAttributeValue("Wit. ", ch.GetMentalAttributeValue(kMentalAttributeWitsId))
       << " ║ Derangements:                         ║" << endl;
  cout << "╠══════════════════════════════════════╣ " << make_fit_l(derangement_strings[0], kRightColumnWidth, '_')
       << " ║" << endl;
  cout << "║ Disciplines:                         ║ " << make_fit_l(derangement_strings[1], kRightColumnWidth, '_')
       << " ║" << endl;
  cout << "║ " << make_fit_l(discipline_strings[0], kLeftColumnWidth) << " ║ "
       << make_fit_l(derangement_strings[2], kRightColumnWidth, '_') << " ║" << endl;
  cout << "║ " << make_fit_l(discipline_strings[1], kLeftColumnWidth) << " ║ "
       << make_fit_l(derangement_strings[3], kRightColumnWidth, '_') << " ║" << endl;
  cout << "║ " << make_fit_l(discipline_strings[2], kLeftColumnWidth) << " ║ "
       << make_fit_l(derangement_strings[4], kRightColumnWidth, '_') << " ║" << endl;
  cout << "╠══════════════════════════════════════╬═══════════════════════════════════════╣" << endl;
  cout << "║ " << make_fit_l(ch.roadName + ": " + itos(ch.roadValue), kLeftColumnWidth)
       << " ║ Nature: " << make_fit_l(GetArchetypeLabel(ch.natureId), 29) << " ║" << endl;
  cout << "║ Willpower: " << make_fit_l(itos(ch.willpower), 25)
       << " ║ Demeanor: " << make_fit_l(GetArchetypeLabel(ch.demeanorId), 27) << " ║" << endl;
  cout << "╠══════════════════════════════════════╩═══════════════════════════════════════╣" << endl;
  cout << "║                                                                              ║" << endl;
  cout << "║                                                                              ║" << endl;
  cout << "║                                                                              ║" << endl;
  cout << "║                        <<PRESS ANY KEY TO CONTINUE>>                         ║" << endl;
  cout << "╚══════════════════════════════════════════════════════════════════════════════╝" << endl;
  WaitForKeypress();
  cout << "╔══════════════════════════════════════════════════════════════════════════════╗" << endl;
  cout << "║ " << make_fit_c("Abilities", 76) << " ║" << endl;
  cout << "║   " << make_fit_c("Talents", 24) << make_fit_c("Skills", 24) << make_fit_c("Knowledges", 24) << "   ║"
       << endl;
  for (index = 1; index <= 10; index++) {
    cout << "║   " << FormatAbilityWithValue(GetTalentLabel(index), ch.GetTalentValue(index))
         << FormatAbilityWithValue(GetSkillLabel(index), ch.GetSkillValue(index))
         << FormatAbilityWithValue(GetKnowledgeLabel(index), ch.GetKnowledgeValue(index)) << "   ║" << endl;
  }
  cout << "╠══════════════════════════════════════╦═══════════════════════════════════════╣" << endl;
  cout << "║ " << make_fit_l("Backgrounds:", kLeftColumnWidth) << " ║ " << make_fit_l("Virtues:", kRightColumnWidth)
       << " ║" << endl;
  cout << "║ " << make_fit_l(background_strings[0], kLeftColumnWidth) << " ║ "
       << make_fit_b("Conscience:", itos(ch.conscience), kRightColumnWidth) << " ║" << endl;
  cout << "║ " << make_fit_l(background_strings[1], kLeftColumnWidth) << " ║ "
       << make_fit_b("Self-Control:", itos(ch.selfControl), kRightColumnWidth) << " ║" << endl;
  cout << "║ " << make_fit_l(background_strings[2], kLeftColumnWidth) << " ║ "
       << make_fit_b("Courage:", itos(ch.courage), kRightColumnWidth) << " ║" << endl;
  cout << "║ " << make_fit_l(background_strings[3], kLeftColumnWidth) << " ║ " << make_fit_l("", kRightColumnWidth)
       << " ║" << endl;
  cout << "║ " << make_fit_l(background_strings[4], kLeftColumnWidth) << " ║ " << make_fit_l("", kRightColumnWidth)
       << " ║" << endl;
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
