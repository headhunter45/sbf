#include "Abilities.h"

#include <iostream>
#include <sstream>

#include "test.h"
using namespace SBF;
using namespace Test;
using namespace std;

namespace Test::Abilities {
TestResults test_AbilityType_operator_extract();
TestResults test_AbilityType_operator_equal_to();
TestResults test_AbilityType_operator_not_equal_to();
TestResults test_FillAbilities();
TestResults test_FillAbilitiesForAbilityGroup();
TestResults test_FillAbilityLabels();
TestResults test_FillKnowledgeLabels();
TestResults test_FillSkillLabels();
TestResults test_FillTalentLabels();
TestResults test_GetAbility();
TestResults test_GetAbilityLabel();
TestResults test_GetKnowledgeLabel();
TestResults test_GetNumItemsForAbilityGroup();
TestResults test_GetSkillLabel();
TestResults test_GetTalentLabel();
}  // End namespace Test::Abilities

using namespace Test::Abilities;

TestResults main_test_Abilities(int argc, char* argv[]) {
  TestResults results;

  results += test_AbilityType_operator_extract();
  results += test_AbilityType_operator_equal_to();
  results += test_AbilityType_operator_not_equal_to();
  results += test_FillAbilities();
  results += test_FillAbilitiesForAbilityGroup();
  results += test_FillAbilityLabels();
  results += test_FillKnowledgeLabels();
  results += test_FillSkillLabels();
  results += test_FillTalentLabels();
  results += test_GetAbility();
  results += test_GetAbilityLabel();
  results += test_GetKnowledgeLabel();
  results += test_GetNumItemsForAbilityGroup();
  results += test_GetSkillLabel();
  results += test_GetTalentLabel();

  return results;
}

namespace Test::Abilities {
TestResults test_AbilityType_operator_extract() {
  return execute_suite<string, AbilityType>(make_test_suite(
      "SBF::AbilityType::operator<<",
      [](const AbilityType& ability) {
        ostringstream os;
        os << ability;
        return os.str();
      },
      vector<TestTuple<string, AbilityType>>({
          make_test<string, AbilityType>("should print talents",
                                         "AbilityGroup: {id: 1, singular: \"Talent\", plural: \"Talents\"}",
                                         make_tuple(kAbilityGroupTalents)),
          make_test<string, AbilityType>("should print skills",
                                         "AbilityGroup: {id: 2, singular: \"Skill\", plural: \"Skills\"}",
                                         make_tuple(kAbilityGroupSkills)),
          make_test<string, AbilityType>("should print knowledges",
                                         "AbilityGroup: {id: 3, singular: \"Knowledge\", plural: \"Knowledges\"}",
                                         make_tuple(kAbilityGroupKnowledges)),
          make_test<string, AbilityType>("should print an unknown ability group",
                                         "AbilityGroup: {id: 0, singular: \"\", plural: \"\"}",
                                         make_tuple(kAbilityGroupUnknown)),
      })));
}

TestResults test_AbilityType_operator_equal_to() {
  return execute_suite<bool, AbilityType, AbilityType>(make_test_suite(
      "SBF::AbilityType::operator==",
      [](const AbilityType& left, const AbilityType& right) { return left == right; },
      vector<TestTuple<bool, AbilityType, AbilityType>>({
          make_test<bool, AbilityType, AbilityType>("should return true when comparing an ability group to itself",
                                                    true,
                                                    make_tuple(kAbilityGroupTalents, kAbilityGroupTalents)),
          make_test<bool, AbilityType, AbilityType>(
              "should return true when comparing two different instances created with the same values",
              true,
              make_tuple(kAbilityGroupSkills,
                         AbilityType({kAbilitySkillsId, kAbilitySkillsSingular, kAbilitySkillsPlural}))),
          make_test<bool, AbilityType, AbilityType>("should return false when comparing two different ability gropus",
                                                    false,
                                                    make_tuple(kAbilityGroupKnowledges, kAbilityGroupSkills)),
      })));
}

TestResults test_AbilityType_operator_not_equal_to() {
  return execute_suite<bool, AbilityType, AbilityType>(make_test_suite(
      "SBF::AbilityType::operator!=",
      [](const AbilityType& left, const AbilityType& right) { return left != right; },
      vector<TestTuple<bool, AbilityType, AbilityType>>({
          make_test<bool, AbilityType, AbilityType>("should return false when comparing an ability group to itself",
                                                    false,
                                                    make_tuple(kAbilityGroupTalents, kAbilityGroupTalents)),
          make_test<bool, AbilityType, AbilityType>(
              "should return false when comparing two different instances created with the same values",
              false,
              make_tuple(kAbilityGroupSkills,
                         AbilityType({kAbilitySkillsId, kAbilitySkillsSingular, kAbilitySkillsPlural}))),
          make_test<bool, AbilityType, AbilityType>("should return true when comparing two different ability gropus",
                                                    true,
                                                    make_tuple(kAbilityGroupKnowledges, kAbilityGroupSkills)),
      })));
}

TestResults test_FillAbilities() {
  return execute_suite<string>(make_test_suite(
      "SBF::FillAbilities",
      []() -> string {
        ostringstream error_message;
        vector<AbilityType> actual = {{-1, "This should be removed.", "This should be removed."}};
        vector<AbilityType> expected = {kAbilityGroupTalents, kAbilityGroupSkills, kAbilityGroupKnowledges};
        FillAbilities(actual);
        compare(error_message, expected, actual);
        string error = error_message.str();
        if (error.size() > 0) {
          return error;
        }
        return "no errors";
      },
      vector<TestTuple<string>>({
          make_test<string>("should fill abilities", "no errors", make_tuple()),
      })));
}

TestResults test_FillAbilitiesForAbilityGroup() {
  return execute_suite<vector<string>, int>(make_test_suite(
      "SBF::FillAbilitiesForAbilityGroup",
      [](int groupId) {
        vector<string> abilities = {"This should be removed."};
        FillAbilitiesForAbilityGroup(abilities, groupId);
        return abilities;
      },
      vector<TestTuple<vector<string>, int>>({
          make_test<vector<string>, int>(
              "should clear the vector for group 0, kAbilityGropuUnknownId", {}, make_tuple(0)),
          make_test<vector<string>, int>("should fill talents for group 1 kAbilityGroupTalentsId",
                                         {
                                             "Acting",
                                             "Alertness",
                                             "Athletics",
                                             "Brawl",
                                             "Dodge",
                                             "Empathy",
                                             "Intimidation",
                                             "Leadership",
                                             "Streetwise",
                                             "Subterfuge",
                                         },  //, "Alertness", "Athletics", "Brawl", "Dodge", "Empathy",
                                             //"Intimidation", "Leadership", "Streetwise", "Subterfuge"
                                         make_tuple(1)),
          make_test<vector<string>, int>("should fill skills for group 2 kAbilityGroupSkillsId",
                                         {
                                             "Animal Ken",
                                             "Drive",
                                             "Etiquette",
                                             "Firearms",
                                             "Melee",
                                             "Music",
                                             "Repair",
                                             "Security",
                                             "Stealth",
                                             "Survival",
                                         },
                                         make_tuple(2)),
          make_test<vector<string>, int>("should fill knowledges for group 3 kAbilityGroupKnowledgesId",
                                         {
                                             "Bureaucracy",
                                             "Computer",
                                             "Finance",
                                             "Investigation",
                                             "Law",
                                             "Linguistics",
                                             "Medicine",
                                             "Occult",
                                             "Politics",
                                             "Science",
                                         },
                                         make_tuple(3)),
          make_test<vector<string>, int>("should clear the vector for group 4 an invalid id", {}, make_tuple(4)),
      })));
}

TestResults test_FillAbilityLabels() {
  return execute_suite<vector<string>, int>(make_test_suite(
      "SBF::FillAbilityLabels",
      [](int groupId) {
        vector<string> abilities = {"This should be removed."};
        FillAbilityLabels(abilities, groupId);
        return abilities;
      },
      vector<TestTuple<vector<string>, int>>({
          make_test<vector<string>, int>(
              "should clear the vector for group 0, kAbilityGropuUnknownId", {}, make_tuple(0)),
          make_test<vector<string>, int>("should fill talents for group 1 kAbilityGroupTalentsId",
                                         {
                                             "Acting",
                                             "Alertness",
                                             "Athletics",
                                             "Brawl",
                                             "Dodge",
                                             "Empathy",
                                             "Intimidation",
                                             "Leadership",
                                             "Streetwise",
                                             "Subterfuge",
                                         },
                                         make_tuple(1)),
          make_test<vector<string>, int>("should fill skills for group 2 kAbilityGroupSkillsId",
                                         {
                                             "Animal Ken",
                                             "Drive",
                                             "Etiquette",
                                             "Firearms",
                                             "Melee",
                                             "Music",
                                             "Repair",
                                             "Security",
                                             "Stealth",
                                             "Survival",
                                         },
                                         make_tuple(2)),
          make_test<vector<string>, int>("should fill knowledges for group 3 kAbilityGroupKnowledgesId",
                                         {
                                             "Bureaucracy",
                                             "Computer",
                                             "Finance",
                                             "Investigation",
                                             "Law",
                                             "Linguistics",
                                             "Medicine",
                                             "Occult",
                                             "Politics",
                                             "Science",
                                         },
                                         make_tuple(3)),
          make_test<vector<string>, int>("should clear the vector for group 4 an invalid id", {}, make_tuple(4)),
      })));
}

TestResults test_FillKnowledgeLabels() {
  return execute_suite<string>(make_test_suite(
      "SBF::FillKnowlegeLabels",
      []() -> string {
        ostringstream error_message;
        vector<string> actual = {"This should be removed."};
        vector<string> expected = {
            "Bureaucracy",
            "Computer",
            "Finance",
            "Investigation",
            "Law",
            "Linguistics",
            "Medicine",
            "Occult",
            "Politics",
            "Science",
        };
        FillKnowledgeLabels(actual);
        compare(error_message, expected, actual);
        string error = error_message.str();
        if (error.size() > 0) {
          return error;
        }
        return "no errors";
      },
      vector<TestTuple<string>>({
          make_test<string>("should fill knowledge labels", "no errors", make_tuple()),
      })));
}

TestResults test_FillSkillLabels() {
  return execute_suite<string>(make_test_suite(
      "SBF::FillSkillLabels",
      []() -> string {
        ostringstream error_message;
        vector<string> actual = {"This should be removed."};
        vector<string> expected = {
            "Animal Ken",
            "Drive",
            "Etiquette",
            "Firearms",
            "Melee",
            "Music",
            "Repair",
            "Security",
            "Stealth",
            "Survival",
        };
        FillSkillLabels(actual);
        compare(error_message, expected, actual);
        string error = error_message.str();
        if (error.size() > 0) {
          return error;
        }
        return "no errors";
      },
      vector<TestTuple<string>>({
          make_test<string>("should fill skill labels", "no errors", make_tuple()),
      })));
}

TestResults test_FillTalentLabels() {
  return execute_suite<string>(make_test_suite(
      "SBF::FillTalentLabels",
      []() -> string {
        ostringstream error_message;
        vector<string> actual = {"This should be removed."};
        vector<string> expected = {
            "Acting",
            "Alertness",
            "Athletics",
            "Brawl",
            "Dodge",
            "Empathy",
            "Intimidation",
            "Leadership",
            "Streetwise",
            "Subterfuge",
        };
        FillTalentLabels(actual);
        compare(error_message, expected, actual);
        string error = error_message.str();
        if (error.size() > 0) {
          return error;
        }
        return "no errors";
      },
      vector<TestTuple<string>>({
          make_test<string>("should fill knowledge labels", "no errors", make_tuple()),
      })));
}

TestResults test_GetAbility() {
  return execute_suite<AbilityType, int>(make_test_suite(
      "SBF::GetAbility",
      GetAbility,
      vector<TestTuple<AbilityType, int>>({
          make_test<AbilityType, int>("should get talents", kAbilityGroupTalents, make_tuple(kAbilityTalentsId)),
          make_test<AbilityType, int>("should get skills", kAbilityGroupSkills, make_tuple(kAbilitySkillsId)),
          make_test<AbilityType, int>(
              "should get knowledges", kAbilityGroupKnowledges, make_tuple(kAbilityKnowledgesId)),
          make_test<AbilityType, int>("should get unknown for id 0", kAbilityGroupUnknown, make_tuple(0)),
          make_test<AbilityType, int>("should get unknown for an invalid id", kAbilityGroupUnknown, make_tuple(4)),
      })));
}

TestResults test_GetAbilityLabel() {
  return execute_suite<string, int, int>(make_test_suite(
      "SBF::GetAbilityLabel",
      GetAbilityLabel,
      vector<TestTuple<string, int, int>>({
          make_test<string, int, int>("should get Acting for group 1 and id 1", "Acting", make_tuple(1, 1)),
          make_test<string, int, int>("should get Alertness for group 1 and id 2", "Alertness", make_tuple(1, 2)),
          make_test<string, int, int>("should get Athletics for group 1 and id 3", "Athletics", make_tuple(1, 3)),
          make_test<string, int, int>("should get Brawl for group 1 and id 4", "Brawl", make_tuple(1, 4)),
          make_test<string, int, int>("should get Dodge for group 1 and id 5", "Dodge", make_tuple(1, 5)),
          make_test<string, int, int>("should get Empathy for group 1 and id 6", "Empathy", make_tuple(1, 6)),
          make_test<string, int, int>("should get Intimidation for group 1 and id 7", "Intimidation", make_tuple(1, 7)),
          make_test<string, int, int>("should get Leadership for group 1 and id 8", "Leadership", make_tuple(1, 8)),
          make_test<string, int, int>("should get Streetwise for group 1 and id 9", "Streetwise", make_tuple(1, 9)),
          make_test<string, int, int>("should get Subterfuge for group 1 and id 10", "Subterfuge", make_tuple(1, 10)),
          make_test<string, int, int>("should get Animal Ken for group 2 and id 1", "Animal Ken", make_tuple(2, 1)),
          make_test<string, int, int>("should get Drive for group 2 and id 2", "Drive", make_tuple(2, 2)),
          make_test<string, int, int>("should get Etiquette for group 2 and id 3", "Etiquette", make_tuple(2, 3)),
          make_test<string, int, int>("should get Firearms for group 2 and id 4", "Firearms", make_tuple(2, 4)),
          make_test<string, int, int>("should get Melee for group 2 and id 5", "Melee", make_tuple(2, 5)),
          make_test<string, int, int>("should get Music for group 2 and id 6", "Music", make_tuple(2, 6)),
          make_test<string, int, int>("should get Repair for group 2 and id 7", "Repair", make_tuple(2, 7)),
          make_test<string, int, int>("should get Security for group 2 and id 8", "Security", make_tuple(2, 8)),
          make_test<string, int, int>("should get Stealth for group 2 and id 9", "Stealth", make_tuple(2, 9)),
          make_test<string, int, int>("should get Survival for group 2 and id 10", "Survival", make_tuple(2, 10)),
          make_test<string, int, int>("should get Bureaucracy for group 3 and id 1", "Bureaucracy", make_tuple(3, 1)),
          make_test<string, int, int>("should get Computer for group 3 and id 2", "Computer", make_tuple(3, 2)),
          make_test<string, int, int>("should get Finance for group 3 and id 3", "Finance", make_tuple(3, 3)),
          make_test<string, int, int>(
              "should get Investigation for group 3 and id 4", "Investigation", make_tuple(3, 4)),
          make_test<string, int, int>("should get Law for group 3 and id 5", "Law", make_tuple(3, 5)),
          make_test<string, int, int>("should get Linguistics for group 3 and id 6", "Linguistics", make_tuple(3, 6)),
          make_test<string, int, int>("should get Medicine for group 3 and id 7", "Medicine", make_tuple(3, 7)),
          make_test<string, int, int>("should get Occult for group 3 and id 8", "Occult", make_tuple(3, 8)),
          make_test<string, int, int>("should get Politics for group 3 and id 9", "Politics", make_tuple(3, 9)),
          make_test<string, int, int>("should get Science for group 3 and id 10", "Science", make_tuple(3, 10)),
          make_test<string, int, int>("should get and empty string for group 0 and id 0", "", make_tuple(0, 0)),
          make_test<string, int, int>("should get and empty string for group 1 and id 11", "", make_tuple(1, 11)),
          make_test<string, int, int>("should get and empty string for group 4 and id 1", "", make_tuple(4, 1)),
      })));
}

TestResults test_GetKnowledgeLabel() {
  return execute_suite<string, int>(
      make_test_suite("SBF::GetKnowledgeLabel",
                      GetKnowledgeLabel,
                      vector<TestTuple<string, int>>({
                          make_test<string, int>("should get Bureaucracy for id 1", "Bureaucracy", make_tuple(1)),
                          make_test<string, int>("should get Computer for id 2", "Computer", make_tuple(2)),
                          make_test<string, int>("should get Finance for id 3", "Finance", make_tuple(3)),
                          make_test<string, int>("should get Investigation for id 4", "Investigation", make_tuple(4)),
                          make_test<string, int>("should get Law for id 5", "Law", make_tuple(5)),
                          make_test<string, int>("should get Linguistics for id 6", "Linguistics", make_tuple(6)),
                          make_test<string, int>("should get Medicine for id 7", "Medicine", make_tuple(7)),
                          make_test<string, int>("should get Occult for id 8", "Occult", make_tuple(8)),
                          make_test<string, int>("should get Politics for id 9", "Politics", make_tuple(9)),
                          make_test<string, int>("should get Science for id 10", "Science", make_tuple(10)),
                          make_test<string, int>("should get and empty string for id 0", "", make_tuple(0)),
                          make_test<string, int>("should get and empty string for id 11", "", make_tuple(11)),
                      })));
  return TestResults();
}

TestResults test_GetNumItemsForAbilityGroup() {
  return execute_suite<int, int>(make_test_suite(
      "SBF::GetNumItemsForAbilityGroup",
      GetNumItemsForAbilityGroup,
      vector<TestTuple<int, int>>({
          make_test<int, int>("should get 10 abilities for talents", 10, make_tuple(kAbilityTalentsId)),
          make_test<int, int>("should get 10 abilities for skills", 10, make_tuple(kAbilitySkillsId)),
          make_test<int, int>("should get 10 abilities for knowledges", 10, make_tuple(kAbilityKnowledgesId)),
          make_test<int, int>("should get 0 abilities for 0", 0, make_tuple(0)),
          make_test<int, int>("should get 0 abilities for an invalid id", 0, make_tuple(4)),
      })));
}

TestResults test_GetSkillLabel() {
  return execute_suite<string, int>(
      make_test_suite("SBF::GetSkillLabel",
                      GetSkillLabel,
                      vector<TestTuple<string, int>>({
                          make_test<string, int>("should get Animal Ken for id 1", "Animal Ken", make_tuple(1)),
                          make_test<string, int>("should get Drive for id 2", "Drive", make_tuple(2)),
                          make_test<string, int>("should get Etiquette for id 3", "Etiquette", make_tuple(3)),
                          make_test<string, int>("should get Firearms for id 4", "Firearms", make_tuple(4)),
                          make_test<string, int>("should get Melee for id 5", "Melee", make_tuple(5)),
                          make_test<string, int>("should get Music for id 6", "Music", make_tuple(6)),
                          make_test<string, int>("should get Repair for id 7", "Repair", make_tuple(7)),
                          make_test<string, int>("should get Security for id 8", "Security", make_tuple(8)),
                          make_test<string, int>("should get Stealth for id 9", "Stealth", make_tuple(9)),
                          make_test<string, int>("should get Survival for id 10", "Survival", make_tuple(10)),
                          make_test<string, int>("should get and empty string for id 0", "", make_tuple(0)),
                          make_test<string, int>("should get and empty string for id 11", "", make_tuple(11)),
                      })));
}

TestResults test_GetTalentLabel() {
  return execute_suite<string, int>(
      make_test_suite("SBF::GetTalentLabel",
                      GetTalentLabel,
                      vector<TestTuple<string, int>>({
                          make_test<string, int>("should get Acting for id 1", "Acting", make_tuple(1)),
                          make_test<string, int>("should get Alertness for id 2", "Alertness", make_tuple(2)),
                          make_test<string, int>("should get Athletics for id 3", "Athletics", make_tuple(3)),
                          make_test<string, int>("should get Brawl for id 4", "Brawl", make_tuple(4)),
                          make_test<string, int>("should get Dodge for id 5", "Dodge", make_tuple(5)),
                          make_test<string, int>("should get Empathy for id 6", "Empathy", make_tuple(6)),
                          make_test<string, int>("should get Intimidation for id 7", "Intimidation", make_tuple(7)),
                          make_test<string, int>("should get Leadership for id 8", "Leadership", make_tuple(8)),
                          make_test<string, int>("should get Streetwise for id 9", "Streetwise", make_tuple(9)),
                          make_test<string, int>("should get Subterfuge for id 10", "Subterfuge", make_tuple(10)),
                          make_test<string, int>("should get and empty string for id 0", "", make_tuple(0)),
                          make_test<string, int>("should get and empty string for id 11", "", make_tuple(11)),
                      })));
}
}  // End namespace Test::Abilities
