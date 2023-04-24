#include "Derangements.h"

#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include "test.h"

using namespace SBF;
using namespace Test;
using namespace std;

namespace Test::Derangements {
TestResults test_DerangementType_operator_extract();
TestResults test_DerangementType_operator_equal_to();
TestResults test_DerangementType_operator_not_equal_to();
TestResults test_GetDerangement();
TestResults test_FillDerangements();
}  // namespace Test::Derangements

using namespace Test::Derangements;

TestResults main_test_Derangements(int argc, char* argv[]) {
  TestResults results;

  results += test_DerangementType_operator_extract();
  results += test_DerangementType_operator_equal_to();
  results += test_DerangementType_operator_not_equal_to();
  results += test_GetDerangement();
  results += test_FillDerangements();

  PrintResults(cout, results);

  return results;
}

int main(int argc, char* argv[]) {
  TestResults results = main_test_Derangements(argc, argv);

  return results.failed() + results.errors();
}

namespace Test::Derangements {
TestResults test_GetDerangement() {
  return execute_suite<DerangementType, int>(make_test_suite(
      "SBF::GetDerangement",
      GetDerangement,
      vector<TestTuple<DerangementType, int>>({
          make_test<DerangementType, int>("should get {0, "
                                          ", "
                                          ", 0} for invalid derangement id 0",
                                          {0, "", "", 0},
                                          make_tuple(0)),
          make_test<DerangementType, int>(
              "should get {kDerangementAmnesiaId, kDerangementAmnesiaLabel, kDerangementAmnesiaDescription, "
              "kDerangementAmnesiaTextColor} for derangement id 1",
              kDerangementAmnesia,
              make_tuple(1)),
          make_test<DerangementType, int>(
              "should get {kDerangementDelusionsOfGrandeurId, kDerangementDelusionsOfGrandeurLabel, "
              "kDerangementDelusionsOfGrandeurDescription, kDerangementDelusionsOfGrandeurTextColor} for derangement "
              "id 2",
              kDerangementDelusionsOfGrandeur,
              make_tuple(2)),
          make_test<DerangementType, int>(
              "should get {kDerangementFantasyId, kDerangementFantasyLabel, kDerangementFantasyDescription, "
              "kDerangementFantasyTextColor} for derangement id 3",
              kDerangementFantasy,
              make_tuple(3)),
          make_test<DerangementType, int>(
              "should get {kDerangementManicDepressionId, kDerangementManicDepressionLabel, "
              "kDerangementManicDepressionDescription, kDerangementManicDepressionTextColor} for derangement id 4",
              kDerangementManicDepression,
              make_tuple(4)),
          make_test<DerangementType, int>(
              "should get {kDerangementMultiplePersonalitiesId, kDerangementMultiplePersonalitiesLabel, "
              "kDerangementMultiplePersonalitiesDescription, kDerangementMultiplePersonalitiesTextColor} for "
              "derangement id 5",
              kDerangementMultiplePersonalities,
              make_tuple(5)),
          make_test<DerangementType, int>(
              "should get {kDerangementObsessionId, kDerangementObsessionLabel, kDerangementObsessionDescription, "
              "kDerangementObsessionTextColor} for derangement id 6",
              kDerangementObsession,
              make_tuple(6)),
          make_test<DerangementType, int>(
              "should get {kDerangementOvercompensationId, kDerangementOvercompensationLabel, "
              "kDerangementOvercompensationDescription, kDerangementOvercompensationTextColor} for derangement id 7",
              kDerangementOvercompensation,
              make_tuple(7)),
          make_test<DerangementType, int>(
              "should get {kDerangementParanoiaId, kDerangementParanoiaLabel, kDerangementParanoiaDescription, "
              "kDerangementParanoiaTextColor} for derangement id 8",
              kDerangementParanoia,
              make_tuple(8)),
          make_test<DerangementType, int>(
              "should get {kDerangementPerfectionId, kDerangementPerfectionLabel, kDerangementPerfectionDescription, "
              "kDerangementPerfectionTextColor} for derangement id 9",
              kDerangementPerfection,
              make_tuple(9)),
          make_test<DerangementType, int>(
              "should get {kDerangementRegressionId, kDerangementRegressionLabel, kDerangementRegressionDescription, "
              "kDerangementRegressionTextColor} for derangement id 10",
              kDerangementRegression,
              make_tuple(10)),
          make_test<DerangementType, int>("should get {0, "
                                          ", "
                                          ", 0} for invalid derangement id 11",
                                          {0, "", "", 0},
                                          make_tuple(11)),
      })));
}

TestResults test_FillDerangements() {
  auto fnToTest = []() -> string {
    ostringstream error_message;
    vector<DerangementType> expected = {
        kDerangementAmnesia,
        kDerangementDelusionsOfGrandeur,
        kDerangementFantasy,
        kDerangementManicDepression,
        kDerangementMultiplePersonalities,
        kDerangementObsession,
        kDerangementOvercompensation,
        kDerangementParanoia,
        kDerangementPerfection,
        kDerangementRegression,
    };
    vector<DerangementType> actual = {{-1, "This should be removed.", "This should be removed.", 255}};
    FillDerangements(actual);
    compare(error_message, expected, actual);
    string error = error_message.str();
    if (error.size() > 0) {
      return error;
    }
    return "no errors";
  };
  return execute_suite<string>(
      make_test_suite("SBF::FillDerangements",
                      fnToTest,
                      vector<TestTuple<string>>({
                          make_test<string>("should fill derangements", "no errors", make_tuple()),
                      })));
}

TestResults test_DerangementType_operator_extract() {
  return execute_suite<string, DerangementType>(make_test_suite(
      "SBF::DerangementType::operator<<",
      [](const DerangementType& derangement) {
        ostringstream os;
        os << derangement;
        return os.str();
      },
      vector<TestTuple<string, DerangementType>>({
          make_test<string, DerangementType>("should print amnesia",
                                             "Derangement: {id: 1, label: \"" + kDerangementAmnesiaLabel
                                                 + "\", description: \"" + kDerangementAmnesiaDescription
                                                 + "\", textColor: 1}",
                                             make_tuple(kDerangementAmnesia)),
          make_test<string, DerangementType>("should print delusions of grandeur",
                                             "Derangement: {id: 2, label: \"" + kDerangementDelusionsOfGrandeurLabel
                                                 + "\", description: \"" + kDerangementDelusionsOfGrandeurDescription
                                                 + "\", textColor: 5}",
                                             make_tuple(kDerangementDelusionsOfGrandeur)),
          make_test<string, DerangementType>("should print fantasy",
                                             "Derangement: {id: 3, label: \"" + kDerangementFantasyLabel
                                                 + "\", description: \"" + kDerangementFantasyDescription
                                                 + "\", textColor: 3}",
                                             make_tuple(kDerangementFantasy)),
          make_test<string, DerangementType>("should print manic depression",
                                             "Derangement: {id: 4, label: \"" + kDerangementManicDepressionLabel
                                                 + "\", description: \"" + kDerangementManicDepressionDescription
                                                 + "\", textColor: 7}",
                                             make_tuple(kDerangementManicDepression)),
          make_test<string, DerangementType>("should print multiple personalities",
                                             "Derangement: {id: 5, label: \"" + kDerangementMultiplePersonalitiesLabel
                                                 + "\", description: \"" + kDerangementMultiplePersonalitiesDescription
                                                 + "\", textColor: 4}",
                                             make_tuple(kDerangementMultiplePersonalities)),
          make_test<string, DerangementType>("should print obsession",
                                             "Derangement: {id: 6, label: \"" + kDerangementObsessionLabel
                                                 + "\", description: \"" + kDerangementObsessionDescription
                                                 + "\", textColor: 10}",
                                             make_tuple(kDerangementObsession)),
          make_test<string, DerangementType>("should print overcompensation",
                                             "Derangement: {id: 7, label: \"" + kDerangementOvercompensationLabel
                                                 + "\", description: \"" + kDerangementOvercompensationDescription
                                                 + "\", textColor: 14}",
                                             make_tuple(kDerangementOvercompensation)),
          make_test<string, DerangementType>("should print paranoia",
                                             "Derangement: {id: 8, label: \"" + kDerangementParanoiaLabel
                                                 + "\", description: \"" + kDerangementParanoiaDescription
                                                 + "\", textColor: 9}",
                                             make_tuple(kDerangementParanoia)),
          make_test<string, DerangementType>("should print perfection",
                                             "Derangement: {id: 9, label: \"" + kDerangementPerfectionLabel
                                                 + "\", description: \"" + kDerangementPerfectionDescription
                                                 + "\", textColor: 13}",
                                             make_tuple(kDerangementPerfection)),
          make_test<string, DerangementType>("should print regression",
                                             "Derangement: {id: 10, label: \"" + kDerangementRegressionLabel
                                                 + "\", description: \"" + kDerangementRegressionDescription
                                                 + "\", textColor: 11}",
                                             make_tuple(kDerangementRegression)),
          make_test<string, DerangementType>(
              "should print an unknown derangement",
              "Derangement: {id: 0, label: \"MyLabel\", description: \"My Description\", textColor: 5}",
              make_tuple((DerangementType){0, "MyLabel", "My Description", 5})),
      })));
}

TestResults test_DerangementType_operator_equal_to() {
  return execute_suite<bool, DerangementType, DerangementType>(make_test_suite(
      "SBF::DerangementType::operator==",
      [](const DerangementType& left, const DerangementType& right) { return left == right; },
      vector<TestTuple<bool, DerangementType, DerangementType>>({
          make_test<bool, DerangementType, DerangementType>(
              "should return true when comparing a derangement to itself",
              true,
              make_tuple(kDerangementDelusionsOfGrandeur, kDerangementDelusionsOfGrandeur)),
          make_test<bool, DerangementType, DerangementType>(
              "should return true when comparing two different instances created with the same values",
              true,
              make_tuple(kDerangementFantasy,
                         DerangementType({kDerangementFantasyId,
                                          kDerangementFantasyLabel,
                                          kDerangementFantasyDescription,
                                          kDerangementFantasyTextColor}))),
          make_test<bool, DerangementType, DerangementType>(
              "should return false when comparing two different derangements",
              false,
              make_tuple(kDerangementManicDepression, kDerangementParanoia)),
      })));
}

TestResults test_DerangementType_operator_not_equal_to() {
  return execute_suite<bool, DerangementType, DerangementType>(make_test_suite(
      "SBF::DerangementType::operator!=",
      [](const DerangementType& left, const DerangementType& right) { return left != right; },
      vector<TestTuple<bool, DerangementType, DerangementType>>({
          make_test<bool, DerangementType, DerangementType>(
              "should return false when comparing a derangement to itself",
              false,
              make_tuple(kDerangementDelusionsOfGrandeur, kDerangementDelusionsOfGrandeur)),
          make_test<bool, DerangementType, DerangementType>(
              "should return false when comparing two different instances created with the same values",
              false,
              make_tuple(kDerangementFantasy,
                         DerangementType({kDerangementFantasyId,
                                          kDerangementFantasyLabel,
                                          kDerangementFantasyDescription,
                                          kDerangementFantasyTextColor}))),
          make_test<bool, DerangementType, DerangementType>(
              "should return true when comparing two different derangements",
              true,
              make_tuple(kDerangementManicDepression, kDerangementParanoia)),
      })));
}

}  // namespace Test::Derangements
