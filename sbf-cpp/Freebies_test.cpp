#include "Freebies.h"

#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include "test.h"

namespace {
using namespace SBF;
using namespace Test;
using namespace std;
}  // End namespace

const int kFreebieDisciplineCost = 7;
const std::string kFreebieDisciplineName = "Discipline";
const std::string kFreebieDisciplineLabel = "Add a discipline dot    7 points";
const FreebieType kFreebieDiscipline = {
    kFreebieDisciplineId, kFreebieDisciplineCost, kFreebieDisciplineName, kFreebieDisciplineLabel};
const int kFreebieAttributeCost = 5;
const std::string kFreebieAttributeName = "Attribute";
const std::string kFreebieAttributeLabel = "Add an attribute dot    5 points";
const FreebieType kFreebieAttribute = {
    kFreebieAttributeId, kFreebieAttributeCost, kFreebieAttributeName, kFreebieAttributeLabel};
const int kFreebieAbilityCost = 2;
const std::string kFreebieAbilityName = "Ability";
const std::string kFreebieAbilityLabel = "Add an ability dot      2 points";
const FreebieType kFreebieAbility = {kFreebieAbilityId, kFreebieAbilityCost, kFreebieAbilityName, kFreebieAbilityLabel};
const int kFreebieVirtueCost = 2;
const std::string kFreebieVirtueName = "Virtue";
const std::string kFreebieVirtueLabel = "Add a virtue dot        2 points";
const FreebieType kFreebieVirtue = {kFreebieVirtueId, kFreebieVirtueCost, kFreebieVirtueName, kFreebieVirtueLabel};
const int kFreebieHumanityCost = 1;
const std::string kFreebieHumanityName = "Humanity";
const std::string kFreebieHumanityLabel = "Add a humanity dot      1 point";
const FreebieType kFreebieHumanity = {
    kFreebieHumanityId, kFreebieHumanityCost, kFreebieHumanityName, kFreebieHumanityLabel};
const int kFreebieBackgroundCost = 1;
const std::string kFreebieBackgroundName = "Background";
const std::string kFreebieBackgroundLabel = "Add a background dot    1 point";
const FreebieType kFreebieBackground = {
    kFreebieBackgroundId, kFreebieBackgroundCost, kFreebieBackgroundName, kFreebieBackgroundLabel};
const int kFreebieShowCharacterSheetCost = 0;
const std::string kFreebieShowCharacterSheetName = "Show character sheet";
const std::string kFreebieShowCharacterSheetLabel = "Show character sheet";
const FreebieType kFreebieShowCharacterSheet = {kFreebieShowCharacterSheetId,
                                                kFreebieShowCharacterSheetCost,
                                                kFreebieShowCharacterSheetName,
                                                kFreebieShowCharacterSheetLabel};

TestResults test_FreebieType_operator_extract() {
  auto fnToTest = [](const FreebieType& freebie) -> string {
    ostringstream os;
    os << freebie;
    return os.str();
  };
  return execute_suite<string, FreebieType>(make_test_suite(
      "SBF::FreebieType::operator<<",
      fnToTest,
      vector<TestTuple<string, FreebieType>>({
          make_test<string, FreebieType>("should print an invalid freebie",
                                         "Freebie: {id: 16, cost: 42, name: \"asdf\", label: \"fdsa\"}",
                                         make_tuple((FreebieType){16, 42, "asdf", "fdsa"})),
          make_test<string, FreebieType>("should print the unknown freebie",
                                         "Freebie: {id: 0, cost: 0, name: \"\", label: \"\"}",
                                         make_tuple(kFreebieUnknown)),
          make_test<string, FreebieType>(
              "should print the discipline freebie",
              "Freebie: {id: 1, cost: 7, name: \"Discipline\", label: \"Add a discipline dot    7 points\"}",
              make_tuple(kFreebieDiscipline)),
          make_test<string, FreebieType>(
              "should print the attribute freebie",
              "Freebie: {id: 2, cost: 5, name: \"Attribute\", label: \"Add an attribute dot    5 points\"}",
              make_tuple(kFreebieAttribute)),
          make_test<string, FreebieType>(
              "should print the ability freebie",
              "Freebie: {id: 3, cost: 2, name: \"Ability\", label: \"Add an ability dot      2 points\"}",
              make_tuple(kFreebieAbility)),
          make_test<string, FreebieType>(
              "should print the virtue freebie",
              "Freebie: {id: 4, cost: 2, name: \"Virtue\", label: \"Add a virtue dot        2 points\"}",
              make_tuple(kFreebieVirtue)),
          make_test<string, FreebieType>(
              "should print the humanity freebie",
              "Freebie: {id: 5, cost: 1, name: \"Humanity\", label: \"Add a humanity dot      1 point\"}",
              make_tuple(kFreebieHumanity)),
          make_test<string, FreebieType>(
              "should print the background freebie",
              "Freebie: {id: 6, cost: 1, name: \"Background\", label: \"Add a background dot    1 point\"}",
              make_tuple(kFreebieBackground)),
          make_test<string, FreebieType>(
              "should print the show character sheet freebie",
              "Freebie: {id: 7, cost: 0, name: \"Show character sheet\", label: \"Show character sheet\"}",
              make_tuple(kFreebieShowCharacterSheet)),
      })));
}

TestResults test_FreebieType_operator_equal_to() {
  return execute_suite<bool, FreebieType, FreebieType>(make_test_suite(
      "SBF::FreebieType::operator==",
      [](const FreebieType& left, const FreebieType& right) -> bool { return left == right; },
      vector<TestTuple<bool, FreebieType, FreebieType>>({
          make_test<bool, FreebieType, FreebieType>("should return true when comparing a freebie to itself",
                                                    true,
                                                    make_tuple(kFreebieBackground, kFreebieBackground)),
          make_test<bool, FreebieType, FreebieType>(
              "should return true when comparing two different instances created with the same values",
              true,
              make_tuple(
                  kFreebieAbility,
                  (FreebieType){kFreebieAbilityId, kFreebieAbilityCost, kFreebieAbilityName, kFreebieAbilityLabel})),
          make_test<bool, FreebieType, FreebieType>("should return false when comparing two different freebies",
                                                    false,
                                                    make_tuple(kFreebieHumanity, kFreebieVirtue)),
      })));
}

TestResults test_FreebieType_operator_not_equal_to() {
  return execute_suite<bool, FreebieType, FreebieType>(make_test_suite(
      "SBF::FreebieType::operator!=",
      [](const FreebieType& left, const FreebieType& right) -> bool { return left != right; },
      vector<TestTuple<bool, FreebieType, FreebieType>>({
          make_test<bool, FreebieType, FreebieType>("should return false when comparing a freebie to itself",
                                                    false,
                                                    make_tuple(kFreebieBackground, kFreebieBackground)),
          make_test<bool, FreebieType, FreebieType>(
              "should return false when comparing two different instances created with the same values",
              false,
              make_tuple(
                  kFreebieAbility,
                  (FreebieType){kFreebieAbilityId, kFreebieAbilityCost, kFreebieAbilityName, kFreebieAbilityLabel})),
          make_test<bool, FreebieType, FreebieType>("should return true when comparing two different freebies",
                                                    true,
                                                    make_tuple(kFreebieHumanity, kFreebieVirtue)),
      })));
}

TestResults test_GetFreebie() {
  return execute_suite<FreebieType, int>(make_test_suite(
      "SBF::GetFreebie",
      GetFreebie,
      vector<TestTuple<FreebieType, int>>({
          make_test<FreebieType, int>("should get the unknown freebie for invalid id 0", {0, 0, "", ""}, make_tuple(0)),
          make_test<FreebieType, int>("should get the discipline freebie for id 1",
                                      {1, 7, "Discipline", "Add a discipline dot    7 points"},
                                      make_tuple(1)),
          make_test<FreebieType, int>("should get the attribute freebie for id 2",
                                      {2, 5, "Attribute", "Add an attribute dot    5 points"},
                                      make_tuple(2)),
          make_test<FreebieType, int>("should get the ability freebie for id 3",
                                      {3, 2, "Ability", "Add an ability dot      2 points"},
                                      make_tuple(3)),
          make_test<FreebieType, int>("should get the virtue freebie for id 4",
                                      {4, 2, "Virtue", "Add a virtue dot        2 points"},
                                      make_tuple(4)),
          make_test<FreebieType, int>("should get the humanity freebie for id 5",
                                      {5, 1, "Humanity", "Add a humanity dot      1 point"},
                                      make_tuple(5)),
          make_test<FreebieType, int>("should get the background freebie for id 6",
                                      {6, 1, "Background", "Add a background dot    1 point"},
                                      make_tuple(6)),
          make_test<FreebieType, int>("should get the show character sheet freebie for id 7",
                                      {7, 0, "Show character sheet", "Show character sheet"},
                                      make_tuple(7)),
          make_test<FreebieType, int>("should get the unknown freebie for invalid id 8", {0, 0, "", ""}, make_tuple(8)),
      })));
}

TestResults test_FillFreebies() {
  auto fnToTest = []() -> string {
    ostringstream error_message;
    vector<FreebieType> expected = {
        kFreebieDiscipline,
        kFreebieAttribute,
        kFreebieAbility,
        kFreebieVirtue,
        kFreebieHumanity,
        kFreebieBackground,
        kFreebieShowCharacterSheet,
    };
    vector<FreebieType> actual = {{-1, -2, "This should be removed.", "This should be removed"}};
    FillFreebies(actual);
    compare(error_message, expected, actual);
    string error = error_message.str();
    if (error.size() > 0) {
      return error;
    }
    return "no errors";
  };
  return execute_suite<string>(make_test_suite(
      "SBF::FillFreebies",
      fnToTest,
      vector<TestTuple<string>>({make_test<string>("should fill freebies", "no errors", make_tuple())})));
}

int main(int argc, char* argv[]) {
  TestResults results;

  results += test_FreebieType_operator_extract();
  results += test_FreebieType_operator_equal_to();
  results += test_FreebieType_operator_not_equal_to();
  results += test_GetFreebie();
  results += test_FillFreebies();

  return results.failed() + results.errors();
}
