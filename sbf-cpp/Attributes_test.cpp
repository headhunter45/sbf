#include "Attributes.h"

#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include "test.h"

using namespace SBF;
using namespace Test;
using namespace std;

namespace Test::Attributes {
TestResults test_GetAttributeGroupLabel();
TestResults test_GetAttributeLabel();
TestResults test_GetAttributeLabelAbbreviation();
TestResults test_GetNumAttributesInGroup();
TestResults test_GetPhysicalAttributeLabel();
TestResults test_GetPhysicalAttributeLabelAbbreviation();
TestResults test_GetSocialAttributeLabel();
TestResults test_GetSocialAttributeLabelAbbreviation();
TestResults test_GetMentalAttributeLabel();
TestResults test_GetMentalAttributeLabelAbbreviation();
TestResults test_FillAttributeGroupLabels();
TestResults test_FillAttributeLabelsInGroup();
TestResults test_FillPhysicalAttributeLabels();
TestResults test_FillSocialAttributeLabels();
TestResults test_FillMentalAttributeLabels();
}  // End namespace Test::Attributes

using namespace Test::Attributes;

TestResults main_test_Attributes(int argc, char** argv) {
  TestResults results;

  results += test_GetAttributeGroupLabel();
  results += test_GetAttributeLabel();
  results += test_GetAttributeLabelAbbreviation();
  results += test_GetNumAttributesInGroup();
  results += test_GetPhysicalAttributeLabel();
  results += test_GetPhysicalAttributeLabelAbbreviation();
  results += test_GetSocialAttributeLabel();
  results += test_GetSocialAttributeLabelAbbreviation();
  results += test_GetMentalAttributeLabel();
  results += test_GetMentalAttributeLabelAbbreviation();
  results += test_FillAttributeGroupLabels();
  results += test_FillAttributeLabelsInGroup();
  results += test_FillPhysicalAttributeLabels();
  results += test_FillSocialAttributeLabels();
  results += test_FillMentalAttributeLabels();

  return results;
}

namespace Test::Attributes {
TestResults test_GetAttributeGroupLabel() {
  return execute_suite<string, int>(
      make_test_suite("SBF::GetAttributeGroupLabel",
                      GetAttributeGroupLabel,
                      vector<TestTuple<string, int>>({
                          make_test<string, int>("should get \"\" for id 0", "", make_tuple(0)),
                          make_test<string, int>("should get \"Physical\" for id 1", "Physical", make_tuple(1)),
                          make_test<string, int>("should get \"Social\" for id 2", "Social", make_tuple(2)),
                          make_test<string, int>("should get \"Mental\" for id 3", "Mental", make_tuple(3)),
                          make_test<string, int>("should get \"\" for id 4", "", make_tuple(4)),
                      })));
}

TestResults test_GetAttributeLabel() {
  return execute_suite<string, int, int>(make_test_suite(
      "SBF::GetAttributeLabel",
      GetAttributeLabel,
      vector<TestTuple<string, int, int>>({
          make_test<string, int, int>("should get \"Strength\" for group id 1 and id 1", "Strength", make_tuple(1, 1)),
          make_test<string, int, int>(
              "should get \"Dexterity\" for group id 1 and id 2", "Dexterity", make_tuple(1, 2)),
          make_test<string, int, int>("should get \"Stamina\" for group id 1 and id 3", "Stamina", make_tuple(1, 3)),
          make_test<string, int, int>("should get \"Charisma\" for group id 2 and id 1", "Charisma", make_tuple(2, 1)),
          make_test<string, int, int>(
              "should get \"Manipulation\" for group id 2 and id 2", "Manipulation", make_tuple(2, 2)),
          make_test<string, int, int>(
              "should get \"Appearance\" for group id 2 and id 3", "Appearance", make_tuple(2, 3)),
          make_test<string, int, int>(
              "should get \"Intelligence\" for group id 3 and id 1", "Intelligence", make_tuple(3, 1)),
          make_test<string, int, int>(
              "should get \"Perception\" for group id 3 and id 2", "Perception", make_tuple(3, 2)),
          make_test<string, int, int>("should get \"Wits\" for group id 3 and id 3", "Wits", make_tuple(3, 3)),
          make_test<string, int, int>("should get \"\" for an invalid group id 0", "", make_tuple(0, 1)),
          make_test<string, int, int>("should get \"\" for an invalid id 0", "", make_tuple(1, 0)),
          make_test<string, int, int>("should get \"\" for invalid group id 4", "", make_tuple(4, 1)),
          make_test<string, int, int>("should get \"\" for an invalid id 4", "", make_tuple(1, 4)),
      })));
}

TestResults test_GetAttributeLabelAbbreviation() {
  return execute_suite<string, int, int>(make_test_suite(
      "SBF::GetAttributeLabelAbbreviation",
      GetAttributeLabelAbbreviation,
      vector<TestTuple<string, int, int>>({
          make_test<string, int, int>("should get \"Str.\" for group id 1 and id 1", "Str.", make_tuple(1, 1)),
          make_test<string, int, int>("should get \"Dex.\" for group id 1 and id 2", "Dex.", make_tuple(1, 2)),
          make_test<string, int, int>("should get \"Sta.\" for group id 1 and id 3", "Sta.", make_tuple(1, 3)),
          make_test<string, int, int>("should get \"Cha.\" for group id 2 and id 1", "Cha.", make_tuple(2, 1)),
          make_test<string, int, int>("should get \"Man.\" for group id 2 and id 2", "Man.", make_tuple(2, 2)),
          make_test<string, int, int>("should get \"App.\" for group id 2 and id 3", "App.", make_tuple(2, 3)),
          make_test<string, int, int>("should get \"Int.\" for group id 3 and id 1", "Int.", make_tuple(3, 1)),
          make_test<string, int, int>("should get \"Per.\" for group id 3 and id 2", "Per.", make_tuple(3, 2)),
          make_test<string, int, int>("should get \"Wits\" for group id 3 and id 3", "Wits", make_tuple(3, 3)),
          make_test<string, int, int>("should get \"\" for an invalid group id 0", "", make_tuple(0, 1)),
          make_test<string, int, int>("should get \"\" for an invalid id 0", "", make_tuple(1, 0)),
          make_test<string, int, int>("should get \"\" for invalid group id 4", "", make_tuple(4, 1)),
          make_test<string, int, int>("should get \"\" for an invalid id 4", "", make_tuple(1, 4)),
      })));
}

TestResults test_GetPhysicalAttributeLabel() {
  return execute_suite<string, int>(
      make_test_suite("SBF::GetPhysicalAttributeLabel",
                      GetPhysicalAttributeLabel,
                      vector<TestTuple<string, int>>({
                          make_test<string, int>("should get \"Strength\" for id 1", "Strength", make_tuple(1)),
                          make_test<string, int>("should get \"Dexterity\" for id 2", "Dexterity", make_tuple(2)),
                          make_test<string, int>("should get \"Stamina\" for id 3", "Stamina", make_tuple(3)),
                          make_test<string, int>("should get \"\" for invalid id 0", "", make_tuple(0)),
                          make_test<string, int>("should get \"\" for invalid id 4", "", make_tuple(4)),
                      })));
}

TestResults test_GetPhysicalAttributeLabelAbbreviation() {
  return execute_suite<string, int>(
      make_test_suite("SBF::GetPhysicalAttributeLabelAbbreviation",
                      GetPhysicalAttributeLabelAbbreviation,
                      vector<TestTuple<string, int>>({
                          make_test<string, int>("should get \"Str.\" for id 1", "Str.", make_tuple(1)),
                          make_test<string, int>("should get \"Dex.\" for id 2", "Dex.", make_tuple(2)),
                          make_test<string, int>("should get \"Sta.\" for id 3", "Sta.", make_tuple(3)),
                          make_test<string, int>("should get \"\" for invalid id 0", "", make_tuple(0)),
                          make_test<string, int>("should get \"\" for invalid id 4", "", make_tuple(4)),
                      })));
}

TestResults test_GetSocialAttributeLabel() {
  return execute_suite<string, int>(
      make_test_suite("SBF::GetSocialAttributeLabel",
                      GetSocialAttributeLabel,
                      vector<TestTuple<string, int>>({
                          make_test<string, int>("should get \"Charisma\" for id 1", "Charisma", make_tuple(1)),
                          make_test<string, int>("should get \"Manipulation\" for id 2", "Manipulation", make_tuple(2)),
                          make_test<string, int>("should get \"Appearance\" for id 3", "Appearance", make_tuple(3)),
                          make_test<string, int>("should get \"\" for invalid id 0", "", make_tuple(0)),
                          make_test<string, int>("should get \"\" for invalid id 4", "", make_tuple(4)),
                      })));
}

TestResults test_GetSocialAttributeLabelAbbreviation() {
  return execute_suite<string, int>(
      make_test_suite("SBF::GetSocialAttributeLabelAbbreviation",
                      GetSocialAttributeLabelAbbreviation,
                      vector<TestTuple<string, int>>({
                          make_test<string, int>("should get \"Cha.\" for id 1", "Cha.", make_tuple(1)),
                          make_test<string, int>("should get \"Man.\" for id 2", "Man.", make_tuple(2)),
                          make_test<string, int>("should get \"App.\" for id 3", "App.", make_tuple(3)),
                          make_test<string, int>("should get \"\" for invalid id 0", "", make_tuple(0)),
                          make_test<string, int>("should get \"\" for invalid id 4", "", make_tuple(4)),
                      })));
}

TestResults test_GetMentalAttributeLabel() {
  return execute_suite<string, int>(
      make_test_suite("SBF::GetMentalAttributeLabel",
                      GetMentalAttributeLabel,
                      vector<TestTuple<string, int>>({
                          make_test<string, int>("should get \"Intelligence\" for id 1", "Intelligence", make_tuple(1)),
                          make_test<string, int>("should get \"Perception\" for id 2", "Perception", make_tuple(2)),
                          make_test<string, int>("should get \"Wits\" for id 3", "Wits", make_tuple(3)),
                          make_test<string, int>("should get \"\" for invalid id 0", "", make_tuple(0)),
                          make_test<string, int>("should get \"\" for invalid id 4", "", make_tuple(4)),
                      })));
}

TestResults test_GetMentalAttributeLabelAbbreviation() {
  return execute_suite<string, int>(
      make_test_suite("SBF::GetMentalAttributeLabelAbbreviation",
                      GetMentalAttributeLabelAbbreviation,
                      vector<TestTuple<string, int>>({
                          make_test<string, int>("should get \"Int.\" for id 1", "Int.", make_tuple(1)),
                          make_test<string, int>("should get \"Per.\" for id 2", "Per.", make_tuple(2)),
                          make_test<string, int>("should get \"Wits\" for id 3", "Wits", make_tuple(3)),
                          make_test<string, int>("should get \"\" for invalid id 0", "", make_tuple(0)),
                          make_test<string, int>("should get \"\" for invalid id 4", "", make_tuple(4)),
                      })));
}

TestResults test_GetNumAttributesInGroup() {
  return execute_suite<int, int>(
      make_test_suite("SBF::GetNumAttributesInGroup",
                      GetNumAttributesInGroup,
                      vector<TestTuple<int, int>>({
                          make_test<int, int>("should get 0 for invalid group 0", 0, make_tuple(0)),
                          make_test<int, int>("should get 3 for group 1 kAttributeGroupPhysicalId", 3, make_tuple(1)),
                          make_test<int, int>("should get 3 for group 2 kAttributeGropuSocialId", 3, make_tuple(2)),
                          make_test<int, int>("should get 3 for group 3 kAttributeGroupMentalId", 3, make_tuple(3)),
                          make_test<int, int>("should get 0 for invalid group 4", 0, make_tuple(4)),
                      })));
}

TestResults test_FillAttributeGroupLabels() {
  return execute_suite<string>(make_test_suite(
      "SBF::FillAttributeGroupLabels",
      []() -> string {
        ostringstream error_message;
        vector<string> expected = {"Physical", "Social", "Mental"};
        vector<string> actual = {"This should be removed."};
        FillAttributeGroupLabels(actual);
        compare(error_message, expected, actual);
        string error = error_message.str();
        if (error.size() > 0) {
          return error;
        }
        return "no errors";
      },
      vector<TestTuple<string>>({
          make_test<string>("should fill attribute group labels", "no errors", make_tuple()),
      })));
}

// void FillAttributeLabelInGroup(std::vector<std::string> attributeLabels);
TestResults test_FillAttributeLabelsInGroup() {
  return execute_suite<string, int, vector<string>>(make_test_suite(
      "SBF::FillAttributeLabelsInGroup",
      [](int id, vector<string> expected) -> string {
        ostringstream error_message;
        vector<string> actual = {"This should be removed."};
        FillAttributeLabelsInGroup(actual, id);
        compare(error_message, expected, actual);
        string error = error_message.str();
        if (error.size() > 0) {
          return error;
        }
        return "no errors";
      },
      vector<TestTuple<string, int, vector<string>>>({
          make_test<string, int, vector<string>>(
              "should fill an empty list for invalid group 0", "no errors", make_tuple(0, vector<string>({}))),
          make_test<string, int, vector<string>>(
              "should fill physical attribute labels for group 1 kAttributeGropuPhysicalId",
              "no errors",
              make_tuple(1, vector<string>({"Strength", "Dexterity", "Stamina"}))),
          make_test<string, int, vector<string>>(
              "should fill social attribute labels for group 2 kAttributeGroupSocialId",
              "no errors",
              make_tuple(2, vector<string>({"Charisma", "Manipulation", "Appearance"}))),
          make_test<string, int, vector<string>>(
              "should should fill mental attribute labels for group 3 kAttributeGroupMentalId",
              "no errors",
              make_tuple(3, vector<string>({"Intelligence", "Perception", "Wits"}))),
          make_test<string, int, vector<string>>(
              "should fill an empty list for invalid group 4", "no errors", make_tuple(4, vector<string>({}))),
      })));
}

TestResults test_FillPhysicalAttributeLabels() {
  return execute_suite<string>(make_test_suite(
      "SBF::FillPhysicalAttributeLabels",
      []() -> string {
        ostringstream error_message;
        vector<string> expected = {"Strength", "Dexterity", "Stamina"};
        vector<string> actual = {"This should be removed."};
        FillPhysicalAttributeLabels(actual);
        compare(error_message, expected, actual);
        string error = error_message.str();
        if (error.size() > 0) {
          return error;
        }
        return "no errors";
      },
      vector<TestTuple<string>>({
          make_test<string>("should fill physical attribute labels", "no errors", make_tuple()),
      })));
}

// void FillSocialAttributeLabels(std::vector<std::string> socialAttributeLabels);
TestResults test_FillSocialAttributeLabels() {
  return execute_suite<string>(make_test_suite(
      "SBF::FillSocialAttributeLabels",
      []() -> string {
        ostringstream error_message;
        vector<string> expected = {"Charisma", "Manipulation", "Appearance"};
        vector<string> actual = {"This should be removed."};
        FillSocialAttributeLabels(actual);
        compare(error_message, expected, actual);
        string error = error_message.str();
        if (error.size() > 0) {
          return error;
        }
        return "no errors";
      },
      vector<TestTuple<string>>({
          make_test<string>("should fill social attribute labels", "no errors", make_tuple()),
      })));
}

// void FillMentalAttributeLabels(std::vector<std::string> mentalAttributeLabels);
TestResults test_FillMentalAttributeLabels() {
  return execute_suite<string>(make_test_suite(
      "SBF::FillMentalAttributeLabels",
      []() -> string {
        ostringstream error_message;
        vector<string> expected = {"Intelligence", "Perception", "Wits"};
        vector<string> actual = {"This should be removed."};
        FillMentalAttributeLabels(actual);
        compare(error_message, expected, actual);
        string error = error_message.str();
        if (error.size() > 0) {
          return error;
        }
        return "no errors";
      },
      vector<TestTuple<string>>({
          make_test<string>("should fill mental attribute labels", "no errors", make_tuple()),
      })));
}
}  // namespace Test::Attributes
