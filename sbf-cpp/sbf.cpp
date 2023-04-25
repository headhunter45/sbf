#include "sbf.h"

#define _XOPEN_SOURCE_EXTENDED
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#include "Abilities.h"
#include "Archetypes.h"
#include "Attributes.h"
#include "Backgrounds.h"
#include "Character.h"
#include "CharacterGenerator.h"
#include "Clans.h"
#include "Disciplines.h"
#include "Freebies.h"
#include "Genders.h"
#include "Menus.h"
#include "Random.h"
#include "Utils.h"
#include "Virtues.h"

#define KEY_ESCAPE 0033

namespace {
using namespace SBF;
using std::cout;
using std::endl;
}  // namespace

void CharacterGeneratorForDummies();
void CombatComputer();
void DiceRoller();
void MainMenu();
void RandomCharacterGenerator();
void SaveCharacterSheet(CharacterType& ch);
void ShowCharacterSheet(CharacterType& ch);
void ShowSplashScreen();
void VehicleGenerator();

int main(int argc, char* argv[]) {
  setlocale(LC_ALL, "");
  ShowSplashScreen();
  MainMenu();
  return 0;
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

void ShowSplashScreen() {
  cout << "Welcome to Tom's Storyteller's Best Friend. This is a program that is meant to" << endl
       << "aid storytellers in running Vampire: the Masquerade Chronicles and Vampire: the" << endl
       << "Dark Ages Chronicles. This program could aid in running campaigns for other" << endl
       << "role-playing games especially those from White Wolf(tm). If you would like" << endl
       << "anything added please open a github issue. https://github.com/headhunter45/sbf" << endl
       << "     Press any key to continue" << endl;
  WaitForKeypress();
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
